//Header includes
#include "library.hpp"
#include "codes.h"
#include "loan.h"
#include "publication.h"
#include "sortedList.h"
#include "sortedList.hpp"

//data includes
#include "member.h"
#include "audiobook.h"
#include "book.h"
#include "ebook.h"
#include "journal.h"
#include "magazine.h"
#include "movie.h"
#include "util.h"

//standard library includes
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

Library::Library() {
    this->clear();
}

void Library::clear() {
    this->audiobooks = new SortedList<AudioBook, std::string>;
    this->books = new SortedList<Book, std::string>;
    this->ebooks = new SortedList<EBook, std::string>;
    this->journals = new SortedList<Journal, std::string>;
    this->magazines = new SortedList<Magazine, std::string>;
    this->movies = new SortedList<Movie, std::string>;
    this->members = new SortedList<Member, std::string>;
}

int Library::save(const std::string& dirname) {
    //init state trackers
    int returnValues[8];
    int status = 0;

    //clean invalid data
    this->clean<Member>();
    this->clean<AudioBook>();
    this->clean<Book>();
    this->clean<EBook>();
    this->clean<Journal>();
    this->clean<Magazine>();
    this->clean<Movie>();

    //save lists to file
    returnValues[0] = members->save(dirname + "/members.txt");
    returnValues[1] = audiobooks->save(dirname + "/audiobooks.txt");
    returnValues[2] = books->save(dirname + "/books.txt");
    returnValues[3] = ebooks->save(dirname + "/ebooks.txt");
    returnValues[4] = journals->save(dirname + "/journals.txt");
    returnValues[5] = magazines->save(dirname + "/magazines.txt");
    returnValues[6] = movies->save(dirname + "/movies.txt");

    //save loans
    returnValues[7] = this->saveLoans(dirname + "/loans.txt");

    //check for errors writing
    for (int val : returnValues) {
        if (val != FILE_WRITTEN) {
            //set status to error
            status = val;
        }
    }

    //return status
    if (status == 0) {
        return FILE_WRITTEN;
    }
    else {
        return status;
    }
}

int Library::saveLoans(const std::string& filename) {
    //init state trackers
    int returnValues[6];
    int status = 0;

    //open file output stream
    std::ofstream file(filename);

    //check if file is open
    if (!file.is_open() || file.bad()) {
        return FILE_ERROR;
    }

    //write loans from each publication list
    returnValues[0] = writeLoans(*audiobooks, file);
    returnValues[1] = writeLoans(*books, file);
    returnValues[2] = writeLoans(*ebooks, file);
    returnValues[3] = writeLoans(*journals, file);
    returnValues[4] = writeLoans(*magazines, file);
    returnValues[5] = writeLoans(*movies, file);

    //check for errors writing
    for (int val : returnValues) {
        if (val != FILE_WRITTEN) {
            //set status to error
            status = val;
        }
    }

    //return status
    if (status == 0) {
        return FILE_WRITTEN;
    }
    else {
        return status;
    }
}

int Library::load(const std::string& dirname) {
    //init state trackers
    int returnValues[8];
    int status = 0;

    //clear library contents
    this->clear();

    //load lists from file
    returnValues[0] = members->load(dirname + "/members.txt");
    returnValues[1] = audiobooks->load(dirname + "/audiobooks.txt");
    returnValues[2] = books->load(dirname + "/books.txt");
    returnValues[3] = ebooks->load(dirname + "/ebooks.txt");
    returnValues[4] = journals->load(dirname + "/journals.txt");
    returnValues[5] = magazines->load(dirname + "/magazines.txt");
    returnValues[6] = movies->load(dirname + "/movies.txt");

    //clean invalid data
    this->clean<Member>();
    this->clean<AudioBook>();
    this->clean<Book>();
    this->clean<EBook>();
    this->clean<Journal>();
    this->clean<Magazine>();
    this->clean<Movie>();

    //load loans
    returnValues[7] = this->linkLoans(dirname);

    //check for errors writing
    for (int val : returnValues) {
        if (val != FILE_READ) {
            //set status to error
            status = val;
        }
    }

    //return status
    if (status == 0) {
        return FILE_READ;
    }
    else {
        return status;
    }
}

int Library::linkLoans(const std::string& dirname) {
    //init filename
    std::string filename = dirname + "/loans.txt";

    //open file input stream
    std::ifstream file(filename);

    //check if file is blank or not open
    if (file.peek() == EOF || !file.is_open()) {
        //close file
        file.close();

        //init member vars
        std::string memberID;
        std::string name;
        std::string pubID;

        //update filename
        filename = dirname + "/members.txt";

        //open member.txt
        std::ifstream file(filename);

        while (file.peek() != EOF) {
            //read id and name
            file >> memberID >> name;

            //get member from ID
            Member* member = memberSearch(memberID, 1);

            //check if member was found
            if (member == nullptr) {
                //return file error as member should exist as was list loaded from this file
                return FILE_ERROR;
            }

            //loop until line end
            while (file.peek() != '\n') {
                //read next publication id
                file >> pubID;

                //check for input stream errors
                if (file.fail() || file.bad()) {
                    //return status
                    return FILE_ERROR;
                }
                else {
                    //get publication from ID
                    Publication* pub = this->findPublication(pubID);

                    //check if publication found
                    if (pub != nullptr){
                        //init new loan
                        Loan* l = new Loan(member, pub);

                        //link loan to member
                        l->getMember()->addLoan(l);
                    }
                }
            }

            //move stream to next line or end of file
            if (file.peek() == '\n') {
                file.ignore();
            }
        }

        //return status code for partially read as all due dates reinitalised
        return FILE_PARTIALLY_READ;
    }

    //check if end of the file had been reached
    while (file.peek() != EOF) {
        //init loan
        Loan* l = readLoan(file);

        //check if data read is valid
        if (file.bad() && !file.eof()) {
            if (file.bad()) {
                //return status code
                return FILE_ERROR;
            }
            else {
                //delete invalid data
                delete l;

                //return status code
                return FILE_PARTIALLY_READ;
            }
        }
        else if (l->getMember() != nullptr && l->getPublication() != nullptr) {
            //link loan to member
            l->getMember()->addLoan(l);
        }

        //move stream to next line or end of file
        if (file.peek() == '\n') {
            file.ignore();
        }
    }

    //close file
    file.close();

    //return success code
    return FILE_READ;
}

Loan* Library::readLoan(std::istream& is) {
    //init variables
    std::string memberID;
    std::string pubID;

    //read data
    is >> memberID;
    is >> pubID;
    int active = util::parse<int>(is);
    std::time_t due = util::parse<std::time_t>(is);

    //check for input stream errors
    if (is.fail() || is.bad()) {
        return nullptr;
    }
    else {
        //get member from ID
        Member* member = memberSearch(memberID);

        //get publication from ID
        Publication* pub = this->findPublication(pubID);

        //check if member and id were found
        if (pub == nullptr || member == nullptr) {
            return nullptr;
        }

        //check if loan is active or a reservation
        if (active) {
            //return new
            return new Loan(member, pub, due);
        }
        else {
            return new Loan(member, pub);
        }
    }
}

Publication* Library::searchPublications(const std::string& title) const {
    //init result and conduct book search
    Publication* result = this->books->find(title);

    //check if result was found
    if (result == nullptr) {
        //search audiobooks
        result = this->audiobooks->find(title);

        //check for result
        if (result == nullptr) {
            //search ebooks
            result = this->ebooks->find(title);

            //check for result
            if (result == nullptr) {
                //search journals
                result = this->journals->find(title);

                //check for result
                if (result == nullptr) {
                    //search magazines
                    result = this->magazines->find(title);

                    //check for result
                    if (result == nullptr) {
                        //search movies
                        result = this->movies->find(title);
                    }
                }
            }
        }
    }

    //return the result of the searches
    return result;
}

Publication* Library::findPublication(const std::string id) const {
    switch (id[0]) {
        case 'A': case 'a':
            return this->findPublication<AudioBook>(id);
            break;
        case 'B': case 'b':
            return this->findPublication<Book>(id);
            break;
        case 'E': case 'e':
            return this->findPublication<EBook>(id);
            break;
        case 'J': case 'j':
            return this->findPublication<Journal>(id);
            break;
        case 'M': case 'm':
            return this->findPublication<Magazine>(id);
            break;
        case 'V': case 'v':
            return this->findPublication<Movie>(id);
            break;
        default:
            return nullptr;
    }
}

Book* Library::advancedBookSearch(const std::string& keystring, int type) const {
    //init function pointer
    std::string (Book::*getter)() const = nullptr;

    //switch for function call
    switch (type) {
        case 1:
            getter = &Book::getID;
            break;
        case 2:
            getter = &Book::getTitle;
            break;
        case 3:
            getter = &Book::getAuthor;
            break;
        case 4:
            getter = &Book::getGenre;
            break;
        default:
            getter = &Book::toString;
    }

    //call main search function
    return this->advancedSearch<Book>(keystring, getter);
}

AudioBook* Library::advancedAudioBookSearch(const std::string& keystring, int type) const {
    //init function pointer
    std::string (AudioBook::*getter)() const = nullptr;

    //switch for function call
    switch (type) {
        case 1:
            getter = &AudioBook::getID;
            break;
        case 2:
            getter = &AudioBook::getTitle;
            break;
        case 3:
            getter = &AudioBook::getAuthor;
            break;
        case 4:
            getter = &AudioBook::getGenre;
            break;
        default:
            getter = &AudioBook::toString;
    }

    //call main search function
    return this->advancedSearch<AudioBook>(keystring, getter);
}

EBook* Library::advancedEBookSearch(const std::string& keystring, int type) const {
    //init function pointer
    std::string (EBook::*getter)() const = nullptr;

    //switch for function call
    switch (type) {
        case 1:
            getter = &EBook::getID;
            break;
        case 2:
            getter = &EBook::getTitle;
            break;
        case 3:
            getter = &EBook::getAuthor;
            break;
        case 4:
            getter = &EBook::getGenre;
            break;
        case 5:
            getter = &EBook::getLink;
            break;
        default:
            getter = &EBook::toString;
    }

    //call main search function
    return this->advancedSearch<EBook>(keystring, getter);
}

Journal* Library::advancedJournalSearch(const std::string& keystring, int type) const {
    //init function pointer
    std::string (Journal::*getter)() const = nullptr;

    //switch for function call
    switch (type) {
        case 1:
            getter = &Journal::getID;
            break;
        case 2:
            getter = &Journal::getTitle;
            break;
        case 3:
            getter = &Journal::getPublisher;
            break;
        case 4:
            getter = &Journal::getLocation;
            break;
        case 5:
            getter = &Journal::getCategory;
            break;
        default:
            getter = &Journal::toString;
    }

    //call main search function
    return this->advancedSearch<Journal>(keystring, getter);
}

Magazine* Library::advancedMagazineSearch(const std::string& keystring, int type) const {
    //init function pointer
    std::string (Magazine::*getter)() const = nullptr;

    //switch for function call
    switch (type) {
        case 1:
            getter = &Magazine::getID;
            break;
        case 2:
            getter = &Magazine::getTitle;
            break;
        case 3:
            getter = &Magazine::getPublisher;
            break;
        case 4:
            getter = &Magazine::getCategory;
            break;
        default:
            getter = &Magazine::toString;
    }

    //call main search function
    return this->advancedSearch<Magazine>(keystring, getter);
}

Movie* Library::advancedMovieSearch(const std::string& keystring, int type) const {
    //init function pointer
    std::string (Movie::*getter)() const = nullptr;

    //switch for function call
    switch (type) {
        case 1:
            getter = &Movie::getID;
            break;
        case 2:
            getter = &Movie::getTitle;
            break;
        case 3:
            getter = &Movie::getStudio;
            break;
        case 4:
            getter = &Movie::getGenre;
            break;
        default:
            getter = &Movie::toString;
    }

    //call main search function
    return this->advancedSearch<Movie>(keystring, getter);
}

Member* Library::memberSearch(const std::string& keystring, int type) const {
    //init function pointer
    std::string (Member::*getter)() const = nullptr;

    //switch for function call
    switch (type) {
        case 1:
            getter = &Member::getID;
            break;
        case 2:
            getter = &Member::getName;
            break;
        default:
            getter = &Member::toString;
    }

    //call main search function
    return this->advancedSearch<MEMBER_H>(keystring, getter);
}

int Library::borrowPublication(const std::string& memberID, const std::string pubID) {
    //get member and publication
    Member* m = this->memberSearch(memberID);
    Publication* p = this->findPublication(pubID);

    //check if member and publication found
    if (m == nullptr || p == nullptr) {
        //return status
        return ELEMENT_NOT_FOUND;
    }

    //add loan to member
    return m->addLoan(p);
}

int Library::returnPublication(const std::string& memberID, const std::string pubID) {
    //get member and publication
    Member* m = this->memberSearch(memberID);
    Publication* p = this->findPublication(pubID);

    //check if member and publication found
    if (m == nullptr || p == nullptr) {
        //return status
        return ELEMENT_NOT_FOUND;
    }

    //add loan to member
    return m->returnLoan(p);
}


std::ostream& operator<<(std::ostream& os, const Library& lib) {
    //print all data
    std::cout << lib.format<Member>() << std::endl;
    std::cout << lib.format<AudioBook>() << std::endl;
    std::cout << lib.format<Book>() << std::endl;
    std::cout << lib.format<EBook>() << std::endl;
    std::cout << lib.format<Journal>() << std::endl;
    std::cout << lib.format<Magazine>() << std::endl;
    std::cout << lib.format<Movie>();

    //return output stream
    return os;
}

#ifndef LIBRARY_H
#define LIBRARY_H

//datatype includes
#include "audiobook.h"
#include "book.h"
#include "ebook.h"
#include "journal.h"
#include "magazine.h"
#include "movie.h"

//header includes
#include "publication.h"
#include "member.h"
#include "sortedList.h"
#include "sortedList.hpp"

//standard library includes
#include <ostream>
#include <string>

class Library {
    public:
        Library();
        ~Library();

        /**
         * Method to add to the library.
         * @param T The data to be added.
         * @return Status indicating success or failure.
         */
        template<class T>
        int add(T& data);

        /**
        * Method to remove a member from the library.
        * @param member The member to be removed.
        * @return status indicating success or failure.
        */
        template<class T>
        int remove(T& data);

        /**
         * Method to clean up unwanted dupliate data
         * @return status code indicating success or failure
         */
        template<class T>
        int clean();

        /**
         * Method to reset the library object with new lists.
         */
        void clear();

        /**
         * Method to create a formatted string of the respective list.
         * @return a string representation of the list of the provided type.
         */
        template<class T>
        std::string format() const;

        /**
         * Method to basic search members
         * @param keyword The keyword to search for.
         * @return A pointer to the member if found, nullptr otherwise.
         */
        template<class T>
        T* search(const std::string& keyword) const;

        /**
         * Method to basic search all publications
         * @param keyword The keyword to search for.
         * @return A pointer to the publication if found, nullptr otherwise.
         */
        Publication* searchPublications(const std::string& title) const;

        /**
         * Method to find a publication in the library based on it's ID
         * @param ID string containing the id of the publication
         * @return A pointer to the publication if found, nullptr otherwise.
         */
        Publication* findPublication(const std::string id) const;

        /**
         * Method to fuzzy wildcard search Books
         * @param keyword The keystring to search through.
         * @param type The category to search through.
         * @return A pointer to the member if found, nullptr otherwise.
         */
        Book* advancedBookSearch(const std::string& keystring, int type = 1) const;

        /**
         * Method to fuzzy wildcard search AudioBooks
         * @param keyword The keyword to search for.
         * @param type The category to search through.
         * @return A pointer to the member if found, nullptr otherwise.
         */
        AudioBook* advancedAudioBookSearch(const std::string& keystring, int type = 1) const;

        /**
         * Method to fuzzy wildcard search eBooks
         * @param keyword The keyword to search for.
         * @param type The category to search through.
         * @return A pointer to the member if found, nullptr otherwise.
         */
        EBook* advancedEBookSearch(const std::string& keystring, int type = 1) const;

        /**
         * Method to fuzzy wildcard search Journal
         * @param keyword The keyword to search for.
         * @param type The category to search through.
         * @return A pointer to the member if found, nullptr otherwise.
         */
        Journal* advancedJournalSearch(const std::string& keystring, int type = 1) const;

        /**
         * Method to fuzzy wildcard search Magazines
         * @param keyword The keyword to search for.
         * @param type The category to search through.
         * @return A pointer to the member if found, nullptr otherwise.
         */
        Magazine* advancedMagazineSearch(const std::string& keystring, int type = 1) const;

        /**
         * Method to fuzzy wildcard search Movies
         * @param keyword The keyword to search for.
         * @param type The category to search through.
         * @return A pointer to the member if found, nullptr otherwise.
         */
        Movie* advancedMovieSearch(const std::string& keystring, int type = 1) const;

        /**
         * Method to fuzzy wildcard search members
         * @param keyword The keyword to search for.
         * @param type The category to search through.
         * @return A pointer to the member if found, nullptr otherwise.
         */
        Member* memberSearch(const std::string& keystring, int type = 1) const;

        /**
         * Method to load the library from a directory
         * @param dirname directory to load from
         * @return status code of the operation
         */
        int load(const std::string& dirname);

        /**
         * Method to save the library to a directory
         * @param dirname directory to save into
         * @return status code of the operation
         */
        int save(const std::string& dirname);

        /**
         * Method to borrow a publication from the library
         * @param memberID member id of the member loaning out the book
         * @param pubID publication id of the publication to loan out
         * @return status code of the operation
         */
        int borrowPublication(const std::string& memberID, const std::string pubID);

        /**
         * Method to return a publication to the library
         * @param memberID member id of the member loaning out the book
         * @param pubID publication id of the publication on loan
         * @return status code of the operation
         */
        int returnPublication(const std::string& memberID, const std::string pubID);

        /**
         * Operator overload to output a library to an input stream.
         *
         * @param os output stream to write to
         * @param library to read data from
         * @return output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Library& lib);

    private:
        //class fields
        SortedList<Member, std::string>* members;
        SortedList<AudioBook, std::string>* audiobooks;
        SortedList<Book, std::string>* books;
        SortedList<EBook, std::string>* ebooks;
        SortedList<Journal, std::string>* journals;
        SortedList<Magazine, std::string>* magazines;
        SortedList<Movie, std::string>* movies;

        /**
         * Method to find a publication in the specifed types list.
         * @param id the id to search for.
         * @return the publication if found, nullptr otherwise.
         */
        template<class T>
        Publication* findPublication(const std::string& id) const;

        /**
         * Method to advanced search the given list and provided function pointer value.
         * @param keystring the string containing the keywords to search for.
         * @param function pointer to the getter for the searched class field.
         * @return closest match to the searchterm in selected field.
         */
        template<class T>
        T* advancedSearch(const std::string& keystring, std::string (T::*getter)() const) const;

        /**
         * Method to save loans to file
         * @param filename the file to write the loans to
         * @return the status code of the write
         */
        int saveLoans(const std::string& filename);

        /**
         * Method to get loans from list and write them to the file
         * @param ostream the file output stream to write the loans to
         * @return the status code of the write
         */
        template<class dataType, typename searchType>
        int writeLoans(SortedList<dataType, searchType>& l, std::ostream& os);

        /**
         * Method to load loans from file and link between publication and members
         * @param dirname the driectory of files to read the list from
         * @return the status code of the read
         */
        int linkLoans(const std::string& dirname);

        /**
         * Method to read a loan from a specified file.
         * @param input stream to read from
         * @return pointer to new loan object, or nullptr upon error
         */
        Loan* readLoan(std::istream& is);

        /**
         * Method to return the correct list for the given type string
         * @param type the typestring to return the list for.
         * @return the respective list as given by the typestring
         */
        SortedList<class Member, std::string>* getList(Member& m) const { return members; };

        /**
         * Method to return the correct list for the given type string
         * @param type the typestring to return the list for.
         * @return the respective list as given by the typestring
         */
        SortedList<class AudioBook, std::string>* getList(AudioBook& m) const { return audiobooks; };

        /**
         * Method to return the correct list for the given type string
         * @param type the typestring to return the list for.
         * @return the respective list as given by the typestring
         */
        SortedList<class Book, std::string>* getList(Book& m) const { return books; };

        /**
         * Method to return the correct list for the given type string
         * @param type the typestring to return the list for.
         * @return the respective list as given by the typestring
         */
        SortedList<class EBook, std::string>* getList(EBook& m) const { return ebooks; };

        /**
         * Method to return the correct list for the given type string
         * @param type the typestring to return the list for.
         * @return the respective list as given by the typestring
         */
        SortedList<class Journal, std::string>* getList(Journal& m) const { return journals; };

        /**
         * Method to return the correct list for the given type string
         * @param type the typestring to return the list for.
         * @return the respective list as given by the typestring
         */
        SortedList<class Magazine, std::string>* getList(Magazine& m) const { return magazines; };

        /**
         * Method to return the correct list for the given type string
         * @param type the typestring to return the list for.
         * @return the respective list as given by the typestring
         */
        SortedList<class Movie, std::string>* getList(Movie& m) const { return movies; };
};

#endif

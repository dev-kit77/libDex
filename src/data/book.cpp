//header includes
#include "book.h"
#include "util.h"

//standard library includes
#include <cstdio>
#include <istream>
#include <ostream>
#include <string>

Book::Book() {
    this->author = "";
    this->genre = "";
    this->pageCount = 0;
}

Book::Book(const std::string id, const std::string& title, const std::string& author, const std::string& genre, const int pageCount, const int availability) {
    //init fields
    this->id = id;
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->pageCount = pageCount;
    this->available = availability;
}

std::string Book::getAuthor() const {
    return this->author;
}

std::string Book::getGenre() const {
    return this->genre;
}

int Book::getPageCount() const {
    return this->pageCount;
}

std::string Book::toString() const {
    return this->id + " \"" + this->title + "\" \"" + this->author + "\" \"" + this->genre + "\" " + std::to_string(this->pageCount) + " " + std::to_string(this->available);
}

std::string Book::getType() const {
    return "book";
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    //add toString to output stream
    os << book.toString();

    //return output stream
    return os;
}

std::istream& operator>>(std::istream& is, Book& book) {
    //get id from input stream
    is >> book.id;

    //get title from input stream
    book.title = util::parseStringInput(is);

    //get author from input stream
    book.author = util::parseStringInput(is);

    //get genre from input stream
    book.genre = util::parseStringInput(is);

    //get page count from input stream
    if (is.peek() != '\n' && is.peek() != EOF) {
        is >> book.pageCount;
    }
    else {
        is.ignore();
    }

    //get copies from input stream
    if (is.peek() != '\n' && is.peek() != EOF) {
        is >> book.available;
    }
    else {
        if (!is.eof()) {
            is.ignore();
        }
    }

    //return input stream
    return is;
}

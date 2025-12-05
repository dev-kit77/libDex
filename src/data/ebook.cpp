//header includes
#include "ebook.h"
#include "util.hpp"

//standard library includes
#include <cstdio>
#include <istream>
#include <ostream>
#include <string>

EBook::EBook() {
    this->author = "";
    this->genre = "";
    this->link = "";
}

EBook::EBook(const std::string id, const std::string& title, const std::string& author, const std::string& genre, const std::string& link, const int availability) {
    //init fields
    this->id = id;
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->link = link;
    this->available = availability;
}

std::string EBook::getAuthor() const {
    return this->author;
}

std::string EBook::getGenre() const {
    return this->genre;
}

std::string EBook::getLink() const {
    return this->link;
}

std::string EBook::toString() const {
    return this->id + " \"" + this->title + "\" \"" + this->author + "\" \"" + this->genre + "\" \"" + this->link + "\" " + std::to_string(this->available);
}

std::string EBook::getType() const {
    return "ebook";
}

std::ostream& operator<<(std::ostream& os, const EBook& e) {
    //add toString to output stream
    os << e.toString();

    //return output stream
    return os;
}

std::istream& operator>>(std::istream& is, EBook& e) {
    //get id from input stream
    is >> e.id;

    //get title from input stream
    e.title = util::parseStringInput(is);

    //get author from input stream
    e.author = util::parseStringInput(is);

    //get genre from input stream
    e.genre = util::parseStringInput(is);

    //get link from input stream
    e.link = util::parseStringInput(is);

    //get copies from input stream
    if (is.peek() != '\n' && is.peek() != EOF) {
        is >> e.available;
    }

    //return input stream
    return is;
}

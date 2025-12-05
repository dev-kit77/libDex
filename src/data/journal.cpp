//header includes
#include "journal.h"
#include "util.hpp"

//standard library includes
#include <cstdio>
#include <istream>
#include <ostream>
#include <string>

Journal::Journal() {
    this->category = "";
    this->publisher = "";
    this->volume = 0;
    this->pageNo = 0;
}

Journal::Journal(const std::string id, const std::string& title, const std::string& author, const int volume, const std::string& publisher, const std::string& location, const int year, const int pageNo, const std::string& category, const int avaliability) {
    //init fields
    this->id = id;
    this->title = title;
    this->author = author;
    this->volume = volume;
    this->publisher = publisher;
    this->location = location;
    this->year = year;
    this->pageNo = pageNo;
    this->category = category;
    this->available = avaliability;
}

std::string Journal::getAuthor() const {
    return this->author;
}

int Journal::getVolume() const {
    return this->volume;
}

std::string Journal::getPublisher() const {
    return this->publisher;
}

std::string Journal::getLocation() const {
    return this->location;
}

int Journal::getYear() const {
    return this->year;
}

std::string Journal::getCategory() const {
    return this->category;
}

int Journal::getPageNo() const {
    return this->pageNo;
}

std::string Journal::toString() const {
    return this->id + " \"" + this->title + "\" \"" + this->author + "\" " + std::to_string(this->volume) + " \"" + this->publisher + "\" \"" + this->location + "\" " + std::to_string(this->year) + " \"" + this->category + "\" " + std::to_string(this->pageNo) + " " + std::to_string(this->available);
}

std::string Journal::getType() const {
    return "journal";
}

std::ostream& operator<<(std::ostream& os, const Journal& j) {
    //add toString to output stream
    os << j.toString();

    //return output stream
    return os;
}

std::istream& operator>>(std::istream& is, Journal& j) {
    //get id from input stream
    is >> j.id;

    //get title from input stream
    j.title = util::parseStringInput(is);

    //get author from input stream
    j.author = util::parseStringInput(is);

    //get volume from input stream
    j.volume = util::parse<int>(is);

    //get publisher from input stream
    j.publisher = util::parseStringInput(is);

    //get location from input stream
    j.location = util::parseStringInput(is);

    //get year from input stream
    j.year = util::parse<int>(is);

    //get location from input stream
    j.category = util::parseStringInput(is);

    //get page number from input stream
    j.pageNo = util::parse<int>(is);

    //get copies from input stream
    if (is.peek() != '\n' && is.peek() != EOF) {
        is >> j.available;
    }

    //return input stream
    return is;
}

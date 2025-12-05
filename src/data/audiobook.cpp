//header includes
#include "audiobook.h"
#include "util.h"

//standard library includes
#include <cstdio>
#include <istream>
#include <ostream>
#include <string>

AudioBook::AudioBook() {
    this->author = "";
    this->genre = "";
    this->duration = 0.0;
}

AudioBook::AudioBook(const std::string id, const std::string& title, const std::string& author, const std::string& genre, const double duration, const int availability) {
    //init fields
    this->id = id;
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->duration = duration;
    this->available = availability;
}

std::string AudioBook::getAuthor() const {
    return this->author;
}

std::string AudioBook::getGenre() const {
    return this->genre;
}

double AudioBook::getDuration() const {
    return this->duration;
}

std::string AudioBook::toString() const {
    return this->id + " \"" + this->title + "\" \"" + this->author + "\" \"" + this->genre + "\" " + std::to_string(this->duration) + " " + std::to_string(this->available);
}

std::string AudioBook::getType() const {
    return "audiobook";
}

std::ostream& operator<<(std::ostream& os, const AudioBook& a) {
    //add toString to output stream
    os << a.toString();

    //return output stream
    return os;
}

std::istream& operator>>(std::istream& is, AudioBook& a) {
    //get id from input stream
    is >> a.id;

    //get title from input stream
    a.title = util::parseStringInput(is);

    //get author from input stream
    a.author = util::parseStringInput(is);

    //get genre from input stream
    a.genre = util::parseStringInput(is);

    //get duration from input stream
    a.duration = util::parse<double>(is);

    //get copies from input stream
    if (is.peek() != '\n' && is.peek() != EOF) {
        is >> a.available;
    }

    //return input stream
    return is;
}

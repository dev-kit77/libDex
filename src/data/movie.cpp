//header includes
#include "movie.h"
#include "util.h"

//standard library includes
#include <cstdio>
#include <istream>
#include <ostream>
#include <string>

Movie::Movie() {
    this->studio = "";
    this->director = "";
    this->genre = "";
    this->duration = 0.0;
}

Movie::Movie(const std::string id, const std::string& title, const std::string& studio, const std::string& director, const std::string& genre, const double duration, const int availability) {
    //init fields
    this->id = id;
    this->title = title;
    this->studio = studio;
    this->director = director;
    this->genre = genre;
    this->duration = duration;
    this->available = availability;
}

std::string Movie::getStudio() const {
    return this->studio;
}

std::string Movie::getDirector() const {
    return this->director;
}

std::string Movie::getGenre() const {
    return this->genre;
}

double Movie::getDuration() const {
    return this->duration;
}

std::string Movie::toString() const {
    return this->id + " \"" + this->title + "\" \"" + this->studio + "\" \"" + this->director + "\" \"" + this->genre + "\" " + std::to_string(this->duration) + " " + std::to_string(this->available);
}

std::string Movie::getType() const {
    return "movie";
}

std::ostream& operator<<(std::ostream& os, const Movie& m) {
    //add toString to output stream
    os << m.toString();

    //return output stream
    return os;
}

std::istream& operator>>(std::istream& is, Movie& m) {
    //get id from input stream
    is >> m.id;

    //get title from input stream
    m.title = util::parseStringInput(is);

    //get studio from input stream
    m.studio = util::parseStringInput(is);

    //get director from input stream
    m.director = util::parseStringInput(is);

    //get genre from input stream
    m.genre = util::parseStringInput(is);

    //get duration from input stream
    m.duration = util::parse<double>(is);

    //get copies from input stream
    if (is.peek() != '\n' && is.peek() != EOF) {
        is >> m.available;
    }

    //return input stream
    return is;
}

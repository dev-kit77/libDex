//header includes
#include "magazine.h"
#include "util.h"

//standard library includes
#include <cstdio>
#include <istream>
#include <ostream>
#include <string>

Magazine::Magazine() {
    this->category = "";
    this->publisher = "";
    this->issue = 0;
    this->pageCount = 0;
}

Magazine::Magazine(const std::string id, const std::string& title, const std::string& publisher, const int issue, const std::string& category, const int pageCount, const int availability) {
    //init fields
    this->id = id;
    this->title = title;
    this->category = category;
    this->publisher = publisher;
    this->issue = issue;
    this->pageCount = pageCount;
    this->available = availability;
}

std::string Magazine::getPublisher() const {
    return this->publisher;
}

std::string Magazine::getCategory() const {
    return this->category;
}

int Magazine::getIssue() const {
    return this->issue;
}

int Magazine::getPageCount() const {
    return this->pageCount;
}

std::string Magazine::toString() const {
    return this->id + " \"" + this->title + "\" \"" + this->publisher + "\"" + std::to_string(this->issue) + " \"" + this->category + "\" " + std::to_string(this->pageCount) + " " + std::to_string(this->available);
}

std::string Magazine::getType() const {
    return "magazine";
}

std::ostream& operator<<(std::ostream& os, const Magazine& a) {
    //add toString to output stream
    os << a.toString();

    //return output stream
    return os;
}

std::istream& operator>>(std::istream& is, Magazine& m) {
    //get id from input stream
    is >> m.id;

    //get title from input stream
    m.title = util::parseStringInput(is);

    //get author from input stream
    m.publisher = util::parseStringInput(is);

    //get duration from input stream
    if (is.peek() != '\n' && is.peek() != EOF) {
        is >> m.issue;
    }
    else {
        is.ignore();
    }

    //get genre from input stream
    m.category = util::parseStringInput(is);

    //get duration from input stream
    if (is.peek() != '\n' && is.peek() != EOF) {
        is >> m.pageCount;
    }
    else {
        is.ignore();
    }

    //get copies from input stream
    if (is.peek() != '\n' && is.peek() != EOF) {
        is >> m.available;
    }
    else {
        if (!is.eof()) {
            is.ignore();
        }
    }

    //return input stream
    return is;
}

//header includes
#include "member.h"
#include "library.h"
#include "loan.h"
#include "codes.h"
#include "publication.h"

//standard library includes
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Member::Member() {
    //init class fields as empty strings
    this->id = "";
    this->name = "";

    //init empty loan vector
    this->loans = new std::vector<Loan*>();
}

Member::Member(const std::string& id, const std::string& name) {
    //init class fields
    this->id = id;
    this->name = name;

    //init empty vector
    this->loans = new std::vector<Loan*>();
}

std::string Member::getID() {
    return this->id;
}

std::string Member::getName() {
    return this->name;
}

std::vector<Loan*>* Member::getLoans() {
    return this->loans;
}

Loan* Member::getLoan(int index) {
    //check if index is valid
    if (index >= 0 && index < this->loans->size()) {
        //return loan at index
        return this->loans->at(index);
    }

    //return null
    return NULL;
}

Loan* Member::getLoan(const std::string& publicationID) {
    //loop for all loans
    for (Loan* l : *this->loans) {
        if (l->getPublication() != nullptr) {
            //check if loan is found
            if (l->getPublication()->getID() == publicationID) {
                //return loan
                return l;
            }
        }
    }

    //return null
    return NULL;
}

int Member::getLoanCount() {
    return this->loans->size();
}

int Member::hasPublication(const std::string& publicationID) {
    //loop for all loans
    for (Loan* l : *this->loans) {
        if (l->getPublication() != nullptr) {
            //check if loan is found
            if (l->getPublication()->getID() == publicationID) {
                //return status code
                return ELEMENT_FOUND;
            }
        }
    }

    //return status code
    return ELEMENT_NOT_FOUND;
}

int Member::addLoan(Publication* publication) {
    //check if loan is already in vector
    if (this->hasPublication(publication->getID()) == ELEMENT_FOUND) {
        //return status code
        return ELEMENT_ALREADY_EXISTS;
    }
    else {
        //instatise new loan object
        Loan* loan = new Loan(this, publication);

        //add loan to vector
        this->loans->push_back(loan);

        //add loan to publication
        publication->addLoan(loan);
    }

    //return status code
    return ELEMENT_ADDED;
}

int Member::returnLoan(Publication* publication) {
    //init index counter
    int i = 0;

    //loop for all loans
    for (Loan* l : *this->loans) {
        //check if loan is found
        if (l->getPublication() == publication) {
            //update publication on loan
            publication->returnLoan(l);

            //erase loan from vector
            this->loans->erase(this->loans->begin() + i);

            //delete loan object
            delete l;

            //return status code
            return ELEMENT_DELETED;
        }

        //increment index counter
        i++;
    }

    //return status code
    return ELEMENT_NOT_FOUND;
}

int Member::clearLoans() {
    //loop for all loans
    for (Loan* l : *this->loans) {
        if (l->getPublication() != nullptr) {
            //update publication on loan
            l->getPublication()->returnLoan(l);
        }

        //delete loan object
        delete l;
    }

    //clear vector
    this->loans->clear();

    //delete vector object
    delete this->loans;

    //return status code
    return ELEMENT_DELETED;
}

std::string Member::toString() const {
    //init result string and add Member ID and name
    std::stringstream* ss = new std::stringstream();

    //add Member ID and name to result string
    *ss << this->id << " " << this->name << " ";

    //loop for all loans
    for (Loan* l : *this->loans) {
        if (l->getPublication() != nullptr) {
            //add current loan ID to result string
            *ss << l->getPublication()->getID() << " ";
        }
    }

    //return completed string representation of Member
    return ss->str();
}

int Member::operator<(Member& member) {
    //compare names
    return this->name.compare(member.name) < 0;
}

int Member::operator>(Member& member) {
    //compare names
    return this->name.compare(member.name) > 0;
}

int Member::operator<(const std::string& s) {
    //compare strings
    return this->name.compare(s) < 0;
}

int Member::operator>(const std::string& s) {
    //compare strings
    return this->name.compare(s) > 0;
}

int operator==(const Member& m1, const Member& m2) {
    //compare names
    return m1.name.compare(m2.name) == 0;
}

std::ostream& operator<<(std::ostream& os, const Member& member) {
    //add member toString to output stream
    os << member.toString();

    //return output stream
    return os;
}

std::istream& operator>>(std::istream& is, Member& member) {
    //read Member ID and name
    is >> member.id >> member.name;

    //loop until end of line
    while (is.peek() != '\n' && is.peek() != EOF) {
        //init publication ID
        std::string* pubID = new std::string();

        //read publication ID
        is >> *pubID;

        //create new loan object with member and link publication from library
        member.loans->push_back(new Loan(&member, Library::getPublication(*pubID)));
    }

    //return input stream
    return is;
}

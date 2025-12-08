//header includes
#include "member.h"
#include "loan.h"
#include "codes.h"
#include "publication.h"

//standard library includes
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <list>

Member::Member() {
    //init class fields as empty strings
    this->id = "";
    this->name = "";

    //init empty Loan list
    this->Loans = new std::list<Loan*>();
}

Member::Member(const std::string& id, const std::string& name) {
    //init class fields
    this->id = id;
    this->name = name;

    //init empty list
    this->Loans = new std::list<Loan*>();
}

std::string Member::getID() const {
    return this->id;
}

std::string Member::getName() const {
    return this->name;
}

std::list<Loan*>* Member::getLoans() const {
    return this->Loans;
}

Loan* Member::getLoan(const std::string& publicationID) {
    //loop for all Loans
    for (Loan* l : *this->Loans) {
        if (l->getPublication() != nullptr) {
            //check if Loan is found
            if (l->getPublication()->getID() == publicationID) {
                //return Loan
                return l;
            }
        }
    }

    //return null
    return nullptr;
}

int Member::getLoanCount() const {
    return this->Loans->size();
}

int Member::hasPublication(const std::string& publicationID) const {
    //loop for all Loans
    for (Loan* l : *this->Loans) {
        if (l->getPublication() != nullptr) {
            //check if Loan is found
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
    //check if Loan is already in list
    if (this->hasPublication(publication->getID()) == ELEMENT_FOUND) {
        //return status code
        return ELEMENT_ALREADY_EXISTS;
    }
    else {
        //add Loan to list
        this->Loans->push_back(new Loan(this, publication));

        //add Loan to publication
        publication->addLoan(this->Loans->back());
    }

    //return status code
    return ELEMENT_ADDED;
}

int Member::addLoan(Loan* loan) {
    //check if Loan is already in list
    if (this->hasPublication(loan->getPublication()->getID()) == ELEMENT_FOUND) {
        //return status code
        return ELEMENT_ALREADY_EXISTS;
    }
    else {
        //add Loan to list
        this->Loans->push_back(loan);

        //add Loan to publication
        loan->getPublication()->addLoan(loan);
    }

    //return status code
    return ELEMENT_ADDED;
}

int Member::returnLoan(Publication* publication) {
    //init index counter
    int i = 0;

    //loop for all Loans
    for (Loan* l : *this->Loans) {
        //check if Loan is found
        if (l->getPublication() == publication) {
            //check for penalty
            if (l->getPenalty() > 0) {
                //return status code;
                return PENALTY_DUE;
            }

            //update publication on Loan
            publication->returnLoan(l);

            //erase Loan from list
            this->Loans->remove(l);

            //delete Loan object
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
    //loop for all Loans
    for (Loan* l : *this->Loans) {
        //check if Loan is a Loan
        if (typeid(*l) == typeid(Loan)) {
            //check for penalty
            if (((Loan*)l)->getPenalty() > 0) {
                //return status code;
                return PENALTY_DUE;
            }
        }

        if (l->getPublication() != nullptr) {
            //update publication on Loan
            l->getPublication()->returnLoan(l);
        }

        //delete Loan object
        delete l;
    }

    //clear list
    this->Loans->clear();

    //return status code
    return ELEMENT_DELETED;
}

std::string Member::toString() const {
    //init result string and add Member ID and name
    std::stringstream* ss = new std::stringstream();

    //add Member ID and name to result string
    *ss << this->id << " " << this->name;

    //loop for all Loans
    for (Loan* l : *this->Loans) {
        if (l->getPublication() != nullptr) {
            //add current Loan ID to result string
            *ss << " " << l->getPublication()->getID();
        }
    }

    //return completed string representation of Member
    return ss->str();
}

int Member::operator<(Member& member) const {
    //compare names
    return this->name.compare(member.name) < 0;
}

int Member::operator>(Member& member) const {
    //compare names
    return this->name.compare(member.name) > 0;
}

int Member::operator<(const std::string& s) const {
    //compare strings
    return this->name.compare(s) < 0;
}

int Member::operator>(const std::string& s) const {
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
        //skip past redundant data (now stored in loans.txt)
        is.ignore();
    }

    //return input stream
    return is;
}

//required header files
#include "member.h"
#include "loan.h"
#include "codes.h"
#include "publication.h"

//standard library includes
#include <cstddef>
#include <string>
#include <vector>

Member::Member(const std::string& id, const std::string& name) {
    //init class fields
    this->id = id;
    this->name = name;
    //init empty vector
    this->loans = std::vector<Loan*>();
}

Member::Member(const std::string& id, const std::string& name, const std::vector<Loan*>& loans) {
    //init class fields
    this->id = id;
    this->name = name;
    this->loans = loans;
}

std::string Member::getID() {
    return this->id;
}

std::string Member::getName() {
    return this->name;
}

std::vector<Loan*>* Member::getLoans() {
    return &this->loans;
}

Loan* Member::getLoan(int index) {
    //check if index is valid
    if (index >= 0 && index < this->loans.size()) {
        //return loan at index
        return this->loans[index];
    }

    //return null
    return NULL;
}

Loan* Member::getLoan(const std::string& publicationID) {
    //loop for all loans
    for (Loan* l : this->loans) {
        //check if loan is found
        if (l->getPublication()->getID() == publicationID) {
            //return loan
            return l;
        }
    }

    //return null
    return NULL;
}

int Member::getLoanCount() {
    return this->loans.size();
}

int Member::hasPublication(const std::string& publicationID) {
    //loop for all loans
    for (Loan* l : this->loans) {
        //check if loan is found
        if (l->getPublication()->getID() == publicationID) {
            //return status code
            return ELEMENT_FOUND;
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
        this->loans.push_back(loan);

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
    for (Loan* l : this->loans) {
        //check if loan is found
        if (l->getPublication() == publication) {
            //update publication on loan
            publication->returnLoan(l);

            //erase loan from vector
            this->loans.erase(this->loans.begin() + i);

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
    for (Loan* l : this->loans) {
        //update publication on loan
        l->getPublication()->returnLoan(l);

        //delete loan object
        delete l;
    }

    //clear vector
    this->loans.clear();

    //return status code
    return ELEMENT_DELETED;
}

std::string Member::toString() {
    //init result string and add Member ID and name
    std::string result = this->id + " " + this->name + " ";

    //loop for all loans
    for (Loan* l : this->loans) {
        //add current loan ID to result string
        result += l->getPublication()->getID() + " ";
    }

    //return completed string representation of Member
    return result;
}

Member::~Member() {
    this->clearLoans();
}

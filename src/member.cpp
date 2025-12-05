//header includes
#include "member.h"
#include "loan.h"
#include "reservation.h"
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

    //init empty Reservation vector
    this->Reservations = new std::vector<Reservation*>();
}

Member::Member(const std::string& id, const std::string& name) {
    //init class fields
    this->id = id;
    this->name = name;

    //init empty vector
    this->Reservations = new std::vector<Reservation*>();
}

std::string Member::getID() {
    return this->id;
}

std::string Member::getName() {
    return this->name;
}

std::vector<Reservation*>* Member::getReservations() {
    return this->Reservations;
}

Reservation* Member::getReservation(int index) {
    //check if index is valid
    if (index >= 0 && index < this->Reservations->size()) {
        //return Reservation at index
        return this->Reservations->at(index);
    }

    //return null
    return NULL;
}

Reservation* Member::getReservation(const std::string& publicationID) {
    //loop for all Reservations
    for (Reservation* l : *this->Reservations) {
        if (l->getPublication() != nullptr) {
            //check if Reservation is found
            if (l->getPublication()->getID() == publicationID) {
                //return Reservation
                return l;
            }
        }
    }

    //return null
    return NULL;
}

int Member::LoanOut(Loan* r) {
    //loop for all Reservations
    for (Reservation* l : *this->Reservations) {
        //check for null pointer
        if (l->getPublication() != nullptr) {
            //check if Reservation is found
            if (l->getPublication()->getID() == r->getPublication()->getID()) {
                //replace Reservation with Loan
                l = r;

                //return status code
                return ELEMENT_UPDATED;
            }
        }
    }

    //return status code
    return ELEMENT_NOT_FOUND;
}

int Member::getReservationCount() {
    return this->Reservations->size();
}

int Member::hasPublication(const std::string& publicationID) {
    //loop for all Reservations
    for (Reservation* l : *this->Reservations) {
        if (l->getPublication() != nullptr) {
            //check if Reservation is found
            if (l->getPublication()->getID() == publicationID) {
                //return status code
                return ELEMENT_FOUND;
            }
        }
    }

    //return status code
    return ELEMENT_NOT_FOUND;
}

int Member::addReservation(Publication* publication) {
    //check if Reservation is already in vector
    if (this->hasPublication(publication->getID()) == ELEMENT_FOUND) {
        //return status code
        return ELEMENT_ALREADY_EXISTS;
    }
    else {
        //instatise new Reservation object
        Reservation* r = new Reservation(this, publication);

        //add Reservation to vector
        this->Reservations->push_back(r);

        //add Reservation to publication
        publication->addReservation(r);
    }

    //return status code
    return ELEMENT_ADDED;
}

int Member::returnReservation(Publication* publication) {
    //init index counter
    int i = 0;

    //loop for all Reservations
    for (Reservation* l : *this->Reservations) {
        //check if Reservation is found
        if (l->getPublication() == publication) {
            //check if Reservation is a Loan
            if (typeid(*l) == typeid(Loan)) {
                //check for penalty
                if (((Loan*)l)->getPenalty() > 0) {
                    //return status code;
                    return PENALTY_DUE;
                }
            }

            //update publication on Reservation
            publication->returnPublication(l);

            //erase Reservation from vector
            this->Reservations->erase(this->Reservations->begin() + i);

            //delete Reservation object
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

int Member::clearReservations() {
    //loop for all Reservations
    for (Reservation* l : *this->Reservations) {
        //check if Reservation is a Loan
        if (typeid(*l) == typeid(Loan)) {
            //check for penalty
            if (((Loan*)l)->getPenalty() > 0) {
                //return status code;
                return PENALTY_DUE;
            }
        }

        if (l->getPublication() != nullptr) {
            //update publication on Reservation
            l->getPublication()->returnPublication(l);
        }

        //delete Reservation object
        delete l;
    }

    //clear vector
    this->Reservations->clear();

    //return status code
    return ELEMENT_DELETED;
}

std::string Member::toString() const {
    //init result string and add Member ID and name
    std::stringstream* ss = new std::stringstream();

    //add Member ID and name to result string
    *ss << this->id << " " << this->name << " ";

    //loop for all Reservations
    for (Reservation* l : *this->Reservations) {
        if (l->getPublication() != nullptr) {
            //add current Reservation ID to result string
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
        //skip past redundant data (now stored in reservations.txt)
        is.ignore();
    }

    //return input stream
    return is;
}

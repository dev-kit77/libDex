//header includes
#include "publication.h"
#include "codes.h"
#include "loan.h"
#include "member.h"

//standard library includes
#include <cstddef>
#include <list>
#include <string>

    Publication::Publication() {
        this->id = "";
        this->title = "";
        this->available = 0;
        this->Loans = new std::list<Loan*>();
    }

    std::string Publication::getID() const {
        return this->id;
    }

    std::string Publication::getTitle() const {
        return this->title;
    }

    std::list<Loan*>* Publication::getLoans() {
        return this->Loans;
    }

    int Publication::getAvailability() const {
        return this->available;
    }

    int Publication::addLoan(Loan* r) {
        //add Loan to List
        this->Loans->push_back(r);

        //update loan status
        this->updateLoan();

        //return status
        return ELEMENT_ADDED;
    }

    int Publication::returnLoan(Loan* r) {
        //init index counter
        int i = 0;

        //loop for all Loans
        for (Loan* l : *this->Loans) {
            if (l == r) {
                //remove Loan from List
                this->Loans->remove(l);

                //update loan status
                this->updateLoan();

                //return status code
                return ELEMENT_DELETED;
            }

            //increment index counter
            i++;
        }

        //return status code
        return ELEMENT_NOT_FOUND;
    }

    Loan* Publication::getLoan() const {
        return this->Loans->front();
    }

    int Publication::updateLoan() {
        //init head object
        Loan* head = this->Loans->front();

        //check if list is empty
        if (head != nullptr) {
            //update availability
            this->available = 0;

            //check if loan is active
            if (!head->getActive()) {
                //make loan active
                head->renew();
            }
        }
        else {
            this->available = 1;
        }

        //return status
        return ELEMENT_UPDATED;
    }

    int Publication::operator>(const Publication& publication) const {
        //compare titles
        return this->title.compare(publication.title) > 0;
    }

    int Publication::operator<(const Publication& publication) const {
        //compare titles
        return this->title.compare(publication.title) < 0;
    }

    int Publication::operator>(const std::string s) const {
        //compare strings
        return this->title.compare(s) > 0;
    }

    int Publication::operator<(const std::string s) const {
        //compare strings
        return this->title.compare(s) < 0;
    }

    int operator==(const Publication& p1, const Publication& p2) {
        //compare titles
        return (p1.title.compare(p2.title) == 0 && p1.getType() == p2.getType());
    }

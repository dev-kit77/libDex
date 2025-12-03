#include "publication.h"
#include "codes.h"
#include "loan.h"
#include <string>
#include <vector>

    std::string Publication::getID() const {
        return this->id;
    }

    std::string Publication::getTitle() const {
        return this->title;
    }

    std::vector<Loan*>* Publication::getLoans() {
        return &this->loans;
    }

    int Publication::getCopies() const {
        return this->copies;
    }

    int Publication::addLoan(Loan* loan) {
        //add loan to vector
        this->loans.push_back(loan);

        //return status
        return ELEMENT_ADDED;
    }

    int Publication::returnLoan(Loan* loan) {
        //init index counter
        int i = 0;

        //loop for all loans
        for (Loan* l : this->loans) {
            if (l == loan) {
                //remove loan from vector
                this->loans.erase(this->loans.begin() + i);

                //return status code
                return ELEMENT_DELETED;
            }

            //increment index counter
            i++;
        }

        //return status code
        return ELEMENT_NOT_FOUND;
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

    int operator==(Publication& p1, Publication& p2) {
        //compare titles
        return (p1.title.compare(p2.title) == 0 && p1.getType() == p2.getType());
    }

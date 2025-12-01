#include "publication.h"
#include "def.h"
#include "loan.h"
#include <string>
#include <vector>

    std::string Publication::getID() {
        return this->id;
    }

    std::string Publication::getTitle() {
        return this->title;
    }

    std::vector<Loan*>* Publication::getLoans() {
        return &this->loans;
    }

    int Publication::getCopies() {
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

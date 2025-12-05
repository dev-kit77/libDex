//header includes
#include "loan.h"

//standard library includes
#include <ctime>
#include <chrono>

Loan::Loan(Member* member, Publication* publication) {
    //init class pointers
    this->publication = publication;
    this->member = member;
    this->active = 0;
}

Loan::Loan(Member* member, Publication* publication, time_t due) {
    //init class pointers
    this->publication = publication;
    this->member = member;
    this->due = due;
    this->active = 1;
}

Member* Loan::getMember() const {
    return this->member;
}

Publication* Loan::getPublication() const {
    return this->publication;
}

std::time_t Loan::getDue() const {
    return this->due;
}

int Loan::getActive() const {
    return this->active;
}

std::time_t Loan::renew() {
    if (this->getPenalty() == 0) {
        //set due to current time + 30 days
        this->due = CURRENT_TIME + LOAN_DURATION;

        //set active to 1
        this->active = 1;

        //return new due date
        return this->due;
    }

    //return old due date if penalty is not 0
    return this->due;
}

double Loan::getPenalty() const {
    //check if loan is overdue
    if (CURRENT_TIME > due && active == 1) {
        //return penalty
        return (CURRENT_TIME - due) * BOOK_RATE;
    }

    //return 0 if loan is not overdue
    return 0;
}

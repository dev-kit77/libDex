//header includes
#include "loan.h"
#include "reservation.h"

//standard library includes
#include <ctime>
#include <chrono>

Loan::Loan(Member* member, Publication* publication) {
    //init class pointers
    this->publication = publication;
    this->member = member;

    //set due to current time + 30 days
    this->due = CURRENT_TIME + LOAN_DURATION;
}

Loan::Loan(Reservation* r) {
    //init class pointers
    this->publication = r->getPublication();
    this->member = r->getMember();

    //set due to current time + 30 days
    this->due = CURRENT_TIME + LOAN_DURATION;
}

std::time_t Loan::getDue() {
    return this->due;
}

std::time_t Loan::renew() {
    if (this->getPenalty() == 0) {
        //set due to current time + 30 days
        this->due = CURRENT_TIME + LOAN_DURATION;

        //return new due date
        return this->due;
    }

    //return old due date if penalty is not 0
    return this->due;
}

double Loan::getPenalty() {
    //check if loan is overdue
    if (CURRENT_TIME > due) {
        //return penalty
        return (CURRENT_TIME - due) * BOOK_RATE;
    }

    //return 0 if loan is not overdue
    return 0;
}

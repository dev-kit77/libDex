#ifndef LOAN_H
#define LOAN_H

//standard library includes
#include <ctime>

class Member;
class Publication;

//Loan Related Constants
#define CURRENT_TIME std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())
#define LOAN_DURATION (30*60*60*24)
#define BOOK_RATE 0.000025 //fraction of penny to be added per overdue second = £2.16 per day

/**
 * Loan Class to represent a loan of a publication to a member, store due date, and cross-reference.
 * Version: 1.00.
 * Kit Cochrane.
 */
class Loan {
    public:
        /**
        * Constructor for Loan class. Creates a new loan with the given member and publication and sets the due date.
        * @param member Pointer to the member who borrowed the publication.
        * @param publication Pointer to the publication that was borrowed.
        */
        Loan(Member* member, Publication* publication);

        /**
         * Getter for the member who borrowed the publication.
         * @return Pointer to the member who borrowed the publication.
         */
        Member* getMember() const;

        /**
         * Getter for the publication that was borrowed.
         * @return Pointer to the publication that was borrowed.
         */
        Publication* getPublication() const;

        /**
         * Getter for the due date of the loan.
         * @return Time_t representing the due date of the loan.
         */
        std::time_t getDue() const;

        /**
         * Getter for the active status of the loan.
         * @return Integer representing the active status of the loan.
         */
        int getActive() const;

        /**
         * Renew the loan for an additional period.
         * @return Time_t representing the new due date of the loan.
         */
        std::time_t renew();

        /**
         * Method to calculate the penalty for late return of the publication.
         * @return Double representing the penalty amount.
         */
        double getPenalty() const ;

    private:
        Member* member;
        Publication* publication;
        int active;
        std::time_t due;
};

#endif

#ifndef PUBLICATION_H
#define PUBLICATION_H

#include "loan.h"
#include <string>
#include <vector>

/**
 * Publication Abstract Class for libDex.
 * Version 1.00
 * Kit Cochrane
 *
 * Subclasses should implement a constructor, toString() and getType() methods along with the respective additional methods, getters for each type of publication.
 */
class Publication {
    public:
        Publication();
        virtual ~Publication();

        /**
         * Getter for id class field
         */
        std::string getID();

        /**
         * Getter for title class field
         */
        std::string getTitle();

        /**
         * Getter for loans class field
         */
        std::vector<Loan*>* getLoans();

        /**
         * Getter for copies class field
         */
        int getCopies();

        /**
         * Method to add a loan to the publication
         */
        int addLoan(Loan* loan);

        /**
         * Method to return a loan from the publication
         */
        int returnLoan(Loan* loan);

        virtual std::string toString() = 0;
        virtual std::string getType() = 0;

    protected:
        //class fields
        std::string id;
        std::string title;
        int copies;
        std::vector<Loan*> loans;
};

#endif

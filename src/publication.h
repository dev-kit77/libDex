#ifndef PUBLICATION_H
#define PUBLICATION_H

#include "loan.h"
#include <string>
#include <list>

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
        virtual ~Publication() {}

        /**
         * Getter for id class field
         */
        std::string getID() const;

        /**
         * Getter for title class field
         */
        std::string getTitle() const;

        /**
         * Getter for Loans class field
         */
        std::list<Loan*>* getLoans();

        /**
         * Getter for copies class field
         */
        int getAvailability() const;

        /**
         * Method to add a Loan to the publication
         */
        int addLoan(Loan* Loan);

        /**
         * Method to remove/return a reservation on the publication.
         * @return The cost of any fees on the loan/reservation.
         */
        int returnLoan(Loan* Loan);

        /**
         * Method to get the current loan for the publication
         */
        Loan* getLoan() const;

        /**
         * Operator overload to compare two publications lexographically by title.
         *
         * @param publication The Publication to compare with.
         * @return 1 if this Publication's title is first alphabetically, 0 otherwise.
         */
        int operator<(const Publication& publication) const;

        /**
         * Operator overload to compare compare a Publication with a string lexographically by title.
         *
         * @param s The string to compare with.
         * @return 1 if this Publication's title is first alphabetically, 0 otherwise.
         */
        int operator<(const std::string s) const;

        /**
         * Operator overload to compare two publications lexographically by title.
         *
         * @param publication The Publication to compare with.
         * @return 1 if this Publication's title is last alphabetically, 0 otherwise.
         */
        int operator>(const Publication& publication) const;

        /**
         * Operator overload to compare a Publication with a string lexographically by title.
         *
         * @param s The string to compare with.
         * @return 1 if this Publication's title is last alphabetically, 0 otherwise.
         */
        int operator>(const std::string s) const;

        /**
         * Operator overload to output a Publication to an output stream.
         *
         * @param os The output stream to write to.
         * @param publication The Publication to output.
         * @return The output stream.
         */
        friend std::ostream& operator<<(std::ostream& os, Publication& publication);

        /**
         * Operator overload to input to a Publication from an input stream.
         *
         * @param is The input stream to read from.
         * @param publication The Publication to input to.
         * @return The input stream.
         */
        friend std::istream& operator>>(std::istream& is, Publication& publication);

        /**
         * Operator overload to compare two Publications lexographically by title.
         *
         * @param publication The Publication to compare with.
         * @return 1 if the Publications titles are the same, 0 otherwise.
         */
        friend int operator==(const Publication& p1, const Publication& p2);

        /**
         * toString method to return a string representation of the publication. Pure virtual method to be implemented by subclasses.
         */
        virtual std::string toString() const = 0;

        /**
         * getType method to return the type of the publication. Pure virtual method to be implemented by subclasses.
         */
        virtual std::string getType() const = 0;

    protected:
        //class fields
        std::string id;
        std::string title;
        int available;
        std::list<Loan*>* Loans;

        /**
         * Method to update the loan status of a publication.
         *
         * @return The result of the update operation, as integer.
         */
        int updateLoan();
};

#endif

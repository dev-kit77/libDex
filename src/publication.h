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

        /**
         * Operator overload to compare two publications lexographically by title.
         *
         * @param publication The Publication to compare with.
         * @return 1 if this Publication's title is first alphabetically, 0 otherwise.
         */
        int operator<(const Publication& publication);

        /**
         * Operator overload to compare compare a Publication with a string lexographically by title.
         *
         * @param s The string to compare with.
         * @return 1 if this Publication's title is first alphabetically, 0 otherwise.
         */
        int operator<(const std::string s);

        /**
         * Operator overload to compare two publications lexographically by title.
         *
         * @param publication The Publication to compare with.
         * @return 1 if this Publication's title is last alphabetically, 0 otherwise.
         */
        int operator>(const Publication& publication);

        /**
         * Operator overload to compare a Publication with a string lexographically by title.
         *
         * @param s The string to compare with.
         * @return 1 if this Publication's title is last alphabetically, 0 otherwise.
         */
        int operator>(const std::string s);

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
         * toString method to return a string representation of the publication. Pure virtual method to be implemented by subclasses.
         */
        virtual std::string toString() = 0;

        /**
         * getType method to return the type of the publication. Pure virtual method to be implemented by subclasses.
         */
        virtual std::string getType() = 0;

    protected:
        //class fields
        std::string id;
        std::string title;
        int copies;
        std::vector<Loan*> loans;
};

#endif

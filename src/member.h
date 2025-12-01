#ifndef MEMBER_H
#define MEMBER_H

#include "publication.h"
#include <string>
#include <vector>

class Loan;

/**
 * Member Class for libDex.
 * Version 1.00.
 * Kit Cochrane.
 *
 * Designed to represent a Member of the library system. Stores Member information and current active Member loans.
 */
class Member {
    public:
        /**
         * Default Constructor for Member class.
         *
         * @param id The Member's ID, as string.
         * @param name The Member's name, as string.
         */
        Member(const std::string& id, const std::string& name);

        /**
         * Constructor for Member class with loan information.
         *
         * @param id The Member's ID, as string.
         * @param name The Member's name, as string.
         * @param loans The Member's loans, as vector of strings.
         */
        Member(const std::string& id, const std::string& name, const std::vector<Loan*>& loans);

        /**
         * Destructor for Member class.
         */
        virtual ~Member();

        /**
         * Getter for Member ID.
         *
         * @return The Member's ID, as string.
         */
        std::string getID();

        /**
         * Getter for Member name.
         *
         * @return The Member's name, as string.
         */
        std::string getName();

        /**
         * Getter for Member loan at index.
         *
         * @param index The index of the loan to retrieve.
         * @return The publication ID of the item loan at the specified index, as string.
         */
        Loan* getLoan(int index);

        /**
         * Getter for Member loan with publication ID.
         *
         * @param publicationID The publication ID of the item loan to retrieve.
         * @return The publication ID of the item loan at the specified index, as string.
         */
        Loan* getLoan(const std::string& publicationID);

        /**
         * Getter for Member loans.
         *
         * @return The Member's loans, as vector of strings.
         */
        std::vector<Loan*>* getLoans();

        /**
         * Getter for Member loan count.
         *
         * @return The number of loans the Member has, as integer.
         */
        int getLoanCount();

        /**
         * Method to check if a Member has a loan for a specific publication.
         *
         * @param loan The publication ID of the item loan to check, as string.
         * @return True if the Member has the publication, false otherwise.
         */
        int hasPublication(const std::string& publicationID);

        /**
         * Method to add a loan to a Members account.
         *
         * @param loan The publication ID of the item loan to add, as string.
         */
        int addLoan(Publication* publication);

        /**
         * Method to return a loan from a Members account.
         *
         * @param loan The publication ID of the item loan to return, as string.
         */
        int returnLoan(Publication* publication);

        /**
         * Method to clear all loans from a Members account.
         *
         * @return Status code indicating success.
         */
        int clearLoans();

        /**
         * Method to create a string representation of this Member object.
         *
         * @return A representation of this Member object, as string.
         */
        std::string toString();

    private:
        std::string id;
        std::string name;
        std::vector<Loan*> loans;
};

#endif

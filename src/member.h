#ifndef MEMBER_H
#define MEMBER_H

//standard library includes
#include "loan.h"
#include <string>
#include <vector>

//forward declarations
class Reservation;
class Publication;

/**
 * Member Class for libDex.
 * Version 1.00.
 * Kit Cochrane.
 *
 * Designed to represent a Member of the library system. Stores Member information and current active Member Reservations.
 */
class Member {
    public:
        /**
        * Default constructor for Member class.
        */
        Member();

        /**
         * Constructor for Member class.
         *
         * @param id The Member's ID, as string.
         * @param name The Member's name, as string.
         */
        Member(const std::string& id, const std::string& name);

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
         * Getter for Member Reservation at index.
         *
         * @param index The index of the Reservation to retrieve.
         * @return The publication ID of the item Reservation at the specified index, as string.
         */
        Reservation* getReservation(int index);

        /**
         * Getter for Member Reservation with publication ID.
         *
         * @param publicationID The publication ID of the item Reservation to retrieve.
         * @return The publication ID of the item Reservation at the specified index, as string.
         */
        Reservation* getReservation(const std::string& publicationID);

        /**
         * Method to loan out a publication that has been reserved.
         *
         * @param r The Loan object to replace the reservation with.
         * @return The result of the loan operation, as integer.
         */
        int LoanOut(Loan* r);

        /**
         * Getter for Member Reservations.
         *
         * @return The Member's Reservations, as vector of strings.
         */
        std::vector<Reservation*>* getReservations();

        /**
         * Getter for Member Reservation count.
         *
         * @return The number of Reservations the Member has, as integer.
         */
        int getReservationCount();

        /**
         * Method to check if a Member has a Reservation for a specific publication.
         *
         * @param Reservation The publication ID of the item Reservation to check, as string.
         * @return True if the Member has the publication, false otherwise.
         */
        int hasPublication(const std::string& publicationID);

        /**
         * Method to add a Reservation to a Members account.
         *
         * @param Reservation The publication ID of the item Reservation to add, as string.
         */
        int addReservation(Publication* publication);

        /**
         * Method to return a Reservation from a Members account.
         *
         * @param Reservation The publication ID of the item Reservation to return, as string.
         */
        int returnReservation(Publication* publication);

        /**
         * Method to clear all Reservations from a Members account.
         *
         * @return Status code indicating success.
         */
        int clearReservations();

        /**
         * Method to create a string representation of this Member object.
         *
         * @return A representation of this Member object, as string.
         */
        std::string toString() const;

        /**
         * Operator overload to compare two Members lexographically by name.
         *
         * @param member The Member to compare with.
         * @return 1 if this Member's name is first alphabetically, 0 otherwise.
         */
        int operator<(Member& member);

        /**
         * Operator overload to compare a Member's name with a string lexographically.
         *
         * @param s The string to compare with.
         * @return 1 if this Member's name is first alphabetically, 0 otherwise.
         */
        int operator<(const std::string& s);

        /**
         * Operator overload to compare two Members lexographically by name.
         *
         * @param member The Member to compare with.
         * @return 1 if this Member's name is last alphabetically, 0 otherwise.
         */
        int operator>(Member& member);

        /**
         * Operator overload to compare a Member's name with a string lexographically.
         *
         * @param s The string to compare with.
         * @return 1 if this Member's name is last alphabetically, 0 otherwise.
         */
        int operator>(const std::string& s);

        /**
         * Operator overload to compare two Members lexographically by name.
         *
         * @param member The Member to compare with.
         * @return 1 if this Member's name is same, 0 otherwise.
         */
        friend int operator==(const Member& m1, const Member& m2);

        /**
         * Operator overload to output a Member object to an output stream.
         *
         * @param os The output stream to write to.
         * @param member The Member object to output.
         * @return The output stream.
         */
        friend std::ostream& operator<<(std::ostream& os, const Member& member);

        /**
         * Operator overload to input to a Member object from an input stream.
         *
         * @param is The input stream to read from.
         * @param member The Member object to input to.
         * @return The input stream.
         */
        friend std::istream& operator>>(std::istream& is, Member& member);

    private:
        std::string id;
        std::string name;
        std::vector<Reservation*>* Reservations;
};

#endif

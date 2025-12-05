#ifndef RESERVATION_H
#define RESERVATION_H

//forward declarations for pointers
class Member;
class Publication;

/**
 * Reservation Class to represent a Reservation of a publication to a member and cross-reference.
 * Version: 1.00.
 * Kit Cochrane.
 */
class Reservation {
    public:
        /**
        * Default constructor for Reservation class. Creates a new Reservation with default values. Used for loan inheritance
        */
        Reservation();

        /**
        * Constructor for Reservation class. Creates a new Reservation with the given member and publication and sets the due date.
        * @param member Pointer to the member who borrowed the publication.
        * @param publication Pointer to the publication that was borrowed.
        */
        Reservation(Member* member, Publication* publication);

        /**
         * Getter for the member who borrowed the publication.
         * @return Pointer to the member who borrowed the publication.
         */
        Member* getMember();

        /**
         * Getter for the publication that was borrowed.
         * @return Pointer to the publication that was borrowed.
         */
        Publication* getPublication();

    protected:
        Member* member;
        Publication* publication;
};

#endif

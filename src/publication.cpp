//header includes
#include "publication.h"
#include "codes.h"
#include "loan.h"
#include "member.h"
#include "reservation.h"

//standard library includes
#include <string>
#include <vector>

    Publication::Publication() {
        this->id = "";
        this->title = "";
        this->available = 0;
        this->Reservations = new std::vector<Reservation*>();
    }

    std::string Publication::getID() const {
        return this->id;
    }

    std::string Publication::getTitle() const {
        return this->title;
    }

    std::vector<Reservation*>* Publication::getReservations() {
        return this->Reservations;
    }

    int Publication::getAvailability() const {
        return this->available;
    }

    int Publication::addReservation(Reservation* r) {
        //add Reservation to vector
        this->Reservations->push_back(r);

        //update loan status
        this->updateLoan();

        //return status
        return ELEMENT_ADDED;
    }

    int Publication::returnPublication(Reservation* r) {
        //init index counter
        int i = 0;

        //loop for all Reservations
        for (Reservation* l : *this->Reservations) {
            if (l == r) {
                //remove Reservation from vector
                this->Reservations->erase(this->Reservations->begin() + i);

                //update loan status
                this->updateLoan();

                //return status code
                return ELEMENT_DELETED;
            }

            //increment index counter
            i++;
        }

        //return status code
        return ELEMENT_NOT_FOUND;
    }

    Loan* Publication::getLoan() const {
        return (Loan*) this->Reservations->front();
    }

    int Publication::updateLoan() {
        //init head object
        Reservation* head = this->Reservations->front();

        //check if first element is a Reservation
        if (typeid(*head) == typeid(Reservation)) {
            //create new Loan object
            head = new Loan(head);

            //get member to update
            Member* m = head->getMember();

            //update member's loan status
            m->LoanOut((Loan*)head);
        }

        //return status
        return ELEMENT_UPDATED;
    }

    int Publication::operator>(const Publication& publication) const {
        //compare titles
        return this->title.compare(publication.title) > 0;
    }

    int Publication::operator<(const Publication& publication) const {
        //compare titles
        return this->title.compare(publication.title) < 0;
    }

    int Publication::operator>(const std::string s) const {
        //compare strings
        return this->title.compare(s) > 0;
    }

    int Publication::operator<(const std::string s) const {
        //compare strings
        return this->title.compare(s) < 0;
    }

    int operator==(const Publication& p1, const Publication& p2) {
        //compare titles
        return (p1.title.compare(p2.title) == 0 && p1.getType() == p2.getType());
    }

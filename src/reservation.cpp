//header includes
#include "reservation.h"

//standard library includes
#include <ctime>

Reservation::Reservation() {
    //init class pointers
    this->publication = nullptr;
    this->member = nullptr;
}

Reservation::Reservation(Member* member, Publication* publication) {
    //init class pointers
    this->publication = publication;
    this->member = member;
}

Member* Reservation::getMember() {
    return this->member;
}

Publication* Reservation::getPublication() {
    return this->publication;
}

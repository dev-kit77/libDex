//header includes
#include "pubtest.hpp"
#include "codes.h"
#include "ebook.h"
#include "interface.h"
#include "loan.h"
#include "member.h"

//data includes
#include "audiobook.h"
#include "book.h"
#include "journal.h"
#include "magazine.h"
#include "movie.h"

//standard library includes
#include <iostream>
#include <list>

int main() {
    //txt print
    interface::printTXT("./res/libdex.txt");

    //print separator
    interface::separator();

    //test message print
    interface::printMessage("Welcome to the Publication Test!");

    //print separator
    interface::separator();

    //test book class
    test<Book>(*new Book("B109", "The Great Gatsby", "F. Scott Fitzgerald", "Roaring 20s, Upper Class", 291, 1));

    //test audiobook class
    test<AudioBook>(*new AudioBook("A101", "The Great Gatsby", "F. Scott Fitzgerald", "Roaring 20s, Upper Class", 29.1, 1));

    //test ebook class
    test<EBook>(*new EBook("E101", "The Great Gatsby", "F. Scott Fitzgerald", "Roaring 20s, Upper Class", "www.gatsbybook.com", 1));

    //test journal class
    test<Journal>(*new Journal("J101", "American Science", 1, "Westing House", "Wisconsin, USA", 2023, 459, "Science", 1));

    //test magazine class
    test<Magazine>(*new Magazine("M101", "The New Yorker", "New York Times", 1043, "Literature", 24, 1));

    //test movie class
    test<Movie>(*new Movie("V102", "The Shawshank Redemption", "Castle Rock Entertainment", "Frank Darabont", "Drama", 142, 1));

    //general publication tests
    interface::printMessage("Generalised Publication Tests!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Instantiating new book publication subclass to serve as generalised publication:");

    //init new book
    Book* p = new Book("B109", "The Great Gatsby", "F. Scott Fitzgerald", "Roaring 20s, Upper Class", 291, 1);

    //print message
    interface::printMessage("Done!");

    //print new line
    interface::newLine();

    //printing
    interface::printMessage("Printing generalised publication for verification:");
    cout << *p << endl;

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Instantising new member class to test loan/Loan functionality:");

    //init new member
    Member* m1 = new Member("M101", "John Doe");

    //print message
    interface::printMessage("Done!");

    //print new line
    interface::newLine();

    //printing
    interface::printMessage("Printing member for verification:");
    cout << *m1 << endl;

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Instantising secondnew member class to test loan/Loan functionality:");

    //init new member
    Member* m2 = new Member("M102", "Jane Doe");

    //print message
    interface::printMessage("Done!");

    //print new line
    interface::newLine();

    //printing
    interface::printMessage("Printing member for verification:");
    cout << *m2 << endl;

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Testing Loan functionality!");

    //print separator
    interface::separator();

    //print availability
    interface::printMessage("Checking availability of publication:");
    interface::printMessage(p->getAvailability() ? "Available" : "Not Available");

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Adding new Loan from member 1 on publication:");

    //adding new Loan
    int returnValue = m1->addLoan(p);

    //check if loan was added
    if(returnValue == ELEMENT_ADDED){
        interface::printMessage("Pass: Loan Added");
    }
    else {
        interface::printMessage("Fail: Loan Failed");
    }

    //print message
    interface::printMessage("Done!");

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Checking if Publication has loan:");

    //get current loan from publication
    list<Loan*>* ls = p->getLoans();

    //check if list is empty
    if (ls->empty()) {
        interface::printMessage("No Loans Found");
    }
    else {
        for (Loan* l : *ls) {
            cout << *l->getMember() << l->getPublication()->getTitle() << " " << l->getActive() << endl;
        }
    }

    //print new line
    interface::newLine();

    //print availability
    interface::printMessage("Checking availability of publication:");
    interface::printMessage(p->getAvailability() ? "Available" : "Not Available");

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Adding new Loan from member 2 on publication:");

    //adding new Loan
    returnValue = m2->addLoan(p);

    //check if loan was added
    if(returnValue == ELEMENT_ADDED){
        interface::printMessage("Pass: Loan Added");
    }
    else {
        interface::printMessage("Fail: Loan Failed");
    }

    //new line
    interface::newLine();

    //get current loan from publication
    ls = p->getLoans();

    //print message
    interface::printMessage("Printing Loans for verification:");

    //check if list is empty
    if (ls->empty()) {
        interface::printMessage("No Loans Found");
    }
    else {
        for (Loan* l : *ls) {
            cout << *l->getMember() << l->getPublication()->getTitle() << " " << l->getActive() << endl;
        }
    }

    //print new line
    interface::newLine();

    //print availability
    interface::printMessage("Checking availability of publication:");
    interface::printMessage(p->getAvailability() ? "Available" : "Not Available");

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Checking loan removal and new loan assignment:");

    //remove loan from member
    returnValue = m1->returnLoan(p);

    //check if loan was removed
    if(returnValue == ELEMENT_DELETED){
        interface::printMessage("Pass: Loan Removed");
    }
    else {
        interface::printMessage("Fail: Loan Not Removed");
    }

    //new line
    interface::newLine();

    //get current loans from publication
    ls = p->getLoans();

    //print message
    interface::printMessage("Printing Loans for verification:");

    if (ls->empty()) {
        interface::printMessage("No Loans Found");
    }
    else {
        for (Loan* l : *ls) {
            if (l != nullptr) {
                cout << *l->getMember() << l->getPublication()->getTitle() << " " << l->getActive() << endl;
            }
        }
    }

    //print availability
    interface::printMessage("Checking availability of publication:");
    interface::printMessage(p->getAvailability() ? "Available" : "Not Available");

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Checking availability after all loans removed:");

    //remove loan from member
    returnValue = m2->returnLoan(p);

    //check if loan was removed
    if(returnValue == ELEMENT_DELETED){
        interface::printMessage("Pass: Loan Removed");
    }
    else {
        interface::printMessage("Fail: Loan Not Removed");
    }

    //print new line
    interface::newLine();

    //print availability
    interface::printMessage("Checking availability of publication:");
    interface::printMessage(p->getAvailability() ? "Available" : "Not Available");

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Printing Loans for verification:");
    if (ls->empty()) {
        interface::printMessage("No Loans Found");
    }
    else {
        for (Loan* l : *ls) {
            cout << *l->getMember() << l->getPublication()->getTitle() << " " << l->getActive() << endl;
        }
    }

    //exit program
    return 0;
}

//header includes
#include "book.h"
#include "codes.h"
#include "interface.h"
#include "member.h"

//standard library includes
#include <iostream>
#include <ostream>

int main() {
    //txt print
    interface::printTXT("./res/libdex.txt");

    //print separator
    interface::separator();

    //test message print
    interface::printMessage("Welcome to the Member Test!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Instantising Testing Book:");

    //create object
    Book* testBook = new Book("B101", "The Great Gatsby", "F. Scott Fitzgerald", "Roaring 20s, Upper Class", 291, 1);

    //print message
    interface::printMessage("Instantising Default Test Member Object:");

    //create object
    Member* m = new Member();

    //print message
    interface::printMessage("Done!");

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing default object for verification:");
    std::cout << *m << std::endl;

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Instantising new Member Object M101 \"John\":");

    //create object
    m = new Member("M101", "John");

    //print message
    interface::printMessage("Done!");

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing object for verification:");
    std::cout << *m << std::endl;

    //print separator
    interface::separator();

    //test message print
    interface::printMessage("Testing loans!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Adding loan on test publication:");

    //add loan
    int returnValue = m->addLoan(testBook);

    //check return value
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Loan added.");
    }
    else {
        interface::printMessage("Fail: Loan not added.");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing member for verification:");
    std::cout << *m << std::endl;

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Adding Duplicate loan on test publication:");

    //add loan
    returnValue = m->addLoan(testBook);

    //check return value
    if (returnValue == ELEMENT_ALREADY_EXISTS) {
        interface::printMessage("Pass: Duplicate Loan detected.");
    }
    else {
        interface::printMessage("Fail: Loan added.");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing member for verification:");
    std::cout << *m << std::endl;

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Removing loan on test publication:");

    //add loan
    returnValue = m->returnLoan(testBook);

    //check return value
    if (returnValue == ELEMENT_DELETED) {
        interface::printMessage("Pass: Loan removed.");
    }
    else {
        interface::printMessage("Fail: Loan not removed.");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing member for verification:");
    std::cout << *m << std::endl;

    //newline
    interface::newLine();

    //print message
    interface::printMessage("Adding prebuilt loan on test publication:");

    //add loan
    returnValue = m->addLoan(new Loan(m, testBook, 1765000000));

    //check return value
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Loan added.");
    }
    else {
        interface::printMessage("Fail: Loan not added.");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing member for verification:");
    std::cout << *m << std::endl;

    //new line
    interface::separator();

    //print message
    interface::printMessage("Testing penalties!");

    //separator
    interface::separator();

    //print message
    interface::printMessage("Testing removing a loan with penalties due:");

    //add loan
    returnValue = m->returnLoan(testBook);

    //check return value
    if (returnValue == PENALTY_DUE) {
        interface::printMessage("Pass: Penalty Due detected.");
    }
    else {
        interface::printMessage("Fail: Loan Removed.");
    }

    //newlien
    interface::newLine();

    //print message
    interface::printMessage("Testing penalty totalling:");

    //get penalties
    double penalty = m->getPenalties();

    //print messahe
    interface::printMessage("Printing penalties due for validation:");

    std::cout << penalty << std::endl;

    //exit program
    return 0;
}

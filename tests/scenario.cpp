//header includes
#include "book.h"
#include "codes.h"
#include "interface.h"
#include "library.hpp"
#include "member.h"
#include <iostream>

int main() {
    //txt print
    interface::printTXT("./res/libdex.txt");

    //print separator
    interface::separator();

    //test message print
    interface::printMessage("Welcome to the Test Scenario!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Instantiating a new Library Class:");

    //init library
    Library* lib = new Library();

    //print message
    interface::printMessage("Done!");

    //newline
    interface::separator();

    //print message
    interface::printMessage("Loading sample files from tests/scenario into Library:");

    //load tester files
    int returnValue = lib->load("tests/scenario");

    //check for expected status code (tester files don't include all files the system is looking for hence file not found)
    if (returnValue == FILE_PARTIALLY_READ) {
        interface::printMessage("Pass: Library loaded.");
    }
    else {
        interface::printMessage("Fail: File Error.");
    }

    //new line
    interface::separator();

    //print message
    interface::printMessage("Adding book B108 \"The Power of Positive Thinking\" \"Norman Vincent Peale\" \"Motivational, Spirituality\" 240 to library:");

    //init book
    Book* b = new Book("B108", "The Power of Positive Thinking", "Norman Vincent Peale", "Motivational, Spirituality", 240, 1);

    //add book (There is already a copy of this book with a different ID, Multiples of books are allowed with different ids)
    returnValue = lib->add(b);

    //check for expected status code
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Book Added.");
    }
    else {
        interface::printMessage("Fail: Book Not Added.");
    }

    //separator
    interface::separator();

    //print message
    interface::printMessage("Adding Member M110 Jane:");

    //init member
    Member* m = new Member("M110", "Jane");

    //add member (Again, There is a member called jane with a different ID, Multiples of names are allowed with different ids)
    returnValue = lib->add(m);

    //check for expected status code
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Member Added.");
    }
    else {
        interface::printMessage("Fail: Member Not Added.");
    }

    //seperator
    interface::separator();

    //print message
    interface::printMessage("Ben borrowing Book B106:");

    //borrow publication (Ben already has this publication)
    returnValue = lib->borrowPublication("M106", "B106");

    //check for expected status code
    if (returnValue == ELEMENT_ALREADY_EXISTS) {
        interface::printMessage("Pass: Loan Not Added.");
    }
    else {
        interface::printMessage("Fail: Loan Added.");
    }

    //separator
    interface::separator();

    //print message
    interface::printMessage("Ben returning Book B106:");

    //borrow publication (Ben already has this publication)
    returnValue = lib->returnPublication("M106", "B106");

    //check for expected status code
    if (returnValue == ELEMENT_DELETED) {
        interface::printMessage("Pass: Loan Returned.");
    }
    else {
        interface::printMessage("Fail: Loan Not Returned.");
    }

    //separator
    interface::separator();

    //print message
    interface::printMessage("Searching for \"Awaken the Giant Within\"");

    //search library
    Book* result = lib->search<Book>("Awaken the Giant Within");

    //check result
    if (result != nullptr) {
        //print result
        interface::printMessage("Pass: Book Found:");
        std::cout << *result << std::endl;
    }
    else {
        interface::printMessage("Fail: No Book Found.");
    }

    //separator
    interface::separator();

    //print message
    interface::printMessage("Searching for author \"Tony Robbins\"");

    //search library
    result = lib->advancedBookSearch("Tony Robbins", 3);

    //check result
    if (result != nullptr) {
        //print result
        interface::printMessage("Pass: Book Found:");
        std::cout << *result << std::endl;
    }
    else {
        interface::printMessage("Fail: No Book Found.");
    }

    //separator
    interface::separator();

    //print message
    interface::printMessage("Chen borrowing Book B109:");

    //borrow publication (This book does not exist)
    returnValue = lib->borrowPublication("M109", "B109");

    //check for expected status code
    if (returnValue == ELEMENT_NOT_FOUND) {
        interface::printMessage("Pass: Loan Not Added.");
    }
    else {
        interface::printMessage("Fail: Loan Added.");
    }

    //separator
    interface::separator();

    //print message
    interface::printMessage("Saving files from Library to tests/scenario/out:");

    //load tester files
    returnValue = lib->save("tests/scenario/out");

    //check for expected status code
    if (returnValue == FILE_WRITTEN) {
        interface::printMessage("Pass: Library Saved.");
    }
    else {
        interface::printMessage("Fail: File Error.");
    }

    //separator
    interface::separator();

    //exit program
    return 0;
}

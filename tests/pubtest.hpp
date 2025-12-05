//header includes
#include "codes.h"
#include "interface.h"
#include "sortedList.hpp"

//standard library includes
#include <iostream>
#include <ostream>
#include <string>

/**
 * Template function to test a given publication object.
 */
template<class Publication>
void test(Publication& testObj) {
    //print message
    interface::printMessage("Testing " + testObj.getType() + " Class!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Printing New " + testObj.getType() + " Object for Verification:");
    std::cout << testObj << std::endl;

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Instantiating New Default " + testObj.getType() + " Object:");

    //instantise book object
    Publication* d = new Publication();

    //print message
    interface::printMessage("Done!");

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Printing Default " + testObj.getType() + " Object for Verification:");
    std::cout << *d << std::endl;

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Test " + testObj.getType() + " insertion!");

    //print separator
    interface::separator();

    //init list
    SortedList<Publication, std::string>* list = new SortedList<Publication, std::string>();

    //add book to list
    interface::printMessage("Inserting " + testObj.getType() + " Object:");
    std::cout << testObj << std::endl;
    int returnValue = list->insert(testObj);

    //check if value was inserted successfully
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Value inserted successfully.");
    } else {
        interface::printMessage("Fail: Failed to insert value.");
    }

    //print new line
    interface::newLine();

    //print books
    interface::printMessage("Printing List for Verification:");
    std::cout << list << std::endl;

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Test " + testObj.getType() + " Saving!");


    //print separator
    interface::separator();

    //load books from file
    interface::printMessage("Saving to file: saveTest.txt");
    returnValue = list->save("saveTest.txt");

    //check result
    if (returnValue == FILE_WRITTEN) {
        interface::printMessage("Pass: File has been saved.");
    }
    else {
        interface::printMessage("Fail: File not saved.");
    }

    //print new line
    interface::newLine();

    //init new list for loaded content
    SortedList<Publication, std::string>* loadedList = new SortedList<Publication, std::string>();

    //load books from file
    interface::printMessage("Loading from file for verification: saveTest.txt");
    returnValue = loadedList->load("saveTest.txt");

    //check result
    if (returnValue == FILE_READ) {
        interface::printMessage("Pass: File has been read.");
    }
    else {
        interface::printMessage("Fail: File not read.");
    }

    //print new line
    interface::newLine();

    //print books
    interface::printMessage("Printing List for Verification:");
    std::cout << loadedList << std::endl;

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Test "+ testObj.getType() + " Removal:");

    //print separator
    interface::separator();

    //add book to list
    interface::printMessage("Inserting " + testObj.getType() + " Object:");
    std::cout << testObj << std::endl;
    returnValue = list->remove(testObj);

    //check if value was inserted successfully
    if (returnValue == ELEMENT_DELETED) {
        interface::printMessage("Pass: Value removed successfully.");
    } else {
        interface::printMessage("Fail: Failed to remove value.");
    }

    //print new line
    interface::newLine();

    //print books
    interface::printMessage("Printing List for Verification:");
    std::cout << list << std::endl;

    //print separator
    interface::separator();
}

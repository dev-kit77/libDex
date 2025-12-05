#include "codes.h"
#include "interface.h"
#include "book.h"
#include <iostream>
#include "sortedList.h"
#include "sortedList.hpp"
#include <string>

int main() {
    //txt print
    interface::printTXT("./res/libdex.txt");

    //print separator
    interface::separator();

    //test message print
    interface::printMessage("Welcome to the Publication Test!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Testing Book Class");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Instantiating New Book Object.");

    //instantise book object
    Book* gatsby = new Book("B109", "The Great Gatsby", "F. Scott Fitzgerald", "1920s, Gilded Age, Fiction", 290, 1);

    //print message
    interface::printMessage("Done!");

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Printing New Book Object for Verification:");
    std::cout << *gatsby << std::endl;

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Deleting Book Object");
    delete gatsby;

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Instantiating New Default Book Object.");

    //instantise book object
    Book* defaultBook = new Book();

    //print message
    interface::printMessage("Done!");

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Printing Default Book Object for Verification:");
    std::cout << *defaultBook << std::endl;

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Test Book Loading!");

    //print separator
    interface::separator();

    //init book list
    SortedList<Book, std::string>* bookList = new SortedList<Book, std::string>();

    //load books from file
    interface::printMessage("Loading from file: books.txt");
    int returnValue = bookList->load("books.txt");

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
    interface::printMessage("Printing List for Verification");
    std::cout << bookList << std::endl;

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Test Book Saving!");

    //print separator
    interface::separator();

    //load books from file
    interface::printMessage("Saving to file: saveTest.txt");
    returnValue = bookList->save("saveTest.txt");

    //check result
    if (returnValue == FILE_WRITTEN) {
        interface::printMessage("Pass: File has been saved.");
    }
    else {
        interface::printMessage("Fail: File not saved.");
    }

    //print new line
    interface::newLine();

    SortedList<Book, std::string>* newBookList = new SortedList<Book, std::string>();

    //load books from file
    interface::printMessage("Loading from file for verification: saveTest.txt");
    returnValue = newBookList->load("saveTest.txt");

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
    interface::printMessage("Printing List for Verification");
    std::cout << newBookList << std::endl;

    //print separator
    interface::separator();

    //exit program
    return 0;
}

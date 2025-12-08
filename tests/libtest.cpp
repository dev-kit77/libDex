//header includes
#include "codes.h"
#include "interface.h"
#include "library.hpp"

//datatype includes
#include "audiobook.h"
#include "book.h"
#include "ebook.h"
#include "journal.h"
#include "magazine.h"
#include "member.h"
#include "movie.h"

#include <iostream>
#include <string>

int main() {
    //txt print
    interface::printTXT("./res/libdex.txt");

    //print separator
    interface::separator();

    //test message print
    interface::printMessage("Welcome to the Library Test!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Instantiating a new Library Class:");

    Library* lib = new Library();

    //print message
    interface::printMessage("Done!");

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Instantiating Test Classes:");

    //test book class
    Book* testBook = new Book("B101", "The Great Gatsby", "F. Scott Fitzgerald", "Roaring 20s, Upper Class", 291, 1);

    //print message
    interface::printMessage("Book");

    //test audiobook class
    AudioBook* testAudioBook = new AudioBook("A101", "The Great Gatsby", "F. Scott Fitzgerald", "Roaring 20s, Upper Class", 29.1, 1);

    //print message
    interface::printMessage("AudioBook");

    //test ebook class
    EBook* testEBook = new EBook("E101", "The Great Gatsby", "F. Scott Fitzgerald", "Roaring 20s, Upper Class", "www.gatsbybook.com", 1);

    //print message
    interface::printMessage("eBook");

    //test journal class
    Journal* testJournal = new Journal("J101", "American Science", 1, "Westing House", "Wisconsin, USA", 2023, 459, "Science", 1);

    //print message
    interface::printMessage("Journal");

    //test magazine class
    Magazine* testMagazine = new Magazine("M101", "The New Yorker", "New York Times", 1043, "Literature", 24, 1);

    //print message
    interface::printMessage("Magazine");

    //test movie class
    Movie* testMovie = new Movie("V102", "The Shawshank Redemption", "Castle Rock Entertainment", "Frank Darabont", "Drama", 142, 1);

    //print message
    interface::printMessage("Movie");

    //init new member
    Member* testMember = new Member("M101", "John");

    //print message
    interface::printMessage("Member");

    //print message
    interface::printMessage("Done!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Testing Add Function!");

    //print separator
    interface::separator();

    //new line
    interface::newLine();

    //add to library
    int returnValue = lib->add<Book*>(testBook);

    //print message
    interface::printMessage("Adding Book to library:");

    //check return value
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Book added to library");
    }
    else {
        interface::printMessage("Fail: Book not added to library");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing Books from library for verification:");
    std::cout << lib->format<Book>() << std::endl;

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Adding AudioBook to library:");

    //add to library
    returnValue = lib->add<AudioBook*>(testAudioBook);

    //check return value
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: AudioBook added to library");
    }
    else {
        interface::printMessage("Fail: Audiobook not added to library");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing AudioBooks from library for verification:");
    std::cout << lib->format<AudioBook>() << std::endl;

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Adding eBook to library:");

    //add to library
    returnValue = lib->add<EBook*>(testEBook);

    //check return value
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: eBook added to library");
    }
    else {
        interface::printMessage("Fail: eBook not added to library");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing eBooks from library:");
    std::cout << lib->format<EBook>() << std::endl;

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Adding Journal to library:");

    //add to library
    returnValue = lib->add(testJournal);

    //check return value
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Journal added to library");
    }
    else {
        interface::printMessage("Fail: Journal not added to library");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing Journals from library:");
    std::cout << lib->format<Journal>() << std::endl;

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Adding Magazine to library:");

    //add to library
    returnValue = lib->add(testMagazine);

    //check return value
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Magazine added to library");
    }
    else {
        interface::printMessage("Fail: Magazine not added to library");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing Magazines from library:");
    std::cout << lib->format<Magazine>() << std::endl;

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Adding Movie to library:");

    //add to library
    returnValue = lib->add(testMovie);

    //check return value
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Movie added to library");
    }
    else {
        interface::printMessage("Fail: Movie not added to library");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing Movies from library:");
    std::cout << lib->format<Movie>() << std::endl;

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Adding Member to library:");

    //add to library
    returnValue = lib->add(testMember);

    //check return value
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Member added to library");
    }
    else {
        interface::printMessage("Fail: Member not added to library");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing Members from library:");
    std::cout << lib->format<Member>() << std::endl;

    //new line
    interface::separator();

    //print message
    interface::printMessage("Testing File loading!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Loading from ./tests/general/:");

    //load from files
    lib->load("tests/general");

    //print message
    interface::printMessage("Done!");

    //print newline
    interface::newLine();

    //print message
    interface::printMessage("Printing Library for validation:");
    std::cout << *lib << std::endl;

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Testing adding Duplicate values");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Adding Dupilicate Pointer to library:");

    //add to library
    returnValue = lib->add(testMember);

    //check return value
    if (returnValue == ELEMENT_ALREADY_EXISTS) {
        interface::printMessage("Pass: Duplicate Pointer Detected");
    }
    else {
        interface::printMessage("Fail: Member added to library");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing Members from library:");
    std::cout << lib->format<Member>() << std::endl;

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Adding Dupilicate ID to library:");

    //instantise new book
    Book* bookTest2 = new Book("B101", "The Great Gatsby", "F. Scott Fitzgerald", "Roaring 20s, Upper Class", 291, 1);

    //add to library
    returnValue = lib->add(bookTest2);

    //check return value
    if (returnValue == ELEMENT_ALREADY_EXISTS) {
        interface::printMessage("Pass: Duplicate ID Detected");
    }
    else {
        interface::printMessage("Fail: Book added to library");
    }

    //new line
    interface::newLine();

    //print message
    interface::printMessage("Printing Books from library for validation:");
    std::cout << lib->format<Book>() << std::endl;

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Testing searching values");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Testing Basic Search for \"The Great Gatsby\":");

    //test basic search
    Book* result = lib->search<Book>("The Great Gatsby");

    //check result
    if (result != nullptr) {
        interface::printMessage("Pass: Book Found:");
        std::cout << *result << endl;
    }
    else {
        interface::printMessage("Fail: No Book Found");
    }

    //print newline
    interface::newLine();

    //print message
    interface::printMessage("Testing Advanced Title Search for \"The Great Gatsby\":");

    //test advanced search
    result = lib->advancedBookSearch("The Great Gatsby", 2);

    //check result
    if (result != nullptr) {
        interface::printMessage("Pass: Book Found:");
        std::cout << *result << endl;
    }
    else {
        interface::printMessage("Fail: No Book Found");
    }

    //print newline
    interface::newLine();

    //print message
    interface::printMessage("Testing Advanced Fuzzy Title Search for \"Gadzby\":");

    //test advanced search
    result = lib->advancedBookSearch("Gadzby", 2);

    //check result
    if (result != nullptr) {
        interface::printMessage("Pass: Book Found:");
        std::cout << *result << endl;
    }
    else {
        interface::printMessage("Fail: No Book Found");
    }

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Testing Advanced Fuzzy Genre Search with multiple keywords for \"Motivation, Leader, Class\":");

    //test advanced search
    result = lib->advancedBookSearch("Motivation, Leader, Class", 4);

    //check result
    if (result != nullptr) {
        interface::printMessage("Pass: Book Found:");
        std::cout << *result << endl;
    }
    else {
        interface::printMessage("Fail: No Book Found");
    }

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Testing Advanced Search with * wildcard for \"Gre*\":");

    //test advanced search
    result = lib->advancedBookSearch("Gre*", 2);

    //check result
    if (result != nullptr) {
        interface::printMessage("Pass: Book Found:");
        std::cout << *result << endl;
    }
    else {
        interface::printMessage("Fail: No Book Found");
    }

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Testing Advanced Search with ? wildcard for \"The Ga?s?y\":");

    //test advanced search
    result = lib->advancedBookSearch("Gats?y", 2);

    //check result
    if (result != nullptr) {
        interface::printMessage("Pass: Book Found:");
        std::cout << *result << endl;
    }
    else {
        interface::printMessage("Fail: No Book Found");
    }

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Testing Borrowing!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Testing borrowing B101 by Member M101");

    //Attempt borrow
    returnValue = lib->borrowPublication("M101", "B101");

    //check return value
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Loan Added");
    }
    else {
        interface::printMessage("Fail: Loan not added");
    }

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Testing Dupication Detection with B101 by Member M101");

    //Attempt borrow
    returnValue = lib->borrowPublication("M101", "B101");

    //check return value
    if (returnValue == ELEMENT_ALREADY_EXISTS) {
        interface::printMessage("Pass: Duplicate Loan Detected");
    }
    else {
        interface::printMessage("Fail: Loan Added");
    }

    //print new line
    interface::newLine();

    //print message
    interface::printMessage("Testing Reservations with B101 by Member M105");

    //Attempt borrow
    returnValue = lib->borrowPublication("M105", "B101");

    //check return value
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Reservation Added");
    }
    else {
        interface::printMessage("Fail: Reservation Not Added");
    }

    //newline
    interface::newLine();

    //print message
    interface::printMessage("Testing Reservations Removal with B101 by Member M106");

    //print message
    interface::printMessage("Inserting test reservation");

    //Attempt borrow
    returnValue = lib->borrowPublication("M106", "B101");

    //print message
    interface::printMessage("Done!");

    //return publication
    returnValue = lib->returnPublication("M106", "B101");

    //check return value
    if (returnValue == ELEMENT_DELETED) {
        interface::printMessage("Pass: Reservation Removed");
    }
    else {
        interface::printMessage("Fail: Reservation Not Removed");
    }

    //newline
    interface::newLine();

    //print message
    interface::printMessage("Testing returning B101 by Member M101");

    //Attempt borrow
    returnValue = lib->returnPublication("M101", "B101");

    //check return value
    if (returnValue == ELEMENT_DELETED) {
        interface::printMessage("Pass: Loan Removed");
    }
    else {
        interface::printMessage("Fail: Loan not Removed");
    }

    //print message
    interface::printMessage("Printing B101 loan info for verification:");

    //get loan
    Loan* l = lib->findPublication("B101")->getLoan();

    //print details
    std::cout << l->getMember()->getID() << " " << l->getPublication()->getID() << " " << l->getActive() << " " << l->getDue() << endl;

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Testing saving!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Saving to ./tests/general/out:");

    //load from files
    lib->save("tests/general/out");

    //print message
    interface::printMessage("Done!");

    //print newline
    interface::newLine();

    //print message
    interface::printMessage("Loading from ./tests/general/out for validation:");

    //load from files
    lib->load("tests/general/out");

    //print message
    interface::printMessage("Done!");

    //print newline
    interface::newLine();

    //print message
    interface::printMessage("Printing Library for validation:");
    std::cout << *lib << std::endl;

    //newline
    interface::newLine();

    //print message
    interface::printMessage("Printing B101 loan info for verification:");

    //get loan
    l = lib->findPublication("B101")->getLoan();

    //print details
    std::cout << l->getMember()->getID() << " " << l->getPublication()->getID() << " " << l->getActive() << " " << l->getDue() << endl;

    //exit program
    return 0;
}

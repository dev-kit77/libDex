#ifndef BOOK_H
#define BOOK_H

#include "publication.h"

class Book : public Publication {
    public:
        /**
         * Default constructor for Book class
         */
        Book();

        /**
         * Constructor for Book class
         * @param id unique identifier for the book
         * @param title title of the book
         * @param author author of the book
         * @param genre genre of the book
         * @param pageCount number of pages in the book
         * @param avalability number of copies available for the book
         */
        Book(const std::string id, const std::string& title, const std::string& author, const std::string& genre, const int pageCount, const int avalability);

        /**
         * Getter for author class field
         * @return author of the book, as string
         */
        std::string getAuthor() const;

        /**
         * Getter for genre class field
         * @return genres of the book, as string
         */
        std::string getGenre() const;

        /**
         * Getter for page count class field
         * @return page count of the book, as int
         */
        int getPageCount() const;

        /**
         * Method to convert book object to string representation
         * @return string representation of the book object
         */
        std::string toString() const override;

        /**
         * Method to get type of the publication object
         * @return string representation of the type
         */
        std::string getType() const override;

        /**
         * Operator overload to output book object to ostream
         * @param os output stream
         * @param book book object to output
         * @return output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Book& b);

        /**
         * Operator overload to input book object from istream
         * @param is input stream
         * @param book book object to input
         * @return input stream
         */
        friend std::istream& operator>>(std::istream& is, Book& b);

        //include publication comparison
        friend int operator==(const Publication& p1, const Publication& p2);
    private:
        //class fields
        std::string author;
        std::string genre;
        int pageCount;
};

#endif

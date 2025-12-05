#ifndef EBOOK_H
#define EBOOK_H

#include "publication.h"

class EBook : public Publication {
    public:
        /**
         * Default constructor for eBook class
         */
        EBook();

        /**
         * Constructor for eBook class
         * @param id unique identifier for the eBook
         * @param title title of the eBook
         * @param author author of the eBook
         * @param genre genre of the eBook
         * @param link link to the eBook
         * @param avalability number of copies available for the eBook
         */
        EBook(const std::string id, const std::string& title, const std::string& author, const std::string& genre, const std::string& link, const int avalability);

        /**
         * Getter for author class field
         * @return author of the eBook, as string
         */
        std::string getAuthor() const;

        /**
         * Getter for genre class field
         * @return genres of the eBook, as string
         */
        std::string getGenre() const;

        /**
         * Getter for page count class field
         * @return page count of the eBook, as int
         */
        std::string getLink() const;

        /**
         * Method to convert eBook object to string representation
         * @return string representation of the eBook object
         */
        std::string toString() const override;

        /**
         * Method to get type of the publication object
         * @return string representation of the type
         */
        std::string getType() const override;

        /**
         * Operator overload to output eBook object to ostream
         * @param os output stream
         * @param audiobook audiobook object to output
         * @return output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const EBook& e);

        /**
         * Operator overload to input audiobook object from istream
         * @param is input stream
         * @param audiobook audiobook object to input
         * @return input stream
         */
        friend std::istream& operator>>(std::istream& is, EBook& e);

        //include publication comparison
        friend int operator==(const Publication& p1, const Publication& p2);
    private:
        //class fields
        std::string author;
        std::string genre;
        std::string link;
};

#endif

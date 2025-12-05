#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "publication.h"

class AudioBook : public Publication {
    public:
        /**
         * Default constructor for audioBook class
         */
        AudioBook();

        /**
         * Constructor for audioBook class
         * @param id unique identifier for the audioBook
         * @param title title of the audioBook
         * @param author author of the audioBook
         * @param genre genre of the audioBook
         * @param duration duration of the audiobook in seconds
         * @param avalability number of copies available for the audioBook
         */
        AudioBook(const std::string id, const std::string& title, const std::string& author, const std::string& genre, double duration, const int avalability);

        /**
         * Getter for author class field
         * @return author of the audioBook, as string
         */
        std::string getAuthor() const;

        /**
         * Getter for genre class field
         * @return genres of the audioBook, as string
         */
        std::string getGenre() const;

        /**
         * Getter for page count class field
         * @return page count of the audioBook, as double
         */
        double getDuration() const;

        /**
         * Method to convert audioBook object to string representation
         * @return string representation of the audioBook object
         */
        std::string toString() const override;

        /**
         * Method to get type of the publication object
         * @return string representation of the type
         */
        std::string getType() const override;

        /**
         * Operator overload to output audioBook object to ostream
         * @param os output stream
         * @param audiobook audiobook object to output
         * @return output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const AudioBook& a);

        /**
         * Operator overload to input audiobook object from istream
         * @param is input stream
         * @param audiobook audiobook object to input
         * @return input stream
         */
        friend std::istream& operator>>(std::istream& is, AudioBook& a);

        //include publication comparison
        friend int operator==(const Publication& p1, const Publication& p2);
    private:
        //class fields
        std::string author;
        std::string genre;
        double duration;
};

#endif

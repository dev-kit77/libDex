#ifndef MOVIE_H
#define MOVIE_H

#include "publication.h"

class Movie : public Publication {
    public:
        /**
         * Default constructor for Movie class
         */
        Movie();

        /**
         * Constructor for Movie class
         * @param id unique identifier for the Movie
         * @param title title of the Movie
         * @param studio studio of the Movie
         * @param director director of the Movie
         * @param genre genre of the Movie
         * @param duration duration of the Movie in seconds
         * @param avalability number of copies available for the Movie
         */
        Movie(const std::string id, const std::string& title, const std::string& studio, const std::string& director, const std::string& genre, double duration, const int avalability);

        /**
         * Getter for studio class field
         * @return studio of the Movie, as string
         */
        std::string getStudio() const;

        /**
         * Getter for director class field
         * @return director of the Movie, as string
         */
        std::string getDirector() const;

        /**
         * Getter for genre class field
         * @return genres of the Movie, as string
         */
        std::string getGenre() const;

        /**
         * Getter for page count class field
         * @return page count of the Movie, as double
         */
        double getDuration() const;

        /**
         * Method to convert Movie object to string representation
         * @return string representation of the Movie object
         */
        std::string toString() const override;

        /**
         * Method to get type of the publication object
         * @return string representation of the type
         */
        std::string getType() const override;

        /**
         * Operator overload to output Movie object to ostream
         * @param os output stream
         * @param Movie Movie object to output
         * @return output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Movie& m);

        /**
         * Operator overload to input Movie object from istream
         * @param is input stream
         * @param Movie Movie object to input
         * @return input stream
         */
        friend std::istream& operator>>(std::istream& is, Movie& m);

        //include publication comparison
        friend int operator==(const Publication& p1, const Publication& p2);
    private:
        //class fields
        std::string studio;
        std::string director;
        std::string genre;
        double duration;
};

#endif

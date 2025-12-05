#ifndef MAGAZINE_H
#define MAGAZINE_H

//header includes
#include "publication.h"

//standard library includes
#include <string>

class Magazine : public Publication {
    public:
        /**
         * Default constructor for Magazine class
         */
        Magazine();

        /**
         * Constructor for Magazine class
         * @param id unique identifier for the Magazine
         * @param title title of the Magazine
         * @param publisher publisher of the Magazine
         * @param issue issue number of the Magazine
         * @param category category of the Magazine
         * @param pageCount number of pages in the Magazine
         * @param avalability number of copies available for the Magazine
         */
        Magazine(const std::string id, const std::string& title, const std::string& publisher, const int issue, const std::string& category, const int pageCount, const int avalability);

        /**
         * Getter for publisher class field
         * @return publisher of the Magazine, as string
         */
        std::string getPublisher() const;

        /**
         * Getter for category class field
         * @return category of the Magazine, as string
         */
        std::string getCategory() const;

        /**
         * Getter for issue class field
         * @return issue of the Magazine, as int
         */
        int getIssue() const;

        /**
         * Getter for page count class field
         * @return page count of the Magazine, as int
         */
        int getPageCount() const;

        /**
         * Method to convert Magazine object to string representation
         * @return string representation of the Magazine object
         */
        std::string toString() const override;

        /**
         * Method to get type of the publication object
         * @return string representation of the type
         */
        std::string getType() const override;

        /**
         * Operator overload to output Magazine object to ostream
         * @param os output stream
         * @param Magazine Magazine object to output
         * @return output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Magazine& b);

        /**
         * Operator overload to input Magazine object from istream
         * @param is input stream
         * @param Magazine Magazine object to input
         * @return input stream
         */
        friend std::istream& operator>>(std::istream& is, Magazine& b);

        //include publication comparison
        friend int operator==(const Publication& p1, const Publication& p2);
    private:
        //class fields
        std::string publisher;
        std::string category;
        int issue;
        int pageCount;
};

#endif

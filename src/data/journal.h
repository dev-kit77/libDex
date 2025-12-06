#ifndef JOURNAL_H
#define JOURNAL_H

#include "publication.h"

class Journal : public Publication {
    public:
        /**
         * Default constructor for Journal class
         */
        Journal();

        /**
         * Constructor for Journal class
         * @param id unique identifier for the Journal
         * @param title title of the Journal
         * @param volume volume number of the Journal
         * @param publisher publisher of the Journal
         * @param location location of the Journal
         * @param year year of publication of the Journal
         * @param pageNo page number of the Journal
         * @param category category of the Journal
         * @param avalability number of copies available for the Journal
         */
        Journal(const std::string id, const std::string& title, const int volume, const std::string& publisher, const std::string& location, const int year, const int pageNo, const std::string& category, const int avalability);

        /**
         * Getter for volume class field
         * @return volume of the Journal, as string
         */
        int getVolume() const;

        /**
         * Getter for publisher class field
         * @return publisher of the Journal, as string
         */
        std::string getPublisher() const;

        /**
         * Getter for location class field
         * @return location of the Journal, as string
         */
        std::string getLocation() const;

        /**
         * Getter for year class field
         * @return year of the Journal, as int
         */
        int getYear() const;

        /**
         * Getter for page number class field
         * @return page number of the Journal, as int
         */
        int getPageNo() const;

        /**
         * Getter for category class field
         * @return category of the Journal, as string
         */
        std::string getCategory() const;

        /**
         * Method to convert Journal object to string representation
         * @return string representation of the Journal object
         */
        std::string toString() const override;

        /**
         * Method to get type of the publication object
         * @return string representation of the type
         */
        std::string getType() const override;

        /**
         * Operator overload to output Journal object to ostream
         * @param os output stream
         * @param journal journal object to output
         * @return output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Journal& j);

        /**
         * Operator overload to input Journal object from istream
         * @param is input stream
         * @param journal journal object to input
         * @return input stream
         */
        friend std::istream& operator>>(std::istream& is, Journal& j);

        //include publication comparison
        friend int operator==(const Publication& p1, const Publication& p2);
    private:
        //class fields
        int volume;
        std::string publisher;
        std::string location;
        int year;
        int pageNo;
        std::string category;
};

#endif

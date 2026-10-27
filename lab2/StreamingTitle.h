#ifndef STREAMINGTITLE_H
#define STREAMINGTITLE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

/**
 * @file StreamingTitle.h
 * Class representing a single streaming title (movie or show).
 *
 * Stores title, type, genre, release year, rating, and length.
 * Includes constructors for default initialization, full initialization,
 * and parsing a single CSV line. Only the rating is mutable.
 *
 * Provides getter methods, a setter for rating, a display method,
 * and a destructor as required by the assignment.
 *
 * @author
 *      Kushal Khatri
 */
class StreamingTitle {

public:

    /**
     * Sets the rating for this streaming title.
     * @param newrating The new rating value.
     */
    void setRating(double newrating) {
        rating = newrating;
    }

    /**
     * Returns the title of the streaming item.
     * @return Title as a string.
     */
    std::string getTitle() const { return title; }

    /**
     * Returns the type of the item (MOVIE or SHOW).
     * @return Type as a string.
     */
    std::string getType() const { return type; }

    /**
     * Returns the genre of the item.
     * @return Genre as a string.
     */
    std::string getGenre() const { return genre; }

    /**
     * Returns the release year.
     * @return Release year as an integer.
     */
    int getYear() const { return releaseYear; }

    /**
     * Returns the rating.
     * @return Rating as a double.
     */
    double getRating() const { return rating; }

    /**
     * Returns the length of the item.
     * Movies: runtime in minutes.
     * Shows: number of seasons.
     * @return Length as an integer.
     */
    int getLength() const { return length; }

    /**
     * Default constructor.
     * Initializes all strings to empty and numeric fields to zero.
     */
    StreamingTitle() {
        title = "";
        type = "";
        genre = "";
        releaseYear = 0;
        rating = 0.0;
        length = 0;
    }

    /**
     * Constructor that accepts all attributes directly.
     * @param ctitle Title
     * @param ctype Type (MOVIE or SHOW)
     * @param cgenre Genre
     * @param creleaseYear Release year
     * @param crating Rating
     * @param clength Runtime (movies) or seasons (shows)
     */
    StreamingTitle(const std::string& ctitle, const std::string& ctype,
        const std::string& cgenre, int creleaseYear,
        double crating, int clength) {
        title = ctitle;
        type = ctype;
        genre = cgenre;
        releaseYear = creleaseYear;
        rating = crating;
        length = clength;
    }

    /**
     * Constructor that parses a single CSV line.
     * Used by the driver to load the vector.
     * @param line A comma-separated line of data.
     */
    StreamingTitle(const std::string& line) {
        std::stringstream ss(line);

        getline(ss, title, ',');
        getline(ss, type, ',');
        getline(ss, genre, ',');

        std::string yearString, ratingString, lengthString;
        getline(ss, yearString, ',');
        getline(ss, ratingString, ',');
        getline(ss, lengthString, ',');

        releaseYear = stoi(yearString);
        rating = stod(ratingString);
        length = stoi(lengthString);
    }

    /**
     * Displays all StreamingTitle objects in a vector.
     * Calls the private print() method for each item.
     * @param vector A vector of StreamingTitle objects.
     */
    void printAll(std::vector<StreamingTitle>& vector);

    /**
     * Destructor for StreamingTitle.
     * Required by the assignment. No dynamic memory is used.
     */
    ~StreamingTitle() {}

private:

    std::string title;
    std::string type;
    std::string genre;
    int releaseYear;
    double rating;
    int length;

    /**
     * Prints this StreamingTitle in a formatted row.
     * Used internally by printAll().
     */
    void print() {
        std::cout << title << " " << type << " " << genre << " "
            << releaseYear << " " << rating << " " << length << std::endl;
    }
};

#endif

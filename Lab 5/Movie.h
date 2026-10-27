/**
 * @file Movie.h
 * @description Specification for the Movie class. Stores a movie title and rating,
 *              and overloads the <, >, and << operators for comparison and display.
 * @author Kushal Khatri
 *
 * This code reflects my own understanding.
 * I can explain every function, data structure, and design decision.
 */

#pragma once
#include <string>
#include <iostream>

class Movie {
private:
    std::string title;
    double rating;
public:
    /**
     * @brief Constructs a Movie with a given title and rating.
     * @param title The title of the movie.
     * @param rating The rating of the movie.
     */
    Movie(std::string title, double rating) : title(title), rating(rating) {}

    /**
     * @brief Overloads > to compare movies by rating.
     * @param other The movie to compare against.
     * @return true if this movie's rating is greater.
     */
    bool operator>(const Movie& other) const;

    /**
     * @brief Overloads < to compare movies by rating.
     * @param other The movie to compare against.
     * @return true if this movie's rating is less.
     */
    bool operator<(const Movie& other) const;

    /**
     * @brief Returns the movie title.
     * @return The title as a string.
     */
    std::string getTitle() const { return title; }

    /**
     * @brief Returns the movie rating.
     * @return The rating as a double.
     */
    double getRating() const { return rating; }
};

/**
 * @brief Overloads << to print a Movie's title and rating.
 * @param os The output stream.
 * @param movie The Movie object to print.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Movie& movie);

/**
 * @file Movie.cpp
 * @description Implementation of the Movie class operator overloads.
 * @author Kushal Khatri
 *
 * This code reflects my own understanding.
 * I can explain every function, data structure, and design decision.
 */

#include "Movie.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Compares this movie's rating to another's using >.
 * @param other The movie to compare against.
 * @return true if this movie's rating is greater.
 */
bool Movie::operator>(const Movie& other) const {
    return this->rating > other.rating;
}

/**
 * @brief Compares this movie's rating to another's using <.
 * @param other The movie to compare against.
 * @return true if this movie's rating is less.
 */
bool Movie::operator<(const Movie& other) const {
    return this->rating < other.rating;
}

/**
 * @brief Outputs the movie's title and rating to the stream.
 * @param os The output stream.
 * @param movie The Movie object to display.
 * @return The output stream.
 */
ostream& operator<<(ostream& os, const Movie& movie) {
    os << movie.getTitle() << " at " << movie.getRating() << endl;
    return os;
}

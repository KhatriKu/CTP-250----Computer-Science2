/**
 * @file MovieSelector.h
 * @description Specification for the MovieSelector class. Manages a LinkedQueue
 *              of Movie objects and a LinkedQueue of strings for the Josephus simulation.
 * @author Kushal Khatri
 *
 * This code reflects my own understanding.
 * I can explain every function, data structure, and design decision.
 */

#pragma once
#include <fstream>
#include <string>
#include "LinkedQueue-4.h"
#include "Movie.h"

class MovieSelector {
private:
    LinkedQueue<std::string>* movieSimulation;
    LinkedQueue<Movie>* movieList;
public:
    /**
     * @brief Default constructor. Initializes both queues.
     */
    MovieSelector();

    /**
     * @brief Simulates removing every nth movie using the Josephus algorithm.
     *        Displays the last remaining movie using the overloaded <<.
     * @param n The elimination interval.
     * @throws runtime_error if movieList is empty or n is invalid.
     */
    void removeEveryN(int n);

    /**
     * @brief Reads movies from the CSV file and loads them into movieList.
     * @throws runtime_error if the file cannot be opened.
     */
    void loadMovies();

    /**
     * @brief Displays the last movie remaining in movieList using <<.
     * @throws runtime_error if movieList is empty.
     */
    void displayLastMovie();
};

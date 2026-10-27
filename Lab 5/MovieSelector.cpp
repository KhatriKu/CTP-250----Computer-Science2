/**
 * @file MovieSelector.cpp
 * @description Implementation of the MovieSelector class for the Movie Selection Game.
 *              Uses a LinkedQueue<string> for the Josephus simulation and a
 *              LinkedQueue<Movie> for storing Movie objects.
 * @author Kushal Khatri
 *
 * This code reflects my own understanding.
 * I can explain every function, data structure, and design decision.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Movie.h"
#include "MovieSelector.h"

using namespace std;

/**
 * @brief Default constructor. Initializes both queues on the heap.
 */
MovieSelector::MovieSelector() {
    movieSimulation = new LinkedQueue<string>();
    movieList = new LinkedQueue<Movie>();
}

/**
 * @brief Reads movies from the CSV file and loads them into movieList.
 *        Clears any previously loaded movies before loading.
 * @throws runtime_error if the file cannot be opened.
 */
void MovieSelector::loadMovies() {
    //clearing any previous Movies
    while (!movieList->isEmpty()) {
        movieList->dequeue();
    }
    ifstream movieFile("movie_ratings_Lab5_Sp26.csv");
    
    if (!movieFile) {
        throw runtime_error("File was unable to be opened.");
    }

    string line;
    getline(movieFile, line); // skipping the header

    while (getline(movieFile, line)) {
        stringstream ss(line);
        string title;
        string stringRating;
        double rating;

        getline(ss, title, ',');
        getline(ss, stringRating);
        rating = stod(stringRating);

        Movie inputMovie(title, rating);
        movieList->enqueue(inputMovie);
    }
}

/**
 * @brief Drains movieList and displays the last Movie object using <<.
 *        This method is independent of removeEveryN.
 * @throws runtime_error if movieList is empty.
 */
void MovieSelector::displayLastMovie() {
    
    if (movieList->isEmpty()) {
        throw runtime_error("No movie available to display.");
    }
    
    Movie last = movieList->peek();
    while (!movieList->isEmpty()) {
        last = movieList->peek();
        movieList->dequeue();
    }
    cout << "The Movie selected for viewing: " << last;
}

/**
 * @brief Simulates the Josephus problem using movieSimulation (LinkedQueue<string>).
 *        Every nth movie is eliminated until one remains. Reloads movieList to
 *        find and display the winning Movie object using the overloaded <<.
 * @param n The elimination interval.
 * @throws runtime_error if movieList is empty, n is invalid, or winner not found.
 */
void MovieSelector::removeEveryN(int n) {
    
    if (movieList->isEmpty()) {
        throw runtime_error("No movies LOADED - use loadMovies() please!");
    }
        while(!movieSimulation->isEmpty()){
            movieSimulation->dequeue();
        }
    if (n <= 0) {
        throw runtime_error("n's value must be greater than 0");
    }
    
    int totalMovies = 0;
    while(!movieList->isEmpty()){
        movieSimulation->enqueue(movieList->peek().getTitle());
        movieList->dequeue();
        totalMovies++;
    }
    int count = 0;
    while(totalMovies > 1){
        count++;
        if(count % n == 0){
            movieSimulation->dequeue();
            totalMovies--;
        }
        else{
            movieSimulation->enqueue(movieSimulation->peek());
            movieSimulation->dequeue();
        }
    }
    
    if (movieSimulation->isEmpty()) {
        throw runtime_error("No movie available to display.");
    }
    string gameWinningTitle = movieSimulation->peek();
    loadMovies();
    while(!movieList->isEmpty()){
        if (movieList->peek().getTitle() == gameWinningTitle) {
                    cout << "The Movie selected for viewing: " << movieList->peek();
                    return;
                }
                movieList->dequeue();
    }
    
    throw runtime_error("Game Winning Movie was Unable to be found");
}

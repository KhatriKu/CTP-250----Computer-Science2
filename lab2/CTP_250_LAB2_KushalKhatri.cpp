// CTP_250_LAB2_KushalKhatri.cpp : This file contains the 'main' function. Program execution begins and ends there.


//This code reflects my own understanding.
//I can explain every function, data structure, and design decision.

/**
 * @file CTP_250_LAB2_KushalKhatri.cpp
 *
 * Driver program for Lab 2. This file loads streaming title data from
 * an input file into a vector of StreamingTitle objects and performs
 * several operations required by the assignment. These operations
 * include displaying all titles, filtering by minimum rating, listing
 * shows and movies, performing a case-insensitive substring search on
 * show titles, and calculating the total runtime of all movies.
 *
 * All data representation and attribute handling are performed by the
 * StreamingTitle class. This driver focuses on functional decomposition
 * and user interaction.
 *
 * Author: Kushal Khatri
 */

#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "StreamingTitle.h"

using namespace std;

/**
 * Loads streaming title data from a file into a vector.
 * Skips the header line and uses the one-line constructor
 * to parse each remaining line into a StreamingTitle object.
 *
 * @param vector The vector to fill with StreamingTitle objects.
 * @param filename The name of the input file to read.
 */

void loadData(vector<StreamingTitle>& vector, const string& filename) {
    ifstream inFS(filename);
    if (!inFS.is_open()) {
        cout << "Error opening file";
        return;
    }

    string headerLine;
    getline(inFS, headerLine);

    string line;
    while (getline(inFS, line)) {
        vector.push_back(StreamingTitle(line));
    }
}

/**
 * Displays all streaming titles with a rating greater than or equal
 * to the minimum rating entered by the user. Prints a message if none match.
 *
 * @param vec The vector of StreamingTitle objects to search.
 * @param minRating The minimum rating threshold.
 */
void displayMinRating(const vector<StreamingTitle>& vec, double minRating) {
    bool found = false;
    for (const auto& item : vec) {
        if (item.getRating() >= minRating) {
            cout << item.getTitle() << " (" << item.getRating() << ")\n";
            found = true;
        }
    }
    if (!found)
        cout << "No titles meet that rating.\n";
}

/**
 * Displays the titles of all streaming items whose type is SHOW.
 * Prints a message if no shows are found.
 *
 * @param vec The vector of StreamingTitle objects to search.
 */

void displayShows(const vector<StreamingTitle>& vec) {
    bool found = false;
    for (const auto& item : vec) {
        if (item.getType() == "Show") {
            cout << item.getTitle() << "\n";
            found = true;
        }
    }
    if (!found)
        cout << "No shows found.\n";
}

/**
 * Displays the titles of all streaming items whose type is MOVIE.
 * Prints a message if no movies are found.
 *
 * @param vec The vector of StreamingTitle objects to search.
 */
void displayMovies(const vector<StreamingTitle>& vec) {
    bool found = false;
    for (const auto& item : vec) {
        if (item.getType() == "Movie") {
            cout << item.getTitle() << "\n";
            found = true;
        }
    }
    if (!found)
        cout << "No movies found.\n";
}

/**
 * Calculates and displays the total runtime of all movies in the dataset.
 * Converts the total minutes into hours and minutes for readability.
 *
 * @param vec The vector of StreamingTitle objects to process.
 */
void displayTotalMovieRuntime(const vector<StreamingTitle>& vec) {
    int total = 0;
    for (const auto& item : vec)
        if (item.getType() == "Movie")
            total += item.getLength();

    int hours = total / 60;
    int minutes = total % 60;

    cout << "Total movie runtime: " << hours << "h " << minutes << "m\n";
}



//Range based loop
//I got the syntax from https://www.geeksforgeeks.org/cpp/range-based-loop-c/
//while we did not learn about these in class to the extent of my knowledge, I learned about them in CTP 150 section 200 with Dr. Ruimen Hu
/**
 * Converts a string to lowercase and returns the modified copy.
 * Used to support case-insensitive substring searching.
 *
 * @param s The original string.
 * @return A lowercase version of the string.
 */
string toLowerCopy(string s) {
    for (char& c : s) c = tolower(c);
    return s;
}

/**
 * Searches all SHOW-type streaming titles for a case-insensitive
 * substring match within the title. Displays matching titles only.
 * Prints a message if no matches are found.
 *
 * @param vec The vector of StreamingTitle objects to search.
 * @param keyRaw The substring entered by the user.
 */
void searchShowsBySubstring(const vector<StreamingTitle>& vec, const string& keyRaw) {
    string key = toLowerCopy(keyRaw);
    bool found = false;

    //found the method in the api for c++ <string>: https://cplusplus.com/reference/string/string/find/
    // got the string::npos value from the same webpage

    for (const auto& item : vec) {
        if (item.getType() == "Show") {
            string titleLower = toLowerCopy(item.getTitle());
            if (titleLower.find(key) != string::npos) {
                cout << item.getTitle() << "\n";
                found = true;
            }
        }
    }

    if (!found)
        cout << "No shows contain that substring.\n";
}


int main() {
    vector<StreamingTitle> data;
    loadData(data, "lab2Sp26Streaming.txt");

    StreamingTitle temp;
    temp.printAll(data);

    double minRating;
    cout << "Enter minimum rating: ";
    cin >> minRating;
    cin.ignore();
    displayMinRating(data, minRating);

    cout << "shows:" << endl;
    displayShows(data);

    cout << "movies:" << endl;
    displayMovies(data);

    string key;
    cout << "Enter substring: " << endl;
    getline(cin, key);
    searchShowsBySubstring(data, key);

    cout << "Total movie runtime:" << endl;
    displayTotalMovieRuntime(data);
}


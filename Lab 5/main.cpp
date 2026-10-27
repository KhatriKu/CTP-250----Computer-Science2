/**
 * @file main.cpp
 * @description Driver for Lab 5. Demonstrates LinkedStack usage for highest/lowest
 *              rated movies and LinkedQueue usage for the Movie Selection Game.
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
#include "LinkedStack.h"
#include "LinkedQueue.h"

using namespace std;

/**
 * @brief Loads movies from the CSV file into the provided LinkedStack.
 *        Clears the stack before loading to avoid duplicate data.
 * @param Stack Pointer to the LinkedStack of Movie objects to populate.
 * @throws runtime_error if the file cannot be opened.
 */
void loadStack(LinkedStack<Movie>* Stack){
    
    ifstream movieFile("movie_ratings_Lab5_Sp26.csv");
    if (!movieFile) {
        throw runtime_error("File was unable to be opened.");
    }
    
    //clearing stack like said in the displayMethods() output stream
    while (!Stack->isEmpty()) {
        Stack->pop();
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
        Stack->push(inputMovie);
    }
    
}

/**
 * @brief Finds and displays the highest rated movie(s) from the stack.
 *        Uses a secondary stack to track all movies tied for the highest rating.
 * @param Stack Pointer to the LinkedStack of Movie objects.
 * @throws runtime_error if the stack is empty.
 */
void highestRatedMovie(LinkedStack<Movie>* Stack){
    
    if (Stack->isEmpty()) {
        throw runtime_error("Stack was unable to be loaded");
    }
    
    LinkedStack<Movie>* LinkedStackHighest = new LinkedStack<Movie>;
    
    LinkedStackHighest->push(Stack->peek());
    Stack->pop();
    
    while(!Stack->isEmpty()){
        
        if( Stack->peek() > LinkedStackHighest->peek()){
            while(!LinkedStackHighest->isEmpty()){
                LinkedStackHighest->pop();
            }
            LinkedStackHighest->push(Stack->peek());
        }
        else if((!(Stack->peek() < LinkedStackHighest->peek()) && !(Stack->peek() > LinkedStackHighest->peek()))){
            LinkedStackHighest->push(Stack->peek());
        }
        Stack->pop();
    }
    cout << "Highest rated movie(s): " << endl;
    while(!LinkedStackHighest->isEmpty()){
        cout << LinkedStackHighest->peek();
        LinkedStackHighest->pop();
    }
    
}

/**
 * @brief Finds and displays the lowest rated movie(s) from the stack.
 *        Uses a secondary stack to track all movies tied for the lowest rating.
 * @param Stack Pointer to the LinkedStack of Movie objects.
 * @throws runtime_error if the stack is empty.
 */
void lowestRatedMovie(LinkedStack<Movie>* Stack){
    
    if (Stack->isEmpty()) {
        throw runtime_error("Stack was unable to be loaded");
    }
    
    LinkedStack<Movie>* LinkedStackLowest = new LinkedStack<Movie>;
    
    LinkedStackLowest->push(Stack->peek());
    Stack->pop();
    
    while(!Stack->isEmpty()){
        
        if( Stack->peek() < LinkedStackLowest->peek()){
            while(!LinkedStackLowest->isEmpty()){
                LinkedStackLowest->pop();
            }
            LinkedStackLowest->push(Stack->peek());
        }
        else if((!(Stack->peek() < LinkedStackLowest->peek()) && !(Stack->peek() > LinkedStackLowest->peek()))){
            LinkedStackLowest->push(Stack->peek());
        }
        Stack->pop();
    }
    cout << "Lowestest rated movie(s): " << endl;
    while(!LinkedStackLowest->isEmpty()){
        cout << LinkedStackLowest->peek();
        LinkedStackLowest->pop();
    }
    
}

/**
 * @brief Displays the menu options to the user.
 *        Separates Stack methods from Queue methods and notes loading behavior.
 */
void displayMethods() {
    cout << "Note: for Stack- the methods will load themselves with data \n but for Queue, it will not and a option will be provided for you to load\n" << endl;
    cout << "STACK - METHODS" << endl;
    cout << "1. Highest Rated Movie(s)" << endl;
    cout << "2. Lowest Rated Movie(s)" << endl;
    cout << "QUEUE - Methods" << endl;
    cout << "3. Display nth movie simulation - every nth Movie is eliminated until there is a Lone Movie standing at the top" << endl;
    cout << "4. Display Last Movie" << endl;
    cout << "5. Fill Queues up with movies\n(no you cant stack the method to get more data members in the queue)\n" << endl;
    cout << "0. Exit" << endl;
}

/**
 * @brief Runs the interactive menu loop. Handles user input and dispatches
 *        to the appropriate stack or queue method. Throws on invalid input.
 * @param Stack Pointer to the LinkedStack of Movie objects.
 * @param movieSelector Reference to the MovieSelector object for queue operations.
 * @return 1 when the user exits.
 * @throws runtime_error on invalid menu input.
 */
int runMenu(LinkedStack<Movie>* Stack, MovieSelector& movieSelector){
    int exitNum = 0;
    do {
        int choice;
        displayMethods();
        cout << "What is your choice?: ";
        cin >> choice;
        if(cin.fail() || !(choice <= 5 && choice >=0)){
            cin.clear();
            cin.ignore();
            throw runtime_error("INVALID INPUT TRY AGAIN with a number between 0 - 5 inclusive.");
        }
        switch (choice) {
                
            case 1:
                loadStack(Stack);
                highestRatedMovie(Stack);
                break;
            case 2:
                loadStack(Stack);
                lowestRatedMovie(Stack);
                break;
            case 3:
                int n;
                cout << "Enter n: ";
                cin >> n;
                if (cin.fail() || n <= 0) {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input. n must be a positive integer." << endl;
                } else {
                    movieSelector.removeEveryN(n);
                }
                break;
            case 4:
                movieSelector.displayLastMovie();
                break;
            case 5:
                movieSelector.loadMovies();
                break;
            case 0:
                exitNum = -1;
                break;
            default:
                throw runtime_error("INVALID INPUT TRY AGAIN with a number between 0 - 5 inclusive.");
                break;
        }
    }
    while (exitNum != -1);
    return 1;
}


int main() {
    LinkedStack<Movie>* Stack = new LinkedStack<Movie>;
    MovieSelector movieSelector;
    int endNum = 0;
    //using a loop so the exceptions will not end the entirety of the program
    while (endNum != 1) {
        try {
            endNum = runMenu(Stack, movieSelector);
        } catch (runtime_error &exception) {
            cout << exception.what() << endl;
        }
    }
}

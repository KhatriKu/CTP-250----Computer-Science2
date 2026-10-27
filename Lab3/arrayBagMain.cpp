// This code reflects my own understanding.
// I can explain every function, data structure, and design decision.

#include <iostream>
#include "ArrayBag.h"
#include <fstream>
#include <string>

using namespace std;

//prototypes

void fillTheBag(ArrayBag<double>& bag1);

void runMenu(ArrayBag<double>& bag1);

void displayMenu();

int getMenuOption();


/**
 * main()
 * Initializes the program by creating an ArrayBag, filling it with data from a file,
 * and then running an interactive menu for user operations on the bag.
 *
 * @return int - program exit status
 */
int main() {
    ArrayBag <double>  bag1;

    fillTheBag(bag1);

    runMenu(bag1);

} 
//end main()

/**
 * runMenu()
 * Displays a menu of options and processes user selections until the user chooses to exit.
 * Supports adding items, checking size, checking if empty, clearing the bag,
 * checking frequency, and checking containment.
 *
 * @param bag1 - the ArrayBag<double> to operate on
 */
void runMenu(ArrayBag <double>& bag1) {
    int leave = 0;
    while(leave != 9){

    displayMenu();  //this could come from the Menu.h file

    //BagMenu bagMenu1;
    // 
   // bagMenu1.displayMenu();  //in the menu class

    int choice = getMenuOption();

    double d = 0.0;

    switch (choice) {

    case 1:
        cout << "in option 1\n";
        cout << "What number do you want to add?" << endl;
        cin >> d;
            //input from user for lab 3, this could easily be a Utility function

        bag1.add(d);

        bag1.display();

        break;

    case 2:

        cout << "current number of items in the bag: " << bag1.getCurrentSize() << endl;

        break;

    case 3:

        cout << "bag empty? " << boolalpha << bag1.isEmpty() << endl;

        break;

    case 4:

        bag1.clear();

        cout << "bag has been emptied\n";

        break;

    case 5:
        cout << "enter the double how wish to check the frequency of in the bag";
        cin >> d;
        //you will do user input here

        cout << d << " occurs " << bag1.getFrequencyOf(d) << " times" << endl;

        break;

    case 6:

        cout << "enter the double how wish to check the if its in the bag";
        cin >> d;

        if (bag1.contains(d))

            cout << "bag contains |" << d << "| \n";

        else

            cout << "bag does not contain |" << d << "| \n";

        break;

    case 7:
        leave = 9;
        break;
    }//end switch 

    }

}  //end runMenu()
/**
 * getMenuOption()
 * Prompts the user for a menu choice and validates that the input is within the valid range (1-7).
 * If the input is out of range, the user is prompted to re-enter and 0 is returned.
 *
 * @return int - the user's validated menu choice, or 0 if invalid
 */
int getMenuOption() {

    int choice = 0;

    string optionString = "";

    cout << "Which option? \n";

    getline(cin, optionString);

    choice = stoi(optionString);

    //check for validity of input, in the correct range and is it an integer?
    //cin.fail() is a better option since you don't have exception handling yet

    if (choice < 1 || choice > 7) {
        cout << "Please enter a number between 1 and 7." << endl;
        return 0;
    }

    return choice;

}

/*
*displayMenu()
* Displays all available menu options for the user to select from.
*/
void displayMenu() {

    cout << "Bag menu options: \n";
    cout << "1.  Add an item to the bag\n";
    cout << "2.  Get current number of items in the bag\n";
    cout << "3.  Is the bag empty?\n";
    cout << "4.  Clear the bag of all items\n";
    cout << "5.  Count the number of occurrences of an item in the bag\n";
    cout << "6.  Does the bag contain at least one of an item\n";
    cout << "7.  Exit \n";

}//end displaMenu()

/**
 * fillTheBag()
 * Reads numerical data from a file named "dataLab3Sp26.txt" and populates the bag.
 * Data in the file is separated by '$' delimiters. Only valid double values are added to the bag.
 * Invalid entries are skipped. The first line of the file is skipped.
 *
 * @param bag1 - the ArrayBag<double> to fill with data from the file
 */
void fillTheBag(ArrayBag<double>& bag1) {
    ifstream infile("dataLab3Sp26.txt");

    string str = "";
    double d = 0.0;

    if (!infile) {
        cout << "no file, terminating....\n";

        exit(0);
    }
    //skipping the first line
    getline(infile, str);

    while (getline(infile, str, '$')) {
        //checks to see if the split token can be a double
        //function is from https://www.geeksforgeeks.org/cpp/stdstringfind_first_not_of-in-c/
        if (!str.empty() && str.find_first_not_of("0123456789.-") == string::npos) {

            d = stod(str);
            bag1.add(d);
            cout << "adding " << d << " to the bag...\n";
        }
    }
    infile.close();
}
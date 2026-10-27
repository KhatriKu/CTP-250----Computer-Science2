#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;





void printRow(const vector<vector<string>>& row) {
    // this is shown in 1.10 vector ADT in zybooks
    unsigned int i;

    // loop to print row
    for (i = 0; i < row[0].size(); ++i) {
        cout << row[0].at(i) << " ";
    }
    cout << endl;
}



void printEveryRow(const vector<vector<vector<string>>>& allRows) {
    //using r for row as I used iota in helper function and this helps me differentiate
    unsigned int r;

    for (r = 0; r < allRows.size(); ++r) {
        cout << "Row " << (r + 1) << ": ";

        // send the row to allRows
        unsigned int c;
        for (c = 0; c < allRows[r][0].size(); ++c) {
            cout << allRows[r][0].at(c) << " ";
        }

        cout << endl;
    }
}



/*I was unsure to remove rows after reading them*/
void createParkVectorData(vector<vector<string>>& Row, ifstream& inFS) {

    string fileLine;

    // Read one line only
    if (!getline(inFS, fileLine)) {
        return; // no more lines to read
    }

    vector<string> targetRow;
    string element;
    stringstream ss(fileLine);

    // Split by commas - LOOP ONE
    while (getline(ss, element, ',')) {
        targetRow.push_back(element);
    }

    // LOOP 2 - And conditional to start loop
    if (targetRow.size() >= 7) {
        vector<string> semicolonRow;
        string subElement;
        stringstream ss2(targetRow[6]);

        while (getline(ss2, subElement, ';')) {
            semicolonRow.push_back(subElement);
        }

        // Replace the original 7th element with the split list
        targetRow.erase(targetRow.begin() + 6);
        targetRow.insert(targetRow.begin() + 6,
            semicolonRow.begin(), semicolonRow.end());
    }

    Row.push_back(targetRow);
}


int main() {

    ifstream inFS;      //Creating the Input File Stream

    vector<vector<string>> rowOne;    //Creating all 6 parrelell vectors
    vector<vector<string>> rowTwo;    // Please note I am making each vector 2d so I can have a second loop in the first to detokenize and then add as values to the seventh value of the vector
    vector<vector<string>> rowThree;
    vector<vector<string>> rowFour;
    vector<vector<string>> rowFive;
    vector<vector<string>> rowSix;
    inFS.open("nationalParksSp2026.csv"); //creates file and below lines check if file is open or not
    if (!inFS.is_open()) {  cout << "Could not open file nationalParksSp2026.csv." << endl;
        return 1; }

    createParkVectorData(rowOne, inFS);
    createParkVectorData(rowTwo, inFS);
    createParkVectorData(rowThree, inFS);
    createParkVectorData(rowFour, inFS);
    createParkVectorData(rowFive, inFS);
    createParkVectorData(rowSix, inFS);

    //final vector to combine all for a function
    vector<vector<vector<string>>> allRows = {
            rowOne, rowTwo, rowThree, rowFour, rowFive, rowSix
    };

    printEveryRow(allRows);

    inFS.close();
    return 0;
}

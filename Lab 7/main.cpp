#include <iostream>
#include <string>
#include <fstream>
#include "MaxHeap.h"
#include <sstream>
#include "Scholarship.h"

using namespace std;

void displayMenu(){
    cout << "Welcome to LAB - 7 MENU\n"<< endl;
    cout << "Option 1: Load sample data: ScholarshipProfile.txt"<< endl;
    cout << "Option 2: Insert a new object - Delimter is a \'|\'"<< endl;
    cout << "Option 3: Remove and display max"<< endl;
    cout << "Option 4: Peek at max"<< endl;
    cout << "Option 5: Display heap"<< endl;
    cout << "Option 6: Heap size"<< endl;
    cout << "Option 7: Sort heap"<< endl;
    cout << "Option 8: Clear heap"<< endl;
    //I wanted to see how well this method works;
    cout << "Option 0: Extra Option - Display heap as tree" << endl;
    cout << "\nOption 9: Exit"<< endl;

}
void loadHeapData(ifstream &inFs, MaxHeap<Scholarship> *heap){
    string line;
    getline(inFs, line); // skipping the header line - yes I have a header line for functionality

    while (getline(inFs, line)) {
        stringstream ss(line);
        string organization, title, stringScholarshipMoney;
        double scholarshipMoney;
        

        getline(ss, title, '|');
        getline(ss, organization, '|');
        getline(ss, stringScholarshipMoney);
        scholarshipMoney = stod(stringScholarshipMoney);

        Scholarship inputScholarship(organization, title, scholarshipMoney);
        heap->insert(inputScholarship);
    }
}

int runMenu(ifstream &inFs, MaxHeap<Scholarship> *heap){
    
    int exitNum = 0;
    do {
        int choice;
        displayMenu();
        cout << "\n\nWhat is your choice?: ";
        cin >> choice;
        if(cin.fail() || !(choice <= 9 && choice >=0)){
            cin.clear();
            cin.ignore(1000, '\n');
            throw runtime_error("INVALID INPUT TRY AGAIN with a number between 0 - 9 inclusive.");
        }
        switch (choice) {
            
            case 0:
                cout << "Displaying Heap Data as a Tree: " <<endl;
                heap->printHeapTree();
                cout << "\n" <<endl;
                break;
            case 1:
                loadHeapData(inFs, heap);
                cout << "Successfully loaded data!"<< endl;
                break;
            case 2:{
                
                cout << "Was unsure how to approach insertion so here are two choices \n"
                << "1. Full line \n2. 3 seperate inputs" << endl;
                int choiceCase;
                cin >> choiceCase;
                if(cin.fail() || !(choiceCase <= 2 && choiceCase >=1)){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    throw runtime_error("INVALID INPUT TRY AGAIN with a number between 1 - 2 inclusive.");
                }
                switch(choiceCase){
                    case 1:{
                        cout << "Input in object data as title|organization|ScholarshipMoney(double)" << endl;
                        Scholarship newScholarship;
                        cin.ignore(1000, '\n'); //flushing any newlines
                        cin >> newScholarship;
                        heap->insert(newScholarship);
                        break;
                    }
                    case 2:{
                        cout << "Input in Scholarship title" << endl;
                        cin.ignore(1000, '\n'); //flushing any newlines
                        string title;
                        getline(cin, title);
                        
                        cout << "Input in Scholarship organization" << endl;
                        string organization;
                        getline(cin, organization);
                        
                        double scholarshipAmount = 0.0;
                        while(scholarshipAmount == 0.0){
                            cout << "Input in Scholarship amount (double)" << endl;
                            string stringScholarship;
                            getline(cin, stringScholarship);
                            try {
                                scholarshipAmount = stod(stringScholarship);
                            }
                            catch (invalid_argument& excpt) {
                                cout << excpt.what();
                            }
                        }
                        Scholarship newScholarship(organization, title, scholarshipAmount);
                        heap->insert(newScholarship);
                        break;
                    }
                    
                }
                break;
            }
            case 3:
                cout << "Removing Scholarship:\n"<< heap->getMax() << "\n" << endl;
                heap->removeMax();
                break;
            case 4:
                cout << "Max Scholarship :\n"<< heap->getMax() << "\n" << endl;
                break;
            case 5:
                cout << "Displaying Heap Data: " << endl;
                heap->printHeap();
                cout << "\n" <<endl;
                break;
            case 6:
                cout << "Heap Size is: " << heap->getSize() << endl;
                break;
            case 7:
                heap->heapSort();
                cout << "Heap has been successfully sorted! " << endl;
                break;
            case 8:
                while(heap->getSize() != 0){heap->removeMax();}
                cout << "Heap has been successfully cleared!" << endl;
                break;
            case 9:
                cout << "Exiting... \n" << endl;
                exitNum = -1;
                break;
            default:
                throw runtime_error("INVALID INPUT TRY AGAIN with a number between 1 - 9 inclusive.");
                break;
        }
    }
    while (exitNum != -1);
    return -1;
}

int main() {
    int exitNum = 0;
    MaxHeap<Scholarship> *MaxHeapOfScholarships;
    ifstream inFs("ScholarshipProfile.txt");
    if (!inFs) {
        throw runtime_error("File was unable to be opened.");
    }
    while(exitNum != -1){
        try{
            int capacity;
            cout << "Enter a integer value for the heap capacity" << endl;
            cin >> capacity;
            if(cin.fail() || capacity <= 0){
                cin.clear();
                cin.ignore(1000, '\n');
                throw runtime_error("INVALID INPUT TRY AGAIN with a number greater than 0");
            }
            MaxHeapOfScholarships = new MaxHeap<Scholarship>(capacity);
            exitNum = runMenu(inFs,MaxHeapOfScholarships);
        }
        catch(runtime_error &exception){ cout << exception.what(); }}
    delete MaxHeapOfScholarships;
    inFs.close();
    return 0;
}

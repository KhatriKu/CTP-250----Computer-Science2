/**
 * @file main.cpp
 * @brief Driver for the DoublyLinkedList lab assignment (Lab 4).
 *
 * This code reflects my own understanding.
 * I can explain every function, data structure, and design decision.
 *
 * Loads a doubly linked list from a CSV file, displays all data using
 * the Part 3 concrete methods, then launches an interactive menu allowing
 * the user to call every method from both Part 2 (interface) and Part 3.
 *
 * @author Kushal
 * @version 1.0
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Node.h"
#include "DoublyLinkedListInterface.h"
#include "DoublyLinkedList.h"

using namespace std;

/**
 * @brief Calls all Part 3 display methods on the list to show its full contents.
 *
 * Demonstrates each concrete display method using the loaded list.
 * Index-based calls use 0 and 5 as representative values since the
 * user will choose specific indices interactively in runMenu.
 *
 * @param DLinkedList Reference to the DoublyLinkedList to display.
 */
void DisplayAll(DoublyLinkedList<string>& DLinkedList){
    
    //Note: for all the ones involving indexes, I am just generalizing it here as they user will have a choice for index in the
    //runMenu function
    DLinkedList.displayFromNToEnd(0);
    DLinkedList.displayFromFrontToN(0);
    DLinkedList.displayNFromTail(0);
    DLinkedList.displayFromNToM(0, 5);
    DLinkedList.display();
    
}

/**
 * @brief Reads a CSV file and populates the doubly linked list.
 *
 * Each line of the file contains a word and a direction ('h' or 't').
 * 'h' means insert at head, 't' means insert at tail.
 * Uses a stringstream to parse each comma-separated line.
 *
 * @param Fs          Reference to the open input file stream.
 * @param DLinkedList Reference to the list to populate.
 */
void createDoublyLinkedList(ifstream& Fs, DoublyLinkedList<string>& DLinkedList){
    
    string line;
    while(getline(Fs, line)){
        stringstream ss(line);
        string value;
        string location;
       
        getline(ss, value, ',');
        getline(ss, location, ',');
        
        if (location == "h") {
            DLinkedList.insertAtHead(value);
        }
        else {
            DLinkedList.insertAtTail(value);
        }
    }
}

/**
 * @brief Prints the interactive menu to the console.
 *
 * Lists all 22 available operations (Part 2 interface methods and
 * Part 3 concrete methods) along with option 0 to exit.
 * Called at the start of each loop iteration in runMenu.
 */
void printMenu(){
    
    cout << "Welcom to the DoublyLinked List menu! Feel free to choose a method to run";
        cout << "Part 2 Interface Methods\n";
        cout << " 1.  Insert at head\n";
        cout << " 2.  Insert at tail\n";
        cout << " 3.  Insert at index\n";
        cout << " 4.  Delete front\n";
        cout << " 5.  Delete tail\n";
        cout << " 6.  Delete at index\n";
        cout << " 7.  Delete by value\n";
        cout << " 8.  Get front value\n";
        cout << " 9.  Get last value\n";
        cout << " 10. Get value at index\n";
        cout << " 11. Size\n";
        cout << " 12. Is empty?\n";
        cout << " 13. Contains value?\n";
        cout << " 14. Clear list\n";
        cout << " 15. Display from head\n";
        cout << " 16. Display from tail\n\n\n\n";
        cout << "Part 3: Concrete Methods\n";
        cout << " 17. Get max value\n";
        cout << " 18. Get min value\n";
        cout << " 19. Display from N to end\n";
        cout << " 20. Display from front to N\n";
        cout << " 21. Display N items from tail\n";
        cout << " 22. Display from index N to M\n\n";
        cout << " IF YOU WANT TO EXIT TYPE 0\n\n\n";
        cout << "Choice: ";
}

/**
 * @brief Runs the interactive menu loop using a do-while.
 *
 * Repeatedly displays the menu and reads the user's choice.
 * Handles invalid (non-numeric) input with cin.fail() and continues
 * the loop. Each valid choice dispatches to the appropriate list method.
 * The loop exits when the user enters 0.
 *
 * @param DLL Reference to the DoublyLinkedList to operate on.
 */
void runMenu(DoublyLinkedList<string>& DLL){
    //Instead of a while(true) - i am using a do-while loop
    int choice = -1;
    do{
        printMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a number.\n";
            continue;
        }
        cin.ignore(1000, '\n');
        
        string val;
        int index;
        int n;
        int m;
        
        switch (choice) {
                
                // ── Part 2 methods
            case 1:
                cout << "Value to insert at head: ";
                getline(cin, val);
                DLL.insertAtHead(val);
                cout << "Value has been inserted.\n";
                break;
                
            case 2:
                cout << "Value to insert at tail: ";
                getline(cin, val);
                DLL.insertAtTail(val);
                cout << "Value has been inserted.\n";
                break;
                
            case 3:
                cout << "Index: ";
                cin >> index;
                cin.ignore(1000, '\n');
                cout << "Value: ";
                getline(cin, val);
                DLL.insertAt(index, val);
                cout << "Value has been inserted \"" << val << "\" at index " << index << ".\n";
                break;
                
            case 4:
                if (DLL.isEmpty()) {
                    cout << "List is empty.\n";
                    break;
                }
                DLL.deleteFront();
                cout << "The Front deleted.\n";
                break;
                
            case 5:
                if (DLL.isEmpty()) {
                    cout << "List is empty.\n";
                    break;
                }
                DLL.deleteTail();
                cout << "The Tail deleted.\n";
                break;
                
            case 6:
                cout << "Index to delete: ";
                cin >> index;
                cin.ignore(1000, '\n');
                DLL.deleteAt(index);
                cout << "Deleted index " << index << ".\n";
                break;
                
            case 7:
                cout << "Value to delete: ";
                getline(cin, val);
                DLL.deleteValue(val);
                cout << "Value \"" << val << "\" has been Deleted(if it even existed).\n";
                break;
                
            case 8:
                if (DLL.isEmpty()) {
                    cout << "List is empty.\n";
                    break;
                }
                cout << "Front: " << DLL.getFront() << "\n";
                break;
                
            case 9:
                if (DLL.isEmpty()) {
                    cout << "List is empty.\n";
                    break;
                }
                cout << "Last: " << DLL.getLast() << "\n";
                break;
                
            case 10:
                cout << "Index: ";
                cin >> index;
                cin.ignore(1000, '\n');
                if (index < 0 || index >= DLL.size()) {
                    cout << "Index out of range.\n";
                    break;
                }
                cout << "Value at " << index << ": " << DLL.at(index) << "\n";
                break;
                
            case 11:
                cout << "Size: " << DLL.size() << "\n";
                break;
                
            case 12:{
                string ifEmpty = "";
                if(DLL.isEmpty()){
                    ifEmpty = " IS ";
                }
                else{
                    ifEmpty = " IS NOT ";
                }
                cout << "List" << ifEmpty << "empty\n";
                break;
            }
            case 13:{
                cout << "Search for: ";
                getline(cin, val);
                string contain = "";
                if(DLL.contains(val) == true){
                    contain = "IS";
                }else{
                    contain = "IS NOT";
                }
                cout << "\"" << val << "\" "
                << contain << " in the list.\n";
                break;
            }
            case 14:
                DLL.clear();
                cout << "List cleared.\n";
                break;
                
            case 15:
                cout << "\n--- From Head ---\n";
                DLL.displayFromHead();
                break;
                
            case 16:
                cout << "\n--- From Tail ---\n";
                DLL.displayFromTail();
                break;
                
                // ── Part 3 methods
            case 17:
                if (DLL.isEmpty()) {
                    cout << "List is empty.\n";
                    break;
                }
                cout << "Max: " << DLL.getMax() << "\n";
                break;
                
            case 18:
                if (DLL.isEmpty()) {
                    cout << "List is empty.\n";
                    break;
                }
                cout << "Min: " << DLL.getMin() << "\n";
                break;
                
            case 19:
                cout << "Start index N: ";
                cin >> n;
                cin.ignore(1000, '\n');
                cout << "\nIndex " << n << " \n";
                DLL.displayFromNToEnd(n);
                break;
                
            case 20:
                cout << "Display front to index N: ";
                cin >> n;
                cin.ignore(1000, '\n');
                cout << "\nFront to index " << n << " \n";
                DLL.displayFromFrontToN(n);
                break;
                
            case 21:
                cout << "How many items from tail: ";
                cin >> n;
                cin.ignore(1000, '\n');
                cout << "\n" << n << " items from tail\n";
                DLL.displayNFromTail(n);
                break;
                
            case 22:
                cout << "From index N: ";
                cin >> n;
                cout << "To index M:   ";
                cin >> m;
                cin.ignore(1000, '\n');
                cout << "\nIndex " << n << " to " << m << " \n";
                DLL.displayFromNToM(n, m);
                break;
                
            case 0:
                cout << "Thank you for using my menu! - Kushal\n";
                break;
                
            default:
                cout << "INVALID — PLEASE CHOSE BETWEEN  0 TO 22.\n";
                break;
        }
    }while(choice != 0);
}

/**
 * @brief Program entry point. Loads data, displays it, then launches the menu.
 *
 * Declares a DoublyLinkedList<string> on the stack, opens the CSV file,
 * builds the list via createDoublyLinkedList, closes the file, displays
 * all data with DisplayAll, then hands control to the interactive runMenu.
 *
 * @return 0 on success, 1 if the file could not be opened.
 */
int main() {
    DoublyLinkedList<string> DLL;
    ifstream inFS("words_list_with_insert.csv");
    
    if (!inFS.is_open()) {
            cout << "Error: COULD NOT OPEN FILE" << endl;
            return 1;
        }
    
    createDoublyLinkedList(inFS, DLL);
    inFS.close();
    DisplayAll(DLL);
    runMenu(DLL);
    return 0;
}

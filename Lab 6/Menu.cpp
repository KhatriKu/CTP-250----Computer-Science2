#include "Menu.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

// Load events from CSV
void Menu::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "\nCould not open file: " << filename << endl;
        return;
    }
    string line;
    getline(file, line); // skip header row
    while (getline(file, line)) {
        if (!line.empty()) {
            Event e(line);
            BSTEvents.insert(e);
        }
    }
    file.close();
    cout << "\nEvents loaded successfully.\n";
}

// Main Menu
void Menu::mainMenu() {
    loadFromFile("events.csv");
    int choice = -1;
    do {
        cout << "\nMain Menu\n";
        cout << "  1. Search\n";
        cout << "  2. Generate Reports\n";
        cout << "  3. Maximums and Minimums\n";
        cout << "  4. Edit Event Data\n";
        cout << "  0. Quit\n";
        cout << "==\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: searchMenu();    break;
            case 2: reportMenu();    break;
            case 3: maxAndMinMenus(); break;
            case 4: editMenu();      break;
            case 0: cout << "\nGoodbye!\n";
                    BSTEvents.clearTree();
                    break;
            default: cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 0);
}

// Search Menu
void Menu::searchMenu() {
    int choice = -1;
    do {
        cout << "\n SEARCH MENU \n";
        cout << "  1. Search by Title\n";
        cout << "  2. Search by Entrance Fee Range\n";
        cout << "  3. Search by Location\n";
        cout << "  0. Return to Main Menu\n";
        cout << "\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: searchTitle();    break;
            case 2: searchFee();      break;
            case 3: searchLocation(); break;
            case 0: break;
            default: cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 0);
}

void Menu::searchTitle() {
    string term;
    cout << "\nEnter title (or portion): ";
    cin.ignore();
    getline(cin, term);

    cout << "\n Search Results \n";
    SearchByTitleVisitor v(term);
    BSTEvents.inorder(v);

    if (!v.wasFound()) {
        cout << "No events found matching: " << term << "\n";
    }
}

void Menu::searchFee() {
    double minFee, maxFee;

    // Input validation loop
    while (true) {
        cout << "\nEnter minimum fee: ";
        if (!(cin >> minFee) || minFee < 0) {
            cout << "Invalid input. Must be a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cout << "Enter maximum fee: ";
        if (!(cin >> maxFee) || maxFee < 0) {
            cout << "Invalid input. Must be a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (minFee > maxFee) {
            cout << "Minimum must be less than maximum. Try again.\n";
            continue;
        }
        break;
    }

    cout << "\n Events with fee between $" << minFee << " and $" << maxFee << " \n";
    SearchByFeeVisitor v(minFee, maxFee);
    BSTEvents.inorder(v);
}

void Menu::searchLocation() {
    string loc;
    cout << "\nEnter location (or portion): ";
    cin.ignore();
    getline(cin, loc);

    cout << "\n Search Results \n";
    SearchByLocationVisitor v(loc);
    BSTEvents.inorder(v);
}

// Report Menu
void Menu::reportMenu() {
    int choice = -1;
    do {
        cout << "\n REPORTS MENU \n";
        cout << "  1. List All Events\n";
        cout << "  2. List Events by Month\n";
        cout << "  3. List Events by Type\n";
        cout << "  4. List Events Longer Than 2 Hours\n";
        cout << "  5. List Free Events ($0)\n";
        cout << "  6. List Events Least to Greatest (Inorder)\n";
        cout << "  7. Postorder Traversal (titles only)\n";
        cout << "  8. Custom report : Summer Events\n";
        cout << "  0. Return to Main Menu\n";
        cout << "\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: listAllEvents();                break;
            case 2: listAllEventsInAMonth();        break;
            case 3: listAllEventsOfAnType();        break;
            case 4: listAllEventsLongerThanTwoHours(); break;
            case 5: listAllFreeEvents();            break;
            case 6: listTheEventsLeastToGreatest(); break;
            case 7: postOrderTraverse();            break;
            case 8: summerEventsReport(); break;
            case 0: break;
            default: cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 0);
}

void Menu::summerEventsReport() {
    cout << "\n Summer Events (June - August) \n";
    MyVisitor v;
    BSTEvents.inorder(v);
    cout << "\nTotal summer events: " << v.getCount() << "\n";
}

void Menu::listAllEvents() {
    cout << "\n All Events \n";
    ListAllVisitor v;
    BSTEvents.inorder(v);
    cout << "\nTotal: " << v.getCount() << " events\n";
}

void Menu::listAllEventsInAMonth() {
    cout << "\n  1. April\n  2. May\n  3. June\n";
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    int month = (choice == 1) ? 4 : (choice == 2) ? 5 : 6;
    string monthName = (month == 4) ? "April" : (month == 5) ? "May" : "June";

    cout << "\n Events in " << monthName << " \n";
    SearchByMonthVisitor v(month);
    BSTEvents.inorder(v);
}

void Menu::listAllEventsOfAnType() {
    cout << "\n  1. COMMUNITY  2. CULTURAL   3. FESTIVAL\n";
    cout << "  4. EXHIBIT    5. CONCERT    6. ART\n";
    cout << "  7. WORKSHOP   8. SPORTS     9. FOOD   10. MOVIE\n";
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    string types[] = {"", "community", "cultural", "festival", "exhibit",
                      "concert", "art", "workshop", "sports", "food", "movie"};
    if (choice < 1 || choice > 10) {
        cout << "Invalid choice.\n";
        return;
    }
    cout << "\n " << types[choice] << " Events \n";
    SearchByTypeVisitor v(types[choice]);
    BSTEvents.inorder(v);
}

void Menu::listAllEventsLongerThanTwoHours() {
    cout << "\n Events Longer Than 2 Hours \n";
    LongDurationVisitor v;
    BSTEvents.inorder(v);
}

void Menu::listAllFreeEvents() {
    cout << "\n Free Events ($0) \n";
    FreeEventsVisitor v;
    BSTEvents.inorder(v);
}

void Menu::listTheEventsLeastToGreatest() {
    cout << "\n All Events Inorder (by Date, Least to Greatest) \n";
    ListAllVisitor v;
    BSTEvents.inorder(v);
}

void Menu::postOrderTraverse() {
    cout << "\n Postorder Traversal (titles only) \n";
    PostOrderDeleteVisitor v;
    BSTEvents.postorder(v);
}

// Max and Minimum menu
void Menu::maxAndMinMenus() {
    int choice = -1;
    do {
        cout << "\n MAX & MIN MENU \n";
        cout << "  1. Maximum Cost\n";
        cout << "  2. Minimum Cost\n";
        cout << "  3. Maximum Duration\n";
        cout << "  4. Minimum Duration\n";
        cout << "  5. Earliest Start Date\n";
        cout << "  6. Latest Start Date\n";
        cout << "  0. Return to Main Menu\n";
        cout << "\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: maxCost();          break;
            case 2: minCost();          break;
            case 3: maxDuration();      break;
            case 4: minDuration();      break;
            case 5: earliestStartTime(); break;
            case 6: latestStartTime();  break;
            case 0: break;
            default: cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 0);
}

void Menu::maxCost() {
    MaxCostVisitor v;
    BSTEvents.inorder(v);
    cout << "\nMaximum Cost Event:\n" << v.getResult() << "\n";
}

void Menu::minCost() {
    MinCostVisitor v;
    BSTEvents.inorder(v);
    cout << "\nMinimum Cost Event:\n" << v.getResult() << "\n";
}

void Menu::maxDuration() {
    MaxDurationVisitor v;
    BSTEvents.inorder(v);
    cout << "\nMaximum Duration Event:\n" << v.getResult() << "\n";
}

void Menu::minDuration() {
    MinDurationVisitor v;
    BSTEvents.inorder(v);
    cout << "\nMinimum Duration Event:\n" << v.getResult() << "\n";
}

void Menu::earliestStartTime() {
    EarliestEventVisitor v;
    BSTEvents.inorder(v);
    cout << "\nEarliest Event:\n" << v.getResult() << "\n";
}

void Menu::latestStartTime() {
    LatestEventVisitor v;
    BSTEvents.inorder(v);
    cout << "\nLatest Event:\n" << v.getResult() << "\n";
}

// Edit Menu
void Menu::editMenu() {
    int choice = -1;
    do {
        cout << "\n Edit Menu \n";
        cout << "  1. Edit Cost of an Event\n";
        cout << "  2. Edit Duration of an Event\n";
        cout << "  3. Add New Event\n";
        cout << "  0. Return to Main Menu\n";
        cout << "\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: editCost();     break;
            case 2: editDuration(); break;
            case 3: addEvent();     break;
            case 0: break;
            default: cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 0);
}

void Menu::editCost() {
    string searchTerm;
    cout << "\nEnter event title (or portion): ";
    cin.ignore();
    getline(cin, searchTerm);

    SearchByTitleVisitor finder(searchTerm);
    BSTEvents.inorder(finder);

    if (!finder.wasFound()) {
        cout << "\nNo events found matching: " << searchTerm << "\n";
        return;
    }

    string exactTitle;
    cout << "\nEnter the exact title of the event to edit: ";
    getline(cin, exactTitle);

    double newCost;
    cout << "Enter new cost: $";
    while (!(cin >> newCost) || newCost < 0) {
        cout << "Invalid input. Must be a positive number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter new cost: $";
    }

    CollectByTitleVisitor collector(exactTitle);
    BSTEvents.inorder(collector);

    if (!collector.wasFound()) {
        cout << "\nExact title not found.\n";
        return;
    }

    Event updated = collector.getResult();
    BSTEvents.remove(updated);
    updated.setCost(newCost);
    BSTEvents.insert(updated);
    cout << "\nCost updated successfully.\n";
}

void Menu::editDuration() {
    string searchTerm;
    cout << "\nEnter event title (or portion): ";
    cin.ignore();
    getline(cin, searchTerm);

    SearchByTitleVisitor finder(searchTerm);
    BSTEvents.inorder(finder);

    if (!finder.wasFound()) {
        cout << "\nNo events found matching: " << searchTerm << "\n";
        return;
    }

    string exactTitle;
    cout << "\nEnter the exact title of the event to edit: ";
    getline(cin, exactTitle);

    int newDuration;
    cout << "Enter new duration (in minutes): ";
    while (!(cin >> newDuration) || newDuration <= 0) {
        cout << "Invalid input. Must be a positive integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter new duration (in minutes): ";
    }

    CollectByTitleVisitor collector(exactTitle);
    BSTEvents.inorder(collector);

    if (!collector.wasFound()) {
        cout << "\nExact title not found.\n";
        return;
    }

    Event updated = collector.getResult();
    BSTEvents.remove(updated);
    updated.setDuration(newDuration);
    BSTEvents.insert(updated);
    cout << "\nDuration updated successfully.\n";
}

void Menu::addEvent() {
    cout << "\nEnter event data in format:\n";
    cout << "Title,Location,Date,Time,Duration,Cost,Type\n";
    cin.ignore();
    string line;
    getline(cin, line);
    try {
        Event e(line);
        BSTEvents.insert(e);
        cout << "\nEvent added successfully.\n";
    } catch (...) {
        cout << "\nInvalid format. Event not added.\n";
    }
}

//==============Menu.h===================
#pragma once
#include "BinarySearchTree.h"
#include "Event.h"
#include "Visitor.h"
#include "SearchByTitleVisitor.h"
#include "SearchByFeeVisitor.h"
#include "SearchByLocationVisitor.h"
#include "SearchByMonthVisitor.h"
#include "SearchByType.h"
#include "LongDurationVisitor.h"
#include "FreeEventsVisitor.h"
#include "ListAllVisitor.h"
#include "PostOrderDeleteVisitor.h"
#include "MaxCostVisitor.h"
#include "MinCostVisitor.h"
#include "MaxDurationVisitor.h"
#include "MinDurationVisitor.h"
#include "EarliestEventVisitor.h"
#include "LatestEventVisitor.h"
#include "CollectByTitleVisitor.h"
#include "MyVisitor.h"

class Menu {
private:
    BinarySearchTree<Event> BSTEvents;

public:
    void mainMenu();

    void searchMenu();
    void searchTitle();
    void searchFee();
    void searchLocation();

    void reportMenu();
    void listAllEvents();
    void listAllEventsOfAnType();
    void listAllEventsInAMonth();
    void listAllEventsLongerThanTwoHours();
    void listAllFreeEvents();
    void listTheEventsLeastToGreatest();
    void postOrderTraverse();
    void summerEventsReport();

    void maxAndMinMenus();
    void maxCost();
    void minCost();
    void maxDuration();
    void minDuration();
    void earliestStartTime();
    void latestStartTime();

    void editMenu();
    void editCost();
    void editDuration();
    void addEvent();

    void loadFromFile(const std::string& filename);
};

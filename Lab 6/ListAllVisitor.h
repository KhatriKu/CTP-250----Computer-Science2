//Doesent list the Visitors but the Events
#pragma once
#include "Visitor.h"
#include "Event.h"
#include <iostream>
#include <iomanip>
class ListAllVisitor : public Visitor<Event> {
private:
    int count = 0;
 
public:
    void visit(const Event& event) override {
        count++;
        std::cout << std::setw(3) << count << ". " << event << std::endl;
    }
 
    int getCount() const { return count; }
};

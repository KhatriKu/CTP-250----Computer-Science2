#pragma once
#include "Visitor.h"
#include "Event.h"
#include <iostream>
#include <iomanip>
class FreeEventsVisitor : public Visitor<Event> {
public:
    void visit(const Event& event) override {
        if (event.getCost() == 0.0) {
            std::cout << std::left
                      << std::setw(20) << event.getTitle()
                      << " | " << std::setw(20) << event.getLocation()
                      << " | " << event.getDate()
                      << std::endl;
        }
    }
};

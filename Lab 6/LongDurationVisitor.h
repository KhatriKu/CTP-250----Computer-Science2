#pragma once
#include "Visitor.h"
#include "Event.h"
#include <iostream>
#include <iomanip>
class LongDurationVisitor : public Visitor<Event> {
public:
    void visit(const Event& event) override {
        if (event.getDuration() > 120) {
            std::cout << std::left
                      << std::setw(20) << event.getTitle()
                      << " | " << event.getLocation()
                      << std::endl;
        }
    }
};

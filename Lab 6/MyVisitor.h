#pragma once
#include "Visitor.h"
#include "Event.h"
#include <iostream>
#include <iomanip>
#include <sstream>

class MyVisitor : public Visitor<Event> {
private:
    int count = 0;

public:
    void visit(const Event& event) override {
        std::stringstream ss(event.getDate());
        int day, month, year;
        char slash;
        ss >> day >> slash >> month >> slash >> year;

        if (month >= 6 && month <= 8) {
            count++;
            std::cout << std::left
                      << std::setw(3)  << count << ". "
                      << std::setw(20) << event.getTitle()
                      << " | " << std::setw(20) << event.getLocation()
                      << " | " << std::setw(12) << event.getDate()
                      << " | $" << std::fixed << std::setprecision(2) << event.getCost()
                      << std::endl;
        }
    }

    int getCount() const { return count; }
};

#pragma once
#include "Visitor.h"
#include "Event.h"
#include <iostream>
#include <iomanip>
#include <sstream>

class SearchByMonthVisitor : public Visitor<Event> {
private:
    int targetMonth;

public:
    SearchByMonthVisitor(int month) : targetMonth(month) {}

    void visit(const Event& event) override {
        std::stringstream ss(event.getDate());
        int day, month, year;
        char slash;
        ss >> day >> slash >> month >> slash >> year;

        if (month == targetMonth) {
            std::cout << std::left
                      << std::setw(20) << event.getTitle()
                      << " | " << std::setw(20) << event.getLocation()
                      << " | " << event.getDate()
                      << std::endl;
        }
    }
};

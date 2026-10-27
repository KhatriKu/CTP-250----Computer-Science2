#pragma once
#include "Visitor.h"
#include "Event.h"
#include <iostream>
#include <iomanip>

class SearchByFeeVisitor : public Visitor<Event> {
private:
    double minFee;
    double maxFee;

public:
    SearchByFeeVisitor(double min, double max) : minFee(min), maxFee(max) {}

    void visit(const Event& event) override {
        double cost = event.getCost();
        if (cost >= minFee && cost <= maxFee) {
            std::cout << std::left
                      << std::setw(20) << event.getTitle()
                      << " | " << std::setw(20) << event.getLocation()
                      << " | $" << std::fixed << std::setprecision(2) << cost
                      << std::endl;
        }
    }
};

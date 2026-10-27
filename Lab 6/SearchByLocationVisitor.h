#pragma once
#include "Visitor.h"
#include "Event.h"
#include <string>
#include <iostream>
#include <algorithm>

class SearchByLocationVisitor : public Visitor<Event> {
private:
    std::string searchTerm;
 
public:
    SearchByLocationVisitor(const std::string& location) : searchTerm(toLower(location)) {}
 
    void visit(const Event& event) override {
        if (toLower(event.getLocation()).find(searchTerm) != std::string::npos) {
            std::cout << event << std::endl;
        }
    }
};

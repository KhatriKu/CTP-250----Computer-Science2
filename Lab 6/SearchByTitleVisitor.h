// I just used my understanding of java functions and figured if the syntax was similar enough, they would share the toLower functions
// got documentation from https://www.geeksforgeeks.org/cpp/tolower-function-in-cpp/
#pragma once
#include "Visitor.h"
#include "Event.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

class SearchByTitleVisitor : public Visitor<Event> {
private:
    std::string searchValue;
    bool found = false;

    //overloadingding toLower function  https://www.geeksforgeeks.org/cpp/transform-c-stl-perform-operation-elements/
    std::string toLower(const std::string& str) const {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

public:
    SearchByTitleVisitor(const std::string& value) : searchValue(toLower(value)) {}

    void visit(const Event& event) override {
        if (toLower(event.getTitle()).find(searchValue) != std::string::npos) {
            std::cout << event << std::endl;
            found = true;
        }
    }

    bool wasFound() const { return found; }
};

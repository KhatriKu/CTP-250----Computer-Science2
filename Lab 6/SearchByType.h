#pragma once
#include "Visitor.h"
#include "Event.h"
#include <string>
#include <iostream>
#include <algorithm>
class SearchByTypeVisitor : public Visitor<Event> {
private:
    std::string targetType;
 
public:
    SearchByTypeVisitor(const std::string& type) : targetType(toLower(type)) {}
 
    void visit(const Event& e) override {
        if (toLower(e.getType()) == targetType) {
            std::cout << e << std::endl;
        }
    }
};

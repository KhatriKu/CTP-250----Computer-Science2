//being used to print title as the tree is being cleared/deleted
#pragma once
#include "Visitor.h"
#include "Event.h"
#include <iostream>
class PostOrderDeleteVisitor : public Visitor<Event> {
public:
    void visit(const Event& e) override {
        std::cout << "Deleting: " << e.getTitle() << std::endl;
    }
};


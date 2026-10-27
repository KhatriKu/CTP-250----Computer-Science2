#pragma once
#include "Visitor.h"
#include "Event.h"

class EarliestEventVisitor : public Visitor<Event> {
private:
    Event result;
    bool first = true;

public:
    void visit(const Event& event) override {
        if (first || event < result) {
            result = event;
            first = false;
        }
    }
    Event getResult() const { return result; }
};

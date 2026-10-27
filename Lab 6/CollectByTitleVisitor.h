#pragma once
#include "Visitor.h"
#include "Event.h"
#include <string>
#include <algorithm>

class CollectByTitleVisitor : public Visitor<Event> {
private:
    std::string targetTitle;
    Event result;
    bool found = false;

    std::string toLower(const std::string& str) const {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

public:
    CollectByTitleVisitor(const std::string& title) : targetTitle(toLower(title)) {}

    void visit(const Event& event) override {
        if (toLower(event.getTitle()) == targetTitle) {
            result = event;
            found = true;
        }
    }

    bool wasFound() const { return found; }
    Event getResult() const { return result; }
};

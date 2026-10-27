#pragma once
#include <string>
#include <iostream>

class Event {
private:
    std::string type;
    std::string title;
    std::string location;
    std::string date;
    std::string time;
    int duration;
    double cost;

public:
    Event() : title(""), type(""), location(""), date(""), time(""), duration(0), cost(0.0) {}
    Event(const std::string &line);

    void setTitle(const std::string &t);
    void setLocation(const std::string &loc);
    void setDate(const std::string &d);
    void setTime(const std::string &ti);
    void setDuration(int dur);
    void setCost(double c);
    void setType(const std::string &ty);

    std::string getTitle() const;
    std::string getLocation() const;
    std::string getDate() const;
    std::string getTime() const;
    int getDuration() const;
    double getCost() const;
    std::string getType() const;

    void setAllData(const std::string &line);

    friend std::ostream& operator<<(std::ostream &out, const Event &event);
    friend std::istream& operator>>(std::istream &in, Event &event);

    bool operator<(const Event &other) const;
    bool operator>(const Event &other) const;

    bool operator<(double value) const;

    bool operator>(int value) const;

    bool operator==(const Event &other) const;
    bool operator==(double value) const;

    ~Event() {}
};

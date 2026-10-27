/**
 * @file Event.cpp
 * @description Implementation of the Event class.
 *
 * This code reflects my own understanding.
 * I can explain every function, data structure, and design decision.
 */

#include "Event.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

Event::Event(const string &line) {
    setAllData(line);
}

void Event::setTitle(const string &t) {
    title = t;
}

void Event::setLocation(const string &loc) {
    location = loc;
}

void Event::setDate(const string &d) {
    date = d;
}

void Event::setTime(const string &ti) {
    time = ti;
}

void Event::setDuration(int dur) {
    duration = dur;
}

void Event::setCost(double c) {
    cost = c;
}

void Event::setType(const string &ty) {
    type = ty;
}

string Event::getTitle() const {
    return title;
}

string Event::getLocation() const {
    return location;
}

string Event::getDate() const {
    return date;
}

string Event::getTime() const {
    return time;
}

int Event::getDuration() const {
    return duration;
}

double Event::getCost() const {
    return cost;
}

string Event::getType() const {
    return type;
}

void Event::setAllData(const string &line) {
    stringstream ss(line);
    string stringDuration, stringCost;

    getline(ss, title, ',');
    getline(ss, location, ',');
    getline(ss, date, ',');
    getline(ss, time, ',');
    getline(ss, stringDuration, ',');
    getline(ss, stringCost, ',');
    getline(ss, type, ',');

    duration = stoi(stringDuration);
    cost = stod(stringCost);
}

ostream& operator<<(ostream &out, const Event &event) {
    out << left
        << setw(20) << event.getTitle()
        << " | " << setw(20) << event.getLocation()
        << " | " << setw(12) << event.getDate()
        << " | " << setw(6)  << event.getDuration() << " min"
        << " | $" << setw(8) << fixed << setprecision(2) << event.getCost()
        << " | " << setw(12) << event.getType()
        << endl;
    return out;
}

istream& operator>>(istream &in, Event &event) {
    string line;
    getline(in, line);

    if (line.empty()) {
        return in;
    }

    try {
        event.setAllData(line);
    } catch (runtime_error &ex) {
        cout << ex.what() << endl;
    }

    return in;
}

bool Event::operator<(const Event &other) const {
    stringstream ss(date);
    stringstream ssOther(other.getDate());
    char slash;
    int month, day, year, monthOther, dayOther, yearOther;

    ss >> day >> slash >> month >> slash >> year;
    ssOther >> dayOther >> slash >> monthOther >> slash >> yearOther;

    if (year != yearOther) {
        return year < yearOther;
    }
    if (month != monthOther) {
        return month < monthOther;
    }
    return day < dayOther;
}

bool Event::operator>(const Event &other) const {
    return other < *this;
}

bool Event::operator<(double value) const {
    return cost < value;
}

bool Event::operator>(int value) const {
    return duration > value;
}

bool Event::operator==(const Event &other) const {
    return title == other.getTitle() && date == other.getDate();
}

bool Event::operator==(double value) const {
    return cost == value;
}

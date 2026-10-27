#pragma once

#include <string>
#include <iostream>
#include "WordInfo.h"

using namespace std;


class KeyValuePair {
private:
    string word; //this is the key
    WordInfo info; //information

public:
    KeyValuePair();

    KeyValuePair(const string& word, int value);

    string getKey() const;

    int getValue() const;

    void setValue(int count);
    void display()const{
        cout << left << setw(15) << word;
        info.display();
    }
    void increment(){info.increment();}
    WordInfo getInfo() const { return info; }
};


KeyValuePair::KeyValuePair() {
    word = "";
}


KeyValuePair::KeyValuePair(const string& word, int count) {
    this->word = word;
    for(int i = 0; i < count; i++){info.increment();}
}


string KeyValuePair::getKey() const {
    return word;
}


int KeyValuePair::getValue() const {
    return info.getCount();
}


void KeyValuePair::setValue(int count) {
    info.setCount(count);
}


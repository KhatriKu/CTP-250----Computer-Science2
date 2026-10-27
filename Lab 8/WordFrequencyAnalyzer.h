#pragma once

#include "KeyValuePair.h"
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

//const int TABLE_SIZE = 10;

class WordFrequencyAnalyzer {
private:
    
    //I added the following to follow a more OOP approach to the hash Maps
    int hashFunctionChoice;
    int computeIndex(const string& word) const {
        switch (hashFunctionChoice) {
            case 1: return hashFunction(word);
            case 2: return hashFunction1(word);
            case 3: return hashFunction2(word);
            case 4: return hashFunction3(word);
        }
        return -1; //end case - this wont need to be dealt with as all input errors will be handled in the driver
    }
//
    
    const int TABLE_SIZE = 50;
    vector<vector<KeyValuePair>> table;

    //Radix hashing? - im not sure but it is ASCII addition
    //GIVEN HASH FUNCTION
    int hashFunction(const string& key) const {
        int hash = 0;
        for (char ch : key)
            hash += ch;
        return hash % TABLE_SIZE;
    }
    
    
    //got this off of http://www.cse.yorku.ca/~oz/hash.html
    int hashFunction1(const string& key)const{
        //Reducing the size of the hash int and the multiplier so that there will not be overflow issues
        int hash = 6;
        
        for(char c : key){
            //keeping the multiplier small as adding the C values will already create a large value for hash and
            //i do not wish for a overflow error and I want the program to be fast by using 'int' rather than a bit slower
            //with 'long' data types.
            hash *=2;
            hash+=(c);
    }
                
        //Im also altering the return so that it returns to a 'bucket' that can be used with the parameritized display function.
        return hash % TABLE_SIZE;
    }
    
    //got this off of https://dev.to/muiz6/string-hashing-in-c-1np3
    int hashFunction2(string key) const{
        int hashCode = 0;
        for (int i = 0; i < key.length(); i++) {
            //using base 2 in order to prevent overflow
            hashCode += key[i] * pow(2, i);
        }
        return hashCode % TABLE_SIZE;
    }
    
    //Made this myself - got inspiration from the identity hash function section of https://en.wikipedia.org/wiki/Hash_function
    int hashFunction3(string key) const{
        int hashCode = key.length() * TABLE_SIZE;
        for(char c : key){
            hashCode += c;
        }
        return hashCode % TABLE_SIZE;
    }


public:
    WordFrequencyAnalyzer(int choice) : table(TABLE_SIZE), hashFunctionChoice(choice) {}

    
    void addWord(const string& word) {
        int index = computeIndex(word);

        for (auto& kvp : table[index]) {
            if (kvp.getKey() == word) {
                kvp.increment();
                return;
            }
        }

        table[index].push_back(KeyValuePair(word, 1));
    }

    void display() const {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "bucket[" << i << "]: ";
            if (table[i].empty()) {
                cout << "(empty)";
            }
            else {
                for (const auto& kvp : table[i]) {
                    cout << "[" << kvp.getKey() << ", " << kvp.getValue() << "] ";
                }
            }
            cout << "\n";
        }
    }
    void displayAnalysis() const {
        cout << left << setw(15) << "Word"
             << setw(10) << "Count"
             << setw(10) << "Common?" << endl;

        cout << string(35, '-') << endl;

        for (int i = 0; i < TABLE_SIZE; i++) {
            for (const auto& kvp : table[i]) {
                cout << left << setw(15) << kvp.getKey();
                kvp.getInfo().display();
                cout << endl;
            }
        }
    }

    void printDistribution()const{
        cout << "Bucket Distribution for hash function: " << hashFunctionChoice << endl;
        for(int i = 0; i < TABLE_SIZE; i++) {
            cout << "Bucket " << setw(5) << i << ": "
            << table[i].size() << " word(s)\n";
            
        }
    }
};

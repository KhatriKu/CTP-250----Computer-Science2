#include "Scholarship.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

 Scholarship::Scholarship(std::string line){
    
    stringstream ss(line);
    string stringScholarship;
    getline(ss, title, '|');
    getline(ss, organization, '|');
    getline(ss, stringScholarship);
    
    scholarshipMoney = stod(stringScholarship);
}

ostream& operator<<(std::ostream &out, const Scholarship &other){
    out << "Scholarship: " << other.title << "| Organization: " << other.organization << "| MONEY $$$: " <<
     other.scholarshipMoney << endl;
     return out;
}
istream& operator>>(std::istream &in, Scholarship &other){
    string line;
    getline(in, line);
    
    if (line.empty()) {
        return in;
    }
    else{
        try {
            stringstream ss(line);
            string stringScholarship;
            getline(ss, other.title, '|');
            getline(ss, other.organization, '|');
            getline(ss, stringScholarship);
            
            other.scholarshipMoney = stod(stringScholarship);
            
        } catch (runtime_error &ex) {
            cout << ex.what() << endl;
        }
    }
    return in;
}

//was unsure if you meant just scholarship or just the data type so i am doing both
/*
 * Comparison basis: double other.getMoney() - double scholarshipMoney
 * Why this makes sense for a MaxHeap: Scholarships should be ranked based on the money they are giving.
 *It would not make sense for a 10$ scholarship from the gov't
 *to be more than a 100,000,000 scholarship from my school for example.
 */
bool Scholarship::operator<(const Scholarship &other) const{
    if (scholarshipMoney < other.getMoney()) {
        return true;
    }else{return false;}
}
/*
 * Comparison basis: double otherScholarship - double scholarshipMoney
 * Why this makes sense for a MaxHeap: Scholarships should be ranked based on the money they are giving.
 *It would not make sense for a 10$ scholarship from the gov't
 *to be more than a 100,000,000 scholarship from my school for example.
 */
bool Scholarship::operator>(const Scholarship &other) const{
    if (scholarshipMoney > other.getMoney()) {
        return true;
    }else{return false;}
}
/*
 * Comparison basis: double otherScholarship - double scholarshipMoney
 * Why this makes sense for a MaxHeap: Scholarships should be ranked based on the money they are giving.
 *It would not make sense for a 10$ scholarship from the gov't
 *to be more than a 100,000,000 scholarship from my school for example.
 */
bool Scholarship::operator<(double otherScholarship) const{
    if (scholarshipMoney < otherScholarship) {
        return true;
    }else{return false;}
}
/*
 * Comparison basis: double otherScholarship - double scholarshipMoney
 * Why this makes sense for a MaxHeap: Scholarships should be ranked based on the money they are giving.
 *It would not make sense for a 10$ scholarship from the gov't
 *to be more than a 100,000,000 scholarship from my school for example.
 */
bool Scholarship::operator>(double otherScholarship) const{
    if (scholarshipMoney > otherScholarship) {
        return true;
    }else{return false;}
}

bool Scholarship::operator==(const Scholarship &other) const{
    if (scholarshipMoney == other.getMoney()) {
        return true;
    }else{return false;}
}
bool Scholarship::operator==(double otherScholarship) const{
    if (scholarshipMoney == otherScholarship) {
        return true;
    }else{return false;}
}



#pragma once
#include <string>
#include <iostream>

class Scholarship {
private:
    std::string organization;
    std::string title;
    double scholarshipMoney;
    
public:
    
     Scholarship() : organization(""), title(""), scholarshipMoney(0.0){}
    
     Scholarship(std::string line);
     Scholarship(std::string org, std::string titleParam, double scholarship) : organization(org), title(titleParam), scholarshipMoney(scholarship){}
    
     double getMoney()const{return scholarshipMoney;}
     std::string getTitle()const{return title;}
     std::string getOrganization()const{return organization;}
     void setMoney(double scholarship){ scholarshipMoney = scholarship;}
     void setTitle(std::string titleParam){title = titleParam;}
     void setOrganization(std::string organizationParam){organization = organizationParam;}
    
    friend std::ostream& operator<<(std::ostream &out, const Scholarship &other);
    friend std::istream& operator>>(std::istream &in, Scholarship &other);
    
    //was unsure if you meant just scholarship or just double so i am doing both
    bool operator<(const Scholarship &other) const;
    bool operator>(const Scholarship &other) const;
    
    bool operator<(double otherScholarship) const;
    
    bool operator>(double otherScholarship) const;
    
    bool operator==(const Scholarship &other) const;
    bool operator==(double otherScholarship) const;
    
    
    ~Scholarship() {
    }
};
    
    

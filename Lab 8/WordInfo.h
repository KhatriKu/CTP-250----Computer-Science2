#include <iostream>
#include <iomanip>
#include <string>

class WordInfo {
private:
    int count;
    bool isCommon;
public:
    WordInfo() : count(0), isCommon(false) {}
    //I realized that the overloading of  the boolean is kind of redundant
    WordInfo(int c, bool i) : count(c), isCommon(i) {}
    int getCount()const{return count;}
    void setCount(int count){this->count=count;}
    bool getCommon()const{return isCommon;}
    //No setter needed for isCommon.
    void increment(){
        count++;
        if(count>3){
            isCommon=true;
        }
    }
    void display()const{
        std::string stringIsCommon;
        if(isCommon){
            stringIsCommon = "yes";
        }
        else{
            stringIsCommon = "no";
        }
        
        std::cout << std::left
                 << std::setw(10) << count
                 << std::setw(10) << stringIsCommon;
    }
};
    

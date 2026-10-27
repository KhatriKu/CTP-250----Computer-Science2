//==============Visitor.h======================
//the abstract super class (interface)
#pragma once
class Node; //forward reference
//Visitor needs to know about Node, but not what it does
//added typename for versatility
template <typename T>
class Visitor {
public:
Visitor() {}
~Visitor() {}
    //edited the line because all the operations dont require the class but only require the data
virtual void visit(const T& data) = 0;
};

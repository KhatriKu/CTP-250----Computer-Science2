/**
 * @file StreamingTitle.cpp
 * Implementation file for the StreamingTitle class.
 *
 * Contains the implementation of the printAll method.
 * All other methods are implemented inline in the header.
 *
 * Author: Kushal Khatri
 */

#include <iostream>
#include <vector>
#include "StreamingTitle.h"

using namespace std;


//see StreamingTitle.h for javadoc comment
void StreamingTitle::printAll(std::vector<StreamingTitle>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        vector[i].print();
    }
}

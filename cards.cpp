//cards.cpp
//Authors: Lizette Crooks 
//Implementation of the classes defined in cards.h

#include "cards.h"

#include <iostream>
using namespace std;

// constructor
CardBST::CardBST() : root(0) { }

// destructor
CardBST::~CardBST() {
    clear(root);
}

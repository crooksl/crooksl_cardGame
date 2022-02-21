// implementation of functions declared in utility.h
#include "utility.h"

#include <iostream>
using namespace std;

// destructor
Card::~Card() {}

// getters
char Card::getSuit() const {
    return su;
}

int Card::getNumber() const {
    return num;
}

// setters
void Card::setSuit(char newSuit) {
    su = newSuit;
}

void Card::setNumber(int newNumber) {
    num = newNumber;
}
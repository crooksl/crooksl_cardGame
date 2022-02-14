// implementation of functions declared in ultility.h
#include "ultility.h"

#include <iostream>
using namespace std;

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
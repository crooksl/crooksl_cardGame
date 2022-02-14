#include "ultility.h"

#include <iostream>
using namespace std;

char Card::getSuit() const {
    return su;
}

int Card::getNumber() const {
    return num;
}
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
using namespace std;

class Card {
    public:
        Card(char suit = '0', int number = 0): su(suit), num(number) {}
        char getSuit() const;
        int getNumber() const;
        void setSuit(char newSuit);
        void setNumber(int newNumber);
        
    private:
        char su;
        int num;
};

#endif
//cards.h
//Authors: Your name and your partner's name
//All class declarations go here
//BSTCard

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
using namespace std;

#include "ultility.h"

class CardBST {

    public:
        CardBST();      // constructor
        ~CardBST();     // destructor

        friend bool operator==(const Card& c1, const Card& c2);
        friend bool operator<(const Card& c1, const Card& c2);
        friend bool operator>(const Card& c1, const Card& c2);

        bool insertCard(char suit, int number);             // insert value; return false if duplicate
        bool containsCard(char suit, int number) const;     // true if value is in tree
        int getSuccessor(int value) const;      // TODO returns the successor value of the given value or 0 if there is none
        int getPredecessor(int value) const;      // TODO returns the predecessor  value of the given value or 0 if there is none
        bool removeCard(int value);             // TODO deletes the Node containing the given value from the tree

    private:
        struct Node {
            // declare card
            Card newCard;
	        Node *left, *right, * parent;
            //useful constructor
            //nCard(n, s)
            Node(char su = '0', int num = 0) : newCard(su,num), left(0), right(0), parent(0) { }
        };

        Node* getNodeFor(char suit, int number, Node* n) const; // returns the node for a given value or NULL if none exists
        void clear(Node *n); // for destructor
        bool insertCard(char suit, int number, Node *n); // note: overloading names for simplicity
        Node* getSuccessorNode(int value) const;   // TODO returns the Node containing the successor of the given value
        Node* getPredecessorNode(int value) const;   // TODO returns the Node containing the predecessor of the given value

        Node *root;

};







#endif
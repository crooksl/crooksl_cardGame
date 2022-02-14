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

        bool insertCard(int value);             // TODO insert value; return false if duplicate
        bool containsCard(int value) const;     // TODO true if value is in tree
        int getSuccessor(int value) const;      // TODO returns the successor value of the given value or 0 if there is none
        bool removeCard(int value);             // TODO deletes the Node containing the given value from the tree

    private:
        struct Node {
            // declare card
            Card newCard;
	        char suit;
            int number;
	        Node *left, *right, * parent;
            //useful constructor
            //nCard(n, s)
            Node(char su = '0', int num = 0) : newCard(su,num), left(0), right(0), parent(0) { }
        };

        Node* getNodeFor(int value, Node* n) const; // TODO returns the node for a given value or NULL if none exists
        void clear(Node *n); // TODO for destructor
        bool insert(int value, Node *n); // TODO note overloading names for simplicity
        Node* getSuccessorNode(int value) const;   // TODO returns the Node containing the successor of the given value

        Node *root;

};







#endif
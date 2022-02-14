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

//destructor helper
void CardBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// overloaded == operator
bool operator==(const Card& c1, const Card& c2) {
    if ( c1.getSuit() == c2.getSuit() && c1.getNumber() == c2.getNumber() ) {
        return true;
    }
    else {
        return false;
    }
}

// overloaded < operator
// note: hearts > spades > diamonds > clubs
bool operator<(const Card& c1, const Card& c2) {
    if (c1 == c2) {
        return false;
    }
    else if (c1.getSuit() == 'c') {
        return true;
    }
    else if (c1.getSuit() == 'd') {
        if (c2.getSuit() == 's' || c2.getSuit() == 'h') {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

// overloaded > operator
// note: hearts > spades > diamonds > clubs
bool operator>(const Card& c1, const Card& c2) {
    if (c1 == c2) {
        return false;
    }
    else if (c1.getSuit() == 'h') {
        return true;
    }
    else if (c1.getSuit() == 's') {
        if (c2.getSuit() == 'd' || c2.getSuit() == 'c') {
            return true;
        }
        else {
            return false;
        }
    }
    else if (c1.getSuit() == 'd') {
        if (c2.getSuit() == 'c') {
            return true;
        }
        else {
            return false;
        }
    }
    return 0;
}

// insert value in tree; return false if duplicate
bool CardBST::insertCard(char suit, int number) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(suit, number);
	return true;
    }
    // otherwise use recursive helper
    return insertCard(suit, number, root);
}

// recursive helper for insert (assumes n is never 0)
bool CardBST::insertCard(char suit, int number, Node *n) {
    Card iCard {suit, number};
    if (iCard == n->newCard) {
	    return false;
    }
    if (iCard < n->newCard) {
	    if (n->left)
	        return insertCard(suit, number, n->left);
	    else {
	        n->left = new Node(suit, number);
	        n->left->parent = n;
	        return true;
	    }
    }
    else {
	    if (n->right)
	        return insertCard(suit, number, n->right);
	    else {
	        n->right = new Node(suit, number);
	        n->right->parent = n;
	        return true;
	    }
    }
}

// (DONE) returns the node for a given value or NULL if none exists
CardBST::Node* CardBST::getNodeFor(char suit, int number, Node* n) const{
    if (n == nullptr) {
        return nullptr;
    }
    Card iCard {suit, number};
    if (n->newCard == iCard) {
        return n;
    }
    if (iCard < n->newCard) {
        return getNodeFor(suit, number, n->left);
    }
    else if (iCard > n->newCard) {
        return getNodeFor(suit, number, n->right);
    }
    return 0;
}

// (DONE) returns true if value is in the tree; false if not
bool CardBST::containsCard(char suit, int number) const {
    if (getNodeFor(suit, number, root)) {
        return true;
    }
    else {
        return false;
    }
}
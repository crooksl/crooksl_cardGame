// cards.h
// Lizette Crooks
// perm #4087193

/* All class declarations go here
 ->CardBST
*/

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
using namespace std;

#include "utility.h"

class CardBST {

    public:
        CardBST();      // constructor
        ~CardBST();     // destructor

        friend bool operator==(const Card& c1, const Card& c2);     // overloaded ==
        friend bool operator<(const Card& c1, const Card& c2);      // overloaded <
        friend bool operator>(const Card& c1, const Card& c2);      // overloaded >

        void printPreOrder() const;                             // prints BST tree in preorder
        void printInOrder() const;
        bool insertCard(char suit, int number);                 // insert value; return false if duplicate
        bool containsCard(char suit, int number) const;         // true if value is in tree
        Card getSuccessor(char suit, int number) const;         // returns the successor value of the given value or 0 if there is none
        Card getPredecessor(char suit, int number) const;       // returns the predecessor  value of the given value or 0 if there is none
        bool removeCard(char suit, int number);                 // deletes the Node containing the given value from the tree

        friend void game(CardBST& bst1, CardBST& bst2);
        friend bool hasMatch(CardBST& bst1, CardBST& bst2);
        friend Card aMatchingCard(CardBST& bst1, CardBST& bst2);
        friend Card bMatchingCard(CardBST& bst1, CardBST& bst2);
        Card getMin() const;
        Card getMax() const;

        friend char intToFaceCard(Card c1);




    private:
        struct Node {
            // declare card
            Card newCard;
	        Node *left, *right, * parent;
            
            //useful constructor
            //newCard(n, s) <- really should change name from newCard to nodeCard/cardNode or something
            Node(char su = '0', int num = 0) : newCard(su,num), left(0), right(0), parent(0) { }
        };

        void printPreOrder(Node *n) const;    
        void printInOrder(Node *n) const;                      
        Node* getNodeFor(char suit, int number, Node* n) const;     // returns the node for a given value or NULL if none exists
        void clear(Node *n);                                        // for destructor
        bool insertCard(char suit, int number, Node *n);            // note: overloading names for simplicity
        Node* getSuccessorNode(char suit, int number) const;        // returns the Node containing the successor of the given value
        Node* getPredecessorNode(char suit, int number) const;      // returns the Node containing the predecessor of the given value

        Card getMinCard(Node *n) const;
        Card getMaxCard(Node *n) const;

        Node *root;

};

#endif
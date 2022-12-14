// Lizette Crooks
// cards.cpp

/* TODO:
    1. implement bst classes ✓
    2. write test code for bst ✓
    3. work out ostream stuff ✓
    4. fix remove function ✓
    5. write game function ✓
    6. write test code for game function ✓
    7. check for memory leaks (valgrind) ✓
*/

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
    //n = nullptr;
    }
    n = nullptr;
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
    if (c1.getSuit() == c2.getSuit()) {
        if (c1.getNumber() < c2.getNumber()) {
            return true;
        }
        else {
            return false;
        }
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
    else if (c1.getSuit() == 's') {
        if (c2.getSuit() == 'h') {
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
    if (c1.getSuit() == c2.getSuit()) {
        if (c1.getNumber() > c2.getNumber()) {
            return true;
        }
        else {
            return false;
        }
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

char intToFaceCard(Card c1) {
    if (c1.getNumber() == 0) {
        return 'a';
    }
    else if (c1.getNumber() == 11) {
        return 'j';
    }
    else if (c1.getNumber() == 12) {
        return 'q';
    }
    else {
        return 'k';
    }
    return 0;
}

// print tree data pre-order
void CardBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void CardBST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->newCard.getSuit() << " " << n->newCard.getNumber() << endl;
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order
void CardBST::printInOrder() const {
    printInOrder(root);
}

// recursive helper for printInOrder()
void CardBST::printInOrder(Node *n) const {
    if (n) {
	printInOrder(n->left);
    cout << n->newCard.getSuit() << " ";

    if (n->newCard.getNumber() == 0 || n->newCard.getNumber() == 11 || n->newCard.getNumber() == 12 || n->newCard.getNumber() == 13) {
        cout << intToFaceCard(n->newCard) << endl; 
    }
    else {
        cout << n->newCard.getNumber() << endl;
    }
    
	printInOrder(n->right);
    }
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

// returns the node for a given value or NULL if none exists
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
    else {
        return getNodeFor(suit, number, n->right);
    }
    return 0;
}
// returns true if value is in the tree; false if not
bool CardBST::containsCard(char suit, int number) const {
    if (getNodeFor(suit, number, root)) {
        return true;
    }
        return false;
}

// returns the Node containing the predecessor of the given value
CardBST::Node* CardBST::getPredecessorNode(char suit, int number) const{
    Node *n = getNodeFor(suit, number, root);
    if (!n) {
        return nullptr;
    }
    if (n->left != nullptr) {
        n = n->left;
        while (n->right) {
            n = n->right;
        }
        return n;
    }
    else {
        //find parent that is > node
        Node *pre = n->parent;
        while (pre && pre->left == n) {
            n = pre;
            pre = pre->parent;
        }
        return pre;
    }
    return 0;
}
// returns the predecessor value of the given value or 0 if there is none
// was returning int n->info, changed it to be card n->newCard
Card CardBST::getPredecessor(char suit, int number) const{
    Node *n = getPredecessorNode(suit, number);
    if (n == nullptr) {
        return 0;
    }
    else {
        return n->newCard;
    }
    
    //return 0; 
}

// returns the Node containing the successor of the given value
CardBST::Node* CardBST::getSuccessorNode(char suit, int number) const{
    Node *n = getNodeFor(suit, number, root);
    if (!n) {
        return nullptr;
    }
    if (n->right != nullptr) {
        n = n->right;
        while (n->left) {
            n = n->left;
        }
        return n;
    }
    else {
        //find parent that is > node
        Node *suc = n->parent;
        while (suc && suc->right == n) {
            n = suc;
            suc = suc->parent;
        }
        return suc;
    }
    return 0;
}
// returns the successor value of the given value or 0 if there is none
// was returning int n->info, changed it to be card n->newCard
Card CardBST::getSuccessor(char suit, int number) const{
    Node *n = getSuccessorNode(suit, number);
    if (n == nullptr) {
        return 0;
    }
    else {
        return n->newCard;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool CardBST::removeCard(char suit, int number){
    Node *n = getNodeFor(suit, number, root);
    // no node exists
    bool canRemove = false;
    if (!n) {
        return canRemove;
    }

    // leaf node case
    if (!n->left && !n->right) {
        if (n != root) {
            if (n == n->parent->left) {
                n->parent->left = nullptr;
            }
            else {
                n->parent->right = nullptr;
            }
        }
        else {
            root = nullptr;
        }
        canRemove = true;
        delete n;
    }
    // node has 2 children
    else if (n->left && n->right) {
        Node *sucNode = getSuccessorNode(n->newCard.getSuit(), n->newCard.getNumber());
        char sucSuit = sucNode->newCard.getSuit();
        int sucNumber = sucNode->newCard.getNumber();
        removeCard(sucSuit, sucNumber);
        n->newCard.setSuit(sucSuit);
        n->newCard.setNumber(sucNumber);
        canRemove = true;
    }
    
    else {
    // node has only one child
        if (n->left) {
            if (n != root) {
                if (n == n->parent->left) {
                    n->parent->left = n->left;
                    n->left->parent = n->parent;
                }
                else {
                    n->parent->right = n->left;
                    n->left->parent = n->parent;
                }
            }
            else {
                root = n->left;
            }
        }
        else if (n->right) {
            if (n != root) {
                if (n == n->parent->left) {
                    n->parent->left = n->right;
                    n->right->parent = n->parent;
                }
                else {
                    n->parent->right = n->right;
                    n->right->parent = n->parent;
                }
            }
            else {
                root = n->right;
            }
        }
        canRemove = true;
        delete n;
    }
    return canRemove;
}

// helper for getMin
Card CardBST::getMinCard(Node *n) const {
    Card minCard = n->newCard;
    while (n) {
        if (n->newCard < minCard) {
            minCard = n->newCard;
        }
        n = n->left;
    }
    return minCard;
}

// gets the minimum card in bst 
Card CardBST::getMin() const {
    Card min = getMinCard(root);
    return min;
}

// helper for getMax
Card CardBST::getMaxCard(Node *n) const {
    Card maxCard = n->newCard;
    while (n) {
        if (n->newCard > maxCard) {
            maxCard = n->newCard;
        }
        n = n->right;
    }
    return maxCard;
}

// gets the max card in bst
Card CardBST::getMax() const {
    Card min = getMaxCard(root);
    return min;
}

// returns true if a match exists between two bst's
bool hasMatch(CardBST& bst1, CardBST& bst2) {
    if (bst1.root == nullptr || bst2.root == nullptr) {
        return false;
    }

    Card aMinCard = bst1.getMin();
    
    while ( !(aMinCard == 0) ) {
        if (bst2.containsCard(aMinCard.getSuit(), aMinCard.getNumber())) {
            //delete aMinCard;
            return true;
        }
        else {
            aMinCard = bst1.getSuccessor(aMinCard.getSuit(), aMinCard.getNumber());
        }
    }

    return false;
}

// finds the 1st matching card between two bst's starting at min (alice method)
Card aMatchingCard(CardBST& bst1, CardBST& bst2) {

    Card aMinCard = bst1.getMin();
    
    while ( !(aMinCard == 0) ) {
        if (bst2.containsCard(aMinCard.getSuit(), aMinCard.getNumber())) {
            return aMinCard;
        }
        else {
            aMinCard = bst1.getSuccessor(aMinCard.getSuit(), aMinCard.getNumber());
        }
    }

    return 0;
}

// finds the 1st matching card between two bst's starting at max (bob method)
Card bMatchingCard(CardBST& bst1, CardBST& bst2) {

    Card bMaxCard = bst2.getMax();
    
    while ( !(bMaxCard == 0) ) {
        if (bst1.containsCard(bMaxCard.getSuit(), bMaxCard.getNumber())) {
            return bMaxCard;
        }
        else {
            bMaxCard = bst2.getPredecessor(bMaxCard.getSuit(), bMaxCard.getNumber());
        }
    }

    return 0;
}


// bst1 = alice, bst2 = bob 
void game (CardBST& bst1, CardBST& bst2) {
    int count = 0;
    
    while (hasMatch(bst1, bst2)) {
        // alice's turn
        if ((count % 2) == 0) {
            Card aMatch = aMatchingCard(bst1, bst2);
            cout << "Alice picked matching card " << aMatch.getSuit() << " ";
            
            if (aMatch.getNumber() == 0 || aMatch.getNumber() == 11 || aMatch.getNumber() == 12 || aMatch.getNumber() == 13) {
                cout << intToFaceCard(aMatch) << endl; 
            }
            else {
                cout << aMatch.getNumber() << endl;
            }

            bst1.removeCard(aMatch.getSuit(), aMatch.getNumber());
            bst2.removeCard(aMatch.getSuit(), aMatch.getNumber());
        }

        // bob's turn
        else {
            Card bMatch = bMatchingCard(bst1, bst2);
            cout << "Bob picked matching card " << bMatch.getSuit() << " ";

            if (bMatch.getNumber() == 0 || bMatch.getNumber() == 11 || bMatch.getNumber() == 12 || bMatch.getNumber() == 13) {
                cout << intToFaceCard(bMatch) << endl; 
            }
            else {
                cout << bMatch.getNumber() << endl;
            } 

            bst1.removeCard(bMatch.getSuit(), bMatch.getNumber());
            bst2.removeCard(bMatch.getSuit(), bMatch.getNumber());
        }

        count++;
    }

    cout << endl;
    cout << "Alice's cards:" << endl;
    bst1.printInOrder();
    cout << endl;
    cout << "Bob's cards:" << endl;
    bst2.printInOrder();

}
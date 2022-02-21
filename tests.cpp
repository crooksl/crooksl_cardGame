#include <iostream>
using namespace std;

#include "cards.h"

int main() {

    CardBST bst1;

    // insert function
    bst1.insertCard('h', 3);
    bst1.insertCard('s', 10);
    bst1.insertCard('c', 0);    // 0 = ace
    bst1.insertCard('c', 3);
    bst1.insertCard('s', 5);
    bst1.insertCard('h', 10);
    bst1.insertCard('d', 0);    // 0 = ace

    // print in preorder
    bst1.printPreOrder();

    // find/contains function
    cout << "  contains h 3? " << (bst1.containsCard('h', 3) ? "Y" : "N") << endl;
	cout << "  contains s 10? " << (bst1.containsCard('s', 10) ? "Y" : "N") << endl;
    cout << "  contains c 0? " << (bst1.containsCard('c', 0) ? "Y" : "N") << endl;
    cout << "  contains c 3? " << (bst1.containsCard('c', 3) ? "Y" : "N") << endl;
    cout << "  contains s 5? " << (bst1.containsCard('s', 5) ? "Y" : "N") << endl;
    cout << "  contains h 10? " << (bst1.containsCard('h', 10) ? "Y" : "N") << endl;
    cout << "  contains d 0? " << (bst1.containsCard('d', 0) ? "Y" : "N") << endl;

    cout << "  contains d 5? " << (bst1.containsCard('d', 5) ? "Y" : "N") << endl;
    cout << "  contains m 10? " << (bst1.containsCard('m', 10) ? "Y" : "N") << endl;
    cout << "  contains h 9? " << (bst1.containsCard('h', 9) ? "Y" : "N") << endl;

    // predecessor function
    cout << "  predecessor of h 3 is: " << bst1.getPredecessor('h', 3).getSuit() << " " << bst1.getPredecessor('h', 3).getNumber() << endl;
	cout << "  predecessor of s 10 is: " << bst1.getPredecessor('s', 10).getSuit() << " " << bst1.getPredecessor('s', 10).getNumber() << endl;
	cout << "  predecessor of c 0 is: " << bst1.getPredecessor('c', 0).getSuit() << " " << bst1.getPredecessor('c', 0).getNumber() << endl;
	
    // successor function
    cout << "  successor of c 3 is: " << bst1.getSuccessor('c', 3).getSuit() << " " << bst1.getSuccessor('c', 3).getNumber() << endl;
    cout << "  successor of s 5 is: " << bst1.getSuccessor('s', 5).getSuit() << " " << bst1.getSuccessor('s', 5).getNumber() << endl;
	cout << "  successor of h 10 is: " << bst1.getSuccessor('h', 10).getSuit() << " " << bst1.getSuccessor('h', 10).getNumber() << endl;

    // min function
    // cout << "  min of bst1 is: " << bst1.getMinCardNode(root).getSuit() << " " << bst1.getMaxCardNode(root).getNumber() << endl;

    // remove function
    cout << "  removing d 0   " << (bst1.removeCard('d', 0) ? "Y" : "N") << endl;
	cout << "  removing c 3   " << (bst1.removeCard('c', 3) ? "Y" : "N") << endl;
	cout << "  removing h 3   " << (bst1.removeCard('h', 3) ? "Y" : "N") << endl;
	cout << "  removing m 3 (should not work)   " << (bst1.removeCard('m', 3) ? "Y" : "N") << endl;

}
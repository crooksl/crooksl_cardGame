#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#include <cstring>
#include "cards.h"

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  CardBST alice;
  while (getline (cardFile1, line) && (line.length() > 0)){

    // can automatically convert to char
    char aSuit;
    aSuit = line[0];

    // check the string to see if it contains char, else convert to int (check for 10!)
    int aNumber;
    // a = 0, j = 11, q = 12, k = 13
    if (isalpha(line[2])) {
      if (line[2] == 'a') {
        aNumber = 0;
      }
      else if (line[2] == 'j') {
        aNumber = 11;
      }
      else if (line[2] == 'q') {
        aNumber = 12;
      }
      else {
        aNumber = 13;
      }
    }
    else {
      if ("10" == line.substr(2, line.length() - 2)) {
        aNumber = 10;
      }
      else {
        // have to do num - 48 otherwise it gives ascii position!
        aNumber = line[2] - 48;
      }
    }

    //insert card to alice
    alice.insertCard(aSuit, aNumber);

  }
  cardFile1.close();

  CardBST bob;
  while (getline (cardFile2, line) && (line.length() > 0)){

    char aSuit;
    aSuit = line[0];

    int aNumber;
    // a = 0, j = 11, q = 12, k = 13
    if (isalpha(line[2])) {
      if (line[2] == 'a') {
        aNumber = 0;
      }
      else if (line[2] == 'j') {
        aNumber = 11;
      }
      else if (line[2] == 'q') {
        aNumber = 12;
      }
      else {
        aNumber = 13;
      }
    }
    else {
      if ("10" == line.substr(2, line.length() - 2)) {
        aNumber = 10;
      }
      else {
        aNumber = line[2] - 48;
      }
    }
    
    bob.insertCard(aSuit, aNumber);

  }
  cardFile2.close();
  




  
  return 0;
}

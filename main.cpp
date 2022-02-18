#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#include "cards.cpp"

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
  // read alice file
  while (getline (cardFile1, line) && (line.length() > 0)){
    char aSuit;
    // (for char) can automatically convert to char
    int aNumber;
    // (for number) check the string to see if it contains char, else convert to int
  }
  cardFile1.close();

  CardBST bob;
  // read bob file
  while (getline (cardFile2, line) && (line.length() > 0)){

  }
  cardFile2.close();
  
  
  return 0;
}

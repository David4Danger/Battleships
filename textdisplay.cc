#include "textdisplay.h"
#include <iostream>
using std::cout;
using std::endl;


TextDisplay::TextDisplay() : theDisplay() {

  char temp = '\0';
  char** mydisplaymatrix = new char*[11];
  for (int col = 0; col < 11; col++) {
    mydisplaymatrix[col] = new char[11];
    for (int row = 0; row < 11; row++) {
      mydisplaymatrix[col][row] = temp;//change when we initialize a game with notifications
    }
  }
  theDisplay = mydisplaymatrix;
}//end constr

TextDisplay::~TextDisplay() {
  for (int col = 0; col < 11; col++) {
    delete [] theDisplay[col];
  }
  delete [] theDisplay;
}

void TextDisplay::notify(int col, int row, char ch) {
  theDisplay[col][row] = ch;//make the change
}

void TextDisplay::print() {
  cout << " ";//line up the first col
  for (int col = 0; col < 11; col++) {
    for (int row = 0; row < 11; row++) {
      cout << theDisplay[col][row] << " ";
    }
    cout << endl;//after each row
  }
}

#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <string>

using std::string;

static const int MAX_ROWS = 11;//Label, 1-10
static const int MAX_COLS = 11;//Label, A-J

class TextDisplay {
  char **theDisplay;//Matrix of chars
public:
  TextDisplay();
  ~TextDisplay();

  void notify(int col, int row, char ch);//notifies matrix position [row][col] to update to ch
  bool wongame();//returns true if a player has won the game
  void print();//prints out the display, call after each turns
};

#endif

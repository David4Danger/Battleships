#ifndef __CELL_H__
#define __CELL_H__
#include "textdisplay.h"

class Cell {
  TextDisplay * mydisplay;
  int state;
  int row, col;
public:
  void notifyPDisplay();//Changes the players textdisplay to the current state of cell
  void notifyEDisplay();//Changes the opponents textdisplay to current state of cell
  Cell();
  int getState();//Returns the current state of the cell
  void setPState(int change);//Sets the state of the cell to change for a player cell
  void setEState(int change);//Sets the state of the cell to change for an enemy cell
  void setCoords(int col, int row);//Sets the grid coordinates for the cell
  void addDisplay(TextDisplay * display);//Adds the appropriate textdisplay to the cell
};

#endif

/*Cell states:
0: Label (i.e all the cells in column 0 and row 0)
1: Empty space
2: Empty Shot space
3: Secret Ship space
4: Shot Ship space*/

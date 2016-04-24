#ifndef __GAME_H__
#define __GAME_H__
#include "cell.h"
#include "textdisplay.h"
#include <string>

class Game {
  Cell** playergrid;//Players grid of cells
  Cell** enemygrid;//Opponents grid of cells
  TextDisplay* playerdisplay;//Players textdisplay
  TextDisplay* enemydisplay;//Opponents textdisplay

public:
  Game();
  ~Game();

  void pchange(int row, int col, int state);//Changes appropriate player cell to the value state
  void echange(int row, int col, int state);//Changes appropriate enemy cell to the value state
  void print();//Prints both gameboards
  void playerattack(std::string command);//Initiates a player attacking opponent phase
  void enemyattack(int col, int rol);//Initiates an enemy attacking player phase
  bool playerwon();//Returns true if the player has destroyed all opponent ships
  bool enemywon();//Returns true if the enemy has destroyed all player ships
};

#endif

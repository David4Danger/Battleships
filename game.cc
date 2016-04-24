#include "game.h"
#include <iostream>
#include <string>
#include <cstdlib>//srand, rand
using std::cout;
using std::endl;
using std::string;

Game::Game(): playergrid(), enemygrid(), playerdisplay(), enemydisplay() {
  srand(4);

  //Handle the players TD/Cell
  TextDisplay* playerTD = new TextDisplay();
  Cell** playerGG = new Cell*[11];
  for (int col = 1; col < 11; col++) {
    playerGG[col] = new Cell[11];
    for (int row = 1; row < 11; row++) {
      Cell mycell;
      mycell.addDisplay(playerTD);
      mycell.setCoords(col,row);
      mycell.setPState(1);//default to an empty space
      playerGG[col][row] = mycell;
    }
  }

  int shipX, shipY;
  bool CAspawn = false, BAspawn = false, CRspawn = false, SUspawn = false, DEspawn = false;
  while (!CAspawn) {//Spawn Carrier
    shipX = (1+(rand() % 10));
    shipY = (1+(rand() % 10));

    if ( (playerGG[shipY - 1][shipX].getState() == 1) && (playerGG[shipY - 2][shipX].getState() == 1) &&
    (playerGG[shipY - 3][shipX].getState() == 1) && (playerGG[shipY - 4][shipX].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY - 1][shipX].setPState(3);
      playerGG[shipY - 2][shipX].setPState(3);
      playerGG[shipY - 3][shipX].setPState(3);
      playerGG[shipY - 4][shipX].setPState(3);
      CAspawn = true;
    } else if ( (playerGG[shipY][shipX + 1].getState() == 1) && (playerGG[shipY][shipX + 2].getState() == 1) &&
    (playerGG[shipY][shipX + 3].getState() == 1) && (playerGG[shipY][shipX + 4].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY][shipX + 1].setPState(3);
      playerGG[shipY][shipX + 2].setPState(3);
      playerGG[shipY][shipX + 3].setPState(3);
      playerGG[shipY][shipX + 4].setPState(3);
      CAspawn = true;
    } else if ( (playerGG[shipY + 1][shipX].getState() == 1) && (playerGG[shipY + 2][shipX].getState() == 1) &&
    (playerGG[shipY + 3][shipX].getState() == 1) && (playerGG[shipY + 4][shipX].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY + 1][shipX].setPState(3);
      playerGG[shipY + 2][shipX].setPState(3);
      playerGG[shipY + 3][shipX].setPState(3);
      playerGG[shipY + 4][shipX].setPState(3);
      CAspawn = true;
    } else if ( (playerGG[shipY][shipX - 1].getState() == 1) && (playerGG[shipY][shipX - 2].getState() == 1) &&
    (playerGG[shipY][shipX - 3].getState() == 1) && (playerGG[shipY][shipX - 4].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY][shipX - 1].setPState(3);
      playerGG[shipY][shipX - 2].setPState(3);
      playerGG[shipY][shipX - 3].setPState(3);
      playerGG[shipY][shipX - 4].setPState(3);
      CAspawn = true;
    }
  }

  while (!BAspawn) {//Spawn Battleship
    shipX = (1+(rand() % 10));
    shipY = (1+(rand() % 10));

    if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY][shipX + 1].getState() == 1) &&
    (playerGG[shipY][shipX + 2].getState() == 1) && (playerGG[shipY][shipX + 3].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY][shipX + 1].setPState(3);
      playerGG[shipY][shipX + 2].setPState(3);
      playerGG[shipY][shipX + 3].setPState(3);
      BAspawn = true;
    } else if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY - 1][shipX].getState() == 1) &&
    (playerGG[shipY - 2][shipX].getState() == 1) && (playerGG[shipY - 3][shipX].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY - 1][shipX].setPState(3);
      playerGG[shipY - 2][shipX].setPState(3);
      playerGG[shipY - 3][shipX].setPState(3);
      BAspawn = true;
    } else if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY + 1][shipX].getState() == 1) &&
    (playerGG[shipY + 2][shipX].getState() == 1) && (playerGG[shipY + 3][shipX].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY + 1][shipX].setPState(3);
      playerGG[shipY + 2][shipX].setPState(3);
      playerGG[shipY + 3][shipX].setPState(3);
      BAspawn = true;
    } else if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY][shipX - 1].getState() == 1) &&
    (playerGG[shipY][shipX - 2].getState() == 1) && (playerGG[shipY][shipX - 3].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY][shipX - 1].setPState(3);
      playerGG[shipY][shipX - 2].setPState(3);
      playerGG[shipY][shipX - 3].setPState(3);
      BAspawn = true;
    }
  }

  while (!CRspawn) {//Spawn Cruiser
    shipX = (1+(rand() % 10));
    shipY = (1+(rand() % 10));

    if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY - 1][shipX].getState() == 1) &&
    (playerGG[shipY - 2][shipX].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY - 1][shipX].setPState(3);
      playerGG[shipY - 2][shipX].setPState(3);
      CRspawn = true;
    } else if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY][shipX + 1].getState() == 1) &&
    (playerGG[shipY][shipX + 2].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY][shipX + 1].setPState(3);
      playerGG[shipY][shipX + 2].setPState(3);
      CRspawn = true;
    } else if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY + 1][shipX].getState() == 1) &&
    (playerGG[shipY + 2][shipX].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY + 1][shipX].setPState(3);
      playerGG[shipY + 2][shipX].setPState(3);
      CRspawn = true;
    } else if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY][shipX - 1].getState() == 1) &&
    (playerGG[shipY][shipX - 2].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY][shipX - 1].setPState(3);
      playerGG[shipY][shipX - 2].setPState(3);
      CRspawn = true;
    }
  }

  while (!SUspawn) {//Spawn Submarine
    shipX = (1+(rand() % 10));
    shipY = (1+(rand() % 10));

    if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY - 1][shipX].getState() == 1) &&
    (playerGG[shipY - 2][shipX].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY - 1][shipX].setPState(3);
      playerGG[shipY - 2][shipX].setPState(3);
      SUspawn = true;
    } else if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY][shipX + 1].getState() == 1) &&
    (playerGG[shipY][shipX + 2].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY][shipX + 1].setPState(3);
      playerGG[shipY][shipX + 2].setPState(3);
      SUspawn = true;
    } else if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY + 1][shipX].getState() == 1) &&
    (playerGG[shipY + 2][shipX].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY + 1][shipX].setPState(3);
      playerGG[shipY + 2][shipX].setPState(3);
      SUspawn = true;
    } else if ( (playerGG[shipY][shipX].getState() == 1) && (playerGG[shipY][shipX - 1].getState() == 1) &&
    (playerGG[shipY][shipX - 2].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY][shipX - 1].setPState(3);
      playerGG[shipY][shipX - 2].setPState(3);
      SUspawn = true;
    }
  }

  while (!DEspawn) {//Spawn Destroyer
    shipX = (1+(rand() % 10));
    shipY = (1+(rand() % 10));

    if ( (playerGG[shipY][shipX - 1].getState() == 1) && (playerGG[shipY][shipX].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY][shipX - 1].setPState(3);
      DEspawn = true;
    } else if ( (playerGG[shipY + 1][shipX].getState() == 1) && (playerGG[shipY][shipX].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY + 1][shipX].setPState(3);
      DEspawn = true;
    } else if ( (playerGG[shipY][shipX + 1].getState() == 1) && (playerGG[shipY][shipX].getState() == 1) ) {
      playerGG[shipY][shipX].setPState(3);
      playerGG[shipY][shipX + 1].setPState(3);
      DEspawn = true;
    } else if ( (playerGG[shipY - 1][shipX].getState() == 1) && (playerGG[shipY][shipX].getState() == 1) ) {
      playerGG[shipY][shipY].setPState(3);
      playerGG[shipY - 1][shipY].setPState(3);
      DEspawn = true;
    }
  }

  //Handle the enemies TD/Cell
  TextDisplay* enemyTD = new TextDisplay();
  Cell** enemyGG = new Cell*[11];
  for (int col = 1; col < 11; col++) {
    enemyGG[col] = new Cell[11];
    for (int row = 1; row < 11; row++) {
      Cell mycell;
      mycell.addDisplay(enemyTD);
      mycell.setCoords(col,row);
      mycell.setEState(1);//default to an empty space
      enemyGG[col][row] = mycell;
    }
  }

  CAspawn = BAspawn = CRspawn = SUspawn = DEspawn = false;//Reset flags
  while (!CAspawn) {//Spawn Carrier
    shipX = (1+(rand() % 10));
    shipY = (1+(rand() % 10));

    if ( (enemyGG[shipY - 1][shipX].getState() == 1) && (enemyGG[shipY - 2][shipX].getState() == 1) &&
    (enemyGG[shipY - 3][shipX].getState() == 1) && (enemyGG[shipY - 4][shipX].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY - 1][shipX].setEState(3);
      enemyGG[shipY - 2][shipX].setEState(3);
      enemyGG[shipY - 3][shipX].setEState(3);
      enemyGG[shipY - 4][shipX].setEState(3);
      CAspawn = true;
    } else if ( (enemyGG[shipY][shipX + 1].getState() == 1) && (enemyGG[shipY][shipX + 2].getState() == 1) &&
    (enemyGG[shipY][shipX + 3].getState() == 1) && (enemyGG[shipY][shipX + 4].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY][shipX + 1].setEState(3);
      enemyGG[shipY][shipX + 2].setEState(3);
      enemyGG[shipY][shipX + 3].setEState(3);
      enemyGG[shipY][shipX + 4].setEState(3);
      CAspawn = true;
    } else if ( (enemyGG[shipY + 1][shipX].getState() == 1) && (enemyGG[shipY + 2][shipX].getState() == 1) &&
    (enemyGG[shipY + 3][shipX].getState() == 1) && (enemyGG[shipY + 4][shipX].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY + 1][shipX].setEState(3);
      enemyGG[shipY + 2][shipX].setEState(3);
      enemyGG[shipY + 3][shipX].setEState(3);
      enemyGG[shipY + 4][shipX].setEState(3);
      CAspawn = true;
    } else if ( (enemyGG[shipY][shipX - 1].getState() == 1) && (enemyGG[shipY][shipX - 2].getState() == 1) &&
    (enemyGG[shipY][shipX - 3].getState() == 1) && (enemyGG[shipY][shipX - 4].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY][shipX - 1].setEState(3);
      enemyGG[shipY][shipX - 2].setEState(3);
      enemyGG[shipY][shipX - 3].setEState(3);
      enemyGG[shipY][shipX - 4].setEState(3);
      CAspawn = true;
    }
  }

  while (!BAspawn) {//Spawn Battleship
    shipX = (1+(rand() % 10));
    shipY = (1+(rand() % 10));

    if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY][shipX + 1].getState() == 1) &&
    (enemyGG[shipY][shipX + 2].getState() == 1) && (enemyGG[shipY][shipX + 3].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY][shipX + 1].setEState(3);
      enemyGG[shipY][shipX + 2].setEState(3);
      enemyGG[shipY][shipX + 3].setEState(3);
      BAspawn = true;
    } else if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY - 1][shipX].getState() == 1) &&
    (enemyGG[shipY - 2][shipX].getState() == 1) && (enemyGG[shipY - 3][shipX].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY - 1][shipX].setEState(3);
      enemyGG[shipY - 2][shipX].setEState(3);
      enemyGG[shipY - 3][shipX].setEState(3);
      BAspawn = true;
    } else if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY + 1][shipX].getState() == 1) &&
    (enemyGG[shipY + 2][shipX].getState() == 1) && (enemyGG[shipY + 3][shipX].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY + 1][shipX].setEState(3);
      enemyGG[shipY + 2][shipX].setEState(3);
      enemyGG[shipY + 3][shipX].setEState(3);
      BAspawn = true;
    } else if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY][shipX - 1].getState() == 1) &&
    (enemyGG[shipY][shipX - 2].getState() == 1) && (enemyGG[shipY][shipX - 3].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY][shipX - 1].setEState(3);
      enemyGG[shipY][shipX - 2].setEState(3);
      enemyGG[shipY][shipX - 3].setEState(3);
      BAspawn = true;
    }
  }

  while (!CRspawn) {//Spawn Cruiser
    shipX = (1+(rand() % 10));
    shipY = (1+(rand() % 10));

    if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY - 1][shipX].getState() == 1) &&
    (enemyGG[shipY - 2][shipX].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY - 1][shipX].setEState(3);
      enemyGG[shipY - 2][shipX].setEState(3);
      CRspawn = true;
    } else if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY][shipX + 1].getState() == 1) &&
    (enemyGG[shipY][shipX + 2].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY][shipX + 1].setEState(3);
      enemyGG[shipY][shipX + 2].setEState(3);
      CRspawn = true;
    } else if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY + 1][shipX].getState() == 1) &&
    (enemyGG[shipY + 2][shipX].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY + 1][shipX].setEState(3);
      enemyGG[shipY + 2][shipX].setEState(3);
      CRspawn = true;
    } else if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY][shipX - 1].getState() == 1) &&
    (enemyGG[shipY][shipX - 2].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY][shipX - 1].setEState(3);
      enemyGG[shipY][shipX - 2].setEState(3);
      CRspawn = true;
    }
  }

  while (!SUspawn) {//Spawn Submarine
    shipX = (1+(rand() % 10));
    shipY = (1+(rand() % 10));

    if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY - 1][shipX].getState() == 1) &&
    (enemyGG[shipY - 2][shipX].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY - 1][shipX].setEState(3);
      enemyGG[shipY - 2][shipX].setEState(3);
      SUspawn = true;
    } else if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY][shipX + 1].getState() == 1) &&
    (enemyGG[shipY][shipX + 2].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY][shipX + 1].setEState(3);
      enemyGG[shipY][shipX + 2].setEState(3);
      SUspawn = true;
    } else if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY + 1][shipX].getState() == 1) &&
    (enemyGG[shipY + 2][shipX].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY + 1][shipX].setEState(3);
      enemyGG[shipY + 2][shipX].setEState(3);
      SUspawn = true;
    } else if ( (enemyGG[shipY][shipX].getState() == 1) && (enemyGG[shipY][shipX - 1].getState() == 1) &&
    (enemyGG[shipY][shipX - 2].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY][shipX - 1].setEState(3);
      enemyGG[shipY][shipX - 2].setEState(3);
      SUspawn = true;
    }
  }

  while (!DEspawn) {//Spawn Destroyer
    shipX = (1+(rand() % 10));
    shipY = (1+(rand() % 10));

    if ( (enemyGG[shipY][shipX - 1].getState() == 1) && (enemyGG[shipY][shipX].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY][shipX - 1].setEState(3);
      DEspawn = true;
    } else if ( (enemyGG[shipY + 1][shipX].getState() == 1) && (enemyGG[shipY][shipX].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY + 1][shipX].setEState(3);
      DEspawn = true;
    } else if ( (enemyGG[shipY][shipX + 1].getState() == 1) && (enemyGG[shipY][shipX].getState() == 1) ) {
      enemyGG[shipY][shipX].setEState(3);
      enemyGG[shipY][shipX + 1].setEState(3);
      DEspawn = true;
    } else if ( (enemyGG[shipY - 1][shipX].getState() == 1) && (enemyGG[shipY][shipX].getState() == 1) ) {
      enemyGG[shipY][shipY].setEState(3);
      enemyGG[shipY - 1][shipY].setEState(3);
      DEspawn = true;
    }
  }

  playerGG[0] = new Cell[11];
  enemyGG[0] = new Cell[11];

  //The below adds the correct label cells to both displays
  Cell A,B,C,D,E,F,G,H,I,J,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN;

  A.addDisplay(playerTD);
  A.setCoords(1,0);
  A.setPState('0');
  playerGG[1][0] = A;
  playerTD->notify(1,0,'A');
  enemyGG[1][0] = A;
  enemyTD->notify(1,0,'A');
  B.addDisplay(playerTD);
  B.setCoords(2,0);
  B.setPState('0');
  playerGG[2][0] = B;
  playerTD->notify(2,0,'B');
  enemyGG[2][0] = B;
  enemyTD->notify(2,0,'B');
  C.addDisplay(playerTD);
  C.setCoords(3,0);
  C.setPState('0');
  playerGG[3][0] = C;
  playerTD->notify(3,0,'C');
  enemyGG[3][0] = C;
  enemyTD->notify(3,0,'C');
  D.addDisplay(playerTD);
  D.setCoords(4,0);
  D.setPState('0');
  playerGG[4][0] = D;
  playerTD->notify(4,0,'D');
  enemyGG[4][0] = D;
  enemyTD->notify(4,0,'D');
  E.addDisplay(playerTD);
  E.setCoords(5,0);
  E.setPState('0');
  playerGG[5][0] = E;
  playerTD->notify(5,0,'E');
  enemyGG[5][0] = E;
  enemyTD->notify(5,0,'E');
  F.addDisplay(playerTD);
  F.setCoords(6,0);
  F.setPState('0');
  playerGG[6][0] = F;
  playerTD->notify(6,0,'F');
  enemyGG[6][0] = F;
  enemyTD->notify(6,0,'F');
  G.addDisplay(playerTD);
  G.setCoords(7,0);
  G.setPState('0');
  playerGG[7][0] = G;
  playerTD->notify(7,0,'G');
  enemyGG[7][0] = G;
  enemyTD->notify(7,0,'G');
  H.addDisplay(playerTD);
  H.setCoords(8,0);
  H.setPState('0');
  playerGG[8][0] = H;
  playerTD->notify(8,0,'H');
  enemyGG[8][0] = H;
  enemyTD->notify(8,0,'H');
  I.addDisplay(playerTD);
  I.setCoords(9,0);
  I.setPState('0');
  playerGG[9][0] = I;
  playerTD->notify(9,0,'I');
  enemyGG[9][0] = I;
  enemyTD->notify(9,0,'I');
  J.addDisplay(playerTD);
  J.setCoords(10,0);
  J.setPState('0');
  playerGG[10][0] = J;
  playerTD->notify(10,0,'J');
  enemyGG[10][0] = J;
  enemyTD->notify(10,0,'J');
  ONE.addDisplay(playerTD);
  ONE.setCoords(0,1);
  ONE.setPState('0');
  playerGG[0][1] = ONE;
  playerTD->notify(0,1,'1');
  enemyGG[0][1] = ONE;
  enemyTD->notify(0,1,'1');
  TWO.addDisplay(playerTD);
  TWO.setCoords(0,2);
  TWO.setPState('0');
  playerGG[0][2] = TWO;
  playerTD->notify(0,2,'2');
  enemyGG[0][2] = TWO;
  enemyTD->notify(0,2,'2');
  THREE.addDisplay(playerTD);
  THREE.setCoords(0,3);
  THREE.setPState('0');
  playerGG[0][3] = THREE;
  playerTD->notify(0,3,'3');
  enemyGG[0][3] = THREE;
  enemyTD->notify(0,3,'3');
  FOUR.addDisplay(playerTD);
  FOUR.setCoords(0,4);
  FOUR.setPState('0');
  playerGG[0][4] = FOUR;
  playerTD->notify(0,4,'4');
  enemyGG[0][4] = FOUR;
  enemyTD->notify(0,4,'4');
  FIVE.addDisplay(playerTD);
  FIVE.setCoords(0,5);
  FIVE.setPState('0');
  playerGG[0][5] = FIVE;
  playerTD->notify(0,5,'5');
  enemyGG[0][5] = FIVE;
  enemyTD->notify(0,5,'5');
  SIX.addDisplay(playerTD);
  SIX.setCoords(0,6);
  SIX.setPState('0');
  playerGG[0][6] = SIX;
  playerTD->notify(0,6,'6');
  enemyGG[0][6] = SIX;
  enemyTD->notify(0,6,'6');
  SEVEN.addDisplay(playerTD);
  SEVEN.setCoords(0,7);
  SEVEN.setPState('0');
  playerGG[0][7] = SEVEN;
  playerTD->notify(0,7,'7');
  enemyGG[0][7] = SEVEN;
  enemyTD->notify(0,7,'7');
  EIGHT.addDisplay(playerTD);
  EIGHT.setCoords(0,8);
  EIGHT.setPState('0');
  playerGG[0][8] = EIGHT;
  playerTD->notify(0,8,'8');
  enemyGG[0][8] = EIGHT;
  enemyTD->notify(0,8,'8');
  NINE.addDisplay(playerTD);
  NINE.setCoords(0,9);
  NINE.setPState('0');
  playerGG[0][9] = NINE;
  playerTD->notify(0,9,'9');
  enemyGG[0][9] = NINE;
  enemyTD->notify(0,9,'9');
  TEN.addDisplay(playerTD);
  TEN.setCoords(0,10);
  TEN.setPState('0');
  playerGG[0][10] = TEN;
  playerTD->notify(0,10,'X');
  enemyGG[0][10] = TEN;
  enemyTD->notify(0,10,'X');

  playergrid = playerGG;
  playerdisplay = playerTD;
  enemygrid = enemyGG;
  enemydisplay = enemyTD;
}

Game::~Game() {
  for (int col = 0; col < 11; col++) {
    delete [] playergrid[col];
    delete [] enemygrid[col];
  }
  delete [] playergrid;
  delete [] enemygrid;
  delete playerdisplay;
  delete enemydisplay;
}

void Game::pchange(int col, int row, int state) {
  playergrid[col][row].setPState(state);
}

void Game::echange(int col, int row, int state) {
  enemygrid[col][row].setEState(state);
}

void Game::print() {
  enemydisplay->print();
  cout << endl;
  playerdisplay->print();
  cout << endl;
}

void Game::playerattack(string command) {
  int col, row;
  if (command[0] == 'A') {//Parse the command
    col = 1;
  } else if (command[0] == 'B') {
    col = 2;
  } else if (command[0] == 'C') {
    col = 3;
  } else if (command[0] == 'D') {
    col = 4;
  } else if (command[0] == 'E') {
    col = 5;
  } else if (command[0] == 'F') {
    col = 6;
  } else if (command[0] == 'G') {
    col = 7;
  } else if (command[0] == 'H') {
    col = 8;
  } else if (command[0] == 'I') {
    col = 9;
  } else if (command[0] == 'J') {
    col = 10;
  }

  if (command[1] == '1') {//Parse the command (could do int -> char narrowing?)
    row = 1;
  } else if (command[1] == '2') {
    row = 2;
  } else if (command[1] == '3') {
    row = 3;
  } else if (command[1] == '4') {
    row = 4;
  } else if (command[1] == '5') {
    row = 5;
  } else if (command[1] == '6') {
    row = 6;
  } else if (command[1] == '7') {
    row = 7;
  } else if (command[1] == '8') {
    row = 8;
  } else if (command[1] == '9') {
    row = 9;
  } else if (command[1] == 'X') {
    row = 10;
  }

  if (enemygrid[col][row].getState() == 1) {
    echange(col, row, 2);//'.' -> 'x'
    cout << "You don't hit anything." << endl << endl;
  } else if (enemygrid[col][row].getState() == 3) {
    echange(col, row, 4);//'.' -> 'H'
    cout << "You hit an enemy ship!" << endl << endl;
  } else {
    cout << "You've already attacked that space!" << endl << endl;
  }
}

void Game::enemyattack(int col, int row) {
  if (playergrid[col][row].getState() == 1) {
    pchange(col, row, 2);//'.' -> 'x'
    cout << "Your opponent fired & missed your fleet." << endl << endl;
  } else if (playergrid[col][row].getState() == 3) {
    pchange(col, row, 4);//'S' -> 'H'
    cout << "Your opponent fired & hit a ship in your fleet." << endl << endl;
  }
  print();
}

bool Game::playerwon() {
  for (int col = 1; col < 11; col++) {
    for (int row = 1; row < 11; row++) {
      if (enemygrid[col][row].getState() == 3) {
        return false;
      }
    }
  }
  return true;//We found no remaining spaces of state 3 (hidden enemy ships)
}

bool Game::enemywon() {
  for (int col = 1; col < 11; col++) {
    for (int row = 1; row < 11; row++) {
      if (playergrid[col][row].getState() == 3) {
        return false;
      }
    }
  }
  return true;//We found no remaining spaces of state 3 (hidden player ships)
}

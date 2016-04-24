#include "game.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>//exit
#include <cstdlib>//srand, rand
using namespace std;

//TODO: Make it so you can't select the same space twice, make CPU smarter, add more PRNG

void usage() {
  cerr << "Usage: ./a.out [ -seed S (seed for random-number generator (1...INT_MAX)) ]" << endl;
  exit( EXIT_FAILURE );//terminate
}

bool isvalid(string command) {
  if (command.length() != 2) {
    return false;
  }

  if ( (command[0] == 'A') || (command[0] == 'B') || (command[0] == 'C') || (command[0] == 'D') ||
    (command[0] == 'E') || (command[0] == 'F') || (command[0] == 'G') || (command[0] == 'H') ||
    (command[0] == 'I') || (command[0] == 'J') ) {
    if ( (command[1] == '1') || (command[1] == '2') || (command[1] == '3') || (command[1] == '4') ||
      (command[1] == '5') || (command[1] == '6') || (command[1] == '7') || (command[1] == '8') ||
      (command[1] == '9') || (command[1] == 'X') ) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

int main (int argc, char * argv[]) {
  int seed = 2;//default value for generation seed

  if (argc == 3) {
    string checkname(argv[1]);
    istringstream checkval(argv[2]);
    if (checkname == "-seed") {
      checkval >> seed;
    } else {//we've gotten something other than a seed
      usage();
    }
  } else if (argc == 1) {
    ;//do nothing
  } else {
    usage();//wrong number of arguments, only 0 and 2 args are valid here
  }

  cout << endl << "Welcome to Battleships! The top display is your opponents, the bottom display is yours." << endl
  << "To attack a territory, enter commands in (row)(column) notation." << endl
  << "For example A1 and E6 are valid commands, while 1A and 6E are not." << endl
  << "Note the 10th column is 'X' for now." << endl
  << "You may also use the command 'Q' during your turn to quit the game" << endl
  << "Goodluck!" << endl << endl;

  srand( seed );//set the random number generator seed
  Game A_game;//initialize an instance of battleships
  A_game.print();//Print once before any commands are given
  string command;

  while(cin >> command) {
    if (command == "Q") {
      break;
    } else if (isvalid(command)) {
      A_game.playerattack(command);
      if (A_game.playerwon()) {
        cout << "You sunk your opponent's fleet, you win!" << endl << endl;
        break;
      }
      A_game.enemyattack( (1+ (rand() % 10)), (1 + (rand() % 10)));
      if (A_game.enemywon()) {
        cout << "Your opponent sunk your fleet, you've lost!" << endl << endl;
        break;
      }
    } else {
      cout << "Invalid command" << endl;
    }
  }
  cout << "Thanks for playing!" << endl;
}

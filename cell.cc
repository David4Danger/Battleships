#include "cell.h"

Cell::Cell() : state(), row(), col() {}

void Cell::notifyPDisplay() {
  if (state == 1) {
    mydisplay->notify(col, row, '.');
  } else if (state == 2) {
    mydisplay->notify(col, row, 'x');
  } else if (state == 3) {
    mydisplay->notify(col, row, 'S');//Our ship, not secret
  } else if (state == 4) {
    mydisplay->notify(col, row, 'H');
  } else {
    ;//do nothing as we don't change labels
  }
}

void Cell::notifyEDisplay() {
  if (state == 1) {
    mydisplay->notify(col, row, '.');
  } else if (state == 2) {
    mydisplay->notify(col, row, 'x');
  } else if (state == 3) {
    mydisplay->notify(col, row, '.');//SECRET SHIP!!
  } else if (state == 4) {
    mydisplay->notify(col, row, 'H');
  } else {
    ;//do nothing as we don't change labels
  }
}

int Cell::getState() {
  return state;
}

void Cell::setPState(int change) {
  state = change;
  notifyPDisplay();
}

void Cell::setEState(int change) {
  state = change;
  notifyEDisplay();
}

void Cell::setCoords(int col, int row) {
  this->col = col;
  this->row = row;
}

void Cell::addDisplay(TextDisplay * display) {
  mydisplay = display;
}

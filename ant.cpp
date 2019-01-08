/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Ant class is used to hold the current orientation,
**                  current row and current column location of the ant.
**                  Ant class interacts with the menu for initializing
**                  the board and ant details and interacts with the
**                  board class as the game is ongoing by passing it
**                  the current ant orientation so that the appropriate
**                  moves are made by the ant when it moves.
*********************************************************************/
#include "ant.hpp"


void Ant::setAntOrientation(int orientation) {
    this->antOrientation = static_cast<AntOrientation>(orientation);
}

AntOrientation Ant::getAntOrientation() {
    return antOrientation;
}

void Ant::setCurrentRowLocation(int row) {
    this->currentRowLocation = row;
}

void Ant::setCurrentColLocation(int col) {
    this->currentColLocation = col;
}

int Ant::getCurrentRowLocation() {
    return currentRowLocation;
}

int Ant::getCurrentColLocation() {
    return currentColLocation;
}

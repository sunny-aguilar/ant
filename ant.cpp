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

/*********************************************************************
** Description:     sets the ant orientation via an enum data type
*********************************************************************/
void Ant::setAntOrientation(int orientation) {
    this->antOrientation = static_cast<AntOrientation>(orientation);
}

/*********************************************************************
** Description:     gets the ant orientation enum variable
*********************************************************************/
AntOrientation Ant::getAntOrientation() {
    return antOrientation;
}

/*********************************************************************
** Description:     sets the current row location of the ant
*********************************************************************/
void Ant::setCurrentRowLocation(int row) {
    this->currentRowLocation = row;
}

/*********************************************************************
** Description:     sets the current column location of the ant
*********************************************************************/
void Ant::setCurrentColLocation(int col) {
    this->currentColLocation = col;
}

/*********************************************************************
** Description:     gets the current row location of the ant
*********************************************************************/
int Ant::getCurrentRowLocation() {
    return currentRowLocation;
}

/*********************************************************************
** Description:     gets the current column location of the ant
*********************************************************************/
int Ant::getCurrentColLocation() {
    return currentColLocation;
}

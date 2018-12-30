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
#ifndef ANT_HPP
#define ANT_HPP

enum AntOrientation {NORTH = 1, SOUTH, EAST, WEST};

class Ant {
private:
    AntOrientation antOrientation;              // ant orientation
    int currentRowLocation;                     // ant current row
    int currentColLocation;                     // ant current location

public:
    void setAntOrientation(int orientation);    // set ant orientation
    AntOrientation getAntOrientation();         // get ant orientation
    void setCurrentRowLocation(int row);        // set current row
    void setCurrentColLocation(int col);        // set current column
    int getCurrentRowLocation();                // get current row
    int getCurrentColLocation();                // get current location
};

#endif

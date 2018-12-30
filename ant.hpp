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
    AntOrientation antOrientation;
    int currentRowLocation;
    int currentColLocation;

public:
    void setAntOrientation(int orientation);
    AntOrientation getAntOrientation();
    void setCurrentRowLocation(int row);
    void setCurrentColLocation(int col);
    int getCurrentRowLocation();
    int getCurrentColLocation();
};

#endif

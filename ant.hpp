/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
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
    void moveAnt();
};

#endif

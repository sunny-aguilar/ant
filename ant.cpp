/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
*********************************************************************/
#include "ant.hpp"

void Ant::setAntOrientation(int orientation) {
    switch (orientation) {
        case 0:
            this->antOrientation = NORTH;
            break;
        case 1:
            this->antOrientation = SOUTH;
            break;
        case 2:
            this->antOrientation = EAST;
            break;
        case 3:
            this->antOrientation = WEST;
            break;
    }


}
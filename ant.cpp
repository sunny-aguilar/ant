/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
*********************************************************************/
#include "ant.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;

void Ant::setAntOrientation(int orientation) {
    this->antOrientation = static_cast<AntOrientation>(orientation);
}

AntOrientation Ant::getAntOrientation() {
    return antOrientation;
}
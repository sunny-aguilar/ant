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
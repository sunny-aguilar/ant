/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     This project implements Langston's ant. The program
**                  begins by asking user to enter game details such
**                  board size dimensions, # of steps, and starting
**                  location. The ant then proceeds to move around
**                  according to the project specifications. The ant
**                  bounces off the walls so as not to exceed bounds.
**                  EXTRA CREDIT - a random starting location option
**                  has been incorporated for extra credit, see
**                  board class.
*********************************************************************/
#include "ant.hpp"
#include "board.hpp"
#include "menu.hpp"
#include <iostream>
//#include <cstdlib>
#include <ctime>

int main() {
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);                    // create random number generator
    Board antBoard;                 // start Ant simulation
    antBoard.startAntSimulation();  // start the ant simulation
    return 0;
}
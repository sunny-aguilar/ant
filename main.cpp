/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
*********************************************************************/
#include "ant.hpp"
#include "board.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
//#include <regex>
using std::cin;
using std::cout;
using std::endl;
using std::string;
//using std::regex;

int main() {

    // ant rules
    // If the ant is on a white space, turn right 90 degrees and change the space to black.
    // If the ant is on a black space, turn left 90 degrees and change the space to white.

    // create menu, board, and ant
    Menu antMenu;
    Board antBoard;
    // call menu
    antMenu.showStartMenu();
    // get user selection
    antMenu.setSelection();
//    cout << "Selection made was " << antMenu.getSelection() << endl; // debugging line (may delete)
    antMenu.validateSelection();

    antMenu.subMenuRows();
    antBoard.setRows( antMenu.validateSize("rows.") );

    antMenu.subMenuCols();
    antBoard.setCols( antMenu.validateSize("columns.") );

    // test board to see if dimensions are correctly applied
    cout << "Your board has " << antBoard.getRows() << " rows and " << antBoard.getCols() << " columns." << endl;

//    antMenu.subMenuStartRow();
//    antMenu.subMenuStartCol();
//
//    antMenu.subMenuSteps();

    return 0;
}
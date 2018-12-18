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

    // call main menu
    antMenu.showStartMenu();
    // get user main menu selection
    antMenu.setSelection( antMenu.validateSelection() );


    // debugging code - test selection variable for main menu in Board
    //    cout << "Selection made was " << antMenu.getSelection() << endl; // debugging line (may delete)

    if (antMenu.getSelection() == "1") {
        // submenu items - ask user to enter rows and columns for board and validate
        antMenu.subMenuRows();
        antBoard.setRows( antMenu.validateSize("rows.") );
        antMenu.subMenuCols();
        antBoard.setCols( antMenu.validateSize("columns.") );


        // submenu item - ask user to enter steps and validate
        antMenu.subMenuSteps();
        antBoard.setSteps( antMenu.validateSteps() );

        // submenu item - ask user to select the starting location method

        if ( antMenu.subMenuStartLocation() == 1) { // need to debug
            // set custom user-picked location
            antBoard.setStartRow( antMenu.subMenuRowStartLocation( antBoard.getRows() ) );
            antBoard.setStartCol( antMenu.subMenuColStartLocation( antBoard.getCols() ) );
        }
        else if ( antMenu.subMenuStartLocation() == 2) {
            // set random starting location
            antBoard.setStartRow( antMenu.setRandomLocation( antBoard.getRows() ) );
//            antBoard.setStartCol( antMenu.setRandomLocation( antBoard.getCols() ) );
        }

//        antBoard.setStartRow( antMenu.subMenuRowStartLocation() );



        // submenu item - ask user to enter the start column

        // ask user to select a random start location

        // debugging code - test board specs
        cout << "\n\nRows " << antBoard.getRows() << " Cols " << antBoard.getCols() << endl;
        cout << "Number of Steps is " << antBoard.getSteps() << endl;
        cout << "Random row start location " << antBoard.getStartRow() << endl;
        cout << "Random column start location " << antBoard.getStartCol() << endl;

        //    submenu item - antMenu.subMenuStartCol();
        //
        //    antMenu.subMenuSteps();
    }
    else {
        cout << "Goodbye\n";
    }

    return 0;
}
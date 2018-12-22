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
#include <cstdlib>
#include <ctime>
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
    Ant ant;

    // call main menu
    antMenu.showStartMenu();
    // get user main menu selection
    antMenu.setSelection( antMenu.validateSelection() );


    // debugging code - test selection variable for main menu in Board
    //    cout << "Selection made was " << antMenu.getSelection() << endl; // debugging line (may delete)

    if (antMenu.getSelection() == "1") {
        // User picked start simulation option
        // submenu items - ask user to enter rows and columns for board and validate
        antMenu.subMenuRows();
        antBoard.setRows( antMenu.validateNumber(2, 100) );
        antMenu.subMenuCols();
        antBoard.setCols( antMenu.validateNumber(2, 100) );

        // initialize board dimensions in a 2-D dynamic array
        antBoard.setBoardArrayDimensions();

        // submenu item - ask user to enter steps and validate
        antMenu.subMenuSteps();
        antBoard.setSteps( antMenu.validateNumber(1, 1000) );

        // submenu item - ask user to select the starting location method
        antMenu.subMenuStartLocation();
        if ( antMenu.validateSelection() == "1") {
            // set custom user-picked location
            antBoard.setStartRow( antMenu.subMenuRowStartLocation( antBoard.getRows() ) );
            antBoard.setStartCol( antMenu.subMenuColStartLocation( antBoard.getCols() ) );
        }
        else {
            // set random starting location for the ant
            // Extra Credit 5%
            unsigned seed;
            seed = static_cast<unsigned int>(time(nullptr));
            srand(seed);
            antBoard.setStartRow( antMenu.setRandomLocation( antBoard.getRows() ) );
            antBoard.setStartCol( antMenu.setRandomLocation( antBoard.getCols() ) );
        }

        // submenu item - ask user to set ant's starting orientation
        antMenu.subMenuSetAntOrientation();
        ant.setAntOrientation( antMenu.validateOrientation() );

        // show message initializing ant
        antMenu.submenuInitializeAnt();

        // debugging code - test board specs
        cout << "\n\nRows " << antBoard.getRows() << " Cols " << antBoard.getCols() << endl;
        cout << "Number of Steps is " << antBoard.getSteps() << endl;
        cout << "Random row start location " << antBoard.getStartRow() << endl;
        cout << "Random column start location " << antBoard.getStartCol() << endl;
        cout << "Starting ant orientation is " << ant.getAntOrientation() << endl;

        //    antMenu.subMenuSteps();



        // initialize ant and board details
        ant.setCurrentRowLocation( antBoard.getStartRow() );
        ant.setCurrentColLocation( antBoard.getStartCol() );
        cout << "Ant row location " << ant.getCurrentRowLocation() << endl;
        cout << "Ant col location " << ant.getCurrentColLocation() << endl;
        antBoard.setBoardArrayDimensions();
        antBoard.setAllBoardCharacters();
        antBoard.setAntCharacter();
        antBoard.showBoard();

        //


    }
    else {
        // user quit the program
        cout << "Goodbye\n";
    }

    return 0;
}
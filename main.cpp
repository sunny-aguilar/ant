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

    // create variables
    bool playAgain = true;

    // create menu, board, and ant
    Menu antMenu;
    Board antBoard;
    Ant ant;

    // call main menu
    antMenu.showStartMenu();
    // get user main menu selection
    antMenu.setSelection( antMenu.validateSelection() );


    if (antMenu.getSelection() == "1") {
        // once game specs have been entered, the user should have the option
        // to replay the game or end it
        do {
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
                // set custom user-picked starting location for the ant
                antBoard.setStartRow( antMenu.subMenuRowStartLocation( antBoard.getRows() ) );
                antBoard.setStartCol( antMenu.subMenuColStartLocation( antBoard.getCols() ) );
            }
            else {
                // set random starting location for the ant
                // Extra Credit 5%
                unsigned seed;
                seed = static_cast<unsigned int>(time(nullptr));
                srand(seed);
                // set random starting location for the ant
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


            // initialize ant and board details
            // set initial ant row and column; values received board class
            // ant class holds current row and column for the ant only
            ant.setCurrentRowLocation( antBoard.getStartRow() );
            ant.setCurrentColLocation( antBoard.getStartCol() );

            // debugging - display current ant row and location
            cout << "Ant row location " << ant.getCurrentRowLocation() << endl;
            cout << "Ant col location " << ant.getCurrentColLocation() << endl;

            // set board dimensions
            antBoard.setBoardArrayDimensions();

            // set initial board characters
            antBoard.setAllBoardCharacters();

            // set ant * location on board (in 2d array)
            // remember current color and set variable in board class
            // setAntLocation function has -1 adjustment included to row and col
            antBoard.setAntLocation( ant.getCurrentRowLocation(), ant.getCurrentColLocation() );

            // show initial board setup
            cout << "\nInitial board set up\n";
            antBoard.showBoard();
            cout << endl;


            // Loop through the steps
            for (int steps = 0; steps < antBoard.getSteps(); steps++) {

                // set/update ant heading
                ant.setAntOrientation( antBoard.setBoardSpace( ant.getCurrentRowLocation(),
                                                               ant.getCurrentColLocation(),
                                                               ant.getAntOrientation() ) );
                // move ant and set new location in ant class
                // if heading is North, South, East, West
                cout << "Current color " << antBoard.getColor( ant.getCurrentRowLocation(),
                                                               ant.getCurrentColLocation() ) << endl;

                cout << "Current heading " << ant.getAntOrientation() << endl;

//                ant.moveAnt( antBoard.getColor( ant.getCurrentRowLocation(),
//                                                ant.getCurrentColLocation() ) );




//                ant.setCurrentRowLocation( antBoard.getAntCurrentRow() );
//                ant.setCurrentColLocation( antBoard.getAntCurrentCol() );

                // delete old * after moving
//                antBoard.deletePriorLocation();

                // add * to board again
                // setAntLocation function has -1 adjustment to row and col
//                antBoard.setAntLocation( ant.getCurrentRowLocation(), ant.getCurrentColLocation() );



                // show updated board
                antBoard.showBoard();
                cout << endl;



                // delete these lines after your done
                // use this pause to help with debugging
                cout << "Hit enter to continue\n";
                cin.get();

                cout << endl;
            }



            // end of simulation
            // provide 2 choices: play again or quit
            if (antMenu.submenuPlayAgain() == "2") {
                playAgain = false;
                cout << "Thanks for playing!\n";
            }

        } while (playAgain);
    }
    else {
        // user quit the program in the main menu
        cout << "Goodbye\n";
    }

    return 0;
}
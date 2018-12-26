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

    // call main menu
    antMenu.showStartMenu();

    // get user main menu selection
    antMenu.setSelection( antMenu.validateSelection() );

    // *********************************************************************************
    // main menu screen - user plays game or quits *************************************
    // *********************************************************************************
    if (antMenu.getSelection() == "1") {
        // do while loop repeats the game if user wants to play again
        do {
            // create board and ant
            Board antBoard;                 // create board inside loop otherwise leak!
            Ant ant{};

            // submenu - ask user to enter rows and columns for board and validate
            antMenu.submenuRows();
            antBoard.setRows( antMenu.validateNumber(2, 100) );
            antMenu.submenuCols();
            antBoard.setCols( antMenu.validateNumber(2, 100) );

            // submenu - ask user to enter steps and validate
            antMenu.submenuSteps();
            antBoard.setSteps( antMenu.validateNumber(1, 1000) );

            // submenu - ask user to select the starting location for the ant
            antMenu.submenuStartLocation();
            if ( antMenu.validateSelection() == "1") {
                // set custom starting location for the ant
                antBoard.setStartRow( antMenu.submenuRowStartLocation( antBoard.getRows() ) );
                antBoard.setStartCol( antMenu.submenuColStartLocation( antBoard.getCols() ) );
            }
            else {
                // Extra Credit 5%
                // set random starting location for the ant
                unsigned seed;
                seed = static_cast<unsigned int>(time(nullptr));
                srand(seed);
                antBoard.setStartRow( antMenu.setRandomLocation( antBoard.getRows() ) );
                antBoard.setStartCol( antMenu.setRandomLocation( antBoard.getCols() ) );
            }

            // submenu - ask user to set ant's starting orientation
            antMenu.submenuSetAntOrientation();
            ant.setAntOrientation( antMenu.validateOrientation() );

            // show message initializing ant
            antMenu.submenuInitializeAntMessage();

            // debugging code - test board specs DELETE WHEN DONE
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
            // send current ant location from ant class back to board class
            antBoard.setNewAntcoor( ant.getCurrentRowLocation(), ant.getCurrentColLocation() );


            // debugging - display current ant row and location DELETE WHEN DONE
            cout << "Ant row location " << ant.getCurrentRowLocation() << endl;
            cout << "Ant col location " << ant.getCurrentColLocation() << endl;

            // set board dimensions rows and columns
            // allocates 2-D array
            antBoard.setBoardArrayDimensions();

            // set initial board characters to white ' '
            antBoard.setAllBoardCharacters();

            // set ant * location on board (in 2d array)
            // remember current color and set variable in board class
            // setAntLocation function has -1 adjustment included to row and col
            // wait until you can find a way to show the * ant and remember the space color too
//            antBoard.setAntLocation( ant.getCurrentRowLocation(), ant.getCurrentColLocation() );

            // show initial board setup
            cout << "\n********** Initial Board Set Up **********\n";



            antBoard.addAntCharacter( ant.getCurrentRowLocation()-1, ant.getCurrentRowLocation()-1 );
            antBoard.showBoard();
            // ********* DEBUGGING - DELETE BELOW ************
            // use this pause to help with debugging
            cout << "Hit enter to continue\n";
            cin.get();
            // ********* DEBUGGING - DELETE ABOVE ^^^ ************
            antBoard.deletePriorLocation();



            cout << endl;


            // Loop through the steps
            for (int steps = 0; steps < antBoard.getSteps(); steps++) {

                // update ant orientation in ant class (ant orientation initially set by user
                // and set in ant class
                ant.setAntOrientation( antBoard.updateOrientation( ant.getCurrentRowLocation(),
                                                               ant.getCurrentColLocation(),
                                                               ant.getAntOrientation() ) );


                // move ant by getting getting new orientation from ant class and moving left
                // or right
                antBoard.moveAnt( ant.getAntOrientation() );                // move and and update new coord in board
                ant.setCurrentRowLocation( antBoard.getAntCurrentRow() );   // update new row coord in ant class
                ant.setCurrentColLocation( antBoard.getAntCurrentCol() );   // update new col coord in ant class



                // show current ant location, show board with ant, then replace ant
                // show current ant location
                antBoard.addAntCharacter( ant.getCurrentRowLocation()-1, ant.getCurrentColLocation()-1 );
                // show updated board
                antBoard.showBoard();
                // delete ant
                antBoard.deletePriorLocation();
                // replace ant with prior space character
                antBoard.addCurrentColor( ant.getCurrentRowLocation()-1, ant.getCurrentColLocation()-1 );




                cout << endl;
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

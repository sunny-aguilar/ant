/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     This project implements Langston's ant. The program
**                  begins by asking user to enter game details such
**                  board size dimensions, # of steps, and starting
**                  location. The ant then proceeds to move around
**                  according to the project specifications. The ant
**                  bounces off the walls so as not to exceed bounds.
*********************************************************************/
#include "ant.hpp"
#include "board.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    // ant rules
    // If the ant is on a white space, turn right 90 degrees and change the space to black.
    // If the ant is on a black space, turn left 90 degrees and change the space to white.

    // create variables
    bool playAgain = true;          // to control repeat games
    int trackSteps = 0;             // to track the steps the ant makes
    const int MIN_ROW = 1;          // to preset min number of rows and columns
    const int MAX_ROW = 100;        // to preset max number fo rows and columns
    const int MIN_STEPS = 1;        // to preset min steps to move the ant
    const int MAX_STEPS = 1000;     // to preset max steps to move the ant

    // create menu
    Menu antMenu;

    // call main menu2
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
            antBoard.setRows( antMenu.validateNumber(MIN_ROW, MAX_ROW) ); // valid numbers are 1 through 100
            antMenu.submenuCols();
            antBoard.setCols( antMenu.validateNumber(MIN_ROW, MAX_ROW) ); // valid numbers are 1 through 100

            // submenu - ask user to enter steps and validate user input
            antMenu.submenuSteps();
            antBoard.setSteps( antMenu.validateNumber(MIN_STEPS, MAX_STEPS) ); // valid numbers are 1 through 1000

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

            // initialize ant and board details
            // set initial ant row and column; values received board class
            ant.setCurrentRowLocation( antBoard.getStartRow() );
            ant.setCurrentColLocation( antBoard.getStartCol() );

            // send current ant location from ant class back to board class
            antBoard.setNewAntcoor( ant.getCurrentRowLocation(), ant.getCurrentColLocation() );

            // set board dimensions rows and columns by dynamically allocating 2D array
            antBoard.setBoardArrayDimensions();

            // set initial board characters to white squares
            antBoard.setAllBoardCharacters();

            // show initial board setup
            cout << "\n********** Initial Board Set Up **********\n";

            // add ant * in array and saves current color ant is on in a variable
            antBoard.addAntCharacter( ant.getCurrentRowLocation()-1, ant.getCurrentColLocation()-1 );

            // show board
            antBoard.showBoard();

            // add current color back on board (replacing * in array)
            antBoard.addCurrentColor( ant.getCurrentRowLocation()-1, ant.getCurrentColLocation()-1 );

            // ********* DEBUGGING - TOOL ************
            // use this to pause between steps to help
            // with debugging and for viewing the ant
            // move 1 step at a time
            cout << "Hit enter to continue\n";
            cin.get();
            cout << endl;
            // ********* DEBUGGING - TOOL^^^ ************


            // Loop through the total steps the ant is to move
            for (int steps = 0; steps < antBoard.getSteps(); steps++) {
                // total steps taken is increased by one for each step
                trackSteps++;

                // update ant orientation for ant going out of bounds. If ant goes out of bounds,
                // behavior is to make ant turn around 180 degree and move 1 square in that new
                // direction
                if (antBoard.checkWallHitVar()) {
                    ant.setAntOrientation( antBoard.wallCheckOrientation() );
                    antBoard.setCheckWallHitVar(false);
                }

                // update ant orientation after moving moving ant on board
                ant.setAntOrientation( antBoard.updateOrientation( ant.getCurrentRowLocation(),
                                                               ant.getCurrentColLocation(),
                                                               ant.getAntOrientation() ) );


                // move ant by getting getting new orientation from ant class and moving left
                // or right   2nd switch stmt for moveAnt(  )
                antBoard.moveAnt( ant.getAntOrientation() );                // move and and update new coord in board
                ant.setCurrentRowLocation( antBoard.getAntCurrentRow() );   // update new row coord in ant class
                ant.setCurrentColLocation( antBoard.getAntCurrentCol() );   // update new col coord in ant class



                // show current ant location, show board with ant, then replace ant
                // add current ant location and update currentColor variable
                antBoard.addAntCharacter( ant.getCurrentRowLocation()-1, ant.getCurrentColLocation()-1 );
                // show updated board
                antBoard.showBoard();
                // delete ant
//                antBoard.deletePriorLocation();
                // replace ant with prior space character
                antBoard.addCurrentColor( ant.getCurrentRowLocation()-1, ant.getCurrentColLocation()-1 );


                // ********* DEBUGGING - TOOL ************
                // a pause is used to
                cout << endl;
                cout << "Steps taken " << trackSteps << endl;
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
            else {
                trackSteps = 0;
            }

        } while (playAgain);
    }
    else {
        // user quit the program in the main menu
        cout << "Goodbye\n";
    }

    return 0;
}

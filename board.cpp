/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Board class creates a game board that is used to
**                  maintain the board colors and move the ant. Works
**                  together with the Ant class to pass data between
**                  both in order to coordinate the ant location and
**                  heading. EXTRA CREDIT - see function called
**                  Board::setupStartLocation() for random start
**                  location option.
*********************************************************************/
#include "board.hpp"

/*********************************************************************
** Description:     default constructor that initializes the pointer
**                  member and bool member variable
*********************************************************************/
Board::Board() {
    ptrBoard = nullptr;
    wallHit = false;
}

/*********************************************************************
** Description:     destructor that de-allocates the 2D pointer
**                  that was allocated in the board class
*********************************************************************/
Board::~Board() {
    // delete dynamically allocated pointers
    for (int col = 0; col < getCols(); col++) {
        delete [] ptrBoard[col];
    }
    //Free the array of pointers
    delete [] ptrBoard;
}

/*********************************************************************
** Description:     this function starts the ant simulation. Constant
**                  variables are created to control game parameters.
*********************************************************************/
void Board::startAntSimulation() {
    // create constant variables
    int trackSteps = 0;             // to track the steps the ant makes
    const int MIN_ROW = 1;          // to preset min number of rows and columns
    const int MAX_ROW = 120;        // to preset max number fo rows and columns
    const int MIN_STEPS = 1;        // to preset min steps to move the ant
    const int MAX_STEPS = 20000;    // to preset max steps to move the ant

    // show start menu & get player selection
    menu.showStartMenu();
    menu.setSelection( menu.validateSelection() );

    if (menu.getSelection() == "1") {
        // do while loop repeats the game if user wants to play again
        do {
            // set board row and column sizes
            setBoardSizes(MIN_ROW, MAX_ROW);

            // submenu - ask user to enter steps and validate user input
            setupSteps(MIN_STEPS, MAX_STEPS);

            // submenu - ask user to select the starting location for the ant
            setupStartLocation();

            // submenu - ask user to set ant's starting orientation
            setupOrientation();

            // show message initializing ant
            menu.submenuInitializeAntMessage();

            // initialize ant and board details
            setupBoardDetails();

            // show initial starting board
            showInitialBoardSetup();

            // move the ant operations
            moveAntOperations(trackSteps);
        } while ( playAgain(trackSteps) );
    }
    else {
        // user quits the program in the main menu
        cout << "Goodbye\n";
    }
}

/*********************************************************************
** Description:     takes constant parameters to set the board rows
**                  and columns
*********************************************************************/
void Board::setBoardSizes(int MIN_ROW, int MAX_ROW) {
    // submenu - ask user to enter rows and columns for board and validate
    menu.submenuRows();
    setRows( menu.validateNumber(MIN_ROW, MAX_ROW) ); // valid numbers are 1 through 100
    menu.submenuCols();
    setCols( menu.validateNumber(MIN_ROW, MAX_ROW) ); // valid numbers are 1 through 100
}

/*********************************************************************
** Description:     takes constant parameters to set the total steps
*********************************************************************/
void Board::setupSteps(int MIN_STEPS, int MAX_STEPS) {
    // submenu - ask user to enter steps and validate user input
    menu.submenuSteps();
    setSteps( menu.validateNumber(MIN_STEPS, MAX_STEPS) ); // valid numbers are 1 through 1000
}

/*********************************************************************
** Description:     EXTRA CREDIT - user can set a random starting
**                  location or a custom user-picked location for
**                  the ant
*********************************************************************/
void Board::setupStartLocation() {
    menu.submenuStartLocation();
    if ( menu.validateSelection() == "1") {
        // set custom starting location for the ant
        setStartRow( menu.submenuRowStartLocation( getRows() ) );
        setStartCol( menu.submenuColStartLocation( getCols() ) );
    }
    else {
        // Extra Credit 5% ************************
        // set random starting location for the ant
        setStartRow( menu.setRandomLocation( getRows() ) );
        setStartCol( menu.setRandomLocation( getCols() ) );
    }
}

/*********************************************************************
** Description:     this function prompts user to pick the ant
**                  orientation, validates input, and sets up
**                  the orientation after valid input
*********************************************************************/
void Board::setupOrientation() {
    menu.submenuSetAntOrientation();
    ant.setAntOrientation( menu.validateOrientation() );
}

/*********************************************************************
** Description:     this function sets up the game details on the
**                  the ant object shc as its current location,
**                  dynamically allocates the array, and sets the
**                  board characters.
*********************************************************************/
void Board::setupBoardDetails() {
    ant.setCurrentRowLocation( getStartRow() );
    ant.setCurrentColLocation( getStartCol() );

    // send current ant location from ant class back to board class
    setNewAntcoor( ant.getCurrentRowLocation(), ant.getCurrentColLocation() );

    // set board dimensions rows and columns by dynamically allocating 2D array
    setBoardArrayDimensions();

    // set initial board characters to white squares
    setAllBoardCharacters();

    // show initial board setup
    cout << "\n\n********** Initial Board Set Up **********\n";

    // add ant * in array and saves current color ant is on in a variable
    addAntCharacter( ant.getCurrentRowLocation()-1, ant.getCurrentColLocation()-1 );
}

/*********************************************************************
** Description:     this functions calls functions to display the
**                  board on the screen. A debugging tool was kept
**                  since it helps in pausing to view the initial
**                  board set-up before the ant moves.
*********************************************************************/
void Board::showInitialBoardSetup() {
    // display board on screen
    showBoard();

    // add current color back on board (replacing * in array)
    addCurrentColor( ant.getCurrentRowLocation()-1, ant.getCurrentColLocation()-1 );

    // ********* DEBUGGING - TOOL ************
    // use this to pause for viewing initial
    // baord set-up
    cout << "The board has been initialized - Hit ENTER to continue\n";
    cin.get();
    cout << endl;
    // ********* DEBUGGING - TOOL^^^ ************
}

/*********************************************************************
** Description:     takes an int parameter to set the total rows in
**                  the board
*********************************************************************/
void Board::setRows(int row) {
    this->rows = row;
}

/*********************************************************************
** Description:     takes an int parameter to set the total columns in
**                  the board
*********************************************************************/
void Board::setCols(int col) {
    this->cols = col;
}

/*********************************************************************
** Description:     takes an int parameter to set the total steps to
**                  move the ant
*********************************************************************/
void Board::setSteps(int steps) {
    this->steps = steps;
}

/*********************************************************************
** Description:     takes an int parameter to set the starting row for
**                  the ant
*********************************************************************/
void Board::setStartRow(int startRow) {
    this->startRow = startRow;
}

/*********************************************************************
** Description:     takes an int parameter to set the starting column
**                  for the ant
*********************************************************************/
void Board::setStartCol(int startCol) {
    this->startCol = startCol;
}

/*********************************************************************
** Description:     get the total rows in the board
*********************************************************************/
int Board::getRows() {
    return rows;
}

/*********************************************************************
** Description:     get the total columns in the board
*********************************************************************/
int Board::getCols() {
    return cols;
}

/*********************************************************************
** Description:     get the total steps to move the ant
*********************************************************************/
int Board::getSteps() {
    return steps;
}

/*********************************************************************
** Description:     get the start row from the board class
*********************************************************************/
int Board::getStartRow() {
    return startRow;
}

/*********************************************************************
** Description:     get the start column from the board class
*********************************************************************/
int Board::getStartCol() {
    return startCol;
}

/*********************************************************************
** Description:     dynamic allocation of 2-D array and is de-allocated
**                  by the destructor
*********************************************************************/
void Board::setBoardArrayDimensions() {
    ptrBoard = new char*[getRows()];
    for (int row = 0; row < getRows(); row++) {
        ptrBoard[row] = new char[getCols()];
    }
}

/*********************************************************************
** Description:     sets the initial board characters to all white
*********************************************************************/
void Board::setAllBoardCharacters() {
    for (int row = 0; row < getRows(); row++) {
        for (int col = 0; col < getCols(); col++) {
            ptrBoard[row][col] = ' ';
        }
    }
}

/*********************************************************************
** Description:     gets the ant row on the board
*********************************************************************/
int Board::getAntCurrentRow() {
    return antBoardCurrentRow;
}

/*********************************************************************
** Description:     gets the ant col on the board
*********************************************************************/
int Board::getAntCurrentCol() {
    return antBoardCurrentCol;
}

/*********************************************************************
** Description:     takes two parameters that are the current row/col
**                  from the ant class and assigns them to the
**                  antBoard current row and column.
*********************************************************************/
void Board::setNewAntcoor(int row, int col) {
    antBoardCurrentRow = row;
    antBoardCurrentCol = col;
}

/*********************************************************************
** Description:     Displays the current game board
*********************************************************************/
void Board::showBoard() {
    // build the top border
    for (int topWall = 0; topWall < getRows(); topWall++) {
        cout << " -";
    }
    cout << endl;
    for (int row = 0; row < getRows(); row++) {
        cout << "|";    // build left wall
        for (int col = 0; col < getCols(); col++) {
            cout << ptrBoard[row][col] << " ";
        }
        cout << "|";    // build right wall
        cout << endl;
    }

    // build the bottom border
    for (int topWall = 0; topWall < getRows(); topWall++) {
        cout << " -";
    }
    cout << endl;
}

/*********************************************************************
** Description:     updates the ant's new orientation. Old orientation
**                  is taken in as a parameter including the row and
**                  column and checks the color of the square it is on
**                  in order to turn right or left. Function
**                  setCurrentColorVariable() is also called to
**                  save the current square color in member variable
**                  currentColor. Function flipColor() is then called
**                  to flip the color of the current square. Finally,
**                  new ant orientation is return.
*********************************************************************/
AntOrientation Board::updateOrientation(int row, int col, AntOrientation heading) {
    switch (heading) {
        case 1:
            // facing NORTH <-- ^ -->
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading EAST ->
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return EAST;                    // return new orientation
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading WEST <-
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return WEST;                    // return new orientation
            }
            break;
        case 2:
            // facing SOUTH <-- \/ -->
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading WEST ->
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return WEST;                    // return new orientation
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading EAST <-
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return EAST;                    // return new orientation
            }
            break;
        case 3:
            // facing EAST >>>
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading SOUTH ->
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return SOUTH;                   // return new orientation
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading NORTH <-
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return NORTH;                   // return new orientation
            }
            break;
        case 4:
            // facing WEST <<<
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading NORTH ->
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return NORTH;                   // return new orientation
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading SOUTH <-
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return SOUTH;                   // return new orientation
            }
            break;
        default:
            cout << "Error updating orientation!\n";
    }
}

/*********************************************************************
** Description:     checks the current square color and heading to
**                  determine where ant goes next. If the ant goes out
**                  of bounds, then other rules take precedence. Outer
**                  if statement determines if ant is out of bounds.
**                  If ant is out of bounds, then direction of ant is
**                  updated to reflect a direction that is 180 degrees
**                  from where it was previously heading and moved
**                  toward that direction. Inner if statement checks
**                  the row and col width of the board. If there is
**                  only one row or column on the board, different
**                  rules are observed. Specifically, the ant is not
**                  moved i.e., if there is only one row in the board
**                  and if the ant is facing NORTH, the ant direction
**                  is changed 180 degrees (SOUTH) however it does not
**                  move the ant since ant cannot move up or down when
**                  there is only one row. Same goes for columns. Outer
**                  else statement is for when ant is within bounds
**                  and there are more than 1 row/col on the game board.
*********************************************************************/
void Board::moveAnt(AntOrientation orientation) {
    switch (orientation) {
        case 1: // move ant NORTH unless it is out of bounds (if stmts)
            if ((antBoardCurrentRow-1) < 1) {
                // this if stmt changes direction of ant if it hits border
                wallHit = true;
                intTempHeading(SOUTH);
                if (rows < 2) {
                    // if board only has 1 row, do not move SOUTH
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol);
                }
                else {
                    // move ant SOUTH otherwise
                    setNewAntcoor(antBoardCurrentRow+1, antBoardCurrentCol);
                }
                break;
            } else {
                // move NORTH
                setNewAntcoor(antBoardCurrentRow-1, antBoardCurrentCol);
                break;
            }
        case 2: // move ant SOUTH unless it is out of bounds (if stmts)
            if ((antBoardCurrentRow+1) > rows) {
                // this if stmt changes direction of ant if it hits border
                wallHit = true;
                intTempHeading(NORTH);
                if (rows < 2) {
                    // if board only has 1 row, do not move NORTH
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol);
                }
                else {
                    // move ant NORTH otherwise
                    setNewAntcoor(antBoardCurrentRow-1, antBoardCurrentCol);
                }
                break;
            }
            else {
                // move SOUTH
                setNewAntcoor(antBoardCurrentRow+1, antBoardCurrentCol);
                break;
            }
        case 3: // move ant EAST unless it is out of bounds (if stmts)
            if ((antBoardCurrentCol+1) > cols) {
                // this if stmt changes direction of ant if it hits border
                wallHit = true;
                intTempHeading(WEST);
                if (cols < 2) {
                    // if board only has 1 row, do not move WEST
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol);
                }
                else {
                    // move ant WEST otherwise
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol-1);
                }
                break;
            }
            else {
                // move EAST
                setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol+1);
                break;
            }
        case 4: // move ant WEST unless it is out of bounds (if stmts)
            if ((antBoardCurrentCol-1) < 1) {
                // this if stmt changes direction of ant if it hits border
                wallHit = true;
                intTempHeading(EAST);
                if (cols < 2) {
                    // if board only has 1 row, do not move EAST
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol);
                }
                else {
                    // move ant EAST otherwise
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol+1);
                }
                break;
            }
            else {
                // move WEST
                setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol-1);
                break;
            }
        default:
            cout << "Error moving ant!\n";
    }
}

/*********************************************************************
** Description:     private function that sets the current color
**                  variable. This function is for internal use of
**                  the class.
*********************************************************************/
void Board::setCurrentColorVariable(char newColor) {
    currentColor = newColor;
}

/*********************************************************************
** Description:     flips the color of the square ant moved from
*********************************************************************/
void Board::flipColor(int row, int col) {
    if (currentColor == ' ') {
        ptrBoard[row][col] = '#';
    }
    else if (currentColor == '#') {
        ptrBoard[row][col] = ' ';
    }
}

/*********************************************************************
** Description:     save board color to variable and add ant character
*********************************************************************/
void Board::addAntCharacter(int row, int col) {
    currentColor = ptrBoard[row][col];
    ptrBoard[row][col] = '*';
}

/*********************************************************************
** Description:     add currentColor back to board
*********************************************************************/
void Board::addCurrentColor(int row, int col) {
    ptrBoard[row][col] = currentColor;
}

/*********************************************************************
** Description:     set temp ant orientation sets the ant orientation
**                  when the ant goes out of bound. Ant orientation is
**                  changed to changed to face the opposite direction
**                  i.e., north --> south and east --> west
*********************************************************************/
void Board::intTempHeading(int newHeading) {
    tempHeading = newHeading;
}

/*********************************************************************
** Description:     get temp ant orientation
*********************************************************************/
AntOrientation Board::wallCheckOrientation() {
   return static_cast<AntOrientation>(tempHeading);
}

/*********************************************************************
** Description:     get bool variable that indicates wall was hit
*********************************************************************/
bool Board::checkWallHitVar() {
    return wallHit;
}

/*********************************************************************
** Description:     takes a bool parameter that is set to true if
**                  moveAnt() detects that the ant has gone out of
**                  bounds.
*********************************************************************/
void Board::setCheckWallHitVar (bool val) {
    wallHit = val;
}

/*********************************************************************
** Description:     this functions takes in a parameter to track the
**                  steps. This is mainly in charge of checking
**                  whether the ant has moved out of bounds, updating
 *                  the ant on the board after moving it, updating
 *                  board class and ant class data variables, and
 *                  calling a function to display the updated board.
*********************************************************************/
void Board::moveAntOperations(int trackSteps) {
    for (int steps = 0; steps < getSteps(); steps++) {
        // total steps taken is increased by one for each step
        trackSteps++;

        // update ant orientation for ant going out of bounds. If ant goes out of bounds,
        // behavior is to make ant turn around 180 degree and move 1 square in that new
        // direction
        if (checkWallHitVar()) {
            ant.setAntOrientation( wallCheckOrientation() );
            setCheckWallHitVar(false);
        }

        // update ant orientation after moving moving ant on board
        ant.setAntOrientation( updateOrientation( ant.getCurrentRowLocation(),
                                                  ant.getCurrentColLocation(),
                                                  ant.getAntOrientation() ) );


        // move ant by getting getting new orientation from ant class and moving left
        // or right
        moveAnt( ant.getAntOrientation() );                // move and and update new coord in board
        ant.setCurrentRowLocation( getAntCurrentRow() );   // update new row coord in ant class
        ant.setCurrentColLocation( getAntCurrentCol() );   // update new col coord in ant class


        // show current ant location, show board with ant, then replace ant
        // add current ant location and update currentColor variable
        addAntCharacter( ant.getCurrentRowLocation()-1, ant.getCurrentColLocation()-1 );
        // show updated board
        showBoard();
        // replace ant with prior space character
        addCurrentColor( ant.getCurrentRowLocation()-1, ant.getCurrentColLocation()-1 );

        // display the steps taken by the ant
        cout << endl << "Steps taken " << trackSteps << endl << endl;
    }
}

/*********************************************************************
** Description:     this function prompts the user whether they want to
**                  play again or quit. A parameter is passed in as a
**                  reference to update the number of steps the ant
**                  has moved if the player decides to play again.
*********************************************************************/
bool Board::playAgain(int &steps) {
    // to control repeat games
    bool playAgain = true;
    // provide 2 choices: play again or quit
    if (menu.submenuPlayAgain() == "2") {
        playAgain = false;
        cout << "Thanks for playing!\n";
    }
    else {
        steps = 0;
    }
    return playAgain;
}
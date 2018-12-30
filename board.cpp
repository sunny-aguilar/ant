/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
*********************************************************************/
#include "board.hpp"

using std::cin;
using std::cout;
using std::endl;

Board::Board() {
    ptrBoard = nullptr;
    wallHit = false;
}

Board::~Board() {
    // delete dynamically allocated pointers
    for (int col = 0; col < getCols(); col++) {
        delete [] ptrBoard[col];
    }
    //Free the array of pointers
    delete [] ptrBoard;
}

void Board::setRows(int row) {
    this->rows = row;
}

void Board::setCols(int col) {
    this->cols = col;
}

void Board::setSteps(int steps) {
    this->steps = steps;
}

void Board::setStartRow(int startRow) {
    this->startRow = startRow;
}

void Board::setStartCol(int startCol) {
    this->startCol = startCol;
}

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
** Description:     sets the initial board characters to white
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
    // build top wall
    cout << " ";
    for (int wall = 0; wall < getRows(); wall++) {
        cout << " _";
    }
    cout << endl;

    // build board grid
    for (int row = 0; row < getRows(); row++) {
        cout << "| ";
        for (int col = 0; col < getCols(); col++) {
            cout << "[" << ptrBoard[row][col] << "]" << " ";
        }
        cout << "|";
        cout << endl;
    }

    // build bottom wall
    cout << " ";
    for (int wall = 0; wall < getRows(); wall++) {
        cout << " _";
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
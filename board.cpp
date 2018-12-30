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
    checkWallHit = false;
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

int Board::getCols() {
    return cols;
}

int Board::getSteps() {
    return steps;
}

int Board::getStartRow() {
    return startRow;
}

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
** Description:     sets the ant col on the board
*********************************************************************/
int Board::getAntCurrentCol() {
    return antBoardCurrentCol;
}

/*********************************************************************
** Description:     set new ant row/col from setBoardSpace function
*********************************************************************/
void Board::setNewAntcoor(int row, int col) {
    antBoardCurrentRow = row;
    antBoardCurrentCol = col;
}

/*********************************************************************
** Description:     Displays the current board
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
**                  is taken in as a parameter and checks the color
**                  of the square it is on in order to turn right or
**                  left
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
            // facing SOUTH
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
            // facing EAST
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
            // facing WEST
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
**                  determine where ant goes next
*********************************************************************/
void Board::moveAnt(AntOrientation orientation) {
    switch (orientation) {
        case 1:
            // move NORTH
            if ((antBoardCurrentRow-1) < 1) {
                // this if stmt changes direction of ant if it hits border
                // need to find a way to update the orientation to face SOUTH
                checkWallHit = true;
                intTempHeading(SOUTH);
                if (rows < 2) {
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol);
                }
                else {
                    setNewAntcoor(antBoardCurrentRow+1, antBoardCurrentCol);
                }

                break;
            } else {
                setNewAntcoor(antBoardCurrentRow-1, antBoardCurrentCol);
                break;
            }
        case 2:
            // move SOUTH
            if ((antBoardCurrentRow+1) > rows) {
                // this if stmt changes direction of ant if it hits border
                checkWallHit = true;
                intTempHeading(NORTH);
                if (rows < 2) {
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol);
                }
                else {
                    setNewAntcoor(antBoardCurrentRow-1, antBoardCurrentCol);
                }

                break;
            }
            else {
                setNewAntcoor(antBoardCurrentRow+1, antBoardCurrentCol);
                break;
            }
        case 3:
            // move EAST
            if ((antBoardCurrentCol+1) > cols) {
                // this if stmt changes direction of ant if it hits border
                checkWallHit = true;
                intTempHeading(WEST);
                if (cols < 2) {
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol);
                }
                else {
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol-1);
                }

                break;
            }
            else {
                setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol+1);
                break;
            }
        case 4:
            // move WEST
            if ((antBoardCurrentCol-1) < 1) {
                // this if stmt changes direction of ant if it hits border
                checkWallHit = true;
                intTempHeading(EAST);
                if (cols < 2) {
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol);
                }
                else {
                    setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol+1);
                }

                break;
            }
            else {
                setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol-1);
                break;
            }
        default:
            cout << "Error moving ant!\n";
    }
}

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
** Description:     save board color and add ant character
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


void Board::intTempHeading(int newHeading) {
    tempHeading = newHeading;
}

/*********************************************************************
** Description:     
*********************************************************************/
AntOrientation Board::wallCheckOrientation() {
   return static_cast<AntOrientation>(tempHeading);
}

/*********************************************************************
** Description:     get bool variable that indicates wall was hit
*********************************************************************/
bool Board::checkWallHitVar() {
    return checkWallHit;
}

/*********************************************************************
** Description:     takes a bool parameter that is set to true if
**                  moveAnt() detects that the ant has gone out of
**                  bounds.
*********************************************************************/
void Board::setCheckWallHitVar (bool val) {
    checkWallHit = val;
}
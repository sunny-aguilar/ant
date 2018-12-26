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
** Description:     sets the ant location on the board
*********************************************************************/
void Board::setAntLocation(int row, int col) {
    // adjustment included since arrays start at 0
    currentColor = getColor(row, col);
    ptrBoard[row-1][col-1] = '*';
}

/*********************************************************************
** Description:     gets the ant row on the board
*********************************************************************/
int Board::getAntCurrentRow() {
    // row and col already include the adjustment necessary from
    // setBoardSpace() --> setNewAntCoor() --> antCurrentRow
    return antBoardCurrentRow;
}

/*********************************************************************
** Description:     sets the ant col on the board
*********************************************************************/
int Board::getAntCurrentCol() {
    // roaw and col already include the adjustment necessary from
    // setBoardSpace() --> setNewAntCoor() --> antCurrentCol
    return antBoardCurrentCol;
}

/*********************************************************************
** Description:     set new ant row/col from setBoardSpace function
*********************************************************************/
void Board::setNewAntcoor(int row, int col) {
    // row and col received include the adjustment necessary from
    // setBoardSpace() so no further adj. needed
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
** Description:     updates the ant's new orientation based on color
**                  it is on
*********************************************************************/
AntOrientation Board::updateOrientation(int row, int col, AntOrientation heading) {
    switch (heading) {
        case 1:
            // facing NORTH
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading EAST ->
                cout << "Heading prior to move - NORTH\n"
                     << "Update heading to EAST\n";
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return EAST;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading WEST <-
                cout << "Heading prior to move - NORTH\n"
                     << "Update heading to WEST\n";
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return WEST;
            }
            break;
        case 2:
            // facing SOUTH
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading WEST ->
                cout << "Heading prior to move - SOUTH\n"
                     << "Update heading to WEST\n";
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return WEST;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading EAST <-
                cout << "Heading prior to move - SOUTH\n"
                     << "Update heading to EAST\n";
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return EAST;
            }
            break;
        case 3:
            // facing EAST
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading SOUTH ->
                cout << "Heading prior to move - EAST\n"
                     << "Update heading to SOUTH\n";
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return SOUTH;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading NORTH <-
                cout << "Heading prior to move - EAST\n"
                     << "Update heading to NORTH\n";
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return NORTH;
            }
            break;
        case 4:
            // facing WEST
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading NORTH ->
                cout << "Heading prior to move - WEST\n"
                     << "Update heading to NORTH\n";
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return NORTH;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading SOUTH <-
                cout << "Heading prior to move - WEST\n"
                     << "Update heading to SOUTH\n";
                setCurrentColorVariable(ptrBoard[row-1][col-1]);
                flipColor(row-1, col-1);
                return SOUTH;
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
                moveAnt(SOUTH);
                break;
            } else {
                setNewAntcoor(antBoardCurrentRow-1, antBoardCurrentCol);
                cout << "Move North - Row " << antBoardCurrentRow << " Col " << antBoardCurrentCol << endl;
                break;
            }
        case 2:
            // move SOUTH
            if ((antBoardCurrentRow+1) > rows) {
                // this if stmt changes direction of ant if it hits border
                moveAnt(NORTH);
                break;
            }
            else {
                setNewAntcoor(antBoardCurrentRow+1, antBoardCurrentCol);
                cout << "Move South - Row " << antBoardCurrentRow << " Col " << antBoardCurrentCol << endl;
                break;
            }
        case 3:
            // move EAST
            if ((antBoardCurrentCol+1) > cols) {
                // this if stmt changes direction of ant if it hits border
                moveAnt(WEST);
                break;
            }
            else {
                setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol+1);
                cout << "Move East - Row " << antBoardCurrentRow << " Col " << antBoardCurrentCol << endl;
                break;
            }
        case 4:
            // move WEST
            if ((antBoardCurrentCol-1) < 1) {
                // this if stmt changes direction of ant if it hits border
                moveAnt(EAST);
                break;
            }
            else {
                setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol-1);
                cout << "Move West - Row " << antBoardCurrentRow << " Col " << antBoardCurrentCol << endl;
                break;
            }
        default:
            cout << "Error moving ant!\n";
    }
}

/*********************************************************************
** Description:     gets the current color of the square ant is on
*********************************************************************/
char Board::getColor(int row, int col) {
    return ptrBoard[row][col];
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
        cout << "flipColor reached for ' '\n";
    }
    else if (currentColor == '#') {
        ptrBoard[row][col] = ' ';
        cout << "flipColor reached for #\n";
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
** Description:     delete old * position
*********************************************************************/
void Board::deletePriorLocation() {
    for (int row = 0; row < getRows(); row++) {
        for (int col = 0; col < getCols(); col++) {
            if (ptrBoard[row][col] == '*') {
//                ptrBoard[row][col] = currentColor;
                ptrBoard[row][col] = ' ';
            }
        }
    }
}

/*********************************************************************
** Description:     add currentColor back to board
*********************************************************************/
void Board::addCurrentColor(int row, int col) {
    cout << "Current color " << currentColor << endl;
    ptrBoard[row][col] = currentColor;
}

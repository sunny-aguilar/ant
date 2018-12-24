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
** Description:     delete old * position
*********************************************************************/
void Board::deletePriorLocation() {
    for (int row = 0; row < getRows(); row++) {
        for (int col = 0; col < getCols(); col++) {
            if (ptrBoard[row][col] == '*') {
//                ptrBoard[row][col] = currentColor;
                ptrBoard[row][col] = '@';
            }
        }
    }
}

/*********************************************************************
** Description:     add currentColor back to board
*********************************************************************/
void Board::addCurrentColor(int row, int col) {
    cout << "Current color " << currentColor << endl;
    ptrBoard[row-1][col-1] = currentColor;
//    ptrBoard[row-1][col-1] = '@';
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
** Description:     updates the ant's new orientation
*********************************************************************/
AntOrientation Board::updateOrientation(int row, int col, AntOrientation heading) {
    switch (heading) {
        case 1:
            // facing NORTH
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading EAST ->
                cout << "Heading prior to move - NORTH\n"
                     << "Update heading to EAST\n";
                setCurrentColor(ptrBoard[row-1][col-1]);
                ptrBoard[row-1][col-1] = getColor(row-1, row-2);
                return EAST;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading WEST <-
                cout << "Heading prior to move - NORTH\n"
                     << "Update heading to WEST\n";
                return WEST;
            }
            break;
        case 2:
            // facing SOUTH
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading WEST ->
                cout << "Heading prior to move - SOUTH\n"
                     << "Update heading to WEST\n";
                setCurrentColor(ptrBoard[row-1][col-1]);
                ptrBoard[row-1][col-1] = getColor(row-1, row-2);
                return WEST;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading EAST <-
                cout << "Heading prior to move - SOUTH\n"
                     << "Update heading to EAST\n";
                return EAST;
            }
            break;
        case 3:
            // facing EAST
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading SOUTH ->
                cout << "Heading prior to move - EAST\n"
                     << "Update heading to SOUTH\n";
                setCurrentColor(ptrBoard[row-1][col-1]);
                ptrBoard[row-1][col-1] = getColor(row-1, row-2);
                return SOUTH;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading NORTH <-
                cout << "Heading prior to move - EAST\n"
                     << "Update heading to NORTH\n";
                return NORTH;
            }
            break;
        case 4:
            // facing WEST
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading NORTH ->
                cout << "Heading prior to move - WEST\n"
                     << "Update heading to NORTH\n";
                setCurrentColor(ptrBoard[row-1][col-1]);
                ptrBoard[row-1][col-1] = getColor(row-1, row-2);
                return NORTH;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading SOUTH <-
                cout << "Heading prior to move - WEST\n"
                     << "Update heading to SOUTH\n";
                return SOUTH;
            }
            break;
        default:
            cout << "Error making move!\n";
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
            setNewAntcoor(antBoardCurrentRow-1, antBoardCurrentCol);
            cout << "Move North - Row " << antBoardCurrentRow << " Col " << antBoardCurrentCol << endl;
            break;
        case 2:
            // move SOUTH
            setNewAntcoor(antBoardCurrentRow+1, antBoardCurrentCol);
            cout << "Move South - Row " << antBoardCurrentRow << " Col " << antBoardCurrentCol << endl;
            break;
        case 3:
            // move EAST
            setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol+1);
            cout << "Move East - Row " << antBoardCurrentRow << " Col " << antBoardCurrentCol << endl;
            break;
        case 4:
            // move WEST
            setNewAntcoor(antBoardCurrentRow, antBoardCurrentCol-1);
            cout << "Move West - Row " << antBoardCurrentRow << " Col " << antBoardCurrentCol << endl;
            break;
        default:
            cout << "Error making move in moveAnt!\n";
    }
}

/*********************************************************************
** Description:     gets the current color of the square ant is on
*********************************************************************/
char Board::getColor(int row, int col) {
    return ptrBoard[row][col];
}

void Board::setCurrentColor(char newColor) {
    currentColor = newColor;
}

void Board::flipColor() {
    if (currentColor == ' ') {
        setCurrentColor('#');
        cout << "flipColor reached for ' '\n";
    }
    else if (currentColor == '#') {
        setCurrentColor(' ');
        cout << "flipColor reached for #\n";
    }
}
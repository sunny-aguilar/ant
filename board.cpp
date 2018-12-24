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
    return antCurrentRow;
}

/*********************************************************************
** Description:     sets the ant col on the board
*********************************************************************/
int Board::getAntCurrentCol() {
    // roaw and col already include the adjustment necessary from
    // setBoardSpace() --> setNewAntCoor() --> antCurrentCol
    return antCurrentCol;
}

/*********************************************************************
** Description:     get new ant row/col from setBoardSpace function
*********************************************************************/
void Board::setNewAntcoor(int row, int col) {
    // row and col received include the adjustment necessary from
    // setBoardSpace() so no further adj. needed
    antCurrentRow = row;
    antCurrentCol = col;
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
** Description:     parameters determine ant's current heading and
**                  the row and col determine the current space its in
*********************************************************************/
AntOrientation Board::setBoardSpace(int row, int col, AntOrientation heading) {
    switch (heading) {
        case 1:
            // facing NORTH
            if (ptrBoard[row-1][col-1] == '*') {
                // if the ant is on a white space, change heading EAST ->
                cout << "Reached\n";
                return EAST;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading WEST <-
                return WEST;
            }
            break;
        case 2:
            // facing SOUTH
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading WEST ->
                return WEST;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading EAST <-
                return EAST;
            }
            break;
        case 3:
            // facing EAST
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading SOUTH ->
                return SOUTH;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading NORTH <-
                return NORTH;
            }
            break;
        case 4:
            // facing WEST
            if (ptrBoard[row-1][col-1] == ' ') {
                // if the ant is on a white space, change heading NORTH ->
                return NORTH;
            }
            else if (ptrBoard[row-1][col-1] == '#') {
                // if the ant is on a black space, change heading SOUTH <-
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
void Board::moveAnt(char color) {
//    cout << "Color is " << color << endl;
//
//    switch (antOrientation) {
//        case 1:
//            if (color == '*') {
//                currentColLocation += 1;
//            }
//            else if (color == '#') {
//                currentColLocation -= 1;
//            }
//            break;
//        case 2:
//
//            break;
//        case 3:
//
//            break;
//        case 4:
//
//            break;
//        default:
//            cout << "Error making move in moveAnt!\n";
//    }
}

/*********************************************************************
** Description:     gets the current color of the square ant is on
*********************************************************************/
char Board::getColor(int row, int col) {
    return ptrBoard[row-1][col-1];
}
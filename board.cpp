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

}

Board::~Board() {
    // deallocate pointers here

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

void Board::setBoardArrayDimensions() {
    ptrBoard = new char*[getRows()];

    for (int row = 0; row < getRows(); row++) {
        ptrBoard[row] = new char[getCols()];
    }
}
/*********************************************************************
** Description:     sets the initial board characters
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
    currentColor = getCurrentColor(row, col);
    ptrBoard[row-1][col-1] = '*';
}

/*********************************************************************
** Description:     sets the ant row on the board
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
            cout << ptrBoard[row][col] << " ";
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
** Description:     paramaters row and col set board space to black or white on move
*********************************************************************/
AntOrientation Board::setBoardSpace(int row, int col, AntOrientation heading) {
    // get current color variable
    // added a new branch again
    switch (heading) {
        case 1:
            // facing north
            if (ptrBoard[row-2][col-1] == ' ') {
                // if the ant is on a white space, change heading -> and
                // change space to black

                // debugging tool - check location of array
//                ptrBoard[row-2][col-1] = '@';
//                cout << ptrBoard[row-3][col-1];

                ptrBoard[row-2][col-1] = '#';

                // return updated ant location
                cout << "SetBoard Space Row " << row-2 << " Col " << col-1 << endl;
                // only need to adjust row because
                setNewAntcoor(row-1, col);

                // add back currentColor where * previously was
//                addCurrentColor(row, col);

                return EAST;
            }
            else if (ptrBoard[row-2][col-1] == '#') {
                // if the ant is on a black space, change heading<- and
                // change space to white
                cout << "Row " << row << " col " << col-1 << " Heading " << WEST  << endl;
                ptrBoard[row-2][col-1] = ' ';

                // return updated ant location


                return WEST;
            }
            break;
        case 2:
            // facing south
            if (ptrBoard[row][col-1] == ' ') {
                // if the ant is on a white space, change heading -> and
                // change space to black
                cout << "Row " << row << " col " << col+1 << " Heading " << WEST << endl;
                ptrBoard[row][col-1] = '#';

                // return updated ant location
                setNewAntcoor(row-1, col);

                return WEST;
            }
            else if (ptrBoard[row][col-1] == '#') {
                // if the ant is on a black space, change heading <- and
                // change space to white
                cout << "Row " << row << " col " << col-1 << " Heading " << EAST  << endl;
                ptrBoard[row][col-1] = ' ';
                // return updated ant location
                return EAST;
            }
            break;
        case 3:
            // facing east
            if (ptrBoard[row-1][col] == ' ') {
                // if the ant is on a white space, change heading -> and
                // change space to black
                cout << "Row " << row << " col " << col+1 << " Heading " << SOUTH << endl;
                ptrBoard[row-1][col] = '#';
                // return updated ant location
                setNewAntcoor(row, col+1);
                return SOUTH;
            }
            else if (ptrBoard[row-1][col] == '#') {
                // if the ant is on a black space, change heading <- and
                // change space to white
                cout << "Row " << row << " col " << col-1 << " Heading " << NORTH  << endl;
                ptrBoard[row-1][col] = ' ';
                // return updated ant location
                return NORTH;
            }
            break;
        case 4:
            // facing west
            if (ptrBoard[row-1][col-2] == ' ') {
                // if the ant is on a white space, change heading -> and
                // change space to black
                cout << "Row " << row << " col " << col+1 << " Heading " << NORTH << endl;
                ptrBoard[row-1][col-2] = '#';
                // return updated ant location
                setNewAntcoor(row-1, col);

                return NORTH;
            }
            else if (ptrBoard[row-1][col-2] == '#') {
                // if the ant is on a black space, change heading <- and
                // change space to white
                cout << "Row " << row << " col " << col-1 << " Heading " << SOUTH  << endl;
                ptrBoard[row-1][col-2] = ' ';
                // return updated ant location
                return SOUTH;
            }
            break;
        default:
            cout << "Error making move!\n";
    }







}
/*********************************************************************
** Description:     gets the current color of the square ant is on
*********************************************************************/
char Board::getCurrentColor(int row, int col) {
    // may need to change to row-1 and col-1
    return currentColor = ptrBoard[row][col];
}
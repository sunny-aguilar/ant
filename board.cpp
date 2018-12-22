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
    currentColor = getCurrentColor(row, col);
    ptrBoard[row-1][col-1] = '*';
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

    switch (heading) {
        case 1:
            // facing north
            if (ptrBoard[row][col+1] == ' ') {
                // if the ant is on a white space, turn right -> and
                // change space to black
                cout << "Row " << row << " col " << col+1 << " Heading " << EAST << endl;
                ptrBoard[row-1][col] = '#';
                return EAST;
            }
            else if (ptrBoard[row][col] == '#') {
                // if the ant is on a black space, turn left <- and
                // change space to white
                cout << "Row " << row << " col " << col-1 << " Heading " << WEST  << endl;
                ptrBoard[row-1][col-2] = ' ';
                return WEST;
            }
            break;
        case 2:
            // facing south
            if (ptrBoard[row][col+1] == ' ') {
                // if the ant is on a white space, turn right -> and
                // change space to black
                cout << "Row " << row << " col " << col+1 << " Heading " << EAST << endl;
                ptrBoard[row-1][col] = '#';
                return EAST;
            }
            else if (ptrBoard[row][col] == '#') {
                // if the ant is on a black space, turn left <- and
                // change space to white
                cout << "Row " << row << " col " << col-1 << " Heading " << WEST  << endl;
                ptrBoard[row-1][col-2] = ' ';
                return WEST;
            }
            break;
        case 3:
            // facing east

            break;
        case 4:
            // facing west

            break;
        default:
            cout << "Error making move!\n";
    }







}
/*********************************************************************
** Description:     gets the current color of the square ant is on
*********************************************************************/
char Board::getCurrentColor(int row, int col) {
    return currentColor = ptrBoard[row][col];
}
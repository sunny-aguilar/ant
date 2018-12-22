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

void Board::setAllBoardCharacters() {
    for (int row = 0; row < getRows(); row++) {
        for (int col = 0; col < getCols(); col++) {
            ptrBoard[row][col] = '#';
        }
    }
}

void Board::setAntCharacter() {
    ptrBoard[getStartRow()][getStartCol()] = '*';
}

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
}

void Board::setBoardSpace(int row, int col, AntOrientation heading) {
    if (ptrBoard[row][col] == '#') {
        // if the ant is on a white space, turn right -> and
        // change space to black
        ptrBoard[row][col+1] = ' ';
    }
    else if (ptrBoard[row][col] == ' ') {
        // if the ant is on a black space, turn left <- and
        // change space to white
        ptrBoard[row][col+1] = '#';
    }


}
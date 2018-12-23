/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "ant.hpp"

class Board {
private:
    int rows;
    int cols;
    int steps;
    int startRow;
    int startCol;
    // updated row and col values for ant class
    int antCurrentRow;
    int antCurrentCol;
    char **ptrBoard = nullptr;
    char currentColor;

public:
    Board();
    ~Board();
    void setRows(int row);
    void setCols(int col);
    void setSteps(int steps);
    void setStartRow(int startRow);
    void setStartCol(int startCol);
    void setBoardArrayDimensions();
    void setAllBoardCharacters();
    void setAntLocation(int row, int col);

    int getRows();
    int getCols();
    int getSteps();
    int getStartRow();
    int getStartCol();
    int getAntCurrentRow();
    int getAntCurrentCol();

    void showBoard();
    AntOrientation setBoardSpace(int row, int col, AntOrientation heading);

    char getCurrentColor(int row, int col);
    void deletePriorLocation();
    // return updated ant row/col from setBoardSpace member function
    void setNewAntcoor(int row, int col);
};

#endif

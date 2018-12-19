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

class Board {
private:
    int rows;
    int cols;
    int steps;
    int startRow;
    int startCol;
    char **ptrBoard = nullptr;

public:
    Board();
    void setRows(int row);
    void setCols(int col);
    void setSteps(int steps);
    void setStartRow(int startRow);
    void setStartCol(int startCol);
    void setBoardArray();
    int getRows();
    int getCols();
    int getSteps();
    int getStartRow();
    int getStartCol();
};

#endif

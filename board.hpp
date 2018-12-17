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
    char **ptrBoard = nullptr;

public:
    Board();
    void setRows(int row);
    void setCols(int col);

};

#endif

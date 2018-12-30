/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Board class creates a game board that is used to
**                  maintain the board colors and move the ant. Works
**                  together with the Ant class to pass data between
**                  both in order to coordinate the ant location and
**                  heading.
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "ant.hpp"

class Board {
private:
    int rows;                   // total board rows
    int cols;                   // total board columns
    int steps;                  // total steps to move
    int startRow;               // start row of ant
    int startCol;               // start column of ant
    int antBoardCurrentRow;
    int antBoardCurrentCol;
    char **ptrBoard;
    char currentColor;
    bool wallHit;
    int tempHeading;
    void setCurrentColorVariable(char newColor);

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


    int getRows();
    int getCols();
    int getSteps();
    int getStartRow();
    int getStartCol();
    int getAntCurrentRow();
    int getAntCurrentCol();

    void showBoard();
    AntOrientation updateOrientation(int row, int col, AntOrientation heading);

    void addCurrentColor(int row, int col);
    // return updated ant row/col from setBoardSpace member function
    void setNewAntcoor(int row, int col);
    void moveAnt(AntOrientation orientation);
    void flipColor(int row, int col);

    void addAntCharacter (int row, int col);

    AntOrientation wallCheckOrientation();
    bool checkWallHitVar();
    void setCheckWallHitVar(bool val);
    void intTempHeading(int heading);
};

#endif

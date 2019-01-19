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
#include "menu.hpp"
using std::cin;
using std::cout;
using std::endl;

class Board {
private:
    Menu menu;
    Ant ant;
    int rows;                                       // total board rows
    int cols;                                       // total board columns
    int steps;                                      // total steps to move
    int startRow;                                   // start row of ant
    int startCol;                                   // start column of ant
    int antBoardCurrentRow;                         // ant current row
    int antBoardCurrentCol;                         // ant current column
    char **ptrBoard;                                // pointer to an array of pointers
    char currentColor;                              // current square color
    bool wallHit;                                   // wall was hit bool
    int tempHeading;                                // temporary ant heading
    void setCurrentColorVariable(char newColor);    // private function

public:
    Board();                                        // default constructor
    ~Board();                                       // destructor
    void startAntSimulation();
    void setRows(int row);                          // set board rows
    void setCols(int col);                          // set board columns
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

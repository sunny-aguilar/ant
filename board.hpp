/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Board class creates a game board that is used to
**                  maintain the board colors and move the ant. Works
**                  together with the Ant class to pass data between
**                  both in order to coordinate the ant location and
**                  heading. EXTRA CREDIT - see function called
**                  Board::setupStartLocation() for random start
**                  location option.
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
    char **ptrBoard;
    int rows;
    int cols;
    int steps;
    int startRow;
    int startCol;
    int antBoardCurrentRow;
    int antBoardCurrentCol;
    char currentColor;
    bool wallHit;
    int tempHeading;
    void setCurrentColorVariable(char newColor);

public:
    Board();
    ~Board();
    void startAntSimulation();
    void setBoardSizes(int MIN_ROW, int MAX_ROW);
    void setupSteps(int MIN_STEPS, int MAX_STEPS);
    void setupStartLocation();
    void setupOrientation();
    void setupBoardDetails();
    void showInitialBoardSetup();
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
    void setNewAntcoor(int row, int col);
    void moveAnt(AntOrientation orientation);
    void flipColor(int row, int col);
    void addAntCharacter (int row, int col);
    AntOrientation wallCheckOrientation();
    bool checkWallHitVar();
    void setCheckWallHitVar(bool val);
    void intTempHeading(int heading);
    void moveAntOperations(int trackSteps);
    bool playAgain(int &steps);
};

#endif

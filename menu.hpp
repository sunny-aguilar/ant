/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Menu class is used to show meny options as well as
**                  to validate user input. Input validation is done
**                  using a generic validators where the ranges are
**                  set as determined by the needs of main.cpp (thus
**                  making it portable and re-usable. Private function
**                  is used for internal class purposes only.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Menu {
private:
    string selection;
    int validateCustomStarting(int min, int customLocation);

public:
    void showStartMenu();
    void setSelection(string select);
    string getSelection();
    string validateSelection();
    int validateOrientation();
    int validateNumber(int min, int max);
    void submenuRows();
    void submenuCols();
    void submenuSteps();
    void submenuStartLocation();
    int submenuRowStartLocation(int boardSize);
    int submenuColStartLocation(int boardSize);
    int setRandomLocation(int boardSize);
    void submenuSetAntOrientation();
    void submenuInitializeAntMessage();
    string submenuPlayAgain();
};

#endif

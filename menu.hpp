/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP
#include <string>
using std::string;

class Menu {
private:
    string selection;           // holds main menu selection made;
    int validateCustomStarting(int min, int customLocation);     // move to private variable section

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
    void submenuInitializeAnt();
    void callNext();
    string submenuPlayAgain();
};

#endif

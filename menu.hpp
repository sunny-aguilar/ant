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

public:
    void showStartMenu();
    void setSelection(string select);
    string getSelection();
    string validateSelection();
    int validateNumber(int min, int max);
    int validateStartingSelection();
    int validateCustomStarting(int min, int customLocation);     // move to private variable section
    int validateOrientation();

    void subMenuRows();
    void subMenuCols();
    void subMenuSteps();
    void subMenuStartLocation();
    int subMenuRowStartLocation(int boardSize);
    int subMenuColStartLocation(int boardSize);
    int setRandomLocation(int boardSize);
    void subMenuSetAntOrientation();
    int returnInteger(string str);
    int getInteger();
    void callNext();
};

#endif

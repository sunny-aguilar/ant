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
    int validateSize(string dimension, int min, int max);
    int validateSteps(int min, int max);
    int validateStartingSelection();
    int validateCustomStarting(int customLocation);
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

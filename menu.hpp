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
    int validateSize(string dimension);
    int validateSteps();

    void subMenuRows();
    void subMenuCols();
    void subMenuSteps();
    void subMenuStartLocation();
    void subMenuStartRow();
    void subMenuStartCol();
    int returnInteger(string str);
    int getInteger();
    void callNext();
};

#endif

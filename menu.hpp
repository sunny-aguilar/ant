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
    string selection;

public:
    void showStartMenu();
    void setSelection();
    string getSelection();
    void validateSelection();
    int validateRows();

    void subMenuRows();
    void subMenuCols();
    void subMenuSteps();
    void subMenuStartRow();
    void subMenuStartCol();
    int returnInteger(string str);
    int getInteger();
    void callNext();
};

#endif

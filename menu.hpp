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
    void subMenuRows();
    void subMenuCols();
    void setSelection();
    string getSelection();
    void validateSelection();
    int getInteger();
    void callNext();
};

#endif

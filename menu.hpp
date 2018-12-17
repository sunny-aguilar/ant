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
    string choice;

public:
    void showStartMenu();
    void setChoice();
    string getChoice();
    void validateSelection();
};

#endif

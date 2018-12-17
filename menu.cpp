/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
*********************************************************************/
#include "menu.hpp"
#include <iostream>
#include <regex>
using std::cin;
using std::cout;
using std::regex;

void Menu::showStartMenu() {
    cout << "1. Start Langston's Ant Simulation\n"
         << "2. Quit\n"
         << "Choice: ";
}

void Menu::setSelection() {
    getline(cin, selection);
}

string Menu::getSelection() {
    return selection;
}

void Menu::validateSelection() {
    regex validMatch("^[1-2]{1}$");
    std::smatch m;
    while (!std::regex_match(selection, m, validMatch)) {
        if (getSelection() == "1") {
            cout << "Option 1\n\n";
        }
        else if (getSelection() == "2") {
            cout << "Option 2\n\n";
        }
        else if (getSelection() > "2" || getSelection() < "1") {
            cout << "Invalid Input!\n\n"
                 << "Enter again: ";
            getline(cin, selection);
        }
        else {
            cout << "Invalid Input!\n\n"
                 << "Enter again: ";
            getline(cin, selection);
        }
    }
}

void Menu::callNext() {
    // use this function to call the next steps
    // after vlidation is completed (i.e., call
    // the next function in different class)
}
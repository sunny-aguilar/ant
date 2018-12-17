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

void Menu::setChoice() {
    getline(cin, choice);
}

string Menu::getChoice() {
    return choice;
}

void Menu::validateSelection() {
    regex validMatch("^[1-2]{1}$");
    std::smatch m;
    while (!std::regex_match(choice, m, validMatch)) {
        if (getChoice() == "1") {
            cout << "Option 1\n\n";
        }
        else if (getChoice() == "2") {
            cout << "Option 2\n\n";
        }
        else if (getChoice() > "2" || getChoice() < "1") {
            cout << "Invalid Input!\n\n"
                 << "Enter again: ";
            getline(cin, choice);
        }
        else {
            cout << "Invalid Input!\n\n"
                 << "Enter again: ";
            getline(cin, choice);
        }
    }
}
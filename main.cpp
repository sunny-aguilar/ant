/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
*********************************************************************/
#include "ant.hpp"
#include "board.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {

    // ant rules
    // If the ant is on a white space, turn right 90 degrees and change the space to black.
    // If the ant is on a black space, turn left 90 degrees and change the space to white.

    // call menu
//    Menu antMenu;
//    antMenu.showStartMenu();
//    antMenu.setChoice();
//    cout << "Selection made was " << antMenu.getChoice() << endl;
//    antMenu.validateSelection();

    bool flag = true;
    string choice;
    cout << "1. Start Langston's Ant Simulation\n"
         << "2. Quit\n"
         << "Choice: ";
    getline(cin, choice);

    while (flag) {
        if (choice == "1") {
            cout << "Option 1\n\n";
            flag = false;
        }
        else if (choice == "2") {
            return 0;
        }
        else if (choice > "2" || choice < "1") {
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


    return 0;
}
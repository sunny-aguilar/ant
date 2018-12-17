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
//#include <regex>
using std::cin;
using std::cout;
using std::endl;
using std::string;
//using std::regex;

int main() {

    // ant rules
    // If the ant is on a white space, turn right 90 degrees and change the space to black.
    // If the ant is on a black space, turn left 90 degrees and change the space to white.

    // create menu, board, and ant
    Menu antMenu;
    Board antBoard;
    // call menu
    antMenu.showStartMenu();
    // get user selection
    antMenu.setSelection();
//    cout << "Selection made was " << antMenu.getSelection() << endl;
    antMenu.validateSelection();

    antMenu.subMenuRows();
    antMenu.validateRows();
//    antBoard.setRows();
//
//    antMenu.subMenuCols();
//    antBoard.setCols();
//
//    antMenu.subMenuStartRow();
//    antMenu.subMenuStartCol();
//
//    antMenu.subMenuSteps();






//    regex validMatch("^[1-2]{1}$");
//    std::smatch m;
//
//    string choice;
//    cout << "1. Start Langston's Ant Simulation\n"
//         << "2. Quit\n"
//         << "Choice: ";
//    getline(cin, choice);
//
//    while (!std::regex_match(choice, m, validMatch)) {
//        if (choice == "1") {
//            cout << "Option 1\n\n";
//        }
//        else if (choice == "2") {
//            cout << "Exiting program...\n\n";
//            return 0;
//        }
//        else if (choice > "2" || choice < "1") {
//            cout << "Invalid Input!\n\n"
//                 << "Enter again: ";
//            getline(cin, choice);
//        }
//        else {
//            cout << "Invalid Input!\n\n"
//                 << "Enter again: ";
//            getline(cin, choice);
//        }
//    }


    return 0;
}
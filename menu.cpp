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
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
using std::regex;

void Menu::showStartMenu() {
    cout << "1. Start Langston's Ant Simulation\n"
         << "2. Quit\n"
         << "Choice: ";
}

void Menu::setSelection(string select) {
    this->selection = select;
}

string Menu::getSelection() {
    return selection;
}

// maybe there is a simpler way to validate? create multiple
// regex strings and select the one you need based on what
// is being validated?
string Menu::validateSelection() {
    string selection;
    getline(cin, selection);

    regex validMatch("^[1-2]{1}$");
    std::smatch m;

    while (!std::regex_match(selection, m, validMatch)) {
        if (getSelection() == "1") {
            cout << "Option 1\n\n";
        }
        else if (getSelection() == "2") {
            cout << "Option 2\n\n";
        }
        else {
            cout << "Invalid Input!\n\n"
                 << "Enter again: ";
            getline(cin, selection);
        }
    }
    return selection;
}
/*********************************************************************
** Description:     Validate number of rows for the board
*********************************************************************/
int Menu::validateSize(string dimension) {
    string choice;
    getline(cin, choice);

    regex validMatch("^[2-9]|[1-9][0-9]|100$");
    std::smatch m;

    while (!std::regex_match(choice, m, validMatch)) {
        cout << "Please enter a valid selection between 2-100\n";
        getline(cin, choice);
    }
    cout << "You have selected " << choice << " " << dimension << endl;

    return returnInteger(choice);
}
/*********************************************************************
** Description:     Validate number of steps during the simulation
*********************************************************************/
int Menu::validateSteps() {
    string steps;
    getline(cin, steps);

    regex validMatch("^[1-9]|[1-9][0-9]|[1-9][0-9][0-9]|1000$");
    std::smatch m;

    while (!std::regex_match(steps, m, validMatch)) {
        cout << "Please enter a valid number of steps between 1 and 1000\n";
        getline(cin, steps);
    }
    cout << "You have selected " << steps << " steps in the simulation\n\n";

    return returnInteger(steps);
}
/*********************************************************************
** Description:     Validate start location of the ant
*********************************************************************/
int Menu::validateStartingSelection() {
    string start;
    getline(cin, start);

    regex validMatch("^[1-2]{1}$");
    std::smatch m;

    while (!std::regex_match(start, m, validMatch)) {
        cout << "Invalid Input!\n\n"
             << "Enter again: ";
        getline(cin, start);
    }

    return returnInteger(start);
}
/*********************************************************************
** Description:     Validate custom start location of the ant
*********************************************************************/
int Menu::validateCustomStarting(int boardSize) {
    string regexPattern;

    if (boardSize < 10)
        regexPattern = "^[2-9]$";
    else if (boardSize < 100)
        regexPattern = "^[2-9]|[1-9][0-9]$";
    else if (boardSize == 100)
        regexPattern = "^[2-9]|[1-9][0-9]|100$";

    string start;
    getline(cin, start);

    regex validMatch(regexPattern);
    std::smatch m;

    while (!std::regex_match(start, m, validMatch)) {
        cout << "Invalid Input!\n\n"
             << "Enter again: ";
        getline(cin, start);
    }

    return returnInteger(start);
}

void Menu::subMenuRows() {
    cout << "Great! Now let's create the board\n"
         << "Enter the number of rows for the board (min 2 rows, max 100 rows)\n";
}

void Menu::subMenuCols() {
    cout << "Enter the number of columns for the board (min 2 columns, max 100 columns)\n";
}

void Menu::subMenuSteps() {
    cout << "Enter the number of steps for the simulation\n";
}

int Menu::subMenuStartLocation() {
    cout << "Now enter 1 or 2 to set the starting location of the ant\n"
         << "1. Pick your own starting location\n"
         << "2. A random starting location\n ";

    return validateStartingSelection();
}

int Menu::subMenuRowStartLocation(int boardSize) {
    cout << "Enter the start row of the ant\n";
    return validateCustomStarting(boardSize);
}

int Menu::subMenuColStartLocation(int boardSize) {
    cout << "Enter the start column of the ant\n";
    return validateCustomStarting(boardSize);
}

int Menu::setRandomLocation(int boardSize) {
    int randomSize;
    unsigned seed;

    seed = time(0);
    srand(seed);
    randomSize = rand() % boardSize + 1;

    return randomSize;
}

int Menu::getInteger() {
    int info;
    cin >> info;
    return info;
}

void Menu::callNext() {
    // use this function to call the next steps
    // after vlidation is completed (i.e., call
    // the next function in different class)
}

int Menu::returnInteger(string str) {
    return std::stoi(str);
}
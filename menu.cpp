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
using std::endl;
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


// maybe there is a simpler way to validate? create multiple
// regex strings and select the one you need based on what
// is being validated?
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
/*********************************************************************
** Description:     Validate number of rows for the board
*********************************************************************/
int Menu::validateSize(string dimension) {
    string choice;
    getline(cin, choice);

    regex validMatch("^[2-9]|[1-9][0-9]|100$");
    std::smatch m;

    while (!std::regex_match(choice, m, validMatch)) {
        cout << "Please enter a valid selection of 2-100 rows\n";
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
    cout << "You have selected " << steps << " steps\n";

    return returnInteger(steps);
}

void Menu::subMenuRows() {
    cout << "Enter the number of rows for the board (min 2 rows, max 10 rows)\n";
}

void Menu::subMenuCols() {
    cout << "Enter the number of columns for the board (min 2 columns, max 10 columns)\n";
}

void Menu::subMenuSteps() {
    cout << "Enter the number of steps for the simulation\n";
}

void Menu::subMenuStartRow() {
    cout << "Enter the start row of the ant\n";
}

void Menu::subMenuStartCol() {
    cout << "Enter the start column of the ant\n";
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
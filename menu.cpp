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
#include <cctype>
#include <sstream>
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
    string choice;
    bool invalid = true;

    cout << "Choose 1 or 2:\n";
    getline(cin, choice);

    while (invalid) {
        if (choice.length() >= 1 && choice != "1" && choice != "2") {
            cout << "Invalid input!\n";
            cout << "Please enter 1 or 2\n";
            getline(cin, choice);
        }
        else {
            if (choice == "1") {
                cout << "You have selected choice 1\n";
                return choice;
            }
            else if (choice == "2") {
                cout << "You have selected choice 2\n";
                return choice;
            }
            invalid = false;
        }
    }
}
/*********************************************************************
** Description:     Validate number of rows for the board
*********************************************************************/
int Menu::validateSize(string dimension) {
    char choice[100];
    int boardSize = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    do {
        cout << "Enter an integer between 2 and 100\n";
        cin.getline(choice, 100);

        // check if length is greater than 3
        tooLong = false;
        if (strlen(choice) > 3) {
            tooLong = true;
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (int i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }

        // check if characters entered are within range
        notInRange = false;
        if (isNotDigit == false && tooLong == false) {
            convert.clear();
            convert << choice;
            convert >> boardSize;

            if (boardSize <= 100 && boardSize > 1) {
                cout << "You entered " << boardSize << " " << dimension << endl;
            }
            else {
                notInRange = true;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

//    cout << "C-string length is " << strlen(choice) << endl;
//    cout << "Is digit" << isdigit(choice[0]) << endl;

    return boardSize;
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
    switch (std::stoi(start)) {
        case 1:
            cout << "Custom starting position\n";
            break;
        case 2:
            cout << "Random starting position\n";
            break;
        default:
            cout << "Invalid selection!\n";
    }

    cout << "Selection made is " << start << endl;
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
/*********************************************************************
** Description:     Validate initial ant orientation
*********************************************************************/
int Menu::validateOrientation() {
    string orientation;
    getline(cin, orientation);

    regex validMatch("^[1-4]{1}$");
    std::smatch m;

    while (!std::regex_match(orientation, m, validMatch)) {
        cout << "Invalid Input!\n\n"
             << "Enter again: ";
        getline(cin, orientation);
    }
    cout << "Selection made is " << orientation << endl;
    return returnInteger(orientation);
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

void Menu::subMenuStartLocation() {
    cout << "Now enter 1 or 2 to set the starting location of the ant\n"
         << "1. Pick your own starting location\n"
         << "2. A random starting location\n ";
}

int Menu::subMenuRowStartLocation(int boardSize) {
    cout << "Enter the start row of the ant\n";
    return validateCustomStarting(boardSize);
}

int Menu::subMenuColStartLocation(int boardSize) {
    cout << "Enter the start column of the ant\n";
    return validateCustomStarting(boardSize);
}

void Menu::subMenuSetAntOrientation() {
    cout << "Select 1-4 to set the ant's starting orientation\n"
         << "1. North\n"
         << "2. South\n"
         << "3. East\n"
         << "4. West\n";
}

int Menu::setRandomLocation(int boardSize) {
    int randomSize;

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
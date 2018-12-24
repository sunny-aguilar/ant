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
#include <cctype>
#include <cstring>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;

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

/*********************************************************************
** Description:     validate selection
*********************************************************************/
string Menu::validateSelection() {
    string choice;
    bool invalid = true;

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
            }
            else if (choice == "2") {
                cout << "You have selected choice 2\n";
            }
            invalid = false;
        }
    }
    return choice;
}
/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Menu::validateNumber(int min, int max) {
    char choice[100];
    int amount = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();


    do {
        cout << "Enter an integer between " <<  min << " and " << max << endl;
        cin.getline(choice, 100);

        // check if length is greater than 3
        tooLong = false;
        if (strlen(choice) > length) {
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
            convert >> amount;

            if (amount >= min && amount <= max) {
                cout << "You entered " << amount << endl;
            }
            else {
                notInRange = true;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return amount;
}
/*********************************************************************
** Description:     validate custom start location of the ant
*********************************************************************/
int Menu::validateCustomStarting(int min, int boardSize) {
    return validateNumber(min, boardSize);
}
/*********************************************************************
** Description:     validate initial ant orientation
*********************************************************************/
int Menu::validateOrientation() {
    return validateNumber(1, 4);
}


/*********************************************************************
** Description:     show menu options
*********************************************************************/
void Menu::submenuRows() {
    cout << "Great! Now let's create the board\n"
         << "Enter the number of rows for the board (min 2 rows, max 100 rows)\n";
}

void Menu::submenuCols() {
    cout << "Enter the number of columns for the board (min 2 columns, max 100 columns)\n";
}

void Menu::submenuSteps() {
    cout << "Enter the number of steps for the simulation\n";
}

void Menu::submenuStartLocation() {
    cout << "Now enter 1 or 2 to set the starting location of the ant\n"
         << "1. Pick your own starting location\n"
         << "2. A random starting location\n ";
}

int Menu::submenuRowStartLocation(int boardSize) {
    cout << "Enter the start row of the ant\n";
    // make this function as private since it should only be accessed
    // within the class
    return validateCustomStarting(2, boardSize);
}

int Menu::submenuColStartLocation(int boardSize) {
    cout << "Enter the start column of the ant\n";
    // make this function as private since it should only be accessed
    // within the class
    return validateCustomStarting(2, boardSize);
}

void Menu::submenuSetAntOrientation() {
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

void Menu::submenuInitializeAntMessage() {
    cout << "Initializing Langston's Ant...";
}

string Menu::submenuPlayAgain() {
    cout << "1. Play again\n"
         << "2. Quit\n";
    return validateSelection();
}

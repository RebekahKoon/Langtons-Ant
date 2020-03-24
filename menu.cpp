/*********************************************************************
** Program name: project1
** Author:       Rebekah Koon
** Date:         6/26/19
** Description:  Source file for the menu function, which lets the
**               user choose whether or not to start Langton's ant
**               simulation and returns the player's choice.
*********************************************************************/

#include "menu.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::getline;
using std::atoi;
using std::string;
using std::endl;


/*********************************************************************
** Description: Function menu gives the user the option to start the 
**              Langton's ant simulation. Calls validInput to make 
**              sure input is valid. Returns 1 if the user wants to
**              play or 2 if the user wants to quit.
*********************************************************************/
int menu()
{
    string choiceStr;
    bool validChoice;
    int choiceInt;
    const int CHOICE_MIN = 1;
    const int CHOICE_MAX = 2;

    cout << "1. Start Langton's Ant simulation" << endl;
    cout << "2. Quit" << endl << endl;
    cout << "Please enter either 1 or 2 to perform your choice: ";
    getline(cin, choiceStr);

    //Calling validInput to see if the user entered 1 or 2
    validChoice = validInput(choiceStr, CHOICE_MIN, CHOICE_MAX);

    //Asking user to reenter choice if input is not valid
    while (!validChoice)
    {
        cout << "Please only enter either 1 or 2: ";
        getline(cin, choiceStr);

        validChoice = validInput(choiceStr, CHOICE_MIN, CHOICE_MAX);
    }

    //Changing choice to an integer
    choiceInt = atoi(choiceStr.c_str());

    return choiceInt;
}
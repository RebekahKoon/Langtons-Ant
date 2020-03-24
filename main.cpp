/****************************************************************************
** Program name: project1
** Author:       Rebekah Koon
** Date:         6/26/19
** Description:  This program is a simulation of Langton's ant. In order to
**               run the program, the user must first choose to run the 
**               program. If run, user inputs the number of rows and columns 
**               for the ant's board and the number of steps the ant takes. 
**               For extra credit, user can put ant in a random space. If not
**               put in a random location, asks the user for the ant's row
**               and column number. Uses Ant class to print the board after 
**               each step. With each step, the ant changes the color of the
**               space it is moving from and either moves right 90 degrees if
**               on a white space or left 90 degrees if on a black space 
**               Gives user choice to run the simulation again or quit.
****************************************************************************/

#include "Ant.hpp"
#include "menu.hpp"
#include "validInput.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::atoi;
using std::getline;
using std::endl;
using std::string;

int main()
{
    int choice;

    cout << "Project 1" << endl;
    cout << "Note: Extra credit is implemented" << endl << endl;
    choice = menu();

    //If user decides to run simulation
    while (choice == 1)
    {
        const int MIN_RANGE_BOARD = 2,
                  MAX_RANGE_BOARD = 100,
                  MIN_ROW_NUM = 1,
                  MIN_COL_NUM = 1,
                  MIN_STEPS = 1,
                  MAX_STEPS = 20000;

        int rowsInt,
            colsInt,
            stepsInt,
            antRowInt,
            antColInt;

        string rowsStr,
               colsStr,
               stepsStr,
               antRowStr,
               antColStr;

        string *randomAnswer = new string;

        unsigned seed;
        bool validAns;


        cout << endl << "Please enter an integer between" << endl
             << "2 and 100 for the number of rows: ";
        getline(cin, rowsStr);
    
        //Calling validInput to check if number of rows is valid
        validAns = validInput(rowsStr, MIN_RANGE_BOARD, MAX_RANGE_BOARD);
        while (!validAns)
        {
            cout << endl << "Please only enter an integer between" << endl
                 << "2 and 100 for the number of rows: ";
            getline(cin, rowsStr);

            validAns = validInput(rowsStr, MIN_RANGE_BOARD, MAX_RANGE_BOARD);
        }

        //Changing string for number of rows into an integer
        rowsInt = atoi(rowsStr.c_str());


        cout << endl << "Please enter an integer between " << endl
             << "2 and 100 for the number of columns: ";
        getline(cin, colsStr);

        //Calling validInput to check if number of columns is valid
        validAns = validInput(colsStr, MIN_RANGE_BOARD, MAX_RANGE_BOARD);
        while (!validAns)
        {
            cout << endl << "Please only enter an integer between" << endl
                 << "2 and 100 for the number of columns: ";
            getline(cin, colsStr);

            validAns = validInput(colsStr, MIN_RANGE_BOARD, MAX_RANGE_BOARD);
        }

        //Chaging string for number of columns into an integer
        colsInt = atoi(colsStr.c_str());


        cout << endl << "Please enter an integer between 1 and 20000 " << endl
             << "for the number of steps the ant should take: ";
        getline(cin, stepsStr);

        //Calling validInput to check if number of steps is valid
        validAns = validInput(stepsStr, MIN_STEPS, MAX_STEPS);
        while(!validAns)
        {
            cout << endl << "Please only enter an integer between " << endl
                 << "1 and 20000 for the number of steps: ";
            getline(cin, stepsStr);

            validAns = validInput(stepsStr, MIN_STEPS, MAX_STEPS);
        }

        //Changing string for number of steps into an integer
        stepsInt = atoi(stepsStr.c_str());


        cout << endl << "Should the ant be randomly set on the board?" << endl
             << "Enter yes for a random location or no to select a location: ";
        getline(cin, *randomAnswer);

        //Calling validInput to check if answer for random location is valid
        validAns = validInput(randomAnswer);
        while (!validAns)
        {
            cout << endl << "Please only type yes for a random location " 
                 << endl << "location or no to type in your own location: ";
            getline(cin, *randomAnswer);

            validAns = validInput(randomAnswer);
        }

        //Picking a random location for ant if answer was yes
        if (*randomAnswer == "yes")
        {
            seed = time(0);
            srand(seed);

            //Making the ant's row/column within the board's range
            antRowInt = rand() % rowsInt + 1;
            antColInt = rand() % colsInt + 1;
        }

        //If user wants to put in their own location for the ant
        else
        {
            cout << endl << "What row should the ant start in?" << endl
                 << "Type in an integer between 1 and " << rowsInt << ": ";
            getline(cin, antRowStr);

            //Calling validInput to check if ant's starting row is valid
            validAns = validInput(antRowStr, MIN_ROW_NUM, rowsInt);
            while (!validAns)
            {
                cout << endl << "Please only type in an integer between 1 and " 
                     << rowsInt << ": ";
                getline(cin, antRowStr);

                validAns = validInput(antRowStr, MIN_ROW_NUM, rowsInt);
            }

            //Changing ant's starting row from string to integer
            antRowInt = atoi(antRowStr.c_str());


            cout << endl << "What column should the ant start in?" << endl
                 << "Type in an integer between 1 and " << colsInt << ": ";
            getline(cin, antColStr);

            //Calling validInput to check if ant's starting column is valid
            validAns = validInput(antColStr, MIN_COL_NUM, colsInt);
            while (!validAns)
            {
                cout << endl << "Please only type in an integer between 1 and "
                     << colsInt << ": ";
                getline(cin, antColStr);

                validAns = validInput(antColStr, MIN_COL_NUM, colsInt);
            }

            //Changing ant's starting column from string to integer
            antColInt = atoi(antColStr.c_str());
        }

        //Calling Ant class constructor to initialize values
        Ant simulation(rowsInt, colsInt, antRowInt, antColInt);

        //Calling Ant class function to move ant desired number of steps
        simulation.antMovement(stepsInt);

        delete randomAnswer;

        //Repeats simulation if user wants to do it again
        cout << endl << "Would you like to play again?" << endl;
        choice = menu();
    }

    cout << endl << "Langton's ant program will now exit." << endl;

    return 0;
}
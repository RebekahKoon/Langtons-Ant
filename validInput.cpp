/**********************************************************************
** Program name: project1
** Author:       Rebekah Koon
** Date:         6/26/19
** Description:  Source file for functions validInput, which checks
**               to see if a user's input is valid or not. Returns true
**               if valid or false if not valid.
**********************************************************************/

#include "validInput.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using std::cin;
using std::cout;
using std::atoi;
using std::transform;
using std::endl;
using std::string;


/***********************************************************************
** Description: Function validInput takes as parameters a string and
**              and two integers representing the range an integer 
**              should be in. Checks to see if the string is an integer.
**              If it is not a positive integer or within the specified
**              range, returns false. If it is a positive integer within
**              the range, returns true.
**              Source: adapted from my lab 1 input validation function.
***********************************************************************/
bool validInput(string numberStr, int minNumber, int maxNumber)
{
    bool valid = true;
    int numberInt;

    //Checking to see if the string is a positive integer
    for (int i = 0; i < numberStr.length(); i++)
    {
        if (!isdigit(numberStr[i]))
        {
            valid = false;
        }
    }

    if (valid)
    {
        //Converting to an integer to check if it is within the min/max range
        numberInt = atoi(numberStr.c_str());

        //Checking to see if the integer is between the min/max range
        if (numberInt < minNumber || numberInt > maxNumber)
        {
            valid = false;
        }
    }

    return valid;
}


/**********************************************************************
** Description: Function validInput takes a pointer to a string as a
**              parameter. Converts the string to lowercase letters
**              and determines whether the answer is valid. If valid,
**              returns true. If not valid, returns false.
**              Source: https://stackoverflow.com/questions/313970/
**              how-to-convert-stdstring-to-lower-case
**********************************************************************/
bool validInput(string *answer)
{
    bool valid = true;

    //Converting the answer to lowercase
    transform(answer->begin(), answer->end(), answer->begin(), ::tolower);
    
    if (*answer != "yes" && *answer != "no")
    {
        valid = false;
    }

    return valid;
}
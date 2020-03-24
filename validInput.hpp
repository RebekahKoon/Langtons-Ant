/*********************************************************************
** Program name: project1
** Author:       Rebekah Koon
** Date:         6/26/19
** Description:  Header file for functions validInput, which either
**               takes in a string and two integers as parameters or
**               a pointer to a string in order to determine if a
**               user's input is valid. Returns true if valid or false
**               if not valid.
*********************************************************************/

#ifndef VALID_INPUT_HPP
#define VALID_INPUT_HPP

#include <string>

using std::string;

bool validInput(string, int, int);
bool validInput(string *);

#endif
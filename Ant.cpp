/***************************************************************************
** Program name: project1
** Author:       Rebekah Koon
** Date:         6/26/19
** Description:  Implementation file for the Ant class that simulates
**               Langton's ant. Contains a constructor to initialize private
**               variables and member function to move the ant a certain 
**               number of steps, two private functions to change the ant's
**               direction and space depending on the space color, and a 
**               private function to check if the ant's movement is valid.
**               An object from the Board class is used to keep track of the
**               board. A destructor deallocates the array's memory.
***************************************************************************/

#include "Ant.hpp"

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

/********************************************************************* 
** Description: Constructor for ant class initializes the number of
**              rows/columns on the board, row/column number the ant
**              starts at, and ant's starting direction. Also creates
**              a dynamic 2d array for the board and calls a function
**              from the Board class to pass array to the Board class.
*********************************************************************/
Ant::Ant(int rows, int cols, int antR, int antC)
{
    rowAmount = rows;
    colAmount = cols;

    //Index of board's first row/column is 0, so subtracting 1 from
    //the starting row/column number of ant's initial location
    antRow = antR - 1;
    antCol = antC - 1;

    direction = "up";

    //Creating dynamic 2d array with number of rows/columns inputted by user
    board = new char *[rowAmount];
    for (int i = 0; i < rowAmount; i++)
    {
        board[i] = new char[colAmount];
    }

    //Initializing array
    for (int i = 0; i < rowAmount; i++)
    {
        for (int j = 0; j < colAmount; j++)
        {
            //Placing the ant in its starting location
            if (i == (antRow) && j == (antCol))
            {
                board[i][j] = '*';
            }

            else
            {
                board[i][j] = ' ';
            }
        }
    }

    //Passing the array to the Board class
    langtonsAnt.setBoard(board);
}


/************************************************************************* 
** Description: Void function antMovement is a member of the Ant class
**              that takes the ant's number of steps as a parameter.
**              Uses Board class functions to get the current space color
**              of the ant as well as change the color of a space. Calls 
**              antWhiteSpace if ant is on a white space or antBlackSpace
**              if ant is on a black space in order to change the
**              direction and space of the ant. Changes ant's location
**              and prints the board with each step using the Board class.
*************************************************************************/
void Ant::antMovement(int steps)
{
    cout << endl << "Board before any steps are taken:" << endl;
    langtonsAnt.getBoard(rowAmount, colAmount);

    //Making the ant move the inputted number of steps
    for (int i = 0; i < steps; i++)
    {
        //Using Board class function to find ant's current space color
        char spaceColor = langtonsAnt.getSpaceColor();

        if (spaceColor == ' ')
        {
            //Board class function to change color of ant's space
            langtonsAnt.setSpaceColor(antRow, antCol);
            
            //Changing direction and space of ant
            antWhiteSpace();
        }

        else if (spaceColor == '#')
        {
            //Board class function to change color of ant's space
            langtonsAnt.setSpaceColor(antRow, antCol);

            //Changing direction and space of ant
            antBlackSpace();
        }

        //Board class function to set ant at new space
        langtonsAnt.setAnt(antRow, antCol);

        cout << "Step #" << i + 1 << ":" << endl;
        //Board class function to print board after each step
        langtonsAnt.getBoard(rowAmount, colAmount);
    }
}


/************************************************************************** 
** Description: Void function antWhiteSpace is a private member function of
**              the Ant class that determines the direction the ant is
**              facing when on a white space, turns the ant 90 degrees to 
**              the right, and moves the ant to a new space. Calls member 
**              function validMovement to determine if the move is legal.
**************************************************************************/
void Ant::antWhiteSpace()
{
    if (direction == "up")
    {
        direction = "right";
        antCol++;
    }
    
    else if (direction == "right")
    {
        direction = "down";
        antRow++;
    }

    else if (direction == "down")
    {
        direction = "left";
        antCol--;
    }

    else if (direction == "left")
    {
        direction = "up";
        antRow--;
    }

    //Calling validMovement to determine if ant moves off board
    validMovement();
}


/*********************************************************************** 
** Description: Void function antBlackSpace is a private member function
**              of the Ant class that determines the direction the ant
**              is facing if on a black space, turns the ant 90 degrees
**              to the left, and moves the ant to a new space. Calls
**              function validMovement to determine if move is legal.
***********************************************************************/
void Ant::antBlackSpace()
{
    if (direction == "up")
    {
        direction = "left";
        antCol--;
    }

    else if (direction == "right")
    {
        direction = "up";
        antRow--;
    }

    else if (direction == "down")
    {
        direction = "right";
        antCol++;
    }

    else if (direction == "left")
    {
        direction = "down";
        antRow++;
    }

    //Calling validMovement to determine if ant moves off board
    validMovement();
}


/********************************************************************** 
** Description: Void function validMovement is a private member of the
**              Ant class. If the ant's movement makes the ant go off
**              the board, wraps the ant around the board so the ant
**              will appear on the opposide side of the board.
**********************************************************************/
void Ant::validMovement()
{
    if (antRow >= rowAmount)
    {
        //Changes ant's row to the beginning row
        antRow = 0;
    }

    else if (antRow < 0)
    {
        //Changes ant's row to last row
        antRow = rowAmount - 1;
    }

    else if (antCol >= colAmount)
    {
        //Changes ant's column to beginning column
        antCol = 0;
    }

    else if (antCol < 0)
    {
        //Changes ant's column to last column
        antCol = colAmount - 1;
    }
}


/*********************************************************************** 
** Description: Deconstructor for the Ant class that deletes the
**              dynamically allocated 2d array.
***********************************************************************/
Ant::~Ant()
{
    for (int i = 0; i < rowAmount; i++)
    {
        delete [] board[i];
    }

    delete [] board;
}
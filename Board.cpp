/************************************************************************
** Program name: project1
** Author:       Rebekah Koon
** Date:         6/26/19
** Description:  Implementation file for the Board class. The Board class 
**               has a default constructor to initialize the board array 
**               and color of the ant's space. Has member functions to 
**               set the array for the board, get the current board, get 
**               the ant's current space color, change a space's color 
**               after an ant moves from the space, and set an ant on a 
**               new space. 
************************************************************************/

#include <iostream>
#include "Board.hpp"

using std::cout;
using std::endl;

/********************************************************************* 
** Description: Default constructor for the Board class that 
**              initializes the color of the space the ant starts on
**              and the board's memory location.
*********************************************************************/
Board::Board()
{
    color = ' ';
    board = NULL;
}


/********************************************************************* 
** Description: setBoard is a member function of the Board class that
**              takes a pointer to a 2d array representing the board
**              for Langton's ant as a parameter and assigns it to the
**              board variable.
*********************************************************************/
void Board::setBoard(char **boardIn)
{
    board = boardIn;
}


/********************************************************************* 
** Description: getBoard is a member function of the Board class that
**              takes the number of rows and columns of a board as
**              parameters. Uses these values to print board for
**              Langton's ant and the border around the board.
*********************************************************************/
void Board::getBoard(const int rows, const int columns)
{
    int numDashes = columns + 2;
    char horizontalBorder = '-';
    char verticalBorder = '|';

    //Creating top border
    for (int i = 0; i < numDashes; i++)
    {
        cout << horizontalBorder;
    }

    cout << endl;

    //Printing contents of board
    for (int i = 0; i < rows; i++)
    {
        //Creating left side of border
        cout << verticalBorder;

        for (int j = 0; j < columns; j++)
        {
            cout << board[i][j];
        }

        //Creating right side of border
        cout << verticalBorder << endl;
    }

    //Creating bottom border
    for (int i = 0; i < numDashes; i++)
    {
        cout << horizontalBorder;
    }

    cout << endl;
}


/********************************************************************* 
** Description: getSpaceColor is a member function of the Board class
**              that returns the ant's current space color.
*********************************************************************/
char Board::getSpaceColor()
{
    return color;
}


/********************************************************************* 
** Description: setSpaceColor is a private member function of the
**              Board class that takes the row and column number of a
**              space the ant is moving from as parameters. Changes
**              the space's color due to the ant moving off the space.
*********************************************************************/
void Board::setSpaceColor(const int rowNum, const int colNum)
{
    if (color == ' ')
    {
        board[rowNum][colNum] = '#';
    }

    else
    {
        board[rowNum][colNum] = ' ';
    }
    
}


/********************************************************************* 
** Description: setAnt is a private member function of the Board class
**              that takes the row and column number of the ant as 
**              parameters. Records the color of the ant's space and
**              then places the ant at the new space.
*********************************************************************/
void Board::setAnt(const int antRow, const int antCol)
{
    color = board[antRow][antCol];
    board[antRow][antCol] = '*';
}

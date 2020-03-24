/**************************************************************************
** Program name: project1
** Author:       Rebekah Koon
** Date:         6/26/19
** Description:  Header file for Board.cpp that defines the interface of
**               the Board class. The Board class has a default constructor
**               to initialize the board array and color of the ant's space.
**               Has member functions to set the array for the board, get
**               the current board, get the ant's current space color, 
**               change a space's color after an ant moves from the space, 
**               and set an ant on a new space. 
**************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
    private:
        //Pointer to a 2d array for the board
        char **board;

        //Current color of the ant's space
        char color;

    public:
        //Default constructor
        Board();

        void setBoard(char **boardIn);
        void getBoard(const int rows, const int columns);

        char getSpaceColor();
        void setSpaceColor(const int rowNum, const int colNum);

        void setAnt(const int antRow, const int antCol);
};

#endif
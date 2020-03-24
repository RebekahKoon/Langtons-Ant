/**************************************************************************
** Program name: project1
** Author:       Rebekah Koon
** Date:         6/26/19
** Description:  Header file for Ant.cpp that defines the interface of the
**               Ant class and simulates Langton's ant. Contains a
**               constructor to initialize private member variables and a
**               function to move the ant a certain number of steps, two
**               private functions to change the ant's direction and space
**               depending on the space color, and a private function to
**               check if the ant's movement is valid. An object from the
**               Board class is used to keep track of the board. Also 
**               contains a destructor to deallocate the array's memory.
**************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include <string>
#include "Board.hpp"

using std::string;

class Ant
{
    private:
        char **board;
        Board langtonsAnt;

        //Number of rows/columns for board
        int rowAmount;
        int colAmount;

        //Row/column position of the ant
        int antRow;
        int antCol;

        //Recording the position the ant is facing
        string direction;

        //Functions to make the ant change direction and move
        void antWhiteSpace();
        void antBlackSpace();

        //Checking to see if a move is valid
        void validMovement();

    public:
        //Constructor
        Ant(int rows, int cols, int antR, int antC);

        //Moving the ant a certain number of steps
        void antMovement(int steps);
        ~Ant();

};

#endif

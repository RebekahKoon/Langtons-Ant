## Program name: project1
## Author:       Rebekah Koon
## Date:         6/26/19
## Description:  Makefile that compiles a program that simulates
##               Langton's ant, where the user picks the row and
##               column number of the board, the location of the
##               ant on the board, and the number of steps the ant
##               takes. Prints the board with each of the ant's steps.

project1: Ant.o Board.o menu.o validInput.o main.o
	g++ -g Ant.o Board.o menu.o validInput.o main.o -o project1

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

validInput.o: validInput.cpp validInput.hpp
	g++ -c validInput.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o project1
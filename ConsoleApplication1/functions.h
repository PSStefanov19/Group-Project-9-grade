#pragma once
/*
================================
		  Libraries
================================
  */
//include in .h file to reduce compile time
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

/*
================================
	  Function signitures
================================
*/

//Draw title function
void title();

//Start game and draw game board functions
void startGame();
void drawBoard();

//Functions to turn square into the player's X or O
void toO(int Oy, int Ox);
void toX(int Xy, int Xx);
//Input function
void input();
//Function to check if either player has won
char checkWin();
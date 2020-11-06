#include <iostream>
//Use for clearing screen 
#include <windows.h>
//Use for getting input with kbhit and getch()
#include <conio.h>
//Standard namespace;
using namespace std;

/*
	================
	Global Variables
	================
*/

char GameBoard[9][9];

//Use for coloring everything in console with SetConsoleTextAttribute()
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);


/* 
	==================
	Functions for game
	==================
*/

//Display Title
void Title()
{
	//Color title to blue with black background
	SetConsoleTextAttribute(handle, 3);
	//Ascii art for title
	cout << "    _______ _          _______             _______			 " << endl;
	Sleep(75);
	cout << "   |__   __(_)        |__   __|           |__   __|		 " << endl;
	Sleep(75);
	cout << "      | |   _  ___ ______| | __ _  ___ ______| | ___   ___	 " << endl;
	Sleep(75);
	cout << "      | |  | |/ __|______| |/ _` |/ __|______| |/ _ \\ / _ \\ " << endl;
	Sleep(75);
	cout << "      | |  | | (__       | | (_| | (__       | | (_) |  __/ " << endl;
	Sleep(75);
	cout << "      |_|  |_|\\___|      |_|\\__,_|\\___|      |_|\\___/ \\___| " << endl;
	cout << endl;
	//Return to default console colors 
	SetConsoleTextAttribute(handle, 15);
}

//Draw Board
void DrawBoard() 
{
	//Fill board with blank spaces
	for (int y = 0; y < 9; y++) 
	{
		for (int x = 0; x < 9; x++) 
		{
			GameBoard[y][x] = ' ';
		}
	}
	for (int y = 0; y < 9; y++)
	{	
		//Center board a little bit
		cout << "                  ";
		for (int x = 0; x < 9; x++)
		{	
			//Draw board and vertical lines that devide squares
			SetConsoleTextAttribute(handle, 119);
			if ((x+1) % 3 == 0 && x+1 != 9) 
			{
				cout << GameBoard[y][x]<<" ";
				SetConsoleTextAttribute(handle, 136);
				cout << "  ";
			}
			else 
			{
				cout << GameBoard[y][x] << " ";
			}
		}
		// Draw horizontal lines that devide squares
		if ((y + 1) % 3 == 0 && (y + 1) != 9) 
		{
			SetConsoleTextAttribute(handle, 15);
			cout << endl;
			cout << "                  ";
			SetConsoleTextAttribute(handle, 136);
			cout << "                      ";
		}
		SetConsoleTextAttribute(handle, 15);
		cout << endl;
	}
}

/*	
	=============
	Main Function
	=============
*/
int main() 
{
	Title();
	//Clear screen after title is shown
	system("cls");
	while (true)
	{
		DrawBoard();
		system("cls");
	}
	//Return to default console colors
	SetConsoleTextAttribute(handle, 15);
	cout << ".";
}
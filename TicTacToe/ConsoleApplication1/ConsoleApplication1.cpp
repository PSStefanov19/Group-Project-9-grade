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
char playerInput;
int playerTurn = 0;

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


void startGame() 
{
	//Fill board with blank spaces
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			GameBoard[y][x] = ' ';
		}
	}
}
//Draw Board
void DrawBoard() 
{
	for (int y = 0; y < 9; y++)
	{	
		//Center board a little bit
		cout << "                  ";
		for (int x = 0; x < 9; x++)
		{	
			//Draw board and vertical lines that devide squares
			SetConsoleTextAttribute(handle, 119);
			if (GameBoard[y][x] == 'x')
			{
				SetConsoleTextAttribute(handle, 204);
				cout << GameBoard[y][x] << " ";
			}
			else if (GameBoard[y][x] == 'o')
			{
				SetConsoleTextAttribute(handle, 170);
				cout << GameBoard[y][x] << " ";
			}
			else
			{
				SetConsoleTextAttribute(handle, 119);
				cout << GameBoard[y][x] << " ";
			}
			if ((x+1) % 3 == 0 && x+1 != 9) 
			{
				SetConsoleTextAttribute(handle, 136);
				cout << "  ";
			}
		}
		 //Draw horizontal lines that devide squares
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

void toO(int Oy, int Ox) 
{
	GameBoard[Oy][Ox + 1] = 'o';
	GameBoard[Oy + 1][Ox] = 'o';
	GameBoard[Oy + 2][Ox + 1] = 'o';
	GameBoard[Oy + 1][Ox + 2] = 'o';
	playerTurn--;
}

void toX(int Xy, int Xx) 
{
	GameBoard[Xy][Xx] = 'x';
	GameBoard[Xy][Xx + 2] = 'x';
	GameBoard[Xy + 2][Xx] = 'x';
	GameBoard[Xy + 1][Xx + 1] = 'x';
	GameBoard[Xy + 2][Xx + 2] = 'x';
	playerTurn++;
}

void Input() 
{
	if (_kbhit) 
	{
		switch (_getch()) 
		{
		case '1':
			if (playerTurn == 0)
			{
				toX(6, 0);
			}
			else
			{
				toO(6, 0);
			}
			break;
		case '2':
			if (playerTurn == 0)
			{
				toX(6, 3);
			}
			else
			{
				toO(6, 3);
			}
			break;
		case '3':
			if (playerTurn == 0)
			{
				toX(6, 6);
			}
			else
			{
				toO(6, 6);
			}
			break;
		case '4':
			if (playerTurn == 0)
			{
				toX(3, 0);
			}
			else
			{
				toO(3, 0);
			}
			break;
		case '5':
			if (playerTurn == 0)
			{
				toX(3, 3);
			}
			else
			{
				toO(3, 3);
			}
			break;
		case '6':
			if (playerTurn == 0)
			{
				toX(3, 6);
			}
			else
			{
				toO(3, 6);
			}
			break;
		case '7':
			if (playerTurn == 0) 
			{
				toX(0,0);
			}
			else
			{
				toO(0,0);
			}
			break;
		case '8':
			if (playerTurn == 0)
			{
				toX(0, 3);
			}
			else
			{
				toO(0, 3);
			}
			break;
		case '9':
			if (playerTurn == 0)
			{
				toX(0, 6);
			}
			else
			{
				toO(0, 6);
			}
			break;
		}
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
	startGame();
	while (true)
	{
		DrawBoard();
		Input();
		system("cls");
	}
	//Return to default console colors
	SetConsoleTextAttribute(handle, 15);
	cout << ".";
}
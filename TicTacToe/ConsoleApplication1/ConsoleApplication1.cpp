#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

/*
	==================================================
					Global Variables
	==================================================
*/

char GameBoard[9][9];
char playerInput;
int playerTurn = 0;

//Use for coloring everything in console with SetConsoleTextAttribute()
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);


/* 
	==================================================
					Functions for game
	==================================================
*/

//Display Title and menu
void Title()
{
	string sentances[2] = { "Play against another human" , "Rules & Controls" };
	int arrow = 0;
	bool chosen = true;
	while (chosen) 
	{
		//Color title to blue with black background
		SetConsoleTextAttribute(handle, 3);
		//Ascii art for title
		cout << "    _______ _          _______             _______			 " << endl;
		cout << "   |__   __(_)        |__   __|           |__   __|		 " << endl;
		cout << "      | |   _  ___ ______| | __ _  ___ ______| | ___   ___	 " << endl;
		cout << "      | |  | |/ __|______| |/ _` |/ __|______| |/ _ \\ / _ \\ " << endl;
		cout << "      | |  | | (__       | | (_| | (__       | | (_) |  __/ " << endl;
		cout << "      |_|  |_|\\___|      |_|\\__,_|\\___|      |_|\\___/ \\___| " << endl;
		cout << endl;
		SetConsoleTextAttribute(handle, 10);
		//Menu for game
		cout << "Choose what you want to play(Use W, S and Space):" << endl;
		if (arrow == 0)
		{
			cout << "->";
		}
		cout << '\t' <<sentances[0] << endl;
		if (arrow == 1)
		{
			cout << "->";
		}
		cout << '\t' <<sentances[1] << endl;
		//Selection of play or rules page
		if (_kbhit) 
		{
			switch (_getch()) 
			{
				case 'w':
					if (arrow == 0) 
					{
						cout << "Already at top" << endl;
						Sleep(20);
					}
					else 
					{
						arrow--;
					}
					break;
				case 's':
					if (arrow == 1) 
					{
						cout << "Already at bottom" << endl;
						Sleep(20);
					}
					else 
					{
						arrow++;
					}
					break;
				case ' ':
					if (arrow == 0) 
					{
						chosen = false;
					}
					else 
					{
						system("cls");
						cout << "\tControls" << endl;
						cout << "Preferably this game uses the NumPad" << endl;
						cout << "So 7 corresponds to the top left cell of the gameboard and so on" << endl;
						cout << "\tRules" << endl;
						cout << " 1. The game is played on a grid that's 3 squares by 3 squares." << endl;
						cout << " 2. You are X, your friend (or the computer in this case) is O.\n   Players take turns putting their marks in empty squares." << endl;
						cout << " 3. The first player to get 3 of her marks in a row(up, down, across, or diagonally) is the winner." << endl;
						cout << " 4. When all 9 squares are full, the game is over.If no player has 3 marks in a row, the game ends in a tie. " << endl;
						system("pause");
					}
					break;
			}
		}
		system("cls");
	}
}

//Fill board with blank spaces 
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

//Turn cell to O
void toO(int Oy, int Ox) 
{
	GameBoard[Oy][Ox + 1] = 'o';
	GameBoard[Oy + 1][Ox] = 'o';
	GameBoard[Oy + 2][Ox + 1] = 'o';
	GameBoard[Oy + 1][Ox + 2] = 'o';
	playerTurn--;
}

//Turn cell to X
void toX(int Xy, int Xx) 
{
	GameBoard[Xy][Xx] = 'x';
	GameBoard[Xy][Xx + 2] = 'x';
	GameBoard[Xy + 2][Xx] = 'x';
	GameBoard[Xy + 1][Xx + 1] = 'x';
	GameBoard[Xy + 2][Xx + 2] = 'x';
	playerTurn++;
}

//Get input and change cells according to player turn
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
	==================================================
						Main Function
	==================================================
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
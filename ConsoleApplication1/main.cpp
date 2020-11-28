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

char gameBoard[9][9];
char playerInput;
int playerTurn = 0;
char winCondition[9]= {  ' ',' ',' ' ,
						 ' ',' ',' ' ,
						 ' ',' ',' '  };

//Use for coloring everything in console with SetConsoleTextAttribute()
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);


/* 
	==================================================
					Functions for game
	==================================================
*/

//Display Title and menu
void title()
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
						cout << "\t\tControls" << endl;
						cout << "Preferably this game is should be played the NumPad" << endl;
						cout << "So 7 corresponds to the top left cell of the gameboard and so on" << endl;
						cout << "\t\tRules" << endl;
						cout << " 1. The game is played on a grid that's 3 squares by 3 squares." << endl;
						cout << " 2. You are X, your friend is O.The first player is X.\n   Players take turns putting their marks in empty squares." << endl;
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
			gameBoard[y][x] = ' ';
		}
	}
}

//Draw Board
void drawBoard() 
{
	for (int y = 0; y < 9; y++)
	{	
		//Center board a little bit
		cout << "                  ";
		for (int x = 0; x < 9; x++)
		{	
			//Draw board and vertical lines that devide squares
			SetConsoleTextAttribute(handle, 119);
			if (gameBoard[y][x] == 'x')
			{
				SetConsoleTextAttribute(handle, 204);
				cout << gameBoard[y][x] << " ";
			}
			else if (gameBoard[y][x] == 'o')
			{
				SetConsoleTextAttribute(handle, 170);
				cout << gameBoard[y][x] << " ";
			}
			else
			{
				SetConsoleTextAttribute(handle, 119);
				cout << gameBoard[y][x] << " ";
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
	gameBoard[Oy][Ox + 1] = 'o';
	gameBoard[Oy + 1][Ox] = 'o';
	gameBoard[Oy + 2][Ox + 1] = 'o';
	gameBoard[Oy + 1][Ox + 2] = 'o';
}

//Turn cell to X
void toX(int Xy, int Xx) 
{
	gameBoard[Xy][Xx] = 'x';
	gameBoard[Xy][Xx + 2] = 'x';
	gameBoard[Xy + 2][Xx] = 'x';
	gameBoard[Xy + 1][Xx + 1] = 'x';
	gameBoard[Xy + 2][Xx + 2] = 'x';
}

//Get input and change cells according to player turn
void input() 
{
	if (_kbhit) 
	{
		switch (_getch()) 
		{
			//First row
		case '7':
			if (playerTurn == 0 && winCondition[0]==' ')
			{
				winCondition[0] = 'X';
				playerTurn++;
				toX(0, 0);
			}
			else if (playerTurn == 1 && winCondition[0] == ' ')
			{
				winCondition[0] = '0';
				playerTurn--;
				toO(0, 0);
			}
			break;
		case '8':
			if (playerTurn == 0 && winCondition[1] == ' ')
			{
				winCondition[1] = 'X';
				playerTurn++;
				toX(0, 3);
			}
			else if (playerTurn == 1 && winCondition[1] == ' ')
			{
				winCondition[1] = '0';
				playerTurn--;
				toO(0, 3);
			}
			break;
		case '9':
			if (playerTurn == 0 && winCondition[2] == ' ')
			{
				winCondition[2] = 'X';
				playerTurn++;
				toX(0, 6);
			}
			else if (playerTurn == 1 && winCondition[2] == ' ')
			{
				winCondition[2] = '0';
				playerTurn--;
				toO(0, 6);
			}
			break;
			//Second row
		case '4':
			if (playerTurn == 0 && winCondition[3] == ' ')
			{
				winCondition[3] = 'X';
				playerTurn++;
				toX(3, 0);
			}
			else if (playerTurn == 1 && winCondition[3] == ' ')
			{
				winCondition[3] = '0';
				playerTurn--;
				toO(3, 0);
				
			}
			break;
		case '5':
			if (playerTurn == 0 && winCondition[4] == ' ')
			{
				winCondition[4] = 'X';
				playerTurn++;
				toX(3, 3);
				
			}
			else if (playerTurn == 1 && winCondition[4] == ' ')
			{
				winCondition[4] = '0';
				playerTurn--;
				toO(3, 3);
				
			}
			break;
		case '6':
			if (playerTurn == 0 && winCondition[5] == ' ')
			{
				winCondition[5] = 'X';
				playerTurn++;
				toX(3, 6);
				
			}
			else if (playerTurn == 1 && winCondition[5] == ' ')
			{
				winCondition[5] = '0';
				playerTurn--;
				toO(3, 6);
				
			}
			break;
			//Third row
		case '1':
			if (playerTurn == 0 && winCondition[6] == ' ')
			{
				winCondition[6] = 'X';
				playerTurn++;
				toX(6, 0);
				
			}
			else if (playerTurn == 1 && winCondition[6] == ' ')
			{
				winCondition[6] = '0';
				playerTurn--;
				toO(6, 0);
				
			}
			break;
		case '2':
			if (playerTurn == 0 && winCondition[7] == ' ')
			{
				winCondition[7] = 'X';
				playerTurn++;
				toX(6, 3);
				
			}
			else if (playerTurn == 1 && winCondition[7] == ' ')
			{
				winCondition[7] = '0';
				playerTurn--;
				toO(6, 3);
				
			}
			break;
		case '3':
			if (playerTurn == 0 && winCondition[8] == ' ')
			{
				winCondition[8] = 'X';
				playerTurn++;
				toX(6, 6);
				
			}
			else if (playerTurn == 1 && winCondition[8] == ' ')
			{	
				winCondition[8] = '0';
				playerTurn--;
				toO(6, 6);
			}
			break;
		}
	}
}

char checkWin() 
{
	if ((winCondition[0] == 'X' && winCondition[1] == 'X' && winCondition[2] == 'X') ||
		(winCondition[3] == 'X' && winCondition[4] == 'X' && winCondition[5] == 'X') ||
		(winCondition[6] == 'X' && winCondition[7] == 'X' && winCondition[8] == 'X') ||
		(winCondition[0] == 'X' && winCondition[3] == 'X' && winCondition[6] == 'X') ||
		(winCondition[1] == 'X' && winCondition[4] == 'X' && winCondition[7] == 'X') ||
		(winCondition[2] == 'X' && winCondition[5] == 'X' && winCondition[8] == 'X') ||
		(winCondition[0] == 'X' && winCondition[4] == 'X' && winCondition[8] == 'X') ||
		(winCondition[6] == 'X' && winCondition[4] == 'X' && winCondition[2] == 'X'))
	{
		return 'X';
	}

	if ((winCondition[0] == '0' && winCondition[1] == '0' && winCondition[2] == '0') ||
		(winCondition[3] == '0' && winCondition[4] == '0' && winCondition[5] == '0') ||
		(winCondition[6] == '0' && winCondition[7] == '0' && winCondition[8] == '0') ||
		(winCondition[0] == '0' && winCondition[3] == '0' && winCondition[6] == '0') ||
		(winCondition[1] == '0' && winCondition[4] == '0' && winCondition[7] == '0') ||
		(winCondition[2] == '0' && winCondition[5] == '0' && winCondition[8] == '0') ||
		(winCondition[0] == '0' && winCondition[4] == '0' && winCondition[8] == '0') ||
		(winCondition[6] == '0' && winCondition[4] == '0' && winCondition[2] == '0')) 
	{
		return '0';
	}
	else if (winCondition[0] != ' ' && winCondition[1] != ' ' && winCondition[2] != ' '
		&& winCondition[3] != ' ' && winCondition[4] != ' ' && winCondition[5] != ' '
		&& winCondition[6] != ' ' && winCondition[7] != ' ' && winCondition[8] != ' ')
	{
		return 'd';
	}
	return 'c';
}

/*	
	==================================================
						Main Function
	==================================================
*/
int main() 
{
	title();
	//Clear screen after title is shown
	system("cls");
	startGame();
	do
	{
		drawBoard();
		input();
		system("cls");
	}while (checkWin() == 'c');
	//Return to default console colors
	SetConsoleTextAttribute(handle, 15);
	if (checkWin() == 'X')
	{
		cout << "X wins";
	}
	else if (checkWin() == '0')
	{
		cout << "O wins";
	}
	else if (checkWin() == 'd')
	{
		cout << "Draw";
	}
	cout << ".";
}
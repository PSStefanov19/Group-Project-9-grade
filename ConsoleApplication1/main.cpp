#include <iostream>
#include "functions.h"
using namespace std;

/*	
	==================================================
						Main Function
	==================================================
*/
int main() 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
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
}
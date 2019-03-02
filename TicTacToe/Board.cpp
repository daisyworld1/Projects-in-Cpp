#include "Board.hpp" 
#include <iostream>

using namespace std;

Board::Board()
{
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			arr[i][j] = '.';
}

bool Board::makeMove(int x_in, int y_in, char player_in)
{
	int x = x_in;
	int y = y_in;
	char player = player_in;

	if (arr[x][y] == '.')
	{
		if (player == 'x')
		{
			arr[x][y] = 'x';
			return true;
		}
		else if (player == 'o')
		{
			arr[x][y] = 'o';
			return true;
		}
	}
	else
	{
		cout << "That square is already taken." << endl;
		return false;
	}

}


gameStatus Board::gameState()
{
	return outcome;
}

void Board::print(char arr[3][3])
{
	for (int i = 0;i < 3; i++)
		for (int j = 0; j < 3; j++)
			cout << arr[i][j];
	cout << endl;
}


#include "TicTacToe.hpp" 
#include <iostream>

using namespace std;


TicTacToe::TicTacToe(char playerTurn_in)
{
	playerTurn = playerTurn_in;
	if (playerTurn == 'x')
	{
		player1 = 'x';
		player2 = 'o';
	}
	else
	{
		player2 = 'x';
		player1 = 'o';
	}
}


void TicTacToe::play(gameStatus outcome)

{
	int tracker = 0;
	int outcome = 4;

	while (outcome == 4)
	{
		int x, y;

		if (tracker % 2 == 0)
		{
			playerTurn = player1;
		}
		else
		{
			playerTurn = player2;
		}

		do
		{
			cout << "Player " << playerTurn << ":please enter your move." << endl;
			cin >> x >> y;
			board.makeMove(a[3][3], x, y, playerTurn);

		} while (board.makeMove == false);

		tracker++;

		if (((a[0][0] == a[0][1] && a[0][0] == a[0][2]) || (a[1][0] == a[1][1] && a[1][0] == a[1][2]) || (a[2][0] == a[2][1] && a[2][0] == a[2][2]))
			&& playerTurn == 'x')
		{
			outcome = 1;
			cout << "x won" << endl;
		}

		else if (((a[0][0] == a[1][0] && a[0][0] == a[2][0]) || (a[0][1] == a[1][1] && a[0][1] == a[2][1]) || (a[0][2] == a[1][2] && a[0][2] == a[2][2]))
			&& playerTurn == 'x')
		{
			outcome = 1;
			cout << "x won" << endl;
		}

		else if (((a[0][0] == a[1][1] && a[0][0] == a[2][2]) || (a[2][0] == a[1][1] && a[2][0] == a[0][2])) && playerTurn == 'x')
		{
			outcome = 1;
			cout << "x won" << endl;
		}
		else if (((a[0][0] == a[0][1] && a[0][0] == a[0][2]) || (a[1][0] == a[1][1] && a[1][0] == a[1][2]) || (a[2][0] == a[2][1] && a[2][0] == a[2][2]))
			&& playerTurn == 'o')
		{
			outcome = 2;
			cout << "o won" << endl;
		}

		else if (((a[0][0] == a[1][0] && a[0][0] == a[2][0]) || (a[0][1] == a[1][1] && a[0][1] == a[2][1]) || (a[0][2] == a[1][2] && a[0][2] == a[2][2]))
			&& playerTurn == 'o')
		{
			outcome = 2;
			cout << "o won" << endl;
		}

		else if (((a[0][0] == a[1][1] && a[0][0] == a[2][2]) || (a[2][0] == a[1][1] && a[2][0] == a[0][2])) && playerTurn == 'o')
		{
			outcome = 2;
			cout << "o won" << endl;
		}

		else if (tracker < 9)
		{
			outcome = 4;
			cout << "Unfinished" << endl;

		}
		else if (tracker = 9)
		{
			outcome = 3;
			cout << "Draw" << endl;
		}
	}
}

int main()
{
	char player;
	//char **barr[3][3];
	gameStatus outcome1;
	cout << "Welcome to Tic Tac Toe, which player should go first? Enter 'x' or 'o'." << endl;
	cin >> player;
	TicTacToe game(player);
	game.play(outcome1);

	return 0;
}

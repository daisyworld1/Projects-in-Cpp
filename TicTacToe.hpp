#pragma once
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "Board.hpp"

class TicTacToe
{
private:
	Board board;
	char &playerTurn;
	char player1;
	char player2;



public:
	TicTacToe(char);

	void play(gameStatus outcome);

};

#endif
#pragma once
#ifndef BOARD_H
#define BOARD_H

enum gameStatus { X_WON, O_WON, DRAW, UNFINISHED };

class Board
{
private:

	char arr[3][3];
	gameStatus outcome;


public:

	Board();

	bool makeMove(int, int, char);

	gameStatus gameState();

	void print(char arr[3][3]);

};
#endif

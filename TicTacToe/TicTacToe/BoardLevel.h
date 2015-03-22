#ifndef BOARDLEVEL_H
#define BOARDLEVEL_H
#include <iostream>
#include <string>
using namespace std;

class BoardLevel
{
private:
	int turn = 0;
	string board[9];
	string Solved(string board[9]);
	void DisplayBoard();
	int BestMove(string _board[9]);

public:
	BoardLevel();
	void Easy();
	void Medium();
	void Hard();
};

#endif
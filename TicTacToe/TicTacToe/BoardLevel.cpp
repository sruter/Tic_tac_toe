#include "BoardLevel.h"
#include <time.h>

BoardLevel::BoardLevel(){
	int entry = 0;
	for (int square = 0; square < 9; square++){
		entry = square + 1;
		board[square] = to_string(entry);
	}
}

void BoardLevel::Easy(){
	int selection;

	cout << "\nInitial Board: \n\n";
	DisplayBoard();
	while (Solved(board) == "NONE")
	{
		if (turn % 2 == 0)
		{
			cout << "Please enter selection of square: ";
			cin >> selection;
			selection--;
			if ((selection >= 0 || selection <= 9) && (board[selection] != "X" || board[selection] != "O")){
				turn++;
				board[selection] = "X";
			}
			else{
				cout << "\nInvalid selection";
			}

		}
		else if (turn % 2 == 1)
		{
			for (int square = 0; square < 9; square++)
			{
				if (board[square] != "X" && board[square] != "O"){
					turn++;
					board[square] = "O";
					DisplayBoard();
					break;
				}
			}
		}
	}
	if (Solved(board) == "X")
		cout << "\nCongrats, you win!!!!\n";
	else if (Solved(board) == "O")
		cout << "\nToo bad, so sad, I win!\n";
	else if (Solved(board) == "DRAW")
		cout << "\nWelp, the cat has this one!\n";
};

void BoardLevel::Medium(){

	int selection;
	srand(time(NULL));
	int rNum;

	cout << "\nInitial Board: \n";
	DisplayBoard();
	while (Solved(board) == "NONE")
	{
		if (turn % 2 == 0)
		{
			cout << "\nPlease enter selection of square: ";
			cin >> selection;
			selection--;
			if ((selection >= 0 || selection <= 9) && (board[selection] != "X" || board[selection] != "O")){
				turn++;
				board[selection] = "X";
			}
			else{
				cout << "\nInvalid selection";
			}

		}
		else if (turn % 2 == 1)
		{
			rNum = rand() % 9;
			if (board[rNum] != "X" && board[rNum] != "O"){
				turn++;
				board[rNum] = "O";
				DisplayBoard();
			}
		}
		Solved(board);
	}
	if (Solved(board) == "X")
		cout << "\nCongrats, you win!!!!\n";
	else if (Solved(board) == "O")
		cout << "\nToo bad, so sad, I win!\n";
	else if (Solved(board) == "DRAW")
		cout << "\nWelp, the cat has this one!\n";
};

void BoardLevel::Hard(){
	int selection;
	int move;

	cout << "\nInitial Board: \n\n";
	DisplayBoard();
	while (Solved(board) == "NONE")
	{
		if (turn % 2 == 0)
		{
			cout << "Please enter selection of square: ";
			cin >> selection;
			selection--;
			if ((selection >= 0 || selection <= 9) && (board[selection] != "X" || board[selection] != "O")){
				turn++;
				board[selection] = "X";
			}
			else{
				cout << "\nInvalid selection";
			}

		}
		else if (turn % 2 == 1)
		{
			move = BestMove(board);
			board[move] = "O";
			turn++;
		}
	}
	if (Solved(board) == "X")
		cout << "\nCongrats, you win!!!!\n";
	else if (Solved(board) == "O")
		cout << "\nToo bad, so sad, I win!\n";
	else if (Solved(board) == "DRAW")
		cout << "\nWelp, the cat has this one!\n";
};
void BoardLevel::TwoPlayer(){
	int selection;

	cout << "\nInitial Board: \n\n";
	DisplayBoard();
	while (Solved(board) == "NONE")
	{
		if (turn % 2 == 0)
		{
			cout << "Player 1, please enter selection of square: ";
			cin >> selection;
			selection--;
			if ((selection >= 0 || selection <= 9) && (board[selection] != "X" || board[selection] != "O")){
				turn++;
				board[selection] = "X";
				DisplayBoard();
			}
			else{
				cout << "\nInvalid selection";
			}

		}
		else if (turn % 2 == 1)
		{
			cout << "Player 2, please enter selection of square: ";
			cin >> selection;
			selection--;
			if ((selection >= 0 || selection <= 9) && (board[selection] != "X" || board[selection] != "O")){
				turn++;
				board[selection] = "O";
				DisplayBoard();
			}
			else{
				cout << "\nInvalid selection ";
			}
		}
	}
	if (Solved(board) == "X")
		cout << "\nCongrats Player 1, you win!!!!\n";
	else if (Solved(board) == "O")
		cout << "\nCongrats Player 2, you win!!!!\n";
	else if (Solved(board) == "DRAW")
		cout << "\nWelp, the cat has this one!\n";
};

int BoardLevel::BestMove(string _board[9]){

	int move[3] = {};
	int finalMove;
	int square = 0;
	bool found = false;

	while (found != true){

		for (int square = 0; square < 9; square++)
		{
			if (_board[square] != "X" && _board[square] != "O"){
				_board[square] = "O";
				move[square] = square;
				square++;
				if (Solved(_board) == "0" || Solved(_board) == "DRAW")
					break;

			}
		}
		if (Solved(_board) == "O" || Solved(_board) == "DRAW")
			found = true;
		else if (square == 4 && Solved(_board) != "X" || Solved(_board) != "NONE")
			square = 0;
	}
	finalMove = move[0];
	return finalMove;
};

string BoardLevel::Solved(string board[9])
{
	//diagonal wins
	if ((board[0] == "X" && board[4] == "X" && board[8] == "X") || (board[6] == "X" && board[4] == "X" && board[2] == "X"))
		return "X";
	else if ((board[0] == "O" && board[4] == "O" && board[8] == "O") || (board[6] == "O" && board[4] == "O" && board[2] == "O"))
		return "O";

	//horizontal wins
	else if ((board[0] == "X" && board[1] == "X" && board[2] == "X") || (board[3] == "X" && board[4] == "X" && board[5] == "X") || (board[6] == "X" && board[7] == "X" && board[8] == "X"))
		return "X";
	else if ((board[0] == "O" && board[1] == "O" && board[2] == "O") || (board[3] == "O" && board[4] == "O" && board[5] == "O") || (board[6] == "O" && board[7] == "O" && board[8] == "O"))
		return "O";

	//verticle wins
	else if ((board[0] == "X" && board[3] == "X" && board[6] == "X") || (board[1] == "X" && board[4] == "X" && board[7] == "X") || (board[2] == "X" && board[5] == "X" && board[8] == "X"))
		return "X";
	else if ((board[0] == "O" && board[3] == "O" && board[6] == "O") || (board[1] == "O" && board[4] == "O" && board[7] == "O") || (board[2] == "O" && board[5] == "O" && board[8] == "O"))
		return "O";

	//draws
	for (int i = 0; i < 9; i++){

		if ((board[i] == "X" || board[i] == "O") && i == 8)
			return "DRAW";
		else if (board[i] != "X" && board[i] != "O")
			break;
		else
			continue;
	}
	return "NONE";
};

void BoardLevel::DisplayBoard(){
	for (int i = 0; i<9; i++)
	{
		if (i == 0 || i == 3 || i == 6)
			cout << "\n\t|";
		cout << board[i] << "|";
	}
	cout << endl;
};
//Sherie Ruter
//Tic Tac Toe Game
//March, 2015

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "BoardLevel.h"
using namespace std;

int main(){

	char selection = ' ';
	bool gameOver = false;


	cout << "\t\tWelcome to Tic Tac Toe\n\n";
	while (gameOver != true){
		BoardLevel level;

		cout << "Please select your level of play:\nA) Easy\nB) Medium\nC) Hard\nD) Two Player\nE) Quit\n\nEnter letter of selection:  ";
		cin >> selection;

		if (selection == 'A' || selection == 'a')
			level.Easy();
		else if (selection == 'B' || selection == 'b')
			level.Medium();
		else if (selection == 'C' || selection == 'c')
			level.Hard();
		else if (selection == 'D' || selection == 'd')
			level.TwoPlayer();
		else if (selection == 'E' || selection == 'e'){
			gameOver = true;
			break;
		}
		else{
			cout << "Your selection was invalid\n";
		}

		cout << "\n\nDo you wish to play again?\n\t Enter (Y or N): ";
		cin >> selection;
		while (selection != 'Y' || selection != 'y'){
			if (selection == 'N' || selection == 'n'){
				gameOver = true;
				break;
			}
			else{
				cout << "Invalid Selection, please select again: ";
				cin >> selection;
			}
		}
		if (gameOver == true)
			break;
	}
	cout << "\n\nThanks for playing!\n\n";

	system("pause");
	return 0;
}
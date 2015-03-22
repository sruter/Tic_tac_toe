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


	cout << "\t\tWelcome to Tic Tac Toe\n";
	while (gameOver != true){
		BoardLevel level;

		cout << "\nPlease select your level of play:\nA) Easy\nB) Medium\nC) Hard\nD) Quit\n\nEnter letter of selection:  ";
		cin >> selection;

		if (selection == 'A')
			level.Easy();
		else if (selection == 'B')
			level.Medium();
		else if (selection == 'C')
			level.Hard();
		else if (selection == 'D'){
			gameOver = true;
			break;
		}
		else{
			cout << "Your selection was invalid\n";
		}

		cout << "\n\nDo you wish to play again?\n\t Enter (Y or N): ";
		cin >> selection;
		while (selection != 'Y'){
			if (selection == 'N'){
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
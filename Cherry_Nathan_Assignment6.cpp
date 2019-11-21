#include <iostream>

using namespace std; 

/* 

Author: Nathan Cherry
Objective: In this assignment, you will implement a computerized version of the game (Tic-Tac-Toe) using a 2-dimensional array. This game will be
played by two humans sharing the same keyboard. The screen will also show the snapshot or the
state of the board after every player’s move. You will store the board as a single 2-dimensional
array of base type char that has 3 rows and 3 columns.

*/

void ScoreBoard (char myArray[][3]); 
void input(char myArray[][3], int& turn);
void lines(); 
void initialize(char myArray[][3]); 
bool XWins(char myArray[][3], int& flagX); 
bool OWins(char myArray[][3], int& flagO);
bool Lose(char myArray[][3], int& loseNumber); 


int main() {

	char continueGame = 'Y'; 
	
	while (continueGame == 'Y' || continueGame == 'y') {

		char myArray[3][3];
		int flagX = 0;
		int flagO = 0;
		int loseNumber = 0;
		int turn = 0; // used to keep track of whose turn it is
		initialize(myArray);
		
		
		cout << "New Game: X goes first.\n";
		cout << endl; 

		do {
			ScoreBoard(myArray);
			input(myArray, turn);
			XWins(myArray, flagX);
			OWins(myArray, flagO);
			Lose(myArray, loseNumber);
		} while (flagX == 0 && flagO == 0 && loseNumber < 9);

		ScoreBoard(myArray);

		if (flagX == 1) {
			cout << "X IS THE WINNER!!!\n";
		}

		else if (flagO) {
			cout << "O IS THE WINNER!!!\n";
		}

		else {
			cout << "DRAW! NOBODY WINS!\n";
		}

		cout << "Another game? Enter Y or y for yes.\n"; 
		cin >> continueGame; 

	}

	return 0; 

}

void ScoreBoard(char myArray[][3]) { // prints the scoreboard
	lines(); 
	cout << "|R\\C| 0 | 1 | 2 | \n"; 
	lines(); 
	cout << "| 0 | " << myArray[0][0] << " | " << myArray[0][1] << " | " << myArray[0][2] << " |\n";
	lines(); 
	cout << "| 1 | " << myArray[1][0] << " | " << myArray[1][1] << " | " << myArray[1][2] << " |\n";
	lines(); 
	cout << "| 2 | " << myArray[2][0] << " | " << myArray[2][1] << " | " << myArray[2][2] << " |\n";
	lines(); 
	cout << endl << endl; 


}

void input(char myArray[][3], int& turn) {
	int tempNum1 = 0; 
	int tempNum2 = 0; 
	int assureValidNum = 0; // variable used to ensure the user inserts valid number


	if (turn == 0) {
		cout << "X's turn.\n"; 
		cout << "Where do you want your X placed?\n"; 
		cout << "Please enter row numberand column number separated by a space.\n"; 
		cin >> tempNum1; cin >> tempNum2; 
		if (myArray[tempNum1][tempNum2] == 'O' || myArray[tempNum1][tempNum2] == 'X' || !(tempNum1 >= 0) || !(tempNum1 <= 2) || !(tempNum2 >= 0) || !(tempNum2 <= 2)) {
			while (assureValidNum == 0) {
				if (myArray[tempNum1][tempNum2] == 'O' || myArray[tempNum1][tempNum2] == 'X') {
					cout << "That cell is already taken.\n";
					cout << "Please make another selection.\n"; 
				}
				else {
					cout << "Invalid entry: try again.\n";
					cout << "Row & column numbers must be either 0, 1, or 2.\n"; 					
				}
				cin >> tempNum1; cin >> tempNum2; 
				if (myArray[tempNum1][tempNum2] == 'O' || myArray[tempNum1][tempNum2] == 'X' || !(tempNum1 >= 0) || !(tempNum1 <= 2) || !(tempNum2 >= 0) || !(tempNum2 <= 2)) {
					assureValidNum = 0; 
				}
				else {
					assureValidNum = 1; 
				}
			}
		}
		cout << "You have entered row #" << tempNum1 << endl; 
		cout << "\t and column #" << tempNum2 << endl; 
		myArray[tempNum1][tempNum2] = 'X'; 
		 
		cout << "Thank you for your selection.\n"; 
		turn++; 
	}

	else {
		cout << "O's turn.\n";
		cout << "Where do you want your O placed?\n";
		cout << "Please enter row numberand column number separated by a space.\n";
		cin >> tempNum1; cin >> tempNum2;
		if (myArray[tempNum1][tempNum2] == 'O' || myArray[tempNum1][tempNum2] == 'X' || !(tempNum1 >= 0) || !(tempNum1 <= 2) || !(tempNum2 >= 0) || !(tempNum2 <= 2)) {
			while (assureValidNum == 0) {
				if ((myArray[tempNum1][tempNum2] == 'O') || (myArray[tempNum1][tempNum2] == 'X')) {
					cout << "That cell is already taken.\n";
					cout << "Please make another selection.\n";
				}
				else {
					cout << "Invalid entry: try again.\n";
					cout << "Row & column numbers must be either 0, 1, or 2.\n";
				}
				cin >> tempNum1; cin >> tempNum2;
				if (myArray[tempNum1][tempNum2] == 'O' || myArray[tempNum1][tempNum2] == 'X' || !(tempNum1 >= 0) || !(tempNum1 <= 2) || !(tempNum2 >= 0) || !(tempNum2 <= 2)) {
					assureValidNum = 0;
				}
				else {
					assureValidNum = 1;
				}
			}
		}
		cout << "You have entered row #" << tempNum1 << endl;
		cout << "\t and column #" << tempNum2 << endl;
		myArray[tempNum1][tempNum2] = 'O';	
		cout << "Thank you for your selection.\n";
		turn--; 
	}

}

void lines() {
	for (int i = 0; i < 17; i++) {
		cout << "-"; 
	}
	cout << endl; 
}

void initialize(char myArray[][3]) { // resets board

	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			myArray[i][j] = ' '; 
		}

	}
}

bool XWins(char myArray[][3], int& flagX) { //evaluates if X wins
	
		for (int i = 0; i <= 2; i++) {
			
				if (myArray[i][0] == 'X' && myArray[i][1] == 'X' && myArray[i][2] == 'X') {

					flagX = 1;
					return false;
				}
			
		}

		for (int j = 0; j <= 2; j++) {
			
				if (myArray[0][j] == 'X' && myArray[1][j] == 'X' && myArray[2][j] == 'X') {

					flagX = 1;
					return false;
				}
			
		}	

	if (myArray[0][0] == 'X' && myArray[1][1] == 'X' && myArray[2][2] == 'X') {
		
		flagX = 1;
		return false;
	}

	else if (myArray[0][2] == 'X' && myArray[1][1] == 'X' && myArray[2][0] == 'X') {

		flagX = 1;
		return false;
	}

	else if (flagX == 1) {
		return false; 
	}

	else {
		return true; 
	}
}

bool OWins(char myArray[][3], int& flagO) { //evaluates if O wins

	
		for (int i = 0; i <= 2; i++) {
			
				if (myArray[i][0] == 'O' && myArray[i][1] == 'O' && myArray[i][2] == 'O') {

					flagO = 1;
					return false;
				}
			
		}

		for (int j = 0; j <= 2; j++) {
			
				if (myArray[0][j] == 'O' && myArray[1][j] == 'O' && myArray[2][j] == 'O') {

					flagO = 1;
					return false;
				}
			
		}
	

	if (myArray[0][0] == 'O' && myArray[1][1] == 'O' && myArray[2][2] == 'O') {

		flagO = 1;
		return false;
	}

	else if (myArray[0][2] == 'O' && myArray[1][1] == 'O' && myArray[2][0] == 'O') {

		flagO = 1;
		return false;
	}

	else if (flagO == 1) {
		return false;
	}

	else {
		return true;
	}
}

bool Lose(char myArray[][3], int& loseNumber) { // determines if the board is full 
	loseNumber = 0; // indicates how many slots are filled
	for (int i = 0; i <= 2; i++) {

		for (int j = 0; j <= 2; j++) {

			if (myArray[i][j] == 'O' || myArray[i][j] == 'X' ) {
				loseNumber++; 
			}
		}
	}
	
	if (loseNumber == 9) {
		return false; 
	}
	else {
		return true;
	}
}
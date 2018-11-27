#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAX_ARRAY_SIZE = 18;
void InitializeBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);
void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);

void InitializeBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard) {
	int CurrentRow = 1;
	int CurrentColumn = 1;
	int RowsOnEachSide = 0;
	RowsOnEachSide = (numRowsInBoard / 2) - 1; //Amount of rows of each side
	for (int i = 0; i < MAX_ARRAY_SIZE; i++) { //rows of array
		for (int j = 0; j < MAX_ARRAY_SIZE; j++) { //columns of array
			//Initializing the white's side based on the board
			if (CurrentRow % 2 == 1 && CurrentColumn % 2 == 0 && CurrentRow <= RowsOnEachSide) {
				CMCheckersBoard[i][j] = 1;
					if (CurrentRow == 1) {
						CMCheckersBoard[i][j] = 2;
					}
				continue;
			}
			else if (CurrentRow % 2 == 0 && CurrentColumn % 2 == 1 && CurrentRow <= RowsOnEachSide) {
				CMCheckersBoard[i][j] = 1;
				continue;
			}
			//Initializing the red's side based on the board
			else if (CurrentRow % 2 == 1 && CurrentColumn % 2 == 0 && CurrentRow >= (numRowsInBoard - RowsOnEachSide)) {
				CMCheckersBoard[i][j] = 4;
				continue;
			}
			else if (CurrentRow % 2 == 0 && CurrentColumn % 2 == 1 && CurrentRow >= (numRowsInBoard - RowsOnEachSide)) {
				CMCheckersBoard[i][j] = 4;
				if (CurrentRow = numRowsInBoard) {
					CMCheckersBoard[i][j] = 5;
				}
			}
			else {
				CMCheckersBoard[i][j] = 0;
			}
		}
		CurrentColumn++;
	}
	CurrentRow++;
}

void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
}

void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard) {
	int BoardCount = 1;
	for (int i = 1; i < MAX_ARRAY_SIZE + 1; i++) {
		for (int j = 1; j < MAX_ARRAY_SIZE + 1; j++) {
			if (j = numRowsInBoard) {
				cout << endl;
				if (CMCheckersBoard[i][j] = 0) {
					cout << setw(4) << j + (i * 10);
				}
				else if (CMCheckersBoard[i][j] = 1) {
					cout << setw(4) << "WHITESOLDIER";
				}
				else if (CMCheckersBoard[i][j] = 2) {
					cout << setw(4) << "WHITEMULE";
				}
				else if (CMCheckersBoard[i][j] = 3) {
					cout << setw(4) << "WHITEKING";
				}
				else if (CMCheckersBoard[i][j] = 4) {
					cout << setw(4) << "REDSOLDIER";
				}
				else if (CMCheckersBoard[i][j] = 5) {
					cout << setw(4) << "REDMULE";
				}
				else if (CMCheckersBoard[i][j] = 6) {
					cout << setw(4) << "REDKING";
				}
			}
		}
	}
}
bool IsMove1Square(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLoc, int yLoc)
{
	if (player = 1) {
		if (CMCheckersBoard[yLoc][xLoc] == 1 || CMCheckersBoard[yLoc][xLoc] == 2) {// 1 for soldier and 2 for mule (white)
			//Checks for available moves at the left side of the board (white)
			if (xLoc == 0) {
				if (CMCheckersBoard[yLoc + 1][numRowsInBoard] != 0 && CMCheckersBoard[yLoc + 1][xLoc + 1] != 0)
					return false;
				else
					return true;
			}
			//Checks for available moves at the right side of the board (white)
			else if (xLoc == numRowsInBoard) {
				if (CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] != 0 && CMCheckersBoard[yLoc + 1][0] != 0)
					return false;
				else
					return true;
			}
			//Checks for available moves in the middle section of the board (white)
			else {
				if (CMCheckersBoard[yLoc + 1][xLoc - 1] != 0 && CMCheckersBoard[yLoc + 1][xLoc + 1] != 0)
					return false;
				else
					return true;
			}
		}
		//Test for White Kings
		if (CMCheckersBoard[yLoc][xLoc] == 3) {
			//Test left side of board
			if (xLoc == 0) {
				//Test front moves
				if (CMCheckersBoard[yLoc + 1][numRowsInBoard] != 0 && CMCheckersBoard[yLoc + 1][xLoc + 1] != 0)
					return false;
				else
					return true;
				//Test back moves
				if (CMCheckersBoard[yLoc - 1][numRowsInBoard] != 0 && CMCheckersBoard[yLoc - 1][xLoc + 1] != 0)
					return false;
				else
					return true;
			}
			//Test right side of the board
			else if (xLoc == numRowsInBoard) {
				//Test front moves
				if (CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] != 0 && CMCheckersBoard[yLoc + 1][0] != 0)
					return false;
				else
					return true;
				//Test back moves
				if (CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] != 0 && CMCheckersBoard[yLoc - 1][0] != 0)
					return false;
				else
					return true;
			}
			//Test middle section of the board
			else {
				//Test front moves
				if (CMCheckersBoard[yLoc + 1][xLoc - 1] != 0 && CMCheckersBoard[yLoc + 1][xLoc + 1] != 0)
					return false;
				else
					return true;
				//Test back moves
				if (CMCheckersBoard[yLoc - 1][xLoc - 1] != 0 && CMCheckersBoard[yLoc - 1][xLoc + 1] != 0)
					return false;
				else
					return true;
			}
		}
	}
	if (player = 2) {
		//Test movement availability for red soldiers and red mules
		if (CMCheckersBoard[yLoc][xLoc] == 4 || CMCheckersBoard[yLoc][xLoc] == 5) {
			//Test for when the red piece is on the left side of the board (Red moves the opposite direction)
			if (xLoc == 0) {
				if (CMCheckersBoard[yLoc - 1][numRowsInBoard] != 0 && CMCheckersBoard[yLoc - 1][xLoc + 1] != 0)
					return false;
				else 
					return true;
			}
			//Test for when the red piece is on the right side of the board
			else if (xLoc == numRowsInBoard) {
				if (CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] != 0 && CMCheckersBoard[yLoc - 1][0] != 0)
					return false;
				else
					return true;
			}
			//Test for movement in the middle section of the board
			else {
				if (CMCheckersBoard[yLoc - 1][xLoc - 1] != 0 && CMCheckersBoard[yLoc - 1][xLoc + 1] != 0)
					return false;
				else
					return true;
			}
		}
		//Test for Red Kings
		if (CMCheckersBoard[yLoc][xLoc] == 6) {
			//Test left side of board
			if (xLoc == 0) {
				//Test back moves
				if (CMCheckersBoard[yLoc + 1][numRowsInBoard] != 0 && CMCheckersBoard[yLoc + 1][xLoc + 1] != 0)
					return false;
				else
					return true;
				//Test front moves
				if (CMCheckersBoard[yLoc - 1][numRowsInBoard] != 0 && CMCheckersBoard[yLoc - 1][xLoc + 1] != 0)
					return false;
				else
					return true;
			}
			//Test right side of the board
			else if (xLoc == numRowsInBoard) {
				//Test back moves
				if (CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] != 0 && CMCheckersBoard[yLoc + 1][0] != 0)
					return false;
				else
					return true;
				//Test front moves
				if (CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] != 0 && CMCheckersBoard[yLoc - 1][0] != 0)
					return false;
				else
					return true;
			}
			//Test middle section of the board
			else {
				//Test back moves
				if (CMCheckersBoard[yLoc + 1][xLoc - 1] != 0 && CMCheckersBoard[yLoc + 1][xLoc + 1] != 0)
					return false;
				else
					return true;
				//Test front moves
				if (CMCheckersBoard[yLoc - 1][xLoc - 1] != 0 && CMCheckersBoard[yLoc - 1][xLoc + 1] != 0)
					return false;
				else
					return true;
			}
		}
	}

}
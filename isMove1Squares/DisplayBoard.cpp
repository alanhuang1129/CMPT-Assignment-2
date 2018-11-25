#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAX_ARRAY_SIZE = 18;
int main()
{
	int *arrayAddress[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
}
void InitializeBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);
void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);

void InitializeBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard) {
	int CurrentRow = 1;
	int CurrentColumn = 1;
	int RowsOnEachSide = 0;
	RowsOnEachSide = (numRowsInBoard / 2) - 1; //Amount of rows of each side
	for (int i = 0; i < MAX_ARRAY_SIZE; i++) { //rows of array
		for (int j = 0; j < MAX_ARRAY_SIZE; j++) { //columns of array

			if ((CurrentRow >= 1 && CurrentRow <= 3) || (MAX_ARRAY_SIZE - CurrentRow < 1 || MAX_ARRAY_SIZE - CurrentRow > 3)) {
				CMCheckersBoard[i][j] = 0;
				continue;
			}
			else if (CurrentRow % 2 == 1 && CurrentColumn % 2 == 1) {
				CMCheckersBoard[i][j] = 0;
				continue;
			}
			else if (CurrentRow % 2 == 0 && CurrentColumn % 2 == 0) {
				CMCheckersBoard[i][j] = 0;
				continue;
			}
			//Initializing the white's side based on the board
			else if (CurrentRow % 2 == 1 && CurrentColumn % 2 == 0 && CurrentRow <= RowsOnEachSide) {
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
	if (CMCheckersBoard[yLoc][xLoc]) {

	}

}
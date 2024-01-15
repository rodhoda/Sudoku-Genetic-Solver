#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

/*
Siimple board formatting, taken directly from Sudoku class
*/
void printBoard(int board[9][9]);

/*
bool function
checks to see if the spot its a valid spot or not for the backtracking. 

*/
bool canPlace(int arr[9][9], int row, int col, int n);

/*
Locations of empty spots 
*/
void isEmpty(int arr[9][9], int row, int col, int& rowNext, int& colNext);

/*
Create a copy of the board, used within the recrusive process. 

*/
void copyBoard(int arr[9][9], int arrCpy[9][9]);

/*
A vector of valid spots for the puzzle. 

*/
vector<int> findSpot(int arr[9][9], int row, int col);

/*
Recursive (backtrascking/DFS) function that will complete the puzzle if it is possible. 
*/
bool solve(int arr[9][9], int row, int col);


/*
function that takes user input, converts it into a string. 

An invalid string, or any normal string will just solve an empty board (a board full of zero's). 

*/
void boardSetter(int board[9][9], const string& Placements);


int main()
{

	string userInput;
	int board[9][9]{ 0 };

	cout << "Enter Board: ";
	cin >> userInput;

	boardSetter(board, userInput);

	if (solve(board, 0, 0)) {
		cout << "\n\nSudoku Solved\n\n";
		printBoard(board);
	}
	else {
		cout << "\n\nNot able to solve board :(\n\n";
	}

	return 0;
}









void printBoard(int board[9][9]) {
	cout << setw(2) << "+------+------+------+" << endl;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == 0) {
				cout << "|";
			}

			if ((j + 1) % 3 != 0) {
				cout << board[i][j] << " ";
			}
			else {
				cout << board[i][j] << setw(2) << "|";
			}
		}

		if ((i + 1) % 3 != 0) {
			cout << endl;
		}
		else {
			cout << endl << setw(2) << "+------+------+------+" << endl;
		}
	}
}

bool canPlace(int arr[9][9], int row, int col, int n)
{
	if (arr[row][col] != 0) return false;
	bool status = true;
	int gridx = (col / 3) * 3;
	int gridy = (row / 3) * 3;
	for (int i = 0; i < 9; i++) {
		if (arr[row][i] == n) {
			status = false;
			break;
		}
		if (arr[i][col] == n) {
			status = false;
			break;
		}
		if (arr[gridy + i / 3][gridx + i % 3] == n) {
			status = false;
			break;
		}
	}
	return status;
}

void isEmpty(int arr[9][9], int row, int col, int& rowNext, int& colNext)
{

	int indexNext = 9 * 9 + 1;
	for (int i = row * 9 + col + 1; i < 9 * 9; i++) {
		if (arr[i / 9][i % 9] == 0) {

			indexNext = i;
			break;
		}
	}
	rowNext = indexNext / 9;
	colNext = indexNext % 9;

}

void copyBoard(int arr[9][9], int arrCpy[9][9]) {
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			arrCpy[y][x] = arr[y][x];
		}
	}
}
std::vector<int> findSpot(int arr[9][9], int row, int col) {
	vector<int> placebles = {};
	for (int n = 1; n <= 9; n++) {

		if (canPlace(arr, row, col, n)) placebles.push_back(n);
	}
	return placebles;
}


bool solve(int arr[9][9], int row, int col)
{


	if (row > 8) {
		return true;
	}

	if (arr[row][col] != 0) {
		int rowNext, colNext;

		isEmpty(arr, row, col, rowNext, colNext);

		return solve(arr, rowNext, colNext);
	}

	vector<int> placebles = findSpot(arr, row, col);

	if (placebles.size() == 0) {

		return false;

	};

	bool status = false;
	for (int i = 0; i < placebles.size(); i++) {
		int n = placebles[i];

		int arrCpy[9][9];

		copyBoard(arr, arrCpy);

		arrCpy[row][col] = n;

		int rowNext = row;

		int colNext = col;

		isEmpty(arrCpy, row, col, rowNext, colNext);

		if (solve(arrCpy, rowNext, colNext)) {

			copyBoard(arrCpy, arr);

			status = true;

			break;
		}
	}
	return status;
}


void boardSetter(int board[9][9], const string& Placements) {

	int stringCounter = 0;
	int converter = 0;


	for (int i = 0; i < 9; i++) {

		for (int j = 0; j < 9; j++) {



			if (stringCounter > Placements.size() - 1)
			{
				break;
				return;
			}

			if (Placements[stringCounter] > 57 || Placements[stringCounter] < 48) {

				board[i][j] = 0;
			}
			else {
				converter = Placements[stringCounter] - '0';
				board[i][j] = converter;

			}
			stringCounter++;


		}
	}
}

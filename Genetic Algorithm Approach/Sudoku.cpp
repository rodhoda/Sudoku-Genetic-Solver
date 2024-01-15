#include "Sudoku.h"
#include "SudokuFitness.h"
#include <iomanip>

Sudoku::Sudoku() {
	this->fitnessLevel = 0;
}

void Sudoku::boardSetter(const string& Placements) {

	int stringCounter = 0;
	int converter = 0;
	this->reader = Placements;

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
				origBoard[i][j] = true;
			}
			stringCounter++;
		}
	}
	this->fitnessLevel = this->getFitness(*this);
}

 void Sudoku::displayBoard(ostream& outPut)const {
	 outPut << setw(2) << "+------+------+------+" << endl;

	 for (int i = 0; i < 9; i++)
	 {
		 for (int j = 0; j < 9; j++)
		 {
			 if (j == 0) {
				 cout << "|";
			}
			 
			 if ((j + 1) % 3 != 0) {
				 outPut << board[i][j] << " ";
			 }
			 else {
				 outPut << board[i][j] << setw(2) << "|";
			 }
		 }

		 if ((i + 1) % 3 != 0) {
			 outPut << endl;
		 }
		 else {
			 outPut << endl<< setw(2) << "+------+------+------+" << endl;
		 }
	 }

}

Puzzle& Sudoku::operator=(const Puzzle& copyMe) {
	const Sudoku& testCase = static_cast<const Sudoku&>(copyMe);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			this->board[i][j] = testCase.board[i][j];
			this->origBoard[i][j] = testCase.origBoard[i][j];
		}
	}
	this->reader = testCase.reader;
	this->fitnessLevel = testCase.fitnessLevel;

	return *this;
}
bool& Sudoku::operator>(const Puzzle& rightSide) {

	const Sudoku& testCase = static_cast<const Sudoku&>(rightSide);
	bool ans = this->fitnessLevel > testCase.fitnessLevel;
	return ans;
}
bool& Sudoku::operator<(const Puzzle& rightSide) {

	const Sudoku& testCase = static_cast<const Sudoku&>(rightSide);
	bool ans = this->fitnessLevel < testCase.fitnessLevel;
	return ans;
}
bool& Sudoku::operator==(const Puzzle& rightSide) {

	const Sudoku& testCase = static_cast<const Sudoku&>(rightSide);
	bool ans = this->fitnessLevel == testCase.fitnessLevel;
	return ans;
}

int Sudoku::getFitness(const Sudoku& fitLevel) {

	SudokuFitness fitChecker;
	this->fitnessLevel = fitChecker.howFit(this);
	return this->fitnessLevel;
}

int Sudoku::getFitnessLevel() {
	return this->fitnessLevel;
}

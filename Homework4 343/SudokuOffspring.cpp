#include "SudokuOffspring.h"
#include "SudokuFitness.h"

SudokuOffspring::SudokuOffspring(Sudoku* parentBoard) {

	

}


Puzzle& SudokuOffspring::makeOffspring(const Puzzle& parent) {

	/*Sudoku* sudok = dynamic_cast<Sudoku*>(parent);*/

	//change to Sudoku*
	/*this->childBoard = new Sudoku;*/


	const Sudoku& testCase = static_cast<const Sudoku&>(parent);

	this->childBoard = new Sudoku;

	*childBoard = testCase;


		for (int q = 0; q < 1; q++) {



			int i = (rand() % 9);
			int j = (rand() % 9);
			int p = 1 + (rand() % 9);

			if (testCase.origBoard[i][j] == false) {
				childBoard->board[i][j] = p;


			}
			else {


				q--;
			}

		}


	//else {

	//	string testy = childBoard->retFinalPiece(); 
	//	string iString;
	//	iString = testy.at(0); 
	//	string jString;
	//	jString = testy.at(1);
	//	for (int q = 0; q < 1; q++) {



	//		int i = stoi(iString);
	//		int j = stoi(jString);
	//		int p = 1 + (rand() % 9);

	//		if (testCase.origBoard[i][j] == false) {
	//			childBoard->board[i][j] = p;


	//		}
	//		else {


	//			q--;
	//		}

	//	}
	//

	//}

	childBoard->getFitness(*childBoard);




	return *childBoard;


};
#include "SudokuFactory.h"
#include "SudokuPopulation.h"

SudokuFactory::SudokuFactory(int numGenerations): numOfGenerations(numGenerations) {};

Puzzle* SudokuFactory::makePuzzle() {


	this->factorySudoku = new Sudoku;



	return factorySudoku;
}



void SudokuFactory::setBoard(string& placements) {

	
	
	this->factorySudoku = new Sudoku; 
	this->factorySudoku->boardSetter(placements);

	/*Sudoku* tryThis = new Sudoku; 
	tryThis->boardSetter(placements);*/ 

	return; 

}

Puzzle* SudokuFactory::getPuzzle() {

	return factorySudoku; 
}

bool SudokuFactory::solveGame() {
	bool isValid = false; 

	SudokuPopulation testPop(this->factorySudoku); 
	int i = 0; 
	int out = numOfGenerations/10;

	while (i < numOfGenerations) {

		testPop.newGeneration();
		

		if (testPop.bestFitness() == 0) {

			cout << testPop.bestFitness();

			cout << endl << endl << *testPop.bestPuzzle();

			cout << endl << endl <<"Generations passed to complete: " << i << endl << endl;
			isValid = true; 
			break;
		}


		if (i % out == 0) {
			cout << i << " generations passed\n";
			cout << "Sudoku Best Fitness---------------------------------: " << testPop.bestFitness() << endl;

		}

		i++;
	}

	if (isValid == false){

	cout << "\n\nSudoku not solved :( \n";
	cout << i << " generations passed\n";
	cout << "Sudoku Best Fitness---------------------------------: " << testPop.bestFitness() << endl;
	cout << endl << endl << *testPop.bestPuzzle();
	
}
	



	return isValid;
}

void SudokuFactory::displayPuzzle(ostream& outPut) const {

	outPut << *factorySudoku << endl;
	outPut << "Fitness Level: "<< this->factorySudoku->getFitnessLevel();
}





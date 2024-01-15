
#include "SudokuPopulation.h"


SudokuPopulation::SudokuPopulation(Sudoku* sudoku) : originalSudoku(sudoku) {

	cout << "Population class has been created" << endl;


	/*Sudoku sudo;*/
	int numOfPuzzles = 100;
	int n = 0;

	while (n < numOfPuzzles) {
		Sudoku* newSudo = new Sudoku;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				newSudo->board[i][j] = originalSudoku->board[i][j];
				newSudo->origBoard[i][j] = originalSudoku->board[i][j];
				if (originalSudoku->board[i][j] == 0) {
					newSudo->board[i][j] = 1 + (rand() % 9);
				}
			}
		}
		newSudo->getFitness(*newSudo);
		/*setSudoku(newSudo);*/
		generation.push(newSudo);


		n++;
	}
	cull();
}



void SudokuPopulation::cull() {
	for (int i = 0; i < 90; i++)
		generation.pop();
}

void SudokuPopulation::newGeneration() {

	SudokuOffspring mutator;
	

	while (!generation.empty()) {
	
		Sudoku mutation;
		mutation = *generation.top();


		for (int i = 0; i < 10; i++) {

			originalSudoku = new Sudoku;
			*originalSudoku = mutator.makeOffspring(mutation);
			mutations.push_back(originalSudoku);

		}
		generation.pop();
		

	}
	transferSudoku();

	

}

void SudokuPopulation::transferSudoku() {
	for (int i = 0; i < mutations.size(); i++) {

		generation.push(mutations.at(i));
	}
	mutations.clear();
	cull();
}

int SudokuPopulation::bestFitness() {
	Sudoku* bestSudoku = bestPuzzle();
	return bestSudoku->getFitness(*bestSudoku);
}

Sudoku& SudokuPopulation::bestIndividual() {
	Sudoku* bestSudoku = bestPuzzle();
	cout << "bestIndividual: Fitness of best Sudoku is: " << bestSudoku->getFitnessLevel() << endl;
	return *bestSudoku;
}

Sudoku* SudokuPopulation::bestPuzzle() {
	priority_queue<Sudoku*, vector<Sudoku*>, Compare> temp = generation;
	int size = temp.size();
	int i = 1;
	
	while (!temp.empty()) {

		
		if (i == temp.size()) {
			Sudoku* s = temp.top();
			return s;
		}
		temp.pop();
	}
}

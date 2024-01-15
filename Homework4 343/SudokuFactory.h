#pragma once
#include "PuzzleFactory.h"
// #include "SudokuPopulation.h"


class SudokuFactory : public PuzzleFactory {
public:
	int numOfGenerations = 0;
	// Constructor
	SudokuFactory() {};
	SudokuFactory(int);

	// Destructor
	~SudokuFactory() { delete factorySudoku; }

	// Precondition: N/A
	// Postcondition: Puzzle object pointer
	// Description: Creates a new Puzzle object pointer
	Puzzle* makePuzzle();
	

	// Precondition: string of sudoku board
	// Postcondition: N/A
	// Description: Sets the sudoku board based on a previous set
	void setBoard(string& placements);

	// Precondition: N/A
	// Postcondition: Puzzle pointer
	// Description: Returns a puzzle pointer
	Puzzle* getPuzzle();

	// Precondition: N/A 
	// Postcondition: Returns a bool of whether sudoku was solved
	//				  or not.
	// Description: Through the number of generations given, will
	//				begin the cycle of sudoku creation, and displaying
	//				 the fitness of every hundredth generation. 
	//				Will stop once the sudoku has a fitness of zero 
	bool solveGame();

	// Precondition: const output stream operator
	// Postcondition: N/A
	// Description: display's the sudoku board
	void displayPuzzle(ostream& outPut)const;
private: 
	// Sudoku object placeholder
	Sudoku* factorySudoku = nullptr;
};

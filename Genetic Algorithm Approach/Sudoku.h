#pragma once

#include "Puzzle.h"
#include <time.h>


class Sudoku :
	public Puzzle
{

public:
	// Constructor
	Sudoku();
	// Destructor
	~Sudoku() { };

	// Precondition: Takes in a reference of a Puzzle object
	// Postcondition: Returns the reference of the newly copied 
	//				  Puzzle object 
	// Description: Creates a copy of the Puzzle object parameter, copies it's board values
	// 				to the new one, it's fitness, and it's string of the original board
	Puzzle& operator=(const Puzzle& copyMe);

	// Precondition: Takes in a reference of a Puzzle object
	// Postcondition: Returns a reference of boolean 
	// Description: Checks if the fitness level of this.Puzzle is 
	// 				greater than the Puzzle parameter
	bool& operator>(const Puzzle& rightSide);

	// Precondition: Takes in a reference of a Puzzle object
	// Postcondition: Returns a reference boolean value
	// Description: Checks if the fitness level of this.Puzzle is 
	// 				less than the Puzzle parameter
	bool& operator<(const Puzzle& rightSide);

	// Precondition: Takes in a reference of a Puzzle object
	// Postcondition: Returns a reference of boolean 
	// Description: Checks to see if the fitness level between this
	//				and Puzzle parameter are the same
	bool& operator==(const Puzzle& rightSide);

	// Precondition: Takes in reference to string that contains the starting sudoku values 
	// Postcondition: N/A
	// Description: Adds each substring from the given string into the int board
	//				and if the value is a non-numerical order, a zero is assigned
	//				in it's place, to indicate it will be mutated
	void boardSetter(const string& placements);


	// Precondition: Takes in a sudoku object parameter
	// Postcondition: Returns the fitness level of the sudoku
	// Description: Takes in a sudoku object, sends it to howFit() in 
	//				SudokuFitness and returns an int value of the fitness
	int getFitness(const Sudoku& fitLevel);

	// Precondition: N/A
	// Postcondition: Returns the fitness level
	// Description: Returns the this.fitness of the class
	int getFitnessLevel();

	// Precondition: const string variable
	// Postcondition: N/A
	// Description: Set's the last variable in the sudoku board
	void setFinalPiece(const string& lastBox) { this->finishBoard = lastBox; };

	// Precondition: const string 
	// Postconditino: const string
	// Description: Returns the almost finaled sudoku board in string 
	//				format.
	string& retFinalPiece() { return this->finishBoard; };

	// Precondition: output stream operator
	// Postcondition: N/A
	// Description: Prints out each sudoku value from the sudoku object and 
	//				displays is in the sudoku format
	void displayBoard(ostream& outPut)const;

	// int array to store all sudoku values
	int board[9][9] = { 0 };
	// boolean array to store the location of the starter sudoku values
	bool origBoard[9][9] = { false };

private:
	// String to contain the input string of the almost 
	// finalized Sudoku board
	string finishBoard;
	// String to contain the input string of the original Sudoku
	string reader;
	// The fitness level variable
	int fitnessLevel = 0;
};

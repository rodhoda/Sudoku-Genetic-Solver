#pragma once
#include "Reproduction.h"
#include "Sudoku.h"
class SudokuOffspring :
	public Reproduction
{
public:
	// Constructor to assign the board from older sudoku
	// to a new one
	SudokuOffspring(Sudoku* parentBoard);
	// Constructor instantiating a new sudoku
	SudokuOffspring() { childBoard = nullptr; };

	// Precondition: const parent Puzzle pointer
	// Postcondition: Returns a const of the new puzzle object
	// Description: Takes the parent sudoku, creates a new sudoku
	//				object and assigns it the parent's board.
	//				It then takes 4 randomly selected locations, and
	//				randomly generates an int value of 1-9, and assigns
	//				it to the randomly selected spot, this is done 4 times
	Puzzle& makeOffspring(const Puzzle& parent);
	// Destructor
	~SudokuOffspring() { delete childBoard; }

private:
	// placeholder for the new child sudoku
	Sudoku* childBoard = nullptr;
};

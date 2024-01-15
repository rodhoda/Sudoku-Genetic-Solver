#pragma once
//#include "SudokuFactory.h"
#include "Sudoku.h"
//#include "SudokuOffspring.h"
class PuzzleFactory
{
public:
	virtual Puzzle* makePuzzle() = 0;
	virtual bool solveGame() = 0;
	virtual void setBoard(string& placements) = 0;
	virtual ~PuzzleFactory() {};
	virtual void displayPuzzle(ostream& outPut)const = 0;
	friend ostream& operator <<(ostream& output, const PuzzleFactory& outPuz) {
		outPuz.displayPuzzle(output);
		return output;
	}
};









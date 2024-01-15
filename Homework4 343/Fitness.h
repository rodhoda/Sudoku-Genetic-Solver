#pragma once
#include "Sudoku.h"

class Fitness
{
public:
	int virtual howFit(Puzzle* board) = 0;

private:

};


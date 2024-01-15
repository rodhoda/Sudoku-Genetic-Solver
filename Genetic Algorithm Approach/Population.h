#pragma once
#include "Sudoku.h"
#include "SudokuFitness.h"
#include "SudokuFactory.h"
#include "SudokuOffspring.h"

class Population {
public:
    void virtual cull() = 0;
    void virtual newGeneration() = 0;

    int virtual bestFitness() = 0;

    virtual Sudoku& bestIndividual() = 0;
};


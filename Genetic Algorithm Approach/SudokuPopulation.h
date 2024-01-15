#pragma once
#include "Population.h"
#include <random>
#include <queue>


// Struct is used as a comparator for the priority queue of Sudoku objects 
// It uses the sudoku's fitness level to order the queue
struct Compare {
    bool operator()(Sudoku* const& sudoOne, Sudoku* const& sudoTwo) {
        return sudoOne->getFitnessLevel() < sudoTwo->getFitnessLevel();
    }
};

class SudokuPopulation: public Population {
public:
    int fitnessVal;
    int maxQueueSize;
    string sudokuString;
    ~SudokuPopulation() { delete originalSudoku; };

    // Queue that will contain a generation of sudoku's at a given time
    priority_queue<Sudoku*, vector<Sudoku*>, Compare> generation;

    // Constructor takes the original sudoku, and creates 100 new ones
    // By randomly adding values to where zero's are located in the board
    // They are then added to the queue.
    SudokuPopulation(Sudoku*);

    // Precondition: N/A
    // Postcondition: N/A
    // Description: Will remove the 90 sudoku's with the worst 
    //              fitness level, in this case, pop the first 90 
    //              from the queue
    void cull();

    // Precondition: N/A
    // Postcondition: N/A
    // Description: Using the best 10 Sudoku's, this function will
    //              send each sudoku for mutation to create 10 new Sudoku's
    //              which are stored in the vector
    void newGeneration();

    // Precondition: N/A
    // Postcondition: int fitness value
    // Description: Using bestPuzzle(), returns the int value of the 
    //              sudoku with the best fitness level
    int bestFitness();

    // Precondition: N/A
    // Postcondition: reference of Sudoku object
    // Description: Using bestPuzzle(), returns the sudoku with the  
    //              best fitness level
    Sudoku& bestIndividual();

    // Precondition: N/A
    // Postcondition: Returns the sudoku object
    // Description: Returns the sudoku object with the best fitness level
    //              from the queue 
    Sudoku* bestPuzzle();

    // Precondition: N/A
    // Postcondition: N/A
    // Description: Transfers the sudoku's from the vector onto the queue,
    //              and then calls cull() to remove the worst 90 sudoku's
    void transferSudoku();

private:
    // Vector of mutated sudoku that are newly created from SudokuOffspring
    vector<Sudoku*> mutations;
    Sudoku* originalSudoku;

};


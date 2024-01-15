#pragma once
#include "Fitness.h"
#include "Sudoku.h"
#include <unordered_map>
#include <set>
#include <string>
using namespace std;

class SudokuFitness : public Fitness {

public:
    //Precondition: Takes a Puzzle object
    //Postcondition: Returns the fitness level of that board
    //Description: Checks for uniqueness in each row, column and 3x3 grid.
    //Uses a set to check if the number has already been inserted
    //If so, then the fitness is incremented by one.
    //Then the sum of the row, column and square fitness is returned. 
    int howFit(Puzzle* board);
    
    //Precondition: Takes a sudoku object
    //Postcondition: Passes that sudoku object into the howFit method and calls it
    //Description: Calls the howFit method to determine fitness level.
    SudokuFitness(Sudoku* checkMe);
    
    //Constructor 
    SudokuFitness() {};
    
    //Precondition: Takes the index of where the duplicate was found.
    //Postcondition: Returns a string with the location of duplicate.
    //Description: In howFit, we check to see if the fitness is 1 due to the 3x3 grid. If it is, we call this 
    //function that returns a string of the index where that fitness level was 1.
    string checkSquareFitness(string lastValue);

private:
    //A set to count the number of duplicate elements in a 3x3 grid to obtain the fitness level
    set<int> squareSet;
    
    //If the fitness level is 1 due to the 3x3 grid, these store the location where the duplicate was found.
    string index1;
    string index2;
    
    //This private variables combines both the string index to one string.
    string finalValue;
    
    //Private variables to keep track of the fitness level in the rows, columns and 3x3 grids.
    int colFitness = 0;
    int rowFitness = 0;
    int threeByFitness = 0;
    
    //We store the final total fitness in this private variable.
    int currentFitness = 0;
};

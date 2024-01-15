# Genetic Algorithm Sudoku Solver

## Team Members:
Rod Hoda
Furqan Kassa
Austin Losik

## Design Analysis

The program will solve Sudoku puzzles randomly, but, the harder the difficulty the longer it takes. For an extremely easy puzzle, the algorithm usually solves in the 2000-5000 range of generations. This will happen quickly and swiftly.

For medium difficulty, it more commonly solved in around 15-20k generations. Lastly, hard puzzles can go into the 100k+ generation size.

The algorithm uses a hash map to calculate the 3x3 fitness, this slows the algorithm down and thus generations are done slightly slower in this portion.

Most portions of the code are solved in O(N) time to reduce the run time. Originally we saw extremely long load times. For example, the original algorithm used a hash map for the entirety of the fitness levels. After slow generational speeds, we made row and column fitness O(N) for loops to iterate the 2D array, thus making it much faster.

The program calls a PuzzleFactory object that dynamically changes at run time to a SudokuFactory, which begins the process of creating the first puzzle, and then solving it via the genetic algorithm. The steps of instantiating a sudoku object are “hidden” from the user via the SudokuFactory.

In this document, I have attached two run-time tests of the program. In testing, we used 3 different Sudoku boards on 3 different Windows machines and 2 different Linux machines.


## Instructions

The main program is in the `Genetic Algorithm Approach` folder

Program runs with test.sh command file within the folder. This will link all the .cpp files and run the program right away. 

There is a blank space in the folder name, therefore in Linux, you must use \ to get to the directory. 

Deterministic extra credit in Deterministic folder - this also has its own sh file called recursive.sh 

Deterministic Approach - When we ran this, we had to remove the genetic algorithm program from our Linux Lab directory due to sizing issues. Remove the genetic algorithm after testing and before testing the deterministic approach. 

Both projects are complete and run. 




PLEASE NOTE:

Compiler warnings do arise in the Linux test enviroment (they do not exist in our windows environments), 
but, the code can still be linked and compiled despite the warnings. 

NOTE TWO: 

Algorithm bases how much to show off user input. Upon starting the algorithm, it may look like it's hanging, however, it only displays in increments. I.e., 50,000 generations requested at the command line will produce results every 5000.


#include "SudokuFactory.h"
////#include "SudokuOffspring.h"
////#include "SudokuFitness.h"
//#include <vector>
//#include <queue>
#include "SudokuPopulation.h"


using namespace std;

#include <iostream> 

int main()
{
	srand(time(0));
	// Below are test Sudoku boards if you would like. Otherwise the program will ask at run time for your board. 
	//string testString = "409806701001307200030009004500030680090000050026080007300100020004603900908402503";
	//string testTwo = "100090005040050090800302004208000603003206400504000709700605001050080030400030002";
	/*"004050000900734600003021049035090480090000030076010920310970200009182003000060100"*/
	//"379245861285361974164978235958634127437192658621857493792413586843526719516789342"
	//4009806701001307200030009004500030680090000050026080007300100020004603900908402503
	string userValue; 
	int numofGenerations = 0; 
	cout << "Please enter the maximum number of generations(Recommended 50,000): \n";
	cin >> numofGenerations;
	cout << "Please enter your board: \n";
	cin >> userValue;


	
	PuzzleFactory* testObj = new SudokuFactory(numofGenerations);

	testObj->setBoard(userValue);
	testObj->solveGame();

	return 0;

}

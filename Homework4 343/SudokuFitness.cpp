#include "SudokuFitness.h"
#include <unordered_map>

using namespace std;
int SudokuFitness::howFit(Puzzle* board) {
	int totalFitness = 0;
	int testResults[10]{ 0 };
	Sudoku* fitCheck = dynamic_cast<Sudoku*>(board);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			testResults[fitCheck->board[i][j]] += 1;
		}
		for (int k = 0; k < 9; k++) {
			if (testResults[k] > 1) {
				rowFitness += testResults[k];
				testResults[k] = 0;
			}
			testResults[k] = 0;
		}

	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			testResults[fitCheck->board[j][i]] += 1;
		}
		for (int k = 0; k < 9; k++) {
			if (testResults[k] > 1) {

				colFitness += testResults[k];
				testResults[k] = 0;
			}
			testResults[k] = 0;
		}
	}


	int count = 0;
	int z = 0;
	int check = 0;
	for (int i = 0; i < 9; i++) {
		for (int x = z; x < z + 3; x++) {
			if (squareSet.count(fitCheck->board[i][x]))
				threeByFitness++;
			else
				squareSet.insert(fitCheck->board[i][x]);
			count++;

			if (threeByFitness == 1 && check == 0) {
				check++;
				index1 = to_string(i);
				index2 = to_string(x);
			}
		}

		if (count == 27 || count == 54)
			z = -3;
		if (count == 9 || count == 18) {
			i = -1;
			squareSet.clear();
			z += 3;
		}
		else if (count == 27 || count == 36 || count == 45) {
			i = 2;
			squareSet.clear();
			z += 3;
		}
		else if (count == 54 || count == 63 || count == 72) {
			i = 5;
			squareSet.clear();
			z += 3;
		}
		else if (count >= 81)
			break;
	}

	currentFitness = threeByFitness + colFitness + rowFitness;

	if (currentFitness == 1 && threeByFitness == 1) {
		
		finalValue= index2 + index1;
		fitCheck->setFinalPiece(finalValue); 
	}

	//cout << index1 << endl;
	//cout << index2 << endl;
	return currentFitness;

}

	//int count = 0;
	//int z = 0;



	//for (int i = 0; i < 9; i++) {
	//	for (int x = z; x < z + 3; x++) {
	//		if (squareSet.count(fitCheck->board[i][x]))
	//			threeByFitness++;
	//		else
	//			squareSet.insert(fitCheck->board[i][x]);
	//		count++;
	//	}
	//	if (count == 27 || count == 54)
	//		z = -3;
	//	if (count == 9 || count == 18) {
	//		i = -1;
	//		squareSet.clear();
	//		z += 3;
	//	}
	//	else if (count == 27 || count == 36 || count == 45) {
	//		i = 2;
	//		squareSet.clear();
	//		z += 3;
	//	}
	//	else if (count == 54 || count == 63 || count == 72) {
	//		i = 5;
	//		squareSet.clear();
	//		z += 3;
	//	}
	//	else if (count >= 81)
	//		break;
	//}
	//cout << "";






	/*currentFitness = threeByFitness + colFitness + rowFitness;*/
//
//	return currentFitness;
//}


string SudokuFitness::checkSquareFitness(string lastValue) {
	return finalValue; 
}





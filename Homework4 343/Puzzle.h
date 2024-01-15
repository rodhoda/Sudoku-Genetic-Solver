#pragma once
#include <iostream>
#include <string>

using namespace std; 
class Puzzle {

public:
	virtual void boardSetter(const string& input)= 0;
	virtual ~Puzzle() {}; 
	virtual bool& operator>(const Puzzle& rightSide) = 0; 
	virtual bool& operator<(const Puzzle& rightSide) = 0;
	virtual bool& operator==(const Puzzle& rightSide) = 0;
	
	friend ostream& operator <<(ostream& output, const Puzzle& outPuz) {
		outPuz.displayBoard(output);
		return output; 
	}

	friend istream& operator >>(istream& input,  Puzzle& inStr) {
		
		string temp;
		input >> temp; 
		inStr.boardSetter(temp);
		
		return input;
	}

	virtual void displayBoard(ostream& outPut)const = 0;
	
private:

};
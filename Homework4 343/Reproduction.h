#pragma once
#include "Puzzle.h"
class Reproduction
{
public: 
	/*virtual Puzzle* makeOffspring(Puzzle* parent) = 0;*/
	virtual Puzzle& makeOffspring(const Puzzle& parent) = 0;
	virtual ~Reproduction() {};
};


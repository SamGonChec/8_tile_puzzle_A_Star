#pragma once
#include "Puzzle.h"
#include <queue>
#include <vector>
#include <set>
class Graph
{
public:
	std::priority_queue<Puzzle> puzzleQueue;
	std::vector<Puzzle> generatedStates;
	std::set<Puzzle> previous_states;
	bool invariant();
	void solvePuzzle();
	void generateChild();
	Graph(Puzzle puzzle);
	bool arrayComparison(char one[3][3], char two[3][3]);
};


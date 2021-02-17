#pragma once
#include <set>
#include <string>
#include "Node.h"
#include <queue>
#include "Puzzle.h"

using namespace std;
class PuzzleSolver
{
	std::set<std::string> previousNodes;
	//std::priority_queue<Node*, std::vector<Node*>, Equal>;


	PuzzleSolver() {
	
	};

	bool Solvable(string str);
	void NextNode();
	void Solve();
};


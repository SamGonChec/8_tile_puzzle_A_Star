#pragma once
class Puzzle
{
public:
	char puzzle[3][3];
	Puzzle* parent;
	char direction;
	int hValue, gValue;
	int calculateH();
	Puzzle(char puzzle[3][3], char direction,Puzzle* parent);
	void outputPuzzle() const;
	bool operator<(const Puzzle& rhs) const;
	int findEmpty() const;
	Puzzle(const Puzzle& obj);
};

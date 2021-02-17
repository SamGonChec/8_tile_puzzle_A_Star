
#include "Puzzle.h"
#include "iostream"


Puzzle::Puzzle(char puzzle[3][3], char direction,Puzzle* parent) {

	for (int i = 0; i < 9; i++) {
		this->puzzle[i / 3][i % 3] = puzzle[i / 3][i % 3];
	}
	this->direction = direction;
	this->parent = parent;
	this->hValue = calculateH();
	if (parent == NULL) {
		this->gValue = 0;
	}
	else {
		this->gValue = parent->gValue + 1;
	}
}
//copy constructor
Puzzle::Puzzle(const Puzzle& obj) {
	for (int i = 0; i < 9; i++) {
		this->puzzle[i / 3][i % 3] = obj.puzzle[i / 3][i % 3];
	}
	this->direction = obj.direction;
	this->parent = obj.parent;
	this->hValue = obj.hValue;
	this->gValue = obj.gValue;
}
void Puzzle::outputPuzzle() const {
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << puzzle[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
//necessary operator in order to use a priority queue. this is the criteria to what goes to the front of the queue
bool Puzzle::operator<(const Puzzle& rhs) const
{
	return this->gValue + this->hValue > rhs.gValue + rhs.hValue;
}
//calculate the manhattan distance
int Puzzle::calculateH() {
	int hIndividual = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//remember that chars have ascii code, to treat as a normal int do -'0' or -48
			int piece = puzzle[i][j] - '0';
			int targetX = (piece - 1) / 3;
			int targetY = (piece - 1) % 3;
			if (puzzle[i][j] != 'E') {
				hIndividual += abs(targetX - i) + abs(targetY - j);
			}
		}
	}
	return hIndividual;
}

int Puzzle::findEmpty() const {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			if (puzzle[i][j] == 'E')
				return (i * 3) + j;
		}
	}
}
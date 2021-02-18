#include "Graph.h"
#include <iostream>
Graph::Graph(Puzzle puzzle) {
	puzzleQueue.push(puzzle);

}
//invariant method used to determine if a puzzle is solvable or not
bool Graph::invariant() {
	int invariantCount = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++) {
		    if (puzzleQueue.top().puzzle[i/3][i%3] > puzzleQueue.top().puzzle[j/3][j%3] && puzzleQueue.top().puzzle[i/3][i%3] != 'E')
		        invariantCount++;
		}
	}
	return (invariantCount % 2) == 0;
}
// I use this method to compare a 2d array with a vector
bool Graph::arrayComparison(char one[3][3], char two[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (one[i][j] != two[i][j]) {
                return false;
            }
        }
    }

    return true;

}
// solves puzzle and outputs the steps to solution, basic premise that if h = 0 then the puzzle is solved.
void Graph::solvePuzzle(){
    std::string stepsToSolution;
	if (invariant()){
		std::cout << "This is Sovable ";
        std::cout << "\n";
        while (puzzleQueue.top().hValue != 0)
        {
            generateChild();
        }
        
        Puzzle* parent = puzzleQueue.top().parent;
        std::cout << "Puzzle Solved:";
        puzzleQueue.top().outputPuzzle();
        
        while (parent != NULL)
        {
            stepsToSolution = stepsToSolution + parent->direction + ' ';
            parent = parent->parent;
        }
        reverse(stepsToSolution.begin(), stepsToSolution.end());
        std::cout << "Steps to Solution: " << stepsToSolution << "\n";
	}
	else {
		std::cout << "This isn't Sovable\n";
	}
}
//generates the next states
void Graph::generateChild(){
    char temp[3][3];
    int position = puzzleQueue.top().findEmpty();
    Puzzle* parent = new Puzzle(puzzleQueue.top());
    puzzleQueue.pop();
    // to see if you can move left
    if (position % 3 != 0) {
        //copying the state of the array
        for (int i = 0; i < 9; i++) {
            temp[i / 3][i % 3] = parent->puzzle[i / 3][i % 3];
        }
        
        temp[position / 3][position % 3] = temp[position / 3][(position % 3) - 1];
        temp[position / 3][(position % 3) - 1] = 'E';

        Puzzle leftChild(temp, 'L', &(*parent));
        bool exists = false;
        //looking if the current state has not been visited before
        for (int i = 0; i < generatedStates.size(); i++)
        {
            if (arrayComparison(generatedStates[i].puzzle, leftChild.puzzle)) {
                exists = true;
            }
        }

        if (!exists) {
            puzzleQueue.push(leftChild);
                generatedStates.push_back(leftChild);
        }
    }
    // to see if you can move right
    if (position % 3 != 2) {
        for (int i = 0; i < 9; i++) {
            temp[i / 3][i % 3] = parent->puzzle[i / 3][i % 3];
        }

        temp[position / 3][position % 3] = temp[position / 3][(position % 3)+1];
        temp[position / 3][(position % 3)+1] = 'E';

        Puzzle rightChild(temp, 'R', &(*parent));
        //looking if the current state has not been visited before
        bool exists = false;
        for (int i = 0; i < generatedStates.size(); i++)
        {
            if (arrayComparison(generatedStates[i].puzzle, rightChild.puzzle)) {
                exists = true;
            }
        }

        if (!exists) {
            puzzleQueue.push(rightChild);
            generatedStates.push_back(rightChild);
        }
    }
    //if you can move up
    if (position / 3 != 0) {
        for (int i = 0; i < 9; i++) {
            temp[i / 3][i % 3] = parent->puzzle[i / 3][i % 3];
        }

        temp[position / 3][position % 3] = temp[(position / 3) - 1][position % 3];
        temp[(position / 3) - 1][position % 3] = 'E';


        Puzzle upChild(temp, 'U', &(*parent));
        bool exists = false;
        //looking if the current state has not been visited before
        for (int i = 0; i < generatedStates.size(); i++)
        {
            if (arrayComparison(generatedStates[i].puzzle, upChild.puzzle)) {
                exists = true;
            }
        }

        if (!exists) {
            puzzleQueue.push(upChild);
            generatedStates.push_back(upChild);
        }
    }
    // if you can move down
    if (position / 3 != 2) {
        for (int i = 0; i < 9; i++) {
            temp[i / 3][i % 3] = parent->puzzle[i / 3][i % 3];
        }

        temp[position / 3][position % 3] = temp[(position / 3) + 1][position % 3];
        temp[(position / 3) + 1][position % 3] = 'E';

        Puzzle downChild(temp, 'D', &(*parent));
        bool exists = false;
        //looking if the current state has not been visited before
        for (int i = 0; i < generatedStates.size(); i++)
        {
            if (arrayComparison(generatedStates[i].puzzle, downChild.puzzle)) {
                exists = true;
            }
        }

        if (!exists) {
            puzzleQueue.push(downChild);
            generatedStates.push_back(downChild);
        }
    }
}

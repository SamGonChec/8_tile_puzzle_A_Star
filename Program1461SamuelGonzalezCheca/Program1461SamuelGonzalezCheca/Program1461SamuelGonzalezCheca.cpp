// Program1461SamuelGonzalezCheca.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <queue>
#include "Puzzle.h"
#include "Graph.h"

int main()
{
    int numOfPuzzles;
    char input[3][3];
    
    std::ifstream puzzleInput;
    puzzleInput.open("prog1_input.txt");
    if (!puzzleInput) {
        return 0;
    }
    puzzleInput >> numOfPuzzles;
    std::cout << numOfPuzzles << std::endl;
    for (int h = 0; h < numOfPuzzles; h++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                puzzleInput >> input[i][j];
            }
        }
        Puzzle puzzle(input, ' ', NULL);
        puzzle.outputPuzzle();
        Graph graph(puzzle);
        graph.solvePuzzle();
        
    }
    
    return 1;
}
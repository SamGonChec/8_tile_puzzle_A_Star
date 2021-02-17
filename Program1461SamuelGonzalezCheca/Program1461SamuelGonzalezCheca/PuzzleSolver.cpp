#include "PuzzleSolver.h"
#include "string"
#include "Puzzle.h"

using namespace std;

bool Solvable(string arr) {
        int inv_count = 0;
        for (int i = 0; i < 9 - 1; i++)
            for (int j = i + 1; j < 9; j++)
                // Value 0 is used for empty space
                if (arr[j] && arr[i] && arr[i] > arr[j])
                    inv_count++;
        return false;
}
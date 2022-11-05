#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include "EightPuzzle.h"

using namespace std;

    /* Expands the cheapest node first */
    EightPuzzle UniformCostSearch(EightPuzzle problem);
    
    /* A* algorithms: Enqueue nodes in order of estimated cost to the goal */
    EightPuzzle A_Star_MisplacedTile(EightPuzzle problem);
    EightPuzzle A_Star_Manhattan(EightPuzzle problem);

    /* A* heuristics */
    int MisplacedTileHeuristic(EightPuzzle problem);
    int ManhattanHeuristic(EightPuzzle problem);

    struct nodes {
        vector<vector<int>> currentStates;
        int f_of_n = 0;
    };

#endif
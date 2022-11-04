#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <vector>
#include <queue>
#include "EightPuzzle.h"

using namespace std;

    /* Expands the cheapest node first */
    EightPuzzle UniformCostSearch(EightPuzzle problem);
    
    /* A* algorithms */
    EightPuzzle A_Star_MisplacedTile(EightPuzzle problem);
    EightPuzzle A_Star_Manhattan(EightPuzzle problem);

#endif
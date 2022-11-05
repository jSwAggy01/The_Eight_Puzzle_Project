#include "Algorithms.h"

/* Algorithms: */

    /* Expands the cheapest node */
    EightPuzzle UniformCostSearch(EightPuzzle problem) {
        int depth = 0;  // Counter for the depth of solution

        /* Our node data structure will be a priority queue */
        priority_queue<vector<int>> QUEUEING_FUNCTION;

        /* Push into it the initial state */
        QUEUEING_FUNCTION.push(problem.currentState);

        /* Enter the loop */
        do {
            /* If nodes is empty, no solution exists */
            if (QUEUEING_FUNCTION.empty()) {
                cout << "\n***FAILURE***\n";
                break;
            }

            /* Pop the head off nodes */
            vector<int> node = QUEUEING_FUNCTION.top();
            QUEUEING_FUNCTION.pop();

            /* If node is goal state,****SUCCESS**** return node */
            if (isGoalState(node)) {
                cout << "\n***SUCCESS***\n\nSolution found at depth " << depth << "\n\n";
                EightPuzzle solution(node);
                // solution.outputCurrentState(); // REMOVE this
                return solution;
            }

            /* If node is not goal state, create all of A's children and push into nodes (priority queue).

            For this problem, I have 4 operators, so the branching factor will be at most 4.
            This implies that 'A' will have at most 4 children.
            */

            // Duplicate the parent node into child nodes:

            EightPuzzle child1(node);
            EightPuzzle child2(node);
            EightPuzzle child3(node);
            EightPuzzle child4(node);

            // Orient each of the child nodes with a unique operation:
            child1.move_left();
            child2.move_right();
            child3.move_up();
            child4.move_down();

            // Push the children into the nodes (priority queue):
            QUEUEING_FUNCTION.push(child1.currentState);
            QUEUEING_FUNCTION.push(child2.currentState);
            QUEUEING_FUNCTION.push(child3.currentState);
            QUEUEING_FUNCTION.push(child4.currentState);

            // Recording depth
            ++depth;
        }
        while (!QUEUEING_FUNCTION.empty());
        
        cout << "\n***ERROR***\n";
        return problem;
    }

    /* A* with misplaced tile heuristic */
    EightPuzzle A_Star_MisplacedTile(EightPuzzle problem) {
        int depth = 0;  // Counter for the depth of solution
        int f_of_n = 0; // f(n) = g(n) + h(n) = cost (same for all in this case) + estimated dist. to goal

        /* Call the heuristic */
        f_of_n = MisplacedTileHeuristic(problem);

        /* Our node data structure */
        nodes QUEUEING_FUNCTION;

        /* Push into it the initial state */
        QUEUEING_FUNCTION.currentStates.push_back(problem.currentState);
        // ***LEFT OFF HERE***
    }

    /* A* with Manhatten heuristic */
    EightPuzzle A_Star_Manhattan(EightPuzzle problem) {

    }

/* Heuristics: */

    /* Returns the number of miplaced tiles from goal state */
    int MisplacedTileHeuristic(EightPuzzle problem) {
        int h_of_n = 0;
        for (int i = 0; i < 8; ++i) {
                if (problem.currentState.at(i) != i + 1) {
                    ++h_of_n;
                }
        }
        return h_of_n;
    }

    /* Returns the number of spaces of misplaced tiles, needed to transform current state to goal state */
    int ManhattanHeuristic(EightPuzzle problem) {
        int h_of_n = 0;
        int h_of_n_GivenNumber = 0;
        int correctElement = 0;
        int currentElement = 0;
        int correctIndex = 0;
        
        /* Return h(n) = 0 if problem is already solved */
        if (problem.isGoalState()) {
            return 0;
        }

        /* Compare each element in the current state to its corresponding element of the goal state */
        for (int currentIndex = 0; currentIndex < 9; ++currentIndex) {
            correctElement = currentIndex + 1;
            currentElement = problem.currentState.at(currentIndex);

            /* Check to see if the element is in the correct spot */
            if (currentElement != correctElement && currentElement != 0) {
                /* Find the index of where the current element is supposed to be */
                correctIndex = problem.getNumberPosition(currentElement);

                /* h(n) = number of spaces that tiles are misplaced

                   Find the difference (subtract) between the correct index of
                   where it's supposed to be, and where it currently is.
                */
                h_of_n_GivenNumber = correctIndex - currentIndex;
                int abs(h_of_n_GivenNumber);

                /* Special case: If h(n) = 3 or 6 => vertical move */
                if (h_of_n_GivenNumber == 3 || h_of_n_GivenNumber == 6) {
                    if (h_of_n_GivenNumber == 3) {
                        ++h_of_n;
                    }
                    else {
                        ++h_of_n << ++h_of_n;
                    }
                }

                /* Special case: If h(n) = 1 for indices 2, 3, 5, or 6 */
                else if (h_of_n_GivenNumber == 1) {
                    if ((currentElement == 2 || currentElement == 3 || currentElement == 5 || currentElement == 6) && (correctElement == 2 || correctElement == 3 || correctElement == 5 || correctElement == 6)) {
                        ++h_of_n << ++h_of_n << h_of_n;
                    }
                }

                /* Sum all h(n)'s */
                h_of_n += h_of_n_GivenNumber;
            }
        }
        return h_of_n;
    }
    
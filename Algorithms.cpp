#include "Algorithms.h"

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
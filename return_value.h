#ifndef RETURN_VALUE_H_INCLUDE
#define RETURN_VALUE_H_INCLUDE

#include <vector>
using namespace std;

/**
 * Structure representing the return values of an algorithm execution.
 * It holds time, comparisons, relaxations, memory usage, distances, and parent information.
 */
struct return_value
{
        long time;                  ///< Execution time of the algorithm.
        int comparisons;            ///< Number of comparisons made during the algorithm execution.
        int relaxations;            ///< Number of relaxations made during the algorithm execution.
        long memory;                ///< Memory used by the algorithm execution.
        vector<vector<int>> parent; ///< Parent information for paths in the algorithm.
        vector<int> distance;       ///< Distances calculated by the algorithm.

        return_value(long time, int comparisons, int relaxations, vector<int> distance, vector<vector<int>> parent, unsigned long long memory);
};

#endif // RETURN_VALUE_H_INCLUDE

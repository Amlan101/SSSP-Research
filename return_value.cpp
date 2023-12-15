#include "return_value.h"

/**
 * Constructor to initialize return_value structure with provided values.
 *
 * @param time Execution time of the algorithm.
 * @param comparisons Number of comparisons made during the algorithm execution.
 * @param relaxations Number of relaxations made during the algorithm execution.
 * @param distance Vector representing distances calculated by the algorithm.
 * @param parent 2D Vector representing parent information for paths in the algorithm.
 * @param memory Memory used by the algorithm execution.
 */
return_value::return_value(long time, int comparisons, int relaxations, vector<int> distance, vector<vector<int>> parent, unsigned long long memory)
{
    this->time = time;
    this->comparisons = comparisons;
    this->relaxations = relaxations;
    this->distance = distance;
    this->parent = parent;
    this->memory = memory;
}

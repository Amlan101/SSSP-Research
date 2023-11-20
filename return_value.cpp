#include "return_value.h"


return_value::return_value(long time, int comparisons, int relaxations, vector<int> distance, vector<vector<int>> parent, unsigned long long memory)
{
    this->time = time;
    this->comparisons = comparisons;
    this->relaxations = relaxations;
    this->distance = distance;
    this->parent = parent;
    this->memory = memory;

}


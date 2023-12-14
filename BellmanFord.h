#ifndef BELLMANFORD_H_INCLUDE
#define BELLMANFORD_H_INCLUDE

#include <chrono>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include "return_value.h"
#include "Graph.h"

// Function to get the an array from the algorithm containing execution time, no of comparisons and no of relaxation
return_value getMinimumSpanningTreeBellmanFord(const Graph graph, int source);

#endif //BELLMANFORD_H_INCLUDE
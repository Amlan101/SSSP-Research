#ifndef DIJKSTRA_H_INCLUDE
#define DIJKSTRA_H_INCLUDE

#include <chrono>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include "return_value.h"
#include "Graph.h"
#include "MinHeap.h"

// Function to get the an array from the algorithm containing execution time, no of comparisons and no of relaxation
return_value getMinimumSpanningTreeDijkstra(const Graph graph, int StartNode);

int findMinDistance(const vector<int>& Dst, const vector<bool>& vis);

#endif //DIJKSTRA_H_INCLUDE



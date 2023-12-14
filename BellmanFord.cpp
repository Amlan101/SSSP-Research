#include "BellmanFord.h"
using namespace std;

// Function to get the an array from the algorithm containing execution time, no of comparisons and no of relaxation
return_value getMinimumSpanningTreeBellmanFord(const Graph graph, int source)
{
    // Record the start time
    auto start = chrono::high_resolution_clock::now();

    vector<int> distance(graph.nodesCount, INT_MAX);
    vector<vector<int>> parent(graph.nodesCount, vector<int>());

    distance[source] = 0;

    int noOfComparisons = 0, noOfRelaxation = 0;

    // Run the Bellman-Ford algorithm
    for (int i = 0; i < graph.nodesCount - 1; ++i)
    {
        for (int curr = 0; curr < graph.nodesCount; ++curr)
        {
            for (auto neigh : graph.adjList[curr])
            {
                int neighbour = neigh.first;
                int weight = neigh.second;

                int relax = distance[curr] + weight;

                noOfComparisons++;

                if (distance[curr] != INT_MAX && relax < distance[neighbour])
                {
                    noOfRelaxation++;
                    distance[neighbour] = relax;
                    parent[neighbour].clear();
                    parent[neighbour].push_back(curr);
                }
                else if (relax == distance[neighbour])
                {
                    // This part remains the same for finding all parents
                    if (parent[neighbour].back() != curr)
                        parent[neighbour].push_back(curr);
                }
            }
        }
    }

    //! Check for negative weight cycles
    // for (int curr = 0; curr < graph.nodesCount; ++curr)
    // {
    //     for (auto neigh : graph.adjList[curr])
    //     {
    //         int v = neigh.first;
    //         int weight = neigh.second;
    //         if (distance[curr] != INT_MAX && distance[curr] + weight < distance[v])
    //         {
    //             cout << "Graph contains a negative weight cycle." << endl;
    //             return {};
    //         }
    //     }
    // }


    // Record the end time
    auto end = chrono::high_resolution_clock::now();
    // Calculate the duration between start and end
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    //Calculating the memory
    unsigned long long mem = sizeof(start) + sizeof(end) + sizeof(distance) + sizeof(parent) + sizeof(noOfComparisons) + sizeof(noOfRelaxation);

    return return_value(duration.count(), noOfComparisons, noOfRelaxation,distance,parent,mem);
}

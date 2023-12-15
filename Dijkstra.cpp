#include "Dijkstra.h"

using namespace std;

/**
 * Calculates the shortest paths from a starting node to all other nodes using Dijkstra's algorithm.
 *
 * @param graph The graph object containing nodes and their adjacency lists with associated weights.
 * @param StartNode The index of the starting node for path calculations.
 * @return return_value An object containing execution time, number of comparisons, number of relaxations, shortest distances,
 *                      parent information, and memory used during the execution.
 */
return_value getMinimumSpanningTreeDijkstra(const Graph graph, int StartNode)
{

    // Record the start time
    auto start = chrono::high_resolution_clock::now();

    // declaring the needed storage structures
    vector<int> Dst(graph.nodesCount, INT_MAX);
    vector<bool> vis(graph.nodesCount, false);
    vector<vector<int>> parent(graph.nodesCount, vector<int>());

    MinHeap mh;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // set<pair<int, int>> st;

    int noOfComparisons = 0, noOfRelaxation = 0;

    // initializing the storage structures
    Dst[StartNode] = 0;
    vis[StartNode] = true;
    mh.insert(make_pair(0, StartNode));
    // st.insert(make_pair(0, StartNode));

    // main loop
    while (!mh.isEmpty())
    {
        //! For finding the SDSP we can break the loop if the current node is the destination
        // if(pq.top().second == EndNode) break;
        // later we can send the distance and the path as output

        // taking out the first element
        int curr = mh.extractMin().second;

        vis[curr] = true;

        for (auto neigh : graph.adjList[curr])
        {
            int neighbor = neigh.first;
            int weight = neigh.second;

            if (vis[neighbor] != true)
            {
                noOfComparisons++;
                int relax = Dst[curr] + weight;
                if (relax < Dst[neighbor])
                {
                    noOfRelaxation++;

                    Dst[neighbor] = relax;

                    parent[neighbor].clear();
                    parent[neighbor].push_back(curr);

                    mh.insert(make_pair(Dst[neighbor], neighbor));
                }
                else if (relax == Dst[neighbor])
                {
                    parent[neighbor].push_back(curr);
                }
            }
        }
    }

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration between start and end
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // Calculating the memory
    unsigned long long mem = sizeof(start) + sizeof(end) + sizeof(Dst) + sizeof(vis) + sizeof(parent) + sizeof(noOfComparisons) + sizeof(noOfRelaxation);

    return return_value(duration.count(), noOfComparisons, noOfRelaxation, Dst, parent, mem);
}

// int findMinDistance(const vector<int>& Dst, const vector<bool>& vis ) {
//     int min = INT_MAX, minIdx = 0;
//
//     for (int i = 0; i < Dst.size(); i++) {
//         if (Dst[i] <= min && !vis[i]) {
//             min = Dst[i];
//             minIdx = i;
//         }
//     }
//     return minIdx;
// }
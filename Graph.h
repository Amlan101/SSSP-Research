#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <vector>
#include <utility>

class Graph
{
public:
    int nodesCount;
    std::vector<std::vector<std::pair<int, int>>> adjList;

    Graph(int nodes);

    void addEdge(int startNode, int endNode, int Weight);
};

#endif // GRAPH_H_INCLUDED

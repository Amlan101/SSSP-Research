#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(int nodes)
{
    this->nodesCount = nodes;
    this->adjList = vector<vector<pair<int, int>>>(nodes);
}

void Graph::addEdge(int startNode, int endNode, int Weight)
{
    if (startNode >= 0 && startNode < nodesCount && endNode >= 0 && endNode < nodesCount)
    {
        adjList[startNode].push_back(make_pair(endNode, Weight));
        adjList[endNode].push_back(make_pair(startNode, Weight));
    }
    else
    {
        // Handle the case where the provided node indices are out of bounds.
        // You can print an error message or take appropriate action.
        cout << "Invalid node indices: " << startNode << " or " << endNode << endl;
    }
}
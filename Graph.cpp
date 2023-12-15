#include "Graph.h"
#include <iostream>
using namespace std;

/**
 * Constructs a graph with a specified number of nodes.
 *
 * @param nodes The number of nodes in the graph.
 */
Graph::Graph(int nodes)
{
    this->nodesCount = nodes;
    this->adjList = vector<vector<pair<int, int>>>(nodes);
}

/**
 * Adds an undirected edge between two nodes with a specified weight.
 * If the node indices are within bounds, the edge is added to both nodes' adjacency lists.
 * If the indices are invalid, an error message is printed.
 *
 * @param startNode The starting node index for the edge.
 * @param endNode The ending node index for the edge.
 * @param Weight The weight of the edge between the nodes.
 */
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
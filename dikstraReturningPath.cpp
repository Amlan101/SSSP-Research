#include <bits/stdc++.h>
#include <chrono>
using namespace std;

class Graph
{
public:
    int nodesCount;
    vector<vector<pair<int, int>>> adjList;

    Graph(int nodes)
    {
        this->nodesCount = nodes;
        this->adjList = vector<vector<pair<int, int>>>(nodes);
    }

    void addEdge(int startNode, int endNode, int Weight)
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
};

// Function to get the MST(Minimum Spanning Tree) from the algorithm
pair<vector<int>, vector<vector<int>>> GetMinimumSpanningTree(const Graph graph, int StartNode)
{
    // declaring the needed storage structures
    vector<int> Dst(graph.nodesCount, INT_MAX);
    vector<bool> vis(graph.nodesCount, false);
    vector<vector<int>> parent(graph.nodesCount, vector<int>());
    // int Dst[graph.nodesCount];
    // int vis[graph.nodesCount];
    // int parent[graph.nodesCount];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // initializing the storage structures
    Dst[StartNode] = 0;
    vis[StartNode] = true;
    pq.push(make_pair(0, StartNode));

    // main loop
    while (!pq.empty())
    {
        //! For finding the SDSP we can break the loop if the current node is the destination
        // if(pq.top().second == EndNode) break;
        //later we can send the distance and the path as output 


        // taking out the first element
        int curr = pq.top().second;
        pq.pop();

        vis[curr] = true;

        for (auto neigh : graph.adjList[curr])
        {
            int neighbor = neigh.first;
            int weight = neigh.second;

            if (vis[neighbor] != true)
            {
                int relax = Dst[curr] + weight;
                if (relax < Dst[neighbor])
                {
                    Dst[neighbor] = relax;
                    parent[neighbor].clear();
                    parent[neighbor].push_back(curr);
                    pq.push(make_pair(Dst[neighbor], neighbor));
                }
                else if (relax == Dst[neighbor]){
                    parent[neighbor].push_back(curr);
                }
            }
        }
    }

    // using an pair to return both distance and parent
    pair<vector<int>, vector<vector<int>>> ans = make_pair(Dst, parent);

    return ans;
}

// Function to find all paths from source to destination
void findAllPaths(const vector<vector<int>> &parentVector, int source, int destination, vector<int> currentPath, vector<vector<int>> &allPaths)
{
    if (destination == source)
    {
        currentPath.push_back(source);
        reverse(currentPath.begin(), currentPath.end());
        allPaths.push_back(currentPath);
        return;
    }

    for (const int parent : parentVector[destination])
    {
        vector<int> newCurrentPath = currentPath;
        newCurrentPath.push_back(destination);
        findAllPaths(parentVector, source, parent, newCurrentPath, allPaths);
    }
}

void print(const vector<int> &arr)
{
    for (size_t it = 0; it < arr.size(); it++)
    {
        cout << it << "      " << arr[it] << endl;
    }
}

void print(const vector<vector<int>> &arr){
    for(size_t it = 0; it < arr.size(); it++){
        cout << it << " -> ";
        for (auto itt : arr[it])
        {
            cout << itt << " ";
        }
        cout << endl;
    }
}

int main()
{
    Graph graph1(9);

    graph1.addEdge(0, 1, 4);
    graph1.addEdge(0, 7, 8);
    graph1.addEdge(1, 2, 8);
    graph1.addEdge(1, 7, 11);
    graph1.addEdge(2, 3, 7);
    graph1.addEdge(2, 8, 2);
    graph1.addEdge(2, 5, 4);
    graph1.addEdge(3, 4, 9);
    graph1.addEdge(3, 5, 14);
    graph1.addEdge(4, 5, 10);
    graph1.addEdge(5, 6, 2);
    graph1.addEdge(6, 7, 1);
    graph1.addEdge(6, 8, 6);
    graph1.addEdge(7, 8, 7);

    Graph graph2(20);

    graph2.addEdge(0, 1, 5);
    graph2.addEdge(0, 2, 8);
    graph2.addEdge(1, 3, 10);
    graph2.addEdge(1, 4, 15);
    graph2.addEdge(2, 5, 12);
    graph2.addEdge(2, 6, 6);
    graph2.addEdge(3, 7, 9);
    graph2.addEdge(3, 8, 7);
    graph2.addEdge(4, 9, 14);
    graph2.addEdge(4, 10, 11);
    graph2.addEdge(5, 11, 3);
    graph2.addEdge(5, 12, 5);
    graph2.addEdge(6, 13, 8);
    graph2.addEdge(6, 14, 4);
    graph2.addEdge(7, 15, 7);
    graph2.addEdge(7, 16, 10);
    graph2.addEdge(8, 17, 6);
    graph2.addEdge(8, 18, 12);
    graph2.addEdge(9, 19, 9);
    graph2.addEdge(9, 0, 13);
    graph2.addEdge(10, 1, 4);
    graph2.addEdge(10, 2, 11);
    graph2.addEdge(11, 3, 7);
    graph2.addEdge(11, 4, 8);

    Graph graph4(41);

    graph4.addEdge(0, 1, 4.6);
    graph4.addEdge(0, 4, 2.2);
    graph4.addEdge(0, 17, 1.1);
    graph4.addEdge(0, 30, 4.4);
    graph4.addEdge(0, 40, 2.1);
    graph4.addEdge(1, 6, 2.2);
    graph4.addEdge(1, 11, 4.9);
    graph4.addEdge(1, 21, 5);
    graph4.addEdge(1, 31, 2.8);
    graph4.addEdge(1, 33, 0.9);
    graph4.addEdge(2, 24, 4.5);
    graph4.addEdge(3, 9, 3.3);
    graph4.addEdge(3, 24, 2.4);
    graph4.addEdge(4, 22, 3.7);
    graph4.addEdge(5, 11, 1.5);
    graph4.addEdge(5, 24, 1.9);
    graph4.addEdge(6, 28, 4.2);
    graph4.addEdge(6, 31, 3.2);
    graph4.addEdge(7, 13, 1);
    graph4.addEdge(8, 22, 0.9);
    graph4.addEdge(8, 39, 3.6);
    graph4.addEdge(10, 13, 14);
    graph4.addEdge(11, 21, 5);
    graph4.addEdge(11, 31, 2.6);
    graph4.addEdge(11, 36, 4.3);
    graph4.addEdge(12, 13, 1);
    graph4.addEdge(13, 37, 2.5);
    graph4.addEdge(14, 34, 2.4);
    graph4.addEdge(15, 36, 4.4);
    graph4.addEdge(16, 13, 18.2);
    graph4.addEdge(17, 21, 2.9);
    graph4.addEdge(18, 35, 1.2);
    graph4.addEdge(18, 38, 0.4);
    graph4.addEdge(19, 20, 1.1);
    graph4.addEdge(19, 29, 5);
    graph4.addEdge(20, 31, 3.2);
    graph4.addEdge(21, 25, 2.7);
    graph4.addEdge(22, 32, 3.2);
    graph4.addEdge(23, 28, 35);
    graph4.addEdge(23, 33, 1.4);
    graph4.addEdge(24, 37, 7.2);
    graph4.addEdge(25, 26, 1);
    graph4.addEdge(25, 35, 2);
    graph4.addEdge(26, 27, 1);
    graph4.addEdge(27, 32, 2.3);
    graph4.addEdge(29, 33, 4.7);
    graph4.addEdge(30, 33, 2.7);
    graph4.addEdge(30, 40, 4.3);
    graph4.addEdge(34, 40, 5.1);
    graph4.addEdge(38, 39, 2.7);



    // Record the start time
    auto start = chrono::high_resolution_clock::now();

    pair<vector<int>, vector<vector<int>>> ans = GetMinimumSpanningTree(graph2, 0);

    // Record the end time
    auto end = chrono::high_resolution_clock::now();
    // Calculate the duration between start and end
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    // Print the duration in microseconds
    cout << "Execution Time of Dijkstra function: " << duration.count() << " microseconds" << endl;

    cout << "Printing the distance between the source and the destination:\n"
         << endl;
    print(ans.first);
    cout << "Printing the parents for each nodes:\n"
         << endl;
    print(ans.second);
    // Vertex Distance from Source
    // 0          0
    // 1          4
    // 2          12
    // 3          19
    // 4          21
    // 5          11
    // 6          9
    // 7          8
    // 8          14

    vector<vector<int>> allPaths;

    // Record the start time
    start = chrono::high_resolution_clock::now();

    findAllPaths(ans.second, 0, 8, {}, allPaths);

    // Record the end time
    end = chrono::high_resolution_clock::now();

    // Calculate the duration between start and end
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    // Print the duration in microseconds
    cout << "Execution Time of the path finding algorithm is: " << duration.count() << " microseconds" << endl;

    // Print all paths
    cout << "Printing all the paths between the source and the destination :" << endl;
    for (const vector<int> &path : allPaths)
    {
        for (size_t i = 0; i < path.size(); ++i)
        {
            cout << path[i];
            if (i < path.size() - 1)
            {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    return 0;
}

    


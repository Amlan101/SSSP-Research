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
    Graph graph(9);      

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);

   // Get the current time before running the algorithm
    auto start_time = chrono::high_resolution_clock::now();

    pair<vector<int>, vector<vector<int>>> ans = GetMinimumSpanningTree(graph, 0);

     // Get the current time after running the algorithm
    auto end_time = chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
   
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

    // Get the current time before running the algorithm
     start_time = chrono::high_resolution_clock::now();

    findAllPaths(ans.second, 0, 8, {}, allPaths);

     // Get the current time after running the algorithm
     end_time = chrono::high_resolution_clock::now();

    // Calculate the duration
     duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

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

    

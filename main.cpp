#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <climits>
#include <algorithm>
#include <queue>
#include <set>

#include "return_value.h"
#include "map.h"
#include "file_handler.h"
#include "Dijkstra.h"
#include "BellmanFord.h"

using namespace std;

// defining constant expressions 
constexpr auto nodeCount = 20;
constexpr auto file = "Graph_2_20_Nodes.csv";
constexpr auto noOfRounds = 20;
constexpr auto noOfTrials = 5;

//Helper function to call and prepare the returned value to be written in a CSV file

static string vecToStr(const vector<int>& vec) {
    stringstream data;
    for (size_t i = 0; i < vec.size(); i++) {
        data << "[" << i << "->" << vec[i] << "]    ";
    }
    return data.str();
}

static string vecVecToStr(const vector<vector<int>>& vec) {
    stringstream data;
    data << "["; 

    for (size_t i = 0; i < vec.size(); ++i) {
        data << " [";
        for (size_t j = 0; j < vec[i].size(); ++j) {
            data << vec[i][j];
            if (j != vec[i].size() - 1) {
                data << "->";
            }
        }
        data << "]";
    }
    data << "]";
    return data.str();
}

static void run(int round, int startNode, const Graph& graph)
{
    //Storing the results
    struct return_value result1 = getMinimumSpanningTreeDijkstra(graph, startNode);
    struct return_value result2 = getMinimumSpanningTreeBellmanFord(graph, startNode);

    //Displaying the result in the compiler output
    //cout << result1.time << "," << result1.comparisons << "," << result1.relaxations << "\n";
    //cout << result2.time << "," << result2.comparisons << "," << result2.relaxations << "\n";

    // Parsing a string representation of the output
    stringstream data;
    data << "Method" << "," << "Execution Time" << "," << "Memory consumed" << "," << "No of Comparisions" << "," << "No of Relaxations" << "," << "Distance" << "," << "Parent" << "\n"
        << "Dijkstra" << "," << result1.time << "," << result1.memory << "," << result1.comparisons << "," << result1.relaxations << "," << vecToStr(result1.distance) << "," << vecVecToStr(result1.parent) << "\n"
        << "Bellman Ford" << "," << result2.time << "," << result2.memory << "," << result2.comparisons << "," << result2.relaxations << "," << vecToStr(result2.distance) << "," << vecVecToStr(result2.parent);
        
    string strs = data.str();

    //Calling the function to write in the csv with the string representation
    writeInCSV(strs);
}

int main()
{

    Graph graph(nodeCount);
    int test = initialize(file, graph);
    if (test == 0)
    {
        return 0;
    }

    for (int i = 0; i < noOfRounds; i++)
    {
        int startNode = i;
        //cout << "For startnode as :: " << startNode << endl;

        // Parsing a string representation of the output
        stringstream data;
        data << "Round" << ","
            << i << "\n"
            << "StartNode" << ","
            << i;
        string strs = data.str();
        writeInCSV(strs);

        // Read the input
        for (int j = 0; j < noOfTrials; j++)
        {
            run(i, startNode, graph);
        }
    }
    
   /* bool compare(pair<int, int> &a, pair<int, int> &b) {

    };


    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.emplace(make_pair(1,3));
    pq.emplace(make_pair(3, 7));
    pq.emplace(make_pair(1,3));
    pq.emplace(make_pair(1,2));
    pq.emplace(make_pair(7,5));
    pq.emplace(make_pair(5,0));

    for (int i = 0; i < 7; i++) {
        auto it = pq.top();
        cout << it.first << " " << it.second <<endl;
        pq.pop();
    }*/


    return 0;
}

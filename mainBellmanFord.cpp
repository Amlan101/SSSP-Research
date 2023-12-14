#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <climits>
#include <algorithm>
#include <queue>
#include <set>

#include "return_value.h"
#include "Graph.h"
#include "file_handler.h"
#include "BellmanFord.h"

using namespace std;

// defining constant expressions
constexpr auto nodeCount = 20;
constexpr auto file = "Graph_2_20_Nodes.csv";
constexpr auto preformanceFile = "BellmanFordPerforma_2_20_Nodes.csv";
constexpr auto outputFile = "BellmanFordOutput_2_20_Nodes.csv";
constexpr auto noOfRounds = 20;
constexpr auto noOfTrials = 5;

// Helper function to call and prepare the returned value to be written in a CSV file

static string vecToStr(const vector<int> &vec)
{
    stringstream data;
    data << "{ ";
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        data << vec[i] << " ";
    }
    data << vec[vec.size() - 1] << " }";
    return data.str();
}

static string vecVecToStr(const vector<vector<int>> &vec)
{
    stringstream data;
    data << "{ ";

    for (size_t i = 0; i < vec.size(); ++i)
    {
        data << " [";
        for (size_t j = 0; j < vec[i].size(); ++j)
        {
            data << vec[i][j];
            if (j != vec[i].size() - 1)
            {
                data << " ";
            }
        }
        data << "]";
    }
    data << " }";
    return data.str();
}

static void run(int round, int trial, int startNode, const Graph &graph)
{
    // Storing the results
    struct return_value result1 = getMinimumSpanningTreeBellmanFord(graph, startNode);

    // Displaying the result in the compiler output
    // cout << result1.time << "," << result1.comparisons << "," << result1.relaxations << "\n";

    // Parsing a string representation of the performance result
    stringstream performaRow;
    performaRow << nodeCount << "," << round << "," << trial << "," << result1.time << "," << result1.memory << "," << result1.comparisons << "," << result1.relaxations;

    string performaRowString = performaRow.str();

    // Calling the function to write in the performa csv with the string representation
    writeInCSV(performaRowString, preformanceFile);

    // parsing a string representation of the output
    stringstream outputRow;
    outputRow << nodeCount << "," << round << "," << trial << "," << vecToStr(result1.distance) << "," << vecVecToStr(result1.parent);

    string outputRowString = outputRow.str();

    // Calling the function to write in the csv with the string representation
    writeInCSV(outputRowString, outputFile);
}

int main()
{

    Graph graph(nodeCount);
    int test = initialize(file, graph);
    if (test == 0)
    {
        return 0;
    }

    // Parsing a string representation of the output
    stringstream performaHeader;
    performaHeader << "Graph Size"
                   << ","
                   << "Start Node"
                   << ","
                   << "trial"
                   << ","
                   << "Execution Time"
                   << ","
                   << "Memory consumed"
                   << ","
                   << "No of Comparisions"
                   << ","
                   << "No of Relaxations";
    string performaHeaderString = performaHeader.str();
    writeInCSV(performaHeaderString, preformanceFile);

    stringstream outputHeader;
    outputHeader << "Graph Size"
                 << ","
                 << "Start Node"
                 << ","
                 << "trial"
                 << ","
                 << "Distance"
                 << ","
                 << "Parent";
    string outputHeaderString = outputHeader.str();
    writeInCSV(outputHeaderString, outputFile);

    for (int i = 0; i < noOfRounds; i++)
    {
        int startNode = i;
        // cout << "For startnode as :: " << startNode << endl;

        // Read the input
        for (int j = 1; j <= noOfTrials; j++)
        {
            run(i, j, startNode, graph);
        }
    }

    return 0;
}
// 1. Test out the MinHeap.h (Unit testing and manually)
// 2. Organise different CSV files for Djikstra and BellmanFord
// 3. Document the entire codebase in a better format
// 4. Document issues and solutions in a report for future
// 5. The CSV files should be formatted better along with independent runs for each of the algorithms
// 6. Keep the system pristine whilst running each algorithm (ideal scenario should be maintained)
// 7.

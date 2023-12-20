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
#include "Dijkstra.h"

using namespace std;

// defining constant expressions
constexpr auto nodeCount = 40;
constexpr auto file = "testGraphs/Graph_4_40_Nodes/Graph_4_Sparse.csv";
constexpr auto preformanceFile = "Outputs/DijkstraPerforma_4_40_Sparse.csv";
constexpr auto outputFile = "Outputs/DijkstraOutput_4_40_Sparse.csv";
constexpr auto noOfRounds = 40;
constexpr auto noOfTrials = 5;

/**
 * Converts a vector of integers to its string representation enclosed within braces.
 *
 * @param vec The input vector to be converted to a string.
 * @return string A string representation of the input vector enclosed within braces.
 */
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

/**
 * Converts a vector of vectors of integers to its string representation enclosed within braces and brackets.
 *
 * @param vec The input vector of vectors to be converted to a string.
 * @return string A string representation of the input vector of vectors enclosed within braces and brackets.
 */
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

/**
 * Executes Dijkstra's algorithm for a specific round and trial, storing and writing the results to CSV files.
 *
 * @param round The round number indicating the iteration.
 * @param trial The trial number within the round.
 * @param startNode The starting node for the algorithm.
 * @param graph The Graph object on which the algorithm will be executed.
 */
static void run(int round, int trial, int startNode, const Graph &graph)
{
    // Storing the results
    struct return_value result1 = getMinimumSpanningTreeDijkstra(graph, startNode);

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
                   << "Trial"
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
                 << "Trial"
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

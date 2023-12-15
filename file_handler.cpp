#include "file_handler.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Graph.h"
using namespace std;

/**
 * Initializes a graph by reading data from a CSV file and populating the graph accordingly.
 *
 * @param filename The name of the CSV file containing graph data.
 * @param graph The Graph object to be initialized and populated with data from the CSV file.
 * @return int Returns 1 upon successful initialization, 0 if the CSV file fails to open.
 */
int initialize(string filename, Graph &graph)
{
    ifstream csvFile;
    csvFile.open(filename);
    if (!csvFile.is_open())
    {
        cout << "Error: Could not open CSV file during initialization" << endl;
        return 0;
    }

    string line;
    getline(csvFile, line); // Skip the header line
    // cout << line << endl;
    while (getline(csvFile, line))
    {
        // cout << line << endl;
        string source;
        string destination;
        string weight;
        istringstream iss(line);
        getline(iss, source, ',');
        getline(iss, destination, ',');
        getline(iss, weight, ',');
        // Assuming the CSV format is correct, add data to the map
        // cout<<source<<" ";
        // cout<<destination<<" ";
        // cout<<weight<<endl;
        graph.addEdge(stoi(source), stoi(destination), stoi(weight));
    }
    // cout << "end of file" << endl;
    csvFile.close();

    return 1;
}

/**
 * Appends given data to a CSV file or creates a new file if it doesn't exist.
 *
 * @param data The string of data to be appended to the CSV file.
 * @param file_name The name of the CSV file where the data will be written.
 */
void writeInCSV(string data, string file_name)
{
    // file pointer
    ofstream csvFile;

    // opens an existing csv file or creates a new file.
    csvFile.open(file_name, ios::in | ios::app);
    csvFile << data
            << "\n";
    csvFile.close();
}

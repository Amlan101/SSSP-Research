#include "file_handler.h"

#include <iostream>
#include <string>
#include<fstream>
#include <sstream>
#include "Graph.h"
using namespace std;

int initialize(string filename, Graph& graph)
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

//Function to write in a CSV file with a given format
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



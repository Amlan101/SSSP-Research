#ifndef FILE_HANDLER_H_INCLUDE
#define FILE_HANDLER_H_INCLUDE
#include <string>
#include "Graph.h"
using namespace std;

// Functions to read and write into the CSV file
  
//Function to read the graph from the CSV file
int initialize(string filename, Graph& graph);

//Function to write in a CSV file with a given format
void writeInCSV(string data, string file_name);


#endif //FILE_HANDLER_H_INCLUDE
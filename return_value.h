#ifndef RETURN_VALUE_H_INCLUDE
#define RETURN_VALUE_H_INCLUDE

#include <vector>
using namespace std;

struct return_value
{
        long time;
        int comparisons;
        int relaxations;
        long memory;
        vector<vector<int>> parent;
        vector<int> distance;

        return_value(long time, int comparisons, int relaxations, vector<int> distance, vector<vector<int>> parent, unsigned long long memory);
};




#endif // RETURN_VALUE_H_INCLUDE



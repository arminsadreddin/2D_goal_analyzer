#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <vector>
using namespace std;

class input
{
public:
    input();
    void load_data(string path);
    vector<vector<pair<double , double> > > all_paths;
};

#endif // INPUT_H

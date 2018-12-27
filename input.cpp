#include "input.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
input::input()
{

}
void input::load_data(string path){

    vector<pair<double , double> > single_path;
    string line;
    ifstream myfile (path.c_str());
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            pair<double , double> pos;
            if(line == "---------"){
                if(single_path.size() != 0){
                    all_paths.push_back(single_path);
                }
                single_path.clear();
                continue;
            }

            int delimiter = line.find(',');
            string x = line.substr(0 , delimiter);
            string y = line.substr(delimiter + 2 , line.size());

            double x_num = atof(x.c_str());
            double y_num = atof(y.c_str());

            pos.first = x_num;
            pos.second = y_num;

            single_path.push_back(pos);

        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
    //cout << all_paths.size() << endl;

}

#include "input.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
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
        pair<double , double> last_pos;
        last_pos.first = -1000;
        last_pos.second = -1000;
        pair<double , double> shoot_pos;
        bool added = false;
        while ( getline (myfile,line) )
        {
            pair<double , double> pos;
            if(line == "---------"){


                if(single_path.size() != 0){
                    if(added == false){
                        single_path.push_back(shoot_pos);
                    }
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

            if(dist(last_pos , pos) > 5){
                single_path.push_back(pos);
                last_pos = pos;
                added = true;
            }
            else{
                added = false;
            }
            shoot_pos = pos;


        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
    //cout << all_paths.size() << endl;

}


double input::dist(pair<double, double> point1, pair<double, double> point2){

    double d =sqrt( pow(point1.first - point2.first , 2) + pow(point1.second - point2.second , 2) );
    return d;
}

















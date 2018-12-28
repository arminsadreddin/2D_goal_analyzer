#ifndef DRAW_PATH_H
#define DRAW_PATH_H
#include <iostream>
#include <vector>
#include <mainwindow.h>
#include <qpainter.h>
using namespace std;

class draw_path
{
public:
    draw_path();
    void draw_goal_paths(MainWindow * w , vector<vector<pair<double , double> > > all_paths);
//protected:
//    void paintEvent(QPaintEvent *e);
};

#endif // DRAW_PATH_H

#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <qpainter.h>
#include <qpicture.h>
#include <input.h>
using namespace std;
pair<int , int> convert_2D_geom(pair<double , double> input , int img_x , int img_y);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //load image
    QPixmap px;
    px.load("/home/arminsadreddin/goal_path/field");

    //load input
    input in;
    in.load_data("/home/arminsadreddin/goal_path/ourGoalPath.txt");



    QPainter p(&px);


    //draw data
    for(int a = 0 ; a < in.all_paths.size() ; a++){
        vector<pair<double , double> > path = in.all_paths.at(a);
        for(int pa = 0 ; pa < path.size()-1 ; pa++){


            pair<int , int> first = convert_2D_geom(path.at(pa) , px.width(), px.height());
            pair<int , int> second = convert_2D_geom(path.at(pa+1) , px.width(), px.height());

            if(first.first < 0.0){
                cout << "wrong"<<endl;
            }
            if(first.second < 0.0){
                cout << "wrong"<<endl;
            }
            if(second.first < 0.0){
                cout << "wrong"<<endl;
            }
            if(second.second < 0.0){
                cout << "wrong"<<endl;
            }

            QPoint p1(first.first , first.second);
            QPoint p2(second.first , second.second);




            p.setPen(Qt::red);
            p.drawLine(p1,p2);

        }

    }


    //RENDER
    p.end();
    QLabel label;
    label.setPixmap(px);
    label.setGeometry(QRect(0, 0, px.width(), px.height()));
    label.show();

    return a.exec();
}
pair<int , int> convert_2D_geom(pair<double , double> input , int img_x , int img_y){

    pair<int , int> out_put;
    double x = input.first;
    double y = input.second;

    x += 52.5;
    y += 34.0;

    if(x < 0){
        x = 0;
    }
    if(y < 0){
        y = 0;
    }

    x *= (double)(img_x/105.0);
    y *= (double)(img_y/68.0);



    out_put.first = x + 0.5;//round to nearest int
    out_put.second = y + 0.5;//round to nearest int
    return out_put;

}







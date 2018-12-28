#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <qpainter.h>
#include <qpicture.h>
#include <input.h>
#include <random>
using namespace std;
pair<int , int> convert_2D_geom(pair<double , double> input , int img_x , int img_y);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    double value_map[105][68] = {0};

    //load image
    QPixmap px;
    QPixmap value_field;
    px.load("/home/arminsadreddin/goal_path/field");
    value_field.load("/home/arminsadreddin/goal_path/field");


    //load input
    input in;
    in.load_data("/home/arminsadreddin/goal_path/ourGoalPath.txt");



    QPainter p(&px);
    QPainter value_painter(&value_field);

    //draw data
    for(int a = 0 ; a < in.all_paths.size() ; a++){
        vector<pair<double , double> > path = in.all_paths.at(a);


        int r = rand() % 255;
        int g = rand() % 255;
        int b = rand() % 255;
        QColor pen_color(r,g,b);
        QPen line_pen(pen_color);
        line_pen.setWidth(1);

        QPen point_pen(pen_color);
        point_pen.setWidth(4);

        pair<double , double> point_2D;
        for(int pa = 0 ; pa < path.size()-1 ; pa++){

            point_2D = path.at(pa);
            point_2D.first = (int)(point_2D.first + 52.5 + 0.5);
            point_2D.second = (int)(point_2D.second + 34.0 + 0.5);

            if(point_2D.first > 104){
                point_2D.first = 104;
            }
            if(point_2D.first < 0){
                point_2D.first = 0;
            }
            if(point_2D.second > 67){
                point_2D.second = 67;
            }
            if(point_2D.second < 0){
                point_2D.second = 0;
            }


            value_map[(int)point_2D.first][(int)point_2D.second] += 0.1;

            pair<int , int> first = convert_2D_geom(path.at(pa) , px.width(), px.height());
            pair<int , int> second = convert_2D_geom(path.at(pa+1) , px.width(), px.height());


            QPoint p1(first.first , first.second);
            QPoint p2(second.first , second.second);


            p.setPen(line_pen);
            p.drawLine(p1,p2);
            p.setPen(point_pen);
            p.drawPoint(p1);
            p.drawPoint(p2);

        }
        point_2D = path.at(path.size() - 1);
        point_2D.first = (int)(point_2D.first + 52.5 + 0.5);
        point_2D.second = (int)(point_2D.second + 34.0 + 0.5);

        if(point_2D.first > 104){
            point_2D.first = 104;
        }
        if(point_2D.first < 0){
            point_2D.first = 0;
        }
        if(point_2D.second > 67){
            point_2D.second = 67;
        }
        if(point_2D.second < 0){
            point_2D.second = 0;
        }

        value_map[(int)point_2D.first][(int)point_2D.second] += 0.1;

    }


    //RENDER
    p.end();
    QLabel paths_label;
    paths_label.setPixmap(px);
    paths_label.setGeometry(QRect(0, 0, px.width(), px.height()));
    paths_label.show();


    double rect_x_lenght = value_field.width() / 105.0;
    double rect_y_lenght = value_field.height() / 68.0;

    for(int x = 0 ; x < 105 ; x++){

        for(int y = 0 ; y < 68 ; y++){
            qreal op;
            op = value_map[x][y];
            QPen grid_pen;

            grid_pen.setColor(Qt::red);
            QPainterPath path;


            path.addRect(QRectF(x*rect_x_lenght+0.5,y*rect_y_lenght+0.5,rect_x_lenght,rect_y_lenght));
            value_painter.drawPath(path);


            value_painter.setPen(grid_pen);
            value_painter.setOpacity(op);

            value_painter.fillPath(path,Qt::red);



        }

    }

    QLabel value_label;
    value_label.setPixmap(value_field);
    value_label.setGeometry(QRect(0, 0, px.width(), px.height()));
    value_label.show();



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







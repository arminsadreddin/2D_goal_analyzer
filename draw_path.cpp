#include "draw_path.h"
#include <iostream>

using namespace std;







draw_path::draw_path()
{

}
void draw_path::draw_goal_paths(MainWindow * w , vector<vector<pair<double, double> > > all_paths){






    QPainter painter(w);
    QPen paintPen(Qt::black);
    paintPen.setWidth(6);


    QPen linePen(Qt::red);
    linePen.setWidth(2);

    QPoint p1;
    p1.setX(10);
    p1.setY(10);


    QPoint p2;
    p2.setX(100);
    p2.setY(100);






    painter.setPen(linePen);
    painter.drawLine(p1,p2);

    painter.setPen(paintPen);
    painter.drawPoint(p1);
    painter.drawPoint(p2);



    //    for(int a = 0 ; a < all_paths.size() ; a++){

    //        for(int p = 0 ; p < all_paths.at(a).size() ; p++){



    //        }

    //    }


}
//void draw_path::paintEvent(QPaintEvent *e){

//    QPainter painter(w);
//    painter.drawLine(10,10,100,100);

//}

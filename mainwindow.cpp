#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include "input.h"
#include <qpainter.h>
#include <qpicture.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{





//    load_image img;
//    string image_path = "/home/arminsadreddin/goal_path/field";
//    img.load_field(this , image_path);

//    input in;
//    in.load_data("/home/arminsadreddin/goal_path/ourGoalPath.txt");
//    paths = in.all_paths;













    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e){




//    QPainter painter(this);
//    draw_path path_draw;
//    path_draw.draw_goal_paths(this , paths,e);

}
















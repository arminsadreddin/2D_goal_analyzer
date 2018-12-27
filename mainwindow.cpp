#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include "load_image.h"
#include "input.h"
#include "draw_path.h"
#include <qpainter.h>
#include <qpicture.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    load_image img;
    string image_path = "/home/arminsadreddin/goal_path/field";
    img.load_field(this , image_path);




    input in;
    in.load_data("/home/arminsadreddin/goal_path/ourGoalPath.txt");



    //TODO filter if needed should be add

    draw_path path_draw;
    //path_draw.draw_goal_paths(this , in.all_paths);












    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include "load_image.h"
#include "input.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //loading field image starts
    load_image img;
    string image_path = "/home/arminsadreddin/goal_path/field";
    img.load_field(this , image_path);
    //field image loaded

    //loading input starts
    input in;
    in.load_data("/home/arminsadreddin/goal_path/ourGoalPath.txt");






    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

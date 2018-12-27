#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include "load_image.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //loading field image starts
    load_image img;
    string image_path = "/home/arminsadreddin/goal_path/field";
    img.load_field(this , image_path);
    //field image loaded








    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

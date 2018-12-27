#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QPixmap pic("/home/arminsadreddin/goal_path/field");


    w.show();

    return a.exec();
}

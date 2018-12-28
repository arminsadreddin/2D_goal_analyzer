#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <vector>
#include <iostream>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    vector<vector<pair<double , double> > > paths;

private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent *e);

};

#endif // MAINWINDOW_H

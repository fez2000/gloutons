#include "mainwindow.h"
#include <QApplication>
#include <QAction>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    welcome we;
    we.exec();

    return a.exec();
}

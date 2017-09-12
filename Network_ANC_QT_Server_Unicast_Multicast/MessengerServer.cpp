#include <QApplication>
#include "mainwindow.h"
//#include "tao/QtResource/QtResource_Loader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //TAO::QtResource_Loader qt_resources (&a);
    MainWindow w;
    w.show();

    return a.exec();
}


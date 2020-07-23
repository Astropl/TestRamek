#include "mainwindow.h"
//#include "Files/checksystemfiles1.h"
#include "Files/checkfiles1.h"
#include <QMessageBox>
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

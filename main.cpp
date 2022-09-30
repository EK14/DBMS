#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include "dbms.h"

int main(int argc, char *argv[])
{
    DBMS dbms;
    QApplication a(argc, argv);
    MainWindow w(nullptr, &dbms);
    w.show();
    return a.exec();
}

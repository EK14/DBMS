#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbms.h"
#include "create.h"
#include "populate.h"
#include "addinformation.h"
#include "printmenu.h"
#include "backup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, DBMS *dbms);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    DBMS *dbms;
    Create *windowCreate;
    Populate *windowPopulate;
    AddInformation *windowChange;
    PrintMenu *windowPrint;
    BackUp *windowBackup;
};
#endif // MAINWINDOW_H

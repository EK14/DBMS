#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, DBMS *dbms)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->dbms = dbms;
    setStyleSheet("background:rgb(102, 103, 171);");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    windowCreate = new Create(this, dbms);
    windowCreate->show();
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    windowPopulate = new Populate(this, dbms);
    windowPopulate->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    hide();
    windowChange = new AddInformation(this, dbms);
    windowChange->show();
}


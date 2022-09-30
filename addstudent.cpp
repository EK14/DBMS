#include "addstudent.h"
#include "ui_addstudent.h"

ADDSTUDENT::ADDSTUDENT(QWidget *parent, DBMS *dbms, QString database, int index):
    QDialog(parent),
    ui(new Ui::ADDSTUDENT)
{
    ui->setupUi(this);
    this->dbms = dbms;
    this->parent = parent;
    this->database = database;
    this->index = index;
}

ADDSTUDENT::~ADDSTUDENT()
{
    delete ui;
}

void ADDSTUDENT::on_pushButton_clicked()
{
    QString studentName = ui->lineEdit->text();
    this->dbms->addStudent(index, studentName, this);
}

void ADDSTUDENT::on_pushButton_2_clicked()
{
    hide();
    parent->show();
}


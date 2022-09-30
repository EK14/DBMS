#include "addvariant.h"
#include "ui_addvariant.h"

ADDVARIANT::ADDVARIANT(QWidget *parent, DBMS *dbms, QString database, int index):
    QDialog(parent),
    ui(new Ui::ADDVARIANT)
{
    ui->setupUi(this);
    this->dbms = dbms;
    this->parent = parent;
    this->database = database;
    this->index = index;
}

ADDVARIANT::~ADDVARIANT()
{
    delete ui;
}

void ADDVARIANT::on_pushButton_clicked()
{
    QString variantName = ui->lineEdit->text();
    this->dbms->addVariant(index, variantName, this);
    on_pushButton_2_clicked();
}




void ADDVARIANT::on_pushButton_2_clicked()
{
    hide();
    parent->show();
}


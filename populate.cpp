#include "populate.h"
#include "ui_populate.h"
#include "QMessageBox"

Populate::Populate(QWidget *parent, DBMS *dbms) :
    QDialog(parent),
    ui(new Ui::Populate)
{
    ui->setupUi(this);
    setStyleSheet("background:rgb(102, 103, 171);");
    this->dbms = dbms;
    this->parent = parent;
}

Populate::~Populate()
{
    delete ui;
}

void Populate::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    int index = this->dbms->databaseExist(name.toStdString());
    if (index >= 0){
        this->dbms->populateDatabase(index);
    }else
        QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    on_pushButton_2_clicked();
}


void Populate::on_pushButton_2_clicked()
{
    parent->show();
    hide();
}


#include "create.h"
#include "ui_create.h"
#include "QMessageBox"

Create::Create(QWidget *parent, DBMS *dbms) :
    QDialog(parent),
    ui(new Ui::Create)
{
    ui->setupUi(this);
    setStyleSheet("background:rgb(102, 103, 171);");
    this->dbms = dbms;
    this->parent = parent;
}

Create::~Create()
{
    delete ui;
}

void Create::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    if(this->dbms->databaseExist(name.toStdString()) < 0){
            this->dbms->databases.push_back(name.toStdString()); // add database name to DBSM
            mkdir(("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + name.toStdString()).c_str(), 0777);//create an empty database
    }
    else{
            QMessageBox::critical(this,"Заголовок", "A database with the same name already exists\n");
    }
    on_pushButton_2_clicked();
}


void Create::on_pushButton_2_clicked()
{
    hide();
    parent->show();
}


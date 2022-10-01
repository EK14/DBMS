#include "addinformation.h"
#include "ui_addinformation.h"

AddInformation::AddInformation(QWidget *parent, DBMS *dbms) :
    QDialog(parent),
    ui(new Ui::AddInformation)
{
    ui->setupUi(this);
    this->dbms = dbms;
    this->parent = parent;
    name = "";
    this->index = -1;
}

AddInformation::~AddInformation()
{
    delete ui;
}

void AddInformation::on_pushButton_clicked()
{
    name = ui->lineEdit->text();
    this->index = this->dbms->databaseExist(name.toStdString());
    if (index < 0)
        QMessageBox::critical(this,"Заголовок", "There is no database with this name");
}


void AddInformation::on_pushButton_2_clicked()
{
    if(name == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the database name");
    else if((this->dbms->databaseExist(name.toStdString())) < 0)
           QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    else{
        hide();
        std::string type = "Add student";
        windowAdd = new ADD(parent, dbms, name, index, type);
        windowAdd->show();
    }
}


void AddInformation::on_pushButton_6_clicked()
{
    hide();
    parent->show();
}


void AddInformation::on_pushButton_3_clicked()
{
    if(name == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the database name");
    else if((this->dbms->databaseExist(name.toStdString())) < 0)
           QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    else{
        hide();
        std::string type = "Add variant";
        windowAdd = new ADD(parent, dbms, name, index, type);
        windowAdd->show();
    }
}


void AddInformation::on_pushButton_7_clicked()
{
    if(name == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the database name");
    else if((this->dbms->databaseExist(name.toStdString())) < 0)
           QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    else{
        hide();
        std::string type = "Remove student";
        windowAdd = new ADD(parent, dbms, name, index, type);
        windowAdd->show();
    }
}


void AddInformation::on_pushButton_8_clicked()
{
    if(name == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the database name");
    else if((this->dbms->databaseExist(name.toStdString())) < 0)
           QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    else{
        hide();
        std::string type = "Remove variant";
        windowAdd = new ADD(parent, dbms, name, index, type);
        windowAdd->show();
    }
}


void AddInformation::on_pushButton_4_clicked()
{
    if(name == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the database name");
    else if((this->dbms->databaseExist(name.toStdString())) < 0)
           QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    else{
        hide();
        std::string type = "students.txt";
        windowCorrection = new Correct(parent, dbms, index, type);
        windowCorrection->show();
    }
}

void AddInformation::on_pushButton_5_clicked()
{
    if(name == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the database name");
    else if((this->dbms->databaseExist(name.toStdString())) < 0)
           QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    else{
        hide();
        std::string type = "variants.txt";
        windowCorrection = new Correct(parent, dbms, index, type);
        windowCorrection->show();
    }
}


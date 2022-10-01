#include "correct.h"
#include "ui_correct.h"

Correct::Correct(QWidget *parent,  DBMS *dbms, int index, std::string& str):
    QDialog(parent),
    ui(new Ui::Correct)
{
    ui->setupUi(this);
    this->dbms = dbms;
    this->parent = parent;
    this->index = index;
    this->nameToCorrect = "";
    this->correctedName = "";
    this->canBeCorrected = false;
    this->type = str;
    this->id = -1;
}

Correct::~Correct()
{
    delete ui;
}

void Correct::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    this->id = this->dbms->checkUp(this, index, name, type);
    if(id != -1)
        this->nameToCorrect = name;
    else
        QMessageBox::critical(parent, "Заголовок", "This name is not listed in the table\n");
}


void Correct::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit_2->text();
    if(name == ""){
        QMessageBox::critical(parent, "Заголовок", "Please, enter the name you want to change to\n");
    }
    else if(this->nameToCorrect == "")
        QMessageBox::critical(parent, "Заголовок", "Please, enter the name you want to correct\n");
    else if(this->dbms->checkUp(this, index, name, type) != -1)
    {
        QMessageBox::critical(parent, "Заголовок", "This name is already listed in the table. Please, try another one.\n");
    }
    else{
        correctedName = name;
    }
}


void Correct::on_pushButton_4_clicked()
{
    if(correctedName != "" && nameToCorrect != ""){
        this->dbms->correction(this, id, nameToCorrect, correctedName, type, index);
        on_pushButton_3_clicked();
    }
    else if(nameToCorrect == "")
        QMessageBox::critical(parent, "Заголовок", "Please, enter the name you want to correct\n");
    else if(correctedName == "")
        QMessageBox::critical(parent, "Заголовок", "Please, enter the name you want to change to\n");
    else if(this->dbms->checkUp(this, index, correctedName, type) != -1)
        QMessageBox::critical(parent, "Заголовок", "This name is already listed in the table. Please, try another one.\n");
}


void Correct::on_pushButton_3_clicked()
{
    hide();
    parent->show();
}


#include "add.h"
#include "ui_add.h"

ADD::ADD(QWidget *parent, DBMS *dbms, QString database, int index, std::string& str):
    QDialog(parent),
    ui(new Ui::ADD)
{
    ui->setupUi(this);
    this->dbms = dbms;
    this->parent = parent;
    this->database = database;
    this->index = index;
    this->type = str;
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setStyleSheet(QString("font-size: %1px;" "color: white;").arg(18));
    if(this->type == "Add student"){
        ui->label->setText("Just write down the student\nyou want to add");
    }
    else if(this->type == "Add variant")
        ui->label->setText("Just write down the variant\nyou want to add");
    else if(this->type == "Remove student")
        ui->label->setText("Just write down the student\nyou want to remove");
    else if(this->type == "Remove variant")
        ui->label->setText("Just write down the variant\nyou want to remove");
}

ADD::~ADD()
{
    delete ui;
}

void ADD::on_pushButton_clicked()
{
    if(this->type == "Add student"){
        QString studentName = ui->lineEdit->text();
        this->dbms->addStudent(index, studentName, this);
    }
    else if(this->type == "Add variant"){
        QString variantName = ui->lineEdit->text();
        this->dbms->addVariant(index, variantName, this);
    }
    else if(this->type == "Remove student"){
        QString variantName = ui->lineEdit->text();
        this->dbms->remove(index, variantName, this, "students.txt");
    }
    else if(this->type == "Remove variant"){
        QString variantName = ui->lineEdit->text();
        this->dbms->remove(index, variantName, this, "variants.txt");
    }
}




void ADD::on_pushButton_2_clicked()
{
    hide();
    parent->show();
}


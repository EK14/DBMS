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
    if(this->type == "student"){
        ui->label->setText("Just write down the student\nyou want to add");
    }
    else
        ui->label->setText("Just write down the variant\nyou want to add");
}

ADD::~ADD()
{
    delete ui;
}

void ADD::on_pushButton_clicked()
{

    if(this->type == "student"){
        QString variantName = ui->lineEdit->text();
        this->dbms->addStudent(index, variantName, this);
    }
    else{
        QString variantName = ui->lineEdit->text();
        this->dbms->addVariant(index, variantName, this);
    }
}




void ADD::on_pushButton_2_clicked()
{
    hide();
    parent->show();
}


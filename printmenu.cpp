#include "printmenu.h"
#include "ui_printmenu.h"

PrintMenu::PrintMenu(QWidget *parent, DBMS *dbms):
    QDialog(parent),
    ui(new Ui::PrintMenu)
{
    ui->setupUi(this);
    this->idStudent = "";
    this->idVariant = "";
    this->dbms = dbms;
    this->parent = parent;
    this->index = -1;
}

PrintMenu::~PrintMenu()
{
    delete ui;
}

void PrintMenu::on_pushButton_clicked()
{
    idStudent = ui->lineEdit->text();
    if(name == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the database name");
    else if((this->dbms->databaseExist(name.toStdString())) < 0)
           QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    else if(idStudent == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the student id");
    else{
        std::string type = "Print student";
        int id = this->dbms->checkID(this, index, idStudent, "students.txt", type);
        if(id == -1)
        {
            QMessageBox::critical(parent, "Заголовок", "There is no name with this id.Please, enter another one.\n");
        }
        else{
            this->dbms->print(id, "students.txt", index, text);
            hide();
            windowPrint = new Print(parent, index, type, dbms, text);
            windowPrint->show();
        }
    }
}


void PrintMenu::on_pushButton_6_clicked()
{
    name = ui->lineEdit_3->text();
    std::string newName = name.toUtf8().constData();
    this->index = this->dbms->databaseExist(newName);
    if (index < 0)
        QMessageBox::critical(this,"Заголовок", "There is no database with this name");
}


void PrintMenu::on_pushButton_2_clicked()
{
    idVariant = ui->lineEdit_2->text();
    if(name == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the database name");
    else if((this->dbms->databaseExist(name.toStdString())) < 0)
           QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    else if(idVariant == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the student id");
    else{
        std::string type = "Print variant";
        int id = this->dbms->checkID(this, index, idVariant, "variants.txt", type);
        if(id == -1)
        {
            QMessageBox::critical(parent, "Заголовок", "There is no name with this id.Please, enter another one.\n");
        }
        else{
            this->dbms->print(id, "variants.txt", index, text);
            hide();
            windowPrint = new Print(parent, index, type, dbms, text);
            windowPrint->show();
        }
    }
}


void PrintMenu::on_pushButton_3_clicked()
{
    std::string type = "Print students";
    if(name == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the database name");
    else if((this->dbms->databaseExist(name.toStdString())) < 0)
           QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    else{
        hide();
        windowPrint = new Print(parent, index, type, dbms, text);
        windowPrint->show();
    }
}


void PrintMenu::on_pushButton_4_clicked()
{
    std::string type = "Print variants";
    if(name == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the database name");
    else if((this->dbms->databaseExist(name.toStdString())) < 0)
           QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    else{
        hide();
        windowPrint = new Print(parent, index, type, dbms, text);
        windowPrint->show();
    }
}


void PrintMenu::on_pushButton_7_clicked()
{
    std::string type = "Testing Table";
    if(name == "")
        QMessageBox::critical(this,"Заголовок", "Please, enter the database name");
    else if((this->dbms->databaseExist(name.toStdString())) < 0)
           QMessageBox::critical(this,"Заголовок", "There is no database with this name");
    else{
        hide();
        windowPrint = new Print(parent, index, type, dbms, text);
        windowPrint->show();
    }
}


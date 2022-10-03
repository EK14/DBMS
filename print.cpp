#include "print.h"
#include "ui_print.h"

Print::Print(QWidget *parent, int index, std::string type, DBMS *dbms, std::string text):
    QDialog(parent),
    ui(new Ui::Print)
{
    ui->setupUi(this);
    this->parent = parent;
    this->index = index;
    this->type = type;
    this->dbms = dbms;
    if(type == "Print student" || type == "Print variant"){
        QString output = QString::fromUtf8(text.c_str());
        ui->listWidget->addItem(output);
    }
    else if(type == "Print students"){
        std::string line;
        std::ifstream file("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + this->dbms->databases[index] + "/students.txt");
        while(getline(file, line)){
            QString output = QString::fromUtf8(line.c_str());
            ui->listWidget->addItem(output);
        }
    }
    else if(type == "Print variants"){
        std::string line;
        std::ifstream file("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + this->dbms->databases[index] + "/variants.txt");
        while(getline(file, line)){
            QString output = QString::fromUtf8(line.c_str());
            ui->listWidget->addItem(output);
        }
    }
    else if(type == "Testing Table"){
        QString output;
        std::string name;
        std::string surname;
        std::string patronymic;
        std::string variant;
        std::ifstream f1("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + this->dbms->databases[index] + "/testingTable.txt");
        std::ifstream f2("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + this->dbms->databases[index] + "/variants.txt");
        std::ifstream f3("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + this->dbms->databases[index] + "/students.txt");
        for(std::string word; f1 >> word;){
            f3.clear();
            f3.seekg(0, std::ios::beg);
            f2.clear();
            f2.seekg(0, std::ios::beg);
            for(std::string student; f3 >> student;){
                f3 >> surname;
                f3 >> name;
                f3 >> patronymic;
                if(word == student){
                    output = QString::fromUtf8((name + " " + surname + " " + patronymic + " ").c_str());
                    break;
                }
            }
            f1 >> word;
            for(std::string id; f2 >> id;){
                f2 >> variant;
                if(word == id){
                    output += QString::fromUtf8(variant.c_str());
                    ui->listWidget->addItem(output);
                    break;
                }
            }
        }
    }
}

Print::~Print()
{
    delete ui;
}

void Print::on_pushButton_clicked()
{
    parent->show();
    hide();
}


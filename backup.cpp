#include "backup.h"
#include "ui_backup.h"
namespace fs = std::__fs::filesystem;

BackUp::BackUp(QWidget *parent, DBMS *dbms):
    QDialog(parent),
    ui(new Ui::BackUp)
{
    ui->setupUi(this);
    this->dbms = dbms;
    this->parent = parent;
}

BackUp::~BackUp()
{
    delete ui;
}

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void BackUp::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    int index = this->dbms->databaseExist(name.toStdString());
    if (index >= 0){
        std::string data = currentDateTime();
        const std::string find = ":";
        const std::string repl = "\\";

        size_t pos = 0;
        for (;;)
        {
            pos = data.find(find, pos);
            if (pos == std::string::npos)
                break;

            data.replace(pos, find.size(), repl);
            pos += repl.size();
        }
        std::string stringName = name.toStdString();
        std::string backUpName = "backup_" +stringName + "_" + data;
        mkdir(("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + backUpName).c_str(), 0777);//create an empty database
        fs::copy("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + name.toStdString() + "/", "/Users/elinakarapetan/Desktop/DataBase/DataBases/" + backUpName + "/");
        this->dbms->databases.push_back(backUpName);
    }else
        QMessageBox::critical(this,"Заголовок", "There is no database with this name");
}


void BackUp::on_pushButton_2_clicked()
{
    hide();
    parent->show();
}


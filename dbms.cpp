#include "dbms.h"
#include <QMessageBox>

namespace fs = std::__fs::filesystem;
DBMS::DBMS() {

}

void DBMS::generateID(int index) {
    int i = 0;
    std::ofstream f1;
    f1.open("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/students.txt");
    std::ifstream f2("/Users/elinakarapetan/Desktop/DataBase/DataBases/names.txt");
    for (std::string word; getline(f2, word);){ // add ID's
        word = std::to_string(i) + " " + word + '\n';
        f1 << word;
        i+=1;
    }
}

void DBMS::transferInformation() {

}

int DBMS::databaseExist(std::string database) {
    for(int i = 0; i < databases.size(); i++){ // checking if a database with the given name exists
        if(QString::fromUtf8(databases[i].c_str()) == QString::fromUtf8(database.c_str()))
            return i;
    }
    return -1;
}

void DBMS::populateDatabase(int index) {
    generateID(index);
    copyInitData(index);
    testingTable(index);
}

void DBMS::copyInitData(int index) {
    fs::remove("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/names.txt");
    fs::remove("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/variants.txt");
    fs::copy("/Users/elinakarapetan/Desktop/DataBase/DataBases/names.txt", "/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/");
    fs::copy("/Users/elinakarapetan/Desktop/DataBase/DataBases/variants.txt", "/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/");
}

void DBMS::testingTable(int index) {
    std::vector <std::string> variants(0);
    std::ofstream f1;
    std::ifstream f2("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/variants.txt");
    std::ifstream f3("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/students.txt");
    f1.open("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/testingTable.txt");
    for(std::string word; getline(f2, word);){
        if(word == "\n")
            break;
        word.erase(word.find_first_of(' ',0), word.size()-1);
        variants.push_back(word);
    }
    for(std::string word; getline(f3, word);){
        word.erase(word.find_first_of(' ',0), word.size()-1);
        word += " " + variants[rand() % variants.size()] + "\n";
        f1 << word;
    }
}

void DBMS::addStudent(int index, QString name, QWidget *parent){
    std::string filename = "students.txt";
    int lastID = checkString(index, name, &filename, "Add");
    std::ofstream f1;
    f1.open("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/students.txt", std::ios::app);
    if(lastID < 0){
        QMessageBox::critical(parent, "Заголовок", "This student is already listed in the table\n");
    }
    else{
        f1 << (lastID + 1);
        f1 << name.toStdString() + "\n";
    }
    f1.close();
}

int DBMS::checkString(int index, QString& str, std::string* s, std::string type) {
    std::string filename = *s;
    std::ifstream file("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/" + filename);
    std::string information;
    std::string name = "";
    int lastId;
    int count = 0;
    str = " " + str;
    for(std::string id; file >> id;){
        count++;
        if(*s == "students.txt"){
            for(int j = 0; j < 3; j++){
                file >> information;
                name += " " + information;
            }
        }
        else{
            file >> information;
            name += " " + information;
        }
        if(QString::fromStdString(name) == str){
            file.close();
            if(type == "Add")
                return -1;
            else if(type == "Remove")
                return count;
            else if(type == "Correct" || type == "Print student" || type == "Print variant")
                return stoi(id);
        }
        lastId = stoi(id);
        name = "";
    }
    file.close();
    if(type == "Add")
        return lastId;
    else if(type == "Remove" || type == "Correct" || type == "Print student" || type == "Print variant")
        return -1;
}

void DBMS::addVariant(int index, QString name, QWidget *parent){
    std::string filename = "variants.txt";
    int lastID = checkString(index, name, &filename, "Add");
    std::ofstream f1;
    f1.open("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/variants.txt", std::ios::app);
    if(lastID < 0){
        QMessageBox::critical(parent, "Заголовок", "This variant is already listed in the table\n");
    }
    else{
        f1 << (lastID + 1);
        f1 << name.toStdString() + "\n";
    }
    f1.close();
}

void DBMS::remove(int index, QString name, QWidget *parent, std::string s){
    std::string filename = s;
    int lineToRemove = checkString(index, name, &filename, "Remove");
    if(lineToRemove == -1){
        QMessageBox::critical(parent, "Заголовок", "There is no student/variant with this name\n");
        return;
    }
    std::ifstream file("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/" + filename);
    std::string line;
    std::string text;
    int amountStr = 0;
    while(getline(file,line))
     {
       amountStr++;

       if(!(amountStr == lineToRemove))
       {
           text.insert(text.size(),line);
           text.insert(text.size(),"\n");
       }
     }
    file.close();
    std::ofstream file_out;

    file_out.open ("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/" + filename,std::ios::trunc | std::ios::binary);

    file_out.write(text.c_str(), text.size());
    file_out.clear();
    file_out.close();
}

void DBMS::correction(QWidget *parent, int id, QString nameToCorrect, QString correctedName, std::string s, int index){
    std::ifstream file("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/" + s);
    std::string line;
    std::string text = "";
    int amountStr = 0;
    while(getline(file,line))
     {
       std::string name = line;
       std::string id_from_line = line.erase(line.find_first_of(' ',0), line.size()-1);
       if(id_from_line == std::to_string(id)){
           text.insert(text.size(),id_from_line + " " + correctedName.toStdString());
           text.insert(text.size(),"\n");
       }
       else{
           text.insert(text.size(),name);
           text.insert(text.size(),"\n");
       }
     }
    file.close();
    std::ofstream file_out;

    file_out.open ("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/" + s,std::ios::trunc | std::ios::binary);

    file_out.write(text.c_str(), text.size());
    file_out.clear();
    file_out.close();
}

int DBMS::checkUp(QWidget *parent, int index, QString nameToCorrect, std::string file, std::string type){
    return checkString(index, nameToCorrect, &file, type);
}


void DBMS::print(int id, std::string type, int index, std::string& str){
    std::ifstream file("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + databases[index] + "/" + type);
    std::string line;
    while(getline(file, line))
     {
       std::string name = line;
       std::string id_from_line = line.erase(line.find_first_of(' ',0), line.size()-1);
       name.erase(name.cbegin(), name.cbegin() + name.find_first_of(' ', 0) + 1);
       if(id_from_line == std::to_string(id)){
           str = name;
       }
    }
}

int DBMS::checkID(QWidget *parent, int index, QString ID, std::string filename, std::string type){
    std::ifstream file("/Users/elinakarapetan/Desktop/DataBase/DataBases/" + this->databases[index] + "/" + filename);
    for(std::string id; file >> id;){
        if(ID.toStdString() == id)
            return stoi(id);
    }
    return -1;
}

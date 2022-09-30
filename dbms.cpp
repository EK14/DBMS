#include "dbms.h"
#include <QMessageBox>

namespace fs = std::__fs::filesystem;
DBMS::DBMS() {

}

void DBMS::generateID(int index) {
    int i = 0;
    std::ofstream f1;
    f1.open("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/students.txt");
    std::ifstream f2("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/names.txt");
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
        if(databases[i] == database)
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
    fs::remove("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/names.txt");
    fs::remove("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/variants.txt");
    fs::copy("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/names.txt", "/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/");
    fs::copy("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/variants.txt", "/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/");
}

void DBMS::testingTable(int index) {
    std::vector <std::string> variants(0);
    std::ofstream f1;
    std::ifstream f2("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/variants.txt");
    std::ifstream f3("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/students.txt");
    f1.open("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/testingTable.txt");
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

void DBMS::printTable(int index) {
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string variant;
    std::ifstream f1("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/testingTable.txt");
    std::ifstream f2("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/variants.txt");
    std::ifstream f3("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/students.txt");
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
                std::cout << name << " " << surname << " " << patronymic << " ";
                break;
            }
        }
        f1 >> word;
        for(std::string id; f2 >> id;){
            f2 >> variant;
            if(word == id){
                std::cout << variant << std::endl;
                break;
            }
        }
    }
}

void DBMS::addStudent(int index, QString name, QWidget *parent){
    std::ifstream f("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/students.txt");
    int lastID = checkString(f, name);
    f.close();
    std::ofstream f1;
    f1.open("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/students.txt");
    if(lastID < 0){
        QMessageBox::critical(parent, "Заголовок", "This student is already listed in the table\n");
    }
    else{
        f1 << (lastID + 1);
        f1 << name.toStdString() + "\n";
    }
}

int DBMS::checkString(std::ifstream& file, QString& str) {
    std::string information;
    std::string name = "";
    int lastId;
    str = " " + str;
    for(std::string id; file >> id;){
        for(int j = 0; j < 3; j++){
            file >> information;
            name += " " + information;
        }
        if(QString::fromStdString(name) == str){
            return -1;
        }
        lastId = stoi(id);
        name = "";
    }
    return lastId;
}

void DBMS::addVariant(int index, QString name, QWidget *parent){
    std::ifstream f("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/variants.txt");
    int lastID = checkString(f, name);
    f.close();
    std::ofstream f1;
    f1.open("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/variants.txt");
    if(lastID < 0){
        QMessageBox::critical(parent, "Заголовок", "This variant is already listed in the table\n");
    }
    else{
        f1 << (lastID + 1);
        f1 << name.toStdString() + "\n";
    }
}

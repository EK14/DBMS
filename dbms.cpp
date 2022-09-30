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
    std::string filename = "students.txt";
    int lastID = checkString(index, name, &filename, "Add");
    std::ofstream f1;
    f1.open("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/students.txt", std::ios::app);
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
    std::ifstream file("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/" + filename);
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
        }
        lastId = stoi(id);
        name = "";
    }
    file.close();
    if(type == "Add")
        return lastId;
    else if(type == "Remove")
        return -1;
}

void DBMS::addVariant(int index, QString name, QWidget *parent){
    std::string filename = "variants.txt";
    int lastID = checkString(index, name, &filename, "Add");
    std::ofstream f1;
    f1.open("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/variants.txt", std::ios::app);
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
    std::ifstream file("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/" + filename);
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

    file_out.open ("/Users/elinakarapetan/Desktop/DataBaseLab1/DataBases/" + databases[index] + "/" + filename,std::ios::trunc | std::ios::binary);

    file_out.write(text.c_str(), text.size());
    file_out.clear();
}

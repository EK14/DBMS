#ifndef DBMS_H
#define DBMS_H


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sys/stat.h>
#include <filesystem>
#include <vector>
#include <QMessageBox>

class DBMS {
public:
    DBMS();
    std::vector<std::string> databases;
    void addVariant(int index, QString name, QWidget *parent);
    void addStudent(int index, QString name, QWidget *parent);
    void remove(int index, QString name, QWidget *parent, std::string s);
    void update();
    int databaseExist(std::string database);
    void populateDatabase(int index);
    void printTable(int index);

private:
    void generateID(int index);
    void testingTable(int index);
    void copyInitData(int index);
    int checkString(int index, QString& str, std::string* s, std::string type);
    void transferInformation();
    int findID();
};

#endif // DBMS_H

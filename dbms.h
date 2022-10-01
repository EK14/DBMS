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
    void correction(QWidget *parent, int id, QString nameToCorrect, QString correctedName, std::string s, int index);
    int databaseExist(std::string database);
    void populateDatabase(int index);
    int checkUp(QWidget *parent, int index, QString nameToCorrect, std::string s, std::string type);
    void print(int id, std::string type, int index, std::string& str);
    int checkID(QWidget *parent, int index, QString nameToCorrect, std::string filename, std::string type);

private:
    void generateID(int index);
    void testingTable(int index);
    void copyInitData(int index);
    int checkString(int index, QString& str, std::string* s, std::string type);
    void transferInformation();
    int findID();
};

#endif // DBMS_H

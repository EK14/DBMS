#ifndef CORRECT_H
#define CORRECT_H

#include <QDialog>
#include "dbms.h"

namespace Ui {
class Correct;
}

class Correct : public QDialog
{
    Q_OBJECT

public:
    explicit Correct(QWidget *parent,  DBMS *dbms, int index, std::string& str);
    ~Correct();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Correct *ui;
    DBMS *dbms;
    QWidget *parent;
    QString nameToCorrect;
    QString correctedName;
    int index;
    bool canBeCorrected;
    std::string type;
    int id;
};

#endif // CORRECT_H

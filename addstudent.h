#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>
#include "dbms.h"

namespace Ui {
class ADDSTUDENT;
}

class ADDSTUDENT : public QDialog
{
    Q_OBJECT

public:
    explicit ADDSTUDENT(QWidget *parent, DBMS *dbms, QString database, int index);
    ~ADDSTUDENT();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ADDSTUDENT *ui;
    DBMS *dbms;
    QWidget *parent;
    QString database;
    int index;
};

#endif // ADDSTUDENT_H

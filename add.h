#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include "dbms.h"

namespace Ui {
class ADD;
}

class ADD : public QDialog
{
    Q_OBJECT

public:
    explicit ADD(QWidget *parent, DBMS *dbms, QString database, int index, std::string& str);
    ~ADD();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ADD *ui;
    DBMS *dbms;
    QWidget *parent;
    QString database;
    int index;
    std::string type;
};

#endif // ADD_H

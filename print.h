#ifndef PRINT_H
#define PRINT_H

#include <QDialog>
#include "dbms.h"

namespace Ui {
class Print;
}

class Print : public QDialog
{
    Q_OBJECT

public:
    explicit Print(QWidget *parent, int index, std::string type, DBMS *dbms, std::string text);
    ~Print();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Print *ui;
    QWidget *parent;
    int index;
    std::string type;
    DBMS *dbms;
    std::string text;
};

#endif // PRINT_H

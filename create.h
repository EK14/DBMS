#ifndef CREATE_H
#define CREATE_H

#include <QDialog>
#include "dbms.h"

namespace Ui {
class Create;
}

class Create : public QDialog
{
    Q_OBJECT

public:
    explicit Create(QWidget *parent, DBMS *dbms);
    ~Create();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Create *ui;
    DBMS *dbms;
    QWidget *parent;
};

#endif // CREATE_H

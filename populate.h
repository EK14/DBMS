#ifndef POPULATE_H
#define POPULATE_H

#include <QDialog>
#include "dbms.h"

namespace Ui {
class Populate;
}

class Populate : public QDialog
{
    Q_OBJECT

public:
    explicit Populate(QWidget *parent, DBMS *dbms);
    ~Populate();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Populate *ui;
    DBMS *dbms;
    QWidget *parent;
};

#endif // POPULATE_H

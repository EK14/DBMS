#ifndef ADDVARIANT_H
#define ADDVARIANT_H

#include <QDialog>
#include "dbms.h"

namespace Ui {
class ADDVARIANT;
}

class ADDVARIANT : public QDialog
{
    Q_OBJECT

public:
    explicit ADDVARIANT(QWidget *parent, DBMS *dbms, QString database, int index);
    ~ADDVARIANT();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ADDVARIANT *ui;
    DBMS *dbms;
    QWidget *parent;
    QString database;
    int index;
};

#endif // ADDVARIANT_H

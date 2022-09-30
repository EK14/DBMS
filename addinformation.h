#ifndef ADDINFORMATION_H
#define ADDINFORMATION_H

#include <QDialog>
#include "dbms.h"
#include "addstudent.h"
#include "addvariant.h"
#include <QMessageBox>

namespace Ui {
class AddInformation;
}

class AddInformation : public QDialog
{
    Q_OBJECT

public:
    explicit AddInformation(QWidget *parent, DBMS *dbms);
    ~AddInformation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AddInformation *ui;
    DBMS *dbms;
    QWidget *parent;
    QString name;
    ADDSTUDENT *windowAddStudent;
    ADDVARIANT *windowAddVariant;
    int index;
};

#endif // ADDINFORMATION_H

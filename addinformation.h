#ifndef ADDINFORMATION_H
#define ADDINFORMATION_H

#include <QDialog>
#include "dbms.h"
#include "add.h"
#include "correct.h"
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

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::AddInformation *ui;
    DBMS *dbms;
    QWidget *parent;
    QString name;
    ADD *windowAdd;
    Correct *windowCorrection;
    int index;
};

#endif // ADDINFORMATION_H

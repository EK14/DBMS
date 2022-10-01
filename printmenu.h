#ifndef PRINTMENU_H
#define PRINTMENU_H

#include <QDialog>
#include "dbms.h"
#include "print.h"

namespace Ui {
class PrintMenu;
}

class PrintMenu : public QDialog
{
    Q_OBJECT

public:
    explicit PrintMenu(QWidget *parent, DBMS *dbms);
    ~PrintMenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::PrintMenu *ui;
    QString idStudent;
    QString idVariant;
    DBMS *dbms;
    QWidget *parent;
    int index;
    QString name;
    Print *windowPrint;
    std::string text;
};

#endif // PRINTMENU_H

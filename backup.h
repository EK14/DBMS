#ifndef BACKUP_H
#define BACKUP_H

#include <QDialog>
#include "dbms.h"

namespace Ui {
class BackUp;
}

class BackUp : public QDialog
{
    Q_OBJECT

public:
    explicit BackUp(QWidget *parent, DBMS *dbms);
    ~BackUp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::BackUp *ui;
    DBMS *dbms;
    QWidget *parent;
};

#endif // BACKUP_H

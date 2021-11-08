#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_btn_baglan_clicked();

    void on_btn_kayitekle_clicked();

    void on_btn_kayitlistele_clicked();

private:
    Ui::Dialog *ui;
    QSqlQueryModel *model;
    QSqlDatabase sqlitedb=QSqlDatabase::addDatabase("QSQLITE");
};

#endif // DIALOG_H

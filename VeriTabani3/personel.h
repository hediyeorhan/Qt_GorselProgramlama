#ifndef PERSONEL_H
#define PERSONEL_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>

class personel:public QDialog
{
    Q_OBJECT;
public:
    explicit personel(QSqlDatabase, QWidget *parent=nullptr);
    personel();
    void listele();
private:
    Ui::personel *ui;
    QSqlQueryModel *model;
    QSqlQuery *sorgu;

};

#endif // PERSONEL_H

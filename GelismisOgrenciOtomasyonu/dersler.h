#ifndef DERSLER_H
#define DERSLER_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDebug>
#include <QVariant>

namespace Ui {
class dersler;
}

class dersler : public QMainWindow
{
    Q_OBJECT

public:
    explicit dersler(QSqlDatabase, QWidget *parent = 0);
    ~dersler();
    void listele();
    int deger;
    void listelesecili();

private slots:
    void on_pushButton_derskayit_clicked();

    void on_pushButton_dersguncelle_clicked();

    void on_pushButton_derssil_clicked();

    void on_tableView_tumdersler_clicked(const QModelIndex &index);

private:
    Ui::dersler *ui;
    QSqlQueryModel *model, *model2, *qry;
    QSqlQuery *sorgu;
};

#endif // DERSLER_H

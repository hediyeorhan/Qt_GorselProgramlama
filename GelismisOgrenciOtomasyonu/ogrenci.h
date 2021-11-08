#ifndef OGRENCI_H
#define OGRENCI_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class ogrenci;
}

class ogrenci : public QMainWindow
{
    Q_OBJECT

public:
    explicit ogrenci(QSqlDatabase, QWidget *parent=0);
    ~ogrenci();
    void listele();

private slots:
    void on_btn_yenikayit_clicked();

    void on_btn_guncelle_clicked();

    void on_btn_sil_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::ogrenci *ui;
    QSqlQueryModel *model;
    QSqlQuery *sorgu;
};

#endif // OGRENCI_H

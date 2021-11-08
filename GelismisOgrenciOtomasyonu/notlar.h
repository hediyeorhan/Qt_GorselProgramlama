#ifndef NOTLAR_H
#define NOTLAR_H

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
class notlar;
}

class notlar : public QMainWindow
{
    Q_OBJECT

public:
    explicit notlar(QSqlDatabase, QWidget *parent = 0);
    ~notlar();
    void listele();

private slots:
    void on_tableView_tumogrenciler_clicked(const QModelIndex &index);

    void on_tableView_tumdersler_clicked(const QModelIndex &index);

    void on_tableView_tum_clicked(const QModelIndex &index);

    void on_pushButton_derskayit_clicked();

private:
    Ui::notlar *ui;
    QSqlQueryModel *model, *model2, *model3;
    QSqlQuery *sorgu;
};

#endif // NOTLAR_H

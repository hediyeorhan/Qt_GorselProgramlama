#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlDriver>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void veritabaninaekle();
    void tableViewGoruntule();
private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    QSqlQuery *sorgu;
    QSqlDatabase sqlitedb = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQueryModel *model;
    QSqlQueryModel *model2;
};

#endif // MAINWINDOW_H

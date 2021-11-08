#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.setDatabaseName("C:/Users/ORHAN/Desktop/GorselProgramlama/DB Browser for SQLite/sirket.db");
    if(!db.open())
        ui->statusBar->showMessage("Veri tabanına bağlanılamadı");
    else
        ui->statusBar->showMessage("Veri tabanına bağlanıldı");

    model = new QSqlTableModel();
    model->setTable("departman");
    ui->tableView->setModel(model);
    model->select();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString indis=model->index(index.row(), 0).data().toString();
    int dep_id=indis.toInt();

    QSqlQuery sorgu;
    sorgu.prepare("Select * from personel WHERE departman_id=?");
    sorgu.addBindValue(dep_id);
    sorgu.exec();
    model2 =new QSqlQueryModel();
    model2->setQuery(sorgu);
    ui->tableView_2->setModel(model2);

}

void MainWindow::on_pushButton_clicked()
{
    personel *per = new personel(db);
    per->show();
}

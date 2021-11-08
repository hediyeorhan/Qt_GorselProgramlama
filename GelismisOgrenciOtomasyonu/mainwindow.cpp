#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ogrenci.h"
#include "dersler.h"
#include "notlar.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.setDatabaseName("C:/Users/ORHAN/Desktop/GorselProgramlama/18010011087/otomasyon.db");
    if(!db.open())
        ui->statusBar->showMessage("Veri tabanına bağlanılamadı");
    else
        ui->statusBar->showMessage("Veri tabanına bağlanıldı");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_ogrislem_clicked()
{
    ogr = new ogrenci(db);
    ogr->show();
}

void MainWindow::on_btn_dersislem_clicked()
{
    ders = new dersler(db);
    ders->show();
}

void MainWindow::on_btn_notislem_clicked()
{
    nott = new notlar(db);
    nott->show();
}

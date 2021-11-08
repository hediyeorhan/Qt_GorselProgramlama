#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::information(this, "ERROR", "Lütfen bir mesaj giriniz !", "Tamam");
        ui->lineEdit->setFocus();
    }
    else
    {
        QMessageBox::information(this, "MESAJINIZ", ui->lineEdit->text());
    }
}

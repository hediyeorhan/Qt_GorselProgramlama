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
    QString cevap = "Yapılan Seçim \n --------------\n ";
    if(ui->radioButton->isChecked())
        cevap += "\n" + ui->radioButton->text();
    else if(ui->radioButton_2->isChecked())
        cevap += "\n" + ui->radioButton_2->text();

    ui->plainTextEdit->setPlainText(cevap);
}

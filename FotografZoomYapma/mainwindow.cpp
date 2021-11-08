#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->scrollArea);
    // butonlara icon atadık.
    ui->actionA->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionUzakla_t_r->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowDown));
    ui->actionYak_nla_t_r->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowUp));
    m_lblResim = new QLabel(this);
    ui->scrollArea->setWidget(m_lblResim);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionA_triggered()
{
    m_path = QFileDialog::getOpenFileName(this, "Dosya Ac", QString(), "All Files(*.*);;JPG(*.jpg);;PNG(*.png)");
    if(m_path.isEmpty())
        return;
    if(!m_resim.load(m_path))
    {
        QMessageBox::critical(this, "HATA", "Dosya Açılamadı");
    }
    m_lblResim->setPixmap(m_resim);
}

void MainWindow::on_actionYak_nla_t_r_triggered()
{
    int w = m_lblResim->width();
    int h = m_lblResim->height();

    w += 10;
    h += 10;

    m_lblResim->resize(w, h);
    m_lblResim->setPixmap(m_resim.scaled(w, h));
}

void MainWindow::on_actionUzakla_t_r_triggered()
{
    int w = m_lblResim->width();
    int h = m_lblResim->height();

    w -= 10;
    h -= 10;

    m_lblResim->resize(w, h);
    m_lblResim->setPixmap(m_resim.scaled(w, h));
}

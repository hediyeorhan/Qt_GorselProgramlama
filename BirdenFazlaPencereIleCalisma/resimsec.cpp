#include "resimsec.h"
#include "ui_resimsec.h"

ResimSec::ResimSec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResimSec)
{
    ui->setupUi(this);
}

ResimSec::~ResimSec()
{
    delete ui;
}

void ResimSec::on_buttonBox_accepted()
{
    selected = ui->listWidget->currentItem()->text();

    accept();

}

void ResimSec::on_buttonBox_rejected()
{
    reject();
}

void ResimSec::init()
{
    QDir root = QDir(":/file");
    QFileInfoList list = root.entryInfoList();
    foreach(QFileInfo fi, list)
    {
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        item->setText(fi.absoluteFilePath());
        item->setIcon(QIcon(fi.absoluteFilePath()));
        ui->listWidget->addItem(item);

    }
}

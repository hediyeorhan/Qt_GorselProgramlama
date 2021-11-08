#include "dialog.h"
#include "ui_dialog.h"
#include "Qt"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::itemDoubleClicked(QListWidgetItem *item)
{
    QString url = item->data(Qt::UserRole).toString();
    QDesktopServices::openUrl(QUrl(url));
}

void Dialog::init()
{
    while(ui->toolBox->count()>0)
    {
        ui->toolBox->removeItem(0);
    }
    addCategory("Eğitim");
    addCategory("Sosyal Medya");
    addCategory("Arama Motorları");

    addEducation();
    addSocial();
    addSearch();
}

void Dialog::addCategory(QString name)
{
    QListWidget *list = new QListWidget(this);
    ui->toolBox->addItem(list, name);
    connect(list,&QListWidget::itemDoubleClicked,this,&Dialog::itemDoubleClicked);
}

void Dialog::addLink(QListWidget *list, QString name, QString url)
{
    QListWidgetItem *item = new QListWidgetItem(name); //hocada (this, name) olarak yazdık.
    item->setData(Qt::UserRole, url); // hocada ItemDataRole::UserRole olarak
    list->addItem(item);
}

void Dialog::addEducation()
{
    QListWidget *list = qobject_cast<QListWidget*>(ui->toolBox->widget(0));
    if(!list)
    {
        qWarning() << "Eğitim Alanı ile ilgili linklerin listesi oluşturulmadı.";
        return;
    }
    addLink(list, "NEÜ", "https://www.erbakan.edu.tr");
    addLink(list, "KTUN", "https://www.ktun.edu.tr");

}

void Dialog::addSocial()
{
    QListWidget *list = qobject_cast<QListWidget*>(ui->toolBox->widget(1));
    if(!list)
    {
        qWarning() << "Sosyal Medya Alanı ile ilgili linklerin listesi oluşturulmadı.";
        return;
    }
    addLink(list, "Twitter", "https://twitter.com/hediyeorhaan");
    addLink(list, "Youtube", "https://www.youtube.com");
}

void Dialog::addSearch()
{
    QListWidget *list = qobject_cast<QListWidget*>(ui->toolBox->widget(2));
    if(!list)
    {
        qWarning() << "Arama Motoru Alanı ile ilgili linklerin listesi oluşturulmadı.";
        return;
    }
    addLink(list, "Google", "https://www.google.com");
    addLink(list, "Yahoo", "https://www.yahoo.com");
}

#include "dialog.h"
#include "ui_dialog.h"
#include "QString"
#include "QDebug"
#include "QObjectList"
#include "QMessageBox"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->gbox_vites->setVisible(false);
    ui->gbox_yakit->setVisible(false);
    ui->gbox_yas->setVisible(false);
    ui->secenek_btn->setVisible(false);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btn_temizle_clicked()
{
    QList<QString> mylist;
    mylist <<"Kitap"<<"Defter"<<"Kalem";

    foreach(QString mystr, mylist)
    {
        qDebug() << mystr;
    }
}

void Dialog::on_btn_listele_clicked()
{
    QString secimler = "SEÇİMLER\n------------------\n";
    QObjectList boxes = this->children();

    foreach(QObject* obj, boxes)
    {
        if(obj->inherits("QCheckBox"))
        {
            QCheckBox* box_ptr = qobject_cast<QCheckBox*>(obj);
            if(box_ptr->isChecked()) secimler += box_ptr->text() + "\r\n";
        }
    }

    ui->secim_textedit->appendPlainText(secimler);
    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->checkBox_3->isChecked())
    {
        ui->gbox_vites->setVisible(true);
        ui->gbox_yakit->setVisible(true);
        ui->gbox_yas->setVisible(true);
    }
    else if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked())
    {
        ui->gbox_vites->setVisible(true);
        ui->gbox_yakit->setVisible(true);
    }
    else if(ui->checkBox_2->isChecked() && ui->checkBox_3->isChecked())
    {
        ui->gbox_yakit->setVisible(true);
        ui->gbox_yas->setVisible(true);
    }
    else if(ui->checkBox->isChecked() && ui->checkBox_3->isChecked())
    {
        ui->gbox_vites->setVisible(true);
        ui->gbox_yas->setVisible(true);
    }
    else if(ui->checkBox->isChecked())
    {
        ui->gbox_vites->setVisible(true);

    }
    else if( ui->checkBox_3->isChecked())
    {
        ui->gbox_yas->setVisible(true);
    }
    else if(ui->checkBox_2->isChecked())
    {
        ui->gbox_yakit->setVisible(true);
    }

    ui->secenek_btn->setVisible(true);
}

void Dialog::on_secenek_btn_clicked()
{
    QString vites = secimAl(ui->gbox_vites);
    QString yakit = secimAl(ui->gbox_yakit);
    QString yas = secimAl(ui->gbox_yas);

    QString alt_secimler = "Vites : " + vites + "\r\n" + "Yakıt : " + yakit + "\r\n" + "Yaş : " + yas;
    QMessageBox::information(this, "SEÇİMLERİNİZ",alt_secimler);
}

QString Dialog::secimAl(QObject* obj)
{
    QString deger = "Hiçbiri";

    QList<QRadioButton*> lst = obj->findChildren<QRadioButton*>(QString(), Qt::FindDirectChildrenOnly);

    foreach(QRadioButton* rb, lst)
    {
        if(rb->isChecked())
        {
            deger = rb->text();
            break;
        }
    }
    return deger;
}

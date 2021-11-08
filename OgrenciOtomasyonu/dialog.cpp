#include "dialog.h"
#include "ui_dialog.h"
#include "QMessageBox"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_rd_lisans_clicked()
{
    ui->grp_sinif->setEnabled(true);
    ui->grp_zorunluderslerlisans->setEnabled(true);
    ui->grp_durum->setEnabled(false);
    ui->grp_zorunluderslerlisansustu->setEnabled(false);
}

void Dialog::on_rd_lisansustu_clicked()
{
    ui->grp_durum->setEnabled(true);
    ui->grp_zorunluderslerlisansustu->setEnabled(true);
    ui->grp_sinif->setEnabled(false);
    ui->grp_zorunluderslerlisans->setEnabled(false);
}

void Dialog::on_btn_bilgileriyazdir_clicked()
{
    QString ad, soyad, bolum, seviye;
    ad = ui->ln_ad->text();
    soyad = ui->ln_soyad->text();
    bolum = ui->ln_bolum->text();


    // 1.Yöntem
   /* QObjectList obj = this->children();
    foreach(QObject* o, obj)
    {
        if(o->inherits("QRadioButton"))
        {
            QRadioButton* rd = qobject_cast<QRadioButton*>(o);
            if(rd->isChecked())
            {
                seviye = rd->text(); // group box içinde olduğu için çnce group box içine erişmemiz lazım. !! bu yüzden alamadık.
            }
        }
    }

    QMessageBox::information(this, "ÖĞRENCİ BİLGİLERİ", "Ad : "+ad+"\n"+"Soyad : "+soyad+"\n"+"Bölüm : "+bolum+"\n"+"Seviye : "+seviye);*/

    // 2.Yöntem
   /* QObject* obj = ui->grp_egitim;
    QList<QRadioButton*> liste = obj->findChildren<QRadioButton*>(QString(), Qt::FindDirectChildrenOnly);
    foreach(QRadioButton* rd, liste)
    {
        if(rd->isChecked())
        {
            seviye = rd->text();
        }
    }
    QMessageBox::information(this, "ÖĞRENCİ BİLGİLERİ", "Ad : "+ad+"\n"+"Soyad : "+soyad+"\n"+"Bölüm : "+bolum+"\n"+"Seviye : "+seviye);

*/

    // 3.Yöntem

    if(ui->rd_lisans->isChecked())
    {
        seviye = ui->rd_lisans->text();
    }
    else if(ui->rd_lisansustu->isChecked())
    {
        seviye = ui->rd_lisansustu->text();
    }

    QMessageBox::information(this, "ÖĞRENCİ BİLGİLERİ", "Ad : "+ad+"\n"+"Soyad : "+soyad+"\n"+"Bölüm : "+bolum+"\n"+"Seviye : "+seviye);
}


void Dialog::on_btn_mezuniyetsorgula_clicked()
{
    bool mezuniyet_durum;
    mezuniyet_durum = MezuniyetSorgula();

    if(ui->rd_lisans->isChecked())
    {
        if(mezuniyet_durum)
            QMessageBox::information(this, "MEZUNİYET DURUMU", "Öğrenci lisanstan mezun olabilir.", "Tamam");
        else
            QMessageBox::information(this, "MEZUNİYET DURUMU", "Öğrenci lisanstan mezun olamaz.", "Tamam");
    }
    else if(ui->rd_lisansustu->isChecked())
    {
        if(mezuniyet_durum)
            QMessageBox::information(this, "MEZUNİYET DURUMU", "Öğrenci lisansüstünden mezun olabilir.", "Tamam");

        else
            QMessageBox::information(this, "MEZUNİYET DURUMU", "Öğrenci lisansüstünden mezun olamaz.", "Tamam");
    }


}

void Dialog::on_btn_ogrencidurumyazdir_clicked()
{
    QString ad, soyad, bolum, seviye;
    bool mezuniyet_durum;

    ad = ui->ln_ad->text();
    soyad = ui->ln_soyad->text();
    bolum = ui->ln_bolum->text();

    if(ui->rd_lisans->isChecked())
    {
        seviye = ui->rd_lisans->text();
    }
    else if(ui->rd_lisansustu->isChecked())
    {
        seviye = ui->rd_lisansustu->text();
    }

    mezuniyet_durum = MezuniyetSorgula();
    if(seviye == "Lisans")
    {
        if(mezuniyet_durum)
            QMessageBox::information(this, "ÖĞRENCİ BİLGİLERİ", "Öğrenci lisans seviyesinde mezun durumunda bir öğrencidir.", "Tamam");

        else
            QMessageBox::information(this, "ÖĞRENCİ BİLGİLERİ", "Öğrenci lisans seviyesinde bir öğrencidir.", "Tamam");
    }
    else if(seviye == "Lisansüstü")
    {
        if(mezuniyet_durum)
            QMessageBox::information(this, "ÖĞRENCİ BİLGİLERİ", "Öğrenci lisansüstü seviyesinde mezun durumunda bir öğrencidir.", "Tamam");

        else
            QMessageBox::information(this, "ÖĞRENCİ BİLGİLERİ", "Öğrenci lisansüstü seviyesinde bir öğrencidir.", "Tamam");
    }

}

bool Dialog::MezuniyetSorgula()
{
    if(ui->rd_lisans->isChecked())
    {
        if(ui->rd_sinif4->isChecked() && ui->cb_aiit->isChecked() && ui->cb_isg->isChecked() && ui->cb_turkdili->isChecked())
            return true;
        else
            return false;
    }
    else if(ui->rd_lisansustu->isChecked())
    {
        if(ui->rd_tez->isChecked() && ui->cb_secmeli->isChecked() && ui->cb_seminerler->isChecked() && ui->cb_tez->isChecked())
            return true;
        else
            return false;
    }
}

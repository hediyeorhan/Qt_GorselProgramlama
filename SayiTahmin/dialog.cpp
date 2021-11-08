#include "dialog.h"
#include "ui_dialog.h"

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

int sayi;
QString birinci_aralik, ikinci_aralik;
int b_aralik, i_aralik;

void Dialog::on_btn_uret_clicked()
{
    birinci_aralik = ui->aralik1->text();
    ikinci_aralik = ui->aralik2->text();
      // sayiları aldık ve int degere cevirdik.
    b_aralik = birinci_aralik.toInt();
    i_aralik = ikinci_aralik.toInt();

    sayi = rand()%(i_aralik - b_aralik)+b_aralik; // araliktaki sayımızı rastgele olusturduk.
    qDebug() <<sayi;
}

int ds=0; // deneme sayisi
void Dialog::on_btn_tahmin_clicked()
{
    ui->btn_tahmin->setAutoRepeat(true);
    int tahmin = rand()%(i_aralik - b_aralik)+ b_aralik; // rastgele tahminde bulunduk.
    ds++;

    QString string = QString::number(ds);

    if(sayi!=tahmin)
        ui->text_sonuc->setText("Doğru tahmin edilmedi. Deneme sayısı : " + string);
    else
    {
         ui->text_sonuc->setText("TEBRİKLER! Doğru tahmin edildi. Deneme sayısı : " + string);
         ui->btn_tahmin->setVisible(false); // doğru tahmin olunca buton kayboluyor. visible - görünüm buton görünümü false yani
    }
}

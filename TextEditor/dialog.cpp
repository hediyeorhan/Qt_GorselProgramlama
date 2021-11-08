#include "dialog.h"
#include "ui_dialog.h"
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include "QPushButton"
#include "QIcon"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //QPushButton *btnAccept = new QPushButton(QIcon(":dialog/kabul.png", "Accept", this));  // --> diğer yol
    QPushButton *btnReject = new QPushButton("Reject", this);
    btnReject->setIcon(QIcon(":dialog/red.png"));
    QPushButton *btnAccept = new QPushButton("Accept", this);
    btnAccept->setIcon(QIcon(":dialog/kabul.png"));  // simge atadık

    ui->buttonBox->addButton(btnAccept, QDialogButtonBox::AcceptRole); //  QDialogButtonBox::ButtonRole::AcceptRole -- hocanın versiyonunda böyle
    ui->buttonBox->addButton(btnReject, QDialogButtonBox::RejectRole);

    /*
    connect(btnAccept, &QPushButton::released, this, kaydet());
    connect(btnReject, &QPushButton::clicked, reject());    // -- Burada hata var
    */
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btn_yeni_clicked()
{
    ui->plainTextEdit->clear();
}

void Dialog::on_btn_oku_clicked()
{
    oku();
}

void Dialog::on_btn_kaydet_clicked()
{
    kaydet();
}

void Dialog::kaydet()
{
    QFile my_file("metin.txt");
    if(!my_file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "UYARI", my_file.errorString());
        return;
    }
    QTextStream stream(&my_file);
    stream << ui->plainTextEdit->toPlainText(); // kendimiz yazıyı giriyoruz.
    my_file.close();

    mesaj_saved = true;

    QMessageBox::information(this, "BİLGİ", "Metin başarıyla kaydedildi.", "Tamam");
}

void Dialog::oku()
{
    QFile file("metin.txt");
    if(!file.exists())
        return;
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, "UYARI", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll()); // plain text içine yazıyı alıyoruz. -- yazıyı okuyoruz. --  readAll, readLine gibi çeşitleri var.
    file.close();

}

void Dialog::closeEvent(QCloseEvent *event)
{
    if(!mesaj_saved)
    {
        QMessageBox::StandardButton btn = QMessageBox::question(this, "KAYIT", "Metin Kutusunun içeriği değişmiştir kaydetmek ister misiniz ?");
        if(btn==QMessageBox::Yes)
            kaydet();
    }

    event->accept(); // eventi kabul edip kapanmasını sağlıyoruz.
}

void Dialog::on_plainTextEdit_textChanged()
{
    mesaj_saved = false;
}

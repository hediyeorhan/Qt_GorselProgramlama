#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnStart_clicked()
{
    quint16 port = static_cast<quint16>(ui->sbPort->value());
    server.setMessage(ui->txtMessage->text() + "\r\n");

    if(!server.listen(QHostAddress::Any, port()))
    {
        QMessageBox::critical(this, "ERROR", server.errorString());
    }

    ui->lblStatus->setText("Sunucu dinliyor");

    enableButtons();
}

void Dialog::on_btnStop_clicked()
{
    server.close();
    ui->lblStatus->setText("Sunucu kapandı");

    enableButtons();
}

void Dialog::next()
{
    int i= ui->stackedWidget->currentIndex();

    i++;
    if(i>=ui->stackedWidget->count()) i=ui->stackedWidget->count();

    ui->stackedWidget->setCurrentIndex(i);
    enableButtons();
}

void Dialog::back()
{
    int i= ui->stackedWidget->currentIndex();

    i--;
    if(i<0) i=0;
    ui->stackedWidget->setCurrentIndex(i);
    enableButtons();
}

void Dialog::changed()
{
    ui->lblStatus->setText(QString("Su anm %0 kullanıcı baglıdır.").arg(server.count()));

}

void Dialog::init()
{
    btnBack=new QPushButton("Geri", this);
    btnNext=new QPushButton("İleri", this);

    // hangi nesne hangi sinyali ürettiğinde , hangi nesne sinyali nasıl kabul edecek ?

    ui->buttonBox->addButton(btnBack, QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnNext, QDialogButtonBox::ButtonRole::ActionRole);

    connect(btnBack, &QPushButton::clicked(), this, &Dialog::back);
    connect(btnNext, &QPushButton::clicked(), this, &Dialog::next);
    connect(&server, &Server::changed, this, &Dialog::changed);

    enableButtons();
}

void Dialog::enableButtons()
{
    ui->btnStart->setEnabled(!server.isListening());
    ui->btnStop->setEnabled(server.isListening());

    if(ui->stackedWidget->count()<=1)
    {
        btnNext->setEnabled(false);
        btnBack->setEnabled(false);
        return;
    }

    if(ui->stackedWidget->currentIndex()==0)
    {
        btnNext->setEnabled(true);
        btnBack->setEnabled(false);
        return;
    }

    if(ui->stackedWidget->currentIndex() >= ui->stackedWidget->count()-1)
    {
        btnNext->setEnabled(false);
        btnBack->setEnabled(true);
        return;
    }
}



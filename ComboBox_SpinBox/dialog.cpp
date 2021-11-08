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

void Dialog::on_btn_uygula_clicked()
{
    ui->bicimlendirilmislabel->setEnabled(true);
    QString yazitipi, renk, yazi;
    yazitipi = ui->fontComboBox->currentText();
    int size = ui->spinBox_fontsize->value();
    renk = ui->comboBox_renk->currentText();
    yazi = ui->ln_yaz->text();
    ui->bicimlendirilmislabel->setText(yazi);

    // Stil Ayarlamaları

    QFont my_font(yazitipi, size);

    if(ui->checkBox_bold->isChecked())
    {
        my_font.setBold(true);
    }
    if(ui->checkBox_italic->isChecked()) // ikisi de seçilince uygulansın diye if if dedik.
    {
        my_font.setItalic(true);
    }
    // Renk için:

    QPalette my_color;

    my_color.setColor(QPalette::WindowText, ui->comboBox_renk->currentText());

    ui->bicimlendirilmislabel->setFont(my_font);
    ui->bicimlendirilmislabel->setPalette(my_color);
}

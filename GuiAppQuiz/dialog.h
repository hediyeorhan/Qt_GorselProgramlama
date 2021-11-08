#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_btn_sayiuret_clicked();

    void on_btn_yarismayibaslat_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_radioButton_tek_clicked();

    void on_radioButton_iki_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

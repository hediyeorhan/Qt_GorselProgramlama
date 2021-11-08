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
    void on_rd_lisans_clicked();

    void on_rd_lisansustu_clicked();

    void on_btn_bilgileriyazdir_clicked();

    void on_btn_mezuniyetsorgula_clicked();

    void on_btn_ogrencidurumyazdir_clicked();

    bool MezuniyetSorgula();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

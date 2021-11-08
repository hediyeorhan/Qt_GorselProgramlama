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
    void on_cmbRenk_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();



    void on_btn_demirbas_clicked();



    void on_btn_sil_clicked();

    void on_btn_temizle_clicked();

    void on_btn_tamam_clicked();

    void on_btn_iptal_clicked();

private:
    Ui::Dialog *ui;
    void yukle();
    void baslarken();
    void yukle_demirbas();
    void kaydet();
};

#endif // DIALOG_H

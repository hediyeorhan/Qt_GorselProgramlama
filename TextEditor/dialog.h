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
    void on_btn_yeni_clicked();

    void on_btn_oku_clicked();

    void on_btn_kaydet_clicked();

    void on_plainTextEdit_textChanged();

private:
    Ui::Dialog *ui;

    bool mesaj_saved;

    void kaydet();

    void oku();

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // DIALOG_H

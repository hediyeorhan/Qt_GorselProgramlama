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
    void on_btn_temizle_clicked();

    void on_btn_listele_clicked();

    void on_secenek_btn_clicked();

    QString secimAl(QObject* obj);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

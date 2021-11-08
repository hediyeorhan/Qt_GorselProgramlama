#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
using std::cout;
using std::endl;

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
    void on_btnCheckable_clicked();

    void on_btnIsCheck_clicked();

    void on_btnAutoRepeat_clicked();

    void on_btnAutoRepeatDegistir_clicked();

    void on_btnDefault_clicked();

    void on_btnDefaultDegistir_clicked();

    void on_btnCikis_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

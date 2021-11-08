#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <dialog2.h>
#include <resimsec.h>

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
    void on_btn_parentshow_clicked();

    void on_btn_noparentshow_clicked();

    void on_btn_parentexec_clicked();

    void on_btn_noparentexec_clicked();

    void on_btn_resimsec_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

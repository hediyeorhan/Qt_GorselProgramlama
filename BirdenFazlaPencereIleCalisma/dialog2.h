#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();

    
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog2 *ui;
};

#endif // DIALOG2_H

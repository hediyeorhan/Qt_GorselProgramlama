#ifndef RESIMSEC_H
#define RESIMSEC_H

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QListWidgetItem>

namespace Ui {
class ResimSec;
}

class ResimSec : public QDialog
{
    Q_OBJECT
    
public:
    explicit ResimSec(QWidget *parent = 0);
    ~ResimSec();
    QString selected;
    
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ResimSec *ui;
    void init();
};

#endif // RESIMSEC_H

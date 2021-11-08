#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QUrl>
#include <QDebug>
#include <QDesktopServices>

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
    void itemDoubleClicked(QListWidgetItem *item);
    
private:
    Ui::Dialog *ui;
    void init();
    void addCategory(QString name);
    void addLink(QListWidget *list, QString name, QString url);
    void addEducation();
    void addSocial();
    void addSearch();
};

#endif // DIALOG_H

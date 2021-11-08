#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDir>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QDebug>

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
    void on_treeView_activated(const QModelIndex &index);

private:
    Ui::Dialog *ui;
    QFileSystemModel dirModel; // treeview modelde kullanmak için tanımladık.
    QFileSystemModel fileModel;

    void init();
};

#endif // DIALOG_H

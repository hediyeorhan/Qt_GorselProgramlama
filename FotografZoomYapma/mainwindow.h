#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QStyle>
#include <QLabel>
#include <QFileDialog>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionA_triggered();

    void on_actionYak_nla_t_r_triggered();

    void on_actionUzakla_t_r_triggered();

private:
    Ui::MainWindow *ui;
    QLabel *m_lblResim;
    QString m_path;
    QPixmap m_resim; // resim tutmak için
};

#endif // MAINWINDOW_H

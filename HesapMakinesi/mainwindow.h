#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_toplama_clicked();

    void on_cikarma_clicked();

    void on_carpma_clicked();

    void on_bolme_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

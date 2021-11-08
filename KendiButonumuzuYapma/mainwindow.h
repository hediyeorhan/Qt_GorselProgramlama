#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMouseEvent>
#include <QMainWindow>
#include <yenibuton.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent*);  // Qt de mevcut tekrar yazıyoruz. Bu yüzden italic
public slots:
    void degistir();

private:
    Ui::MainWindow *ui;
    QList<yenibuton*> butonlar2;
    QList<yenibuton*> butonlar;
};

#endif // MAINWINDOW_H

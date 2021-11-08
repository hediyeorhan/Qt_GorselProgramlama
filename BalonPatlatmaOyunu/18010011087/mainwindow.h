#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsSceneMouseEvent>

// HEDİYE ORHAN - 18010011087


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void time_timeout();
    void yazdir();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

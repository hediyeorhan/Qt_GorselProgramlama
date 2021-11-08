#ifndef YENIBUTON_H
#define YENIBUTON_H

#include <QPushButton>

class yenibuton : public QPushButton
{
    Q_OBJECT;
public:
    explicit yenibuton(QWidget *parent = 0);
    bool tiklandimi;
    
signals:
    
public slots:
    void tikla();
    
};

#endif // YENIBUTON_H

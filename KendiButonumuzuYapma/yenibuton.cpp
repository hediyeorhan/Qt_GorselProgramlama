#include "yenibuton.h"

yenibuton::yenibuton(QWidget *parent):

    QPushButton(parent)
{
    tiklandimi = false;
    connect(this, SIGNAL(clicked()), this, SLOT(tikla())); // signal yerine &clicked da diyebiliriz.
}


void yenibuton::tikla()
{
    tiklandimi = !tiklandimi;
}

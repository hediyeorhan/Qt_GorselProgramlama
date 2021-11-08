#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ekran büyüdüğünde eşdeğer text yeri büyüsün
    this->setCentralWidget(ui->plainTextEdit);

    // en üst main bar
    // alt toolbar
    // en alt status bar
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    ui->plainTextEdit->clear();
    ui->statusBar->showMessage("New File");
}

void MainWindow::on_actionSave_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "Save file");
    QFile myfile(path);
    if(!myfile.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "ERROR", myfile.errorString());
        return;
    }
    QTextStream stream(&myfile);
    stream << ui->plainTextEdit->toPlainText();
    myfile.close();
    ui->statusBar->showMessage(path);
}

void MainWindow::on_actionOpen_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Open a file");
    QFile myfile(path);
    if(!myfile.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, "ERROR", myfile.errorString());
        return;
    }
    QTextStream stream(&myfile);
    ui->plainTextEdit->setPlainText(stream.readAll());
    myfile.close();
    ui->statusBar->showMessage(path);
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionSelect_All_triggered()
{
    ui->plainTextEdit->selectAll();
}

void MainWindow::on_actionSelect_None_triggered()
{ /*
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    int position = cursor.position();
    cursor.clearSelection();
    cursor.setPosition(0, QTextCursor::MoveMode::KeepAnchor);
    ui->plainTextEdit->setTextCursor(cursor);*/
}

void MainWindow::on_actionToolbar_Top_triggered()
{
    addToolBar(Qt::TopToolBarArea, ui->toolBar);
}

void MainWindow::on_actionToolbar_Bottom_triggered()
{
    addToolBar(Qt::BottomToolBarArea, ui->toolBar);  // Qt::ToolBarArea::BottomToolBarArea
}

void MainWindow::on_actionToolbar_Left_triggered()
{
    addToolBar(Qt::LeftToolBarArea, ui->toolBar); // Qt::ToolBarArea::LeftToolBarArea,
}

void MainWindow::on_actionToolbar_Right_triggered()
{
    addToolBar(Qt::RightToolBarArea, ui->toolBar);  // Qt::ToolBarArea::RightToolBarArea
}


void MainWindow::on_actionToolbar_Floatable_toggled(bool arg1)
{
    ui->toolBar->setFloatable(arg1); // seçiliyken ortaya falan gelebiliyor. true iken
}

void MainWindow::on_actionToolbar_Movable_toggled(bool arg1)
{
    ui->toolBar->setMovable(arg1); // false iken taşınamıyor. sağ sol hareket edemiyor. el ile buton ile çalışıyor hareket etme
}

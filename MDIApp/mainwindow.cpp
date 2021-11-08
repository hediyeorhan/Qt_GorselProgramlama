#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->mdiArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNext_triggered()
{
    ui->mdiArea->activateNextSubWindow(); // aktif pencereyi değiştirir.
}

void MainWindow::on_actionPrevious_triggered()
{
    ui->mdiArea->activatePreviousSubWindow();
}

void MainWindow::on_actionCascade_triggered()
{
    ui->mdiArea->cascadeSubWindows();  // ekrana sığdırır plaintextleri
}

void MainWindow::on_actionTile_triggered()
{
    ui->mdiArea->tileSubWindows(); // alt alta sıralar  cascade ile tam tersi aslında şekilleri
}

void MainWindow::on_actionCut_triggered()
{
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->paste();
}

void MainWindow::on_actionClose_triggered()
{
    ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_actionCloseAll_triggered()
{
    ui->mdiArea->closeAllSubWindows();
}

void MainWindow::on_actionSelectAll_triggered()
{
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->selectAll();
}

void MainWindow::on_actionNew_triggered()
{
    QMdiSubWindow *editor = newDocument(); // plain text oluşuyor uygulamamız içine.
    editor->setWindowTitle("New File");


}

void MainWindow::on_actionOpen_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Open a file"); // dosya penceresi açarak dosya seçmesini sağlıyoruz.
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, "ERROR", file.errorString());
        return;
    }
    QTextStream stream(&file);
    QMdiSubWindow *window = newDocument();
    window->setWindowTitle(path);

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    editor->setPlainText(stream.readAll());
    file.close();

}

void MainWindow::on_actionSave_triggered()
{
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QString path = window->windowTitle();
    QFile file(path);
    if(!file.exists()) // böyle bir dosya yoksa
    {
        on_actionSaveAs_triggered();
        return;
    }
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "ERROR", file.errorString());
        return;
    }

    QTextStream stream(&file);
    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    stream << editor->toPlainText();
    file.close();
    window->setWindowTitle(path);
    ui->statusBar->showMessage("Saved", 1000);

}

void MainWindow::on_actionSaveAs_triggered()
{
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QString path = QFileDialog::getSaveFileName(this, "Save File"); //Saveden farkı
    if(path.isEmpty()) return;


    QFile file(path);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "ERROR", file.errorString());
        return;
    }

    QTextStream stream(&file);
    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    stream << editor->toPlainText();
    file.close();
    window->setWindowTitle(path);
    ui->statusBar->showMessage("Saved", 1000);

}

QMdiSubWindow *MainWindow::newDocument()
{
    QMdiSubWindow *window = new QMdiSubWindow(this);
    QPlainTextEdit *editor = new QPlainTextEdit(window);

    window->setWidget(editor);
    window->setAttribute(Qt::WA_DeleteOnClose); // alt pencereyi kapattığımda delete yap.

    ui->mdiArea->addSubWindow(window);
    window->show();

    return window;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

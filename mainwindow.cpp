#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculer_clicked()
{
   QString val = this->ui->lineEdit->text();
   this->ui->lineEdit->clear();

}

void MainWindow::on_lineEdit_editingFinished()
{

}

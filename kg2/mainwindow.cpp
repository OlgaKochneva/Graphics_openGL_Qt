#include "mainwindow.h"
#include "ui_mainwindow.h"
//



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->slider_ref->setMinimum(0);
    ui->slider_ref->setMaximum(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}



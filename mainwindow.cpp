#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->sort_type->addItem("id",0);
ui->sort_type->addItem("value",1);
ui->sort_order->addItem("по возрастанию",0);
ui->sort_order->addItem("по убыванию",1);
}


MainWindow::~MainWindow()
{
    delete ui;
}


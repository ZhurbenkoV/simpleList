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
connect(ui->addButton,&QPushButton::clicked,this,&MainWindow::render);
connect(ui->deleteButton,&QPushButton::clicked,this,&MainWindow::render);
connect(ui->changeValueButton,&QPushButton::clicked,this,&MainWindow::render);
connect(ui->sort_type,&QComboBox::currentTextChanged,this,&MainWindow::render);
connect(ui->sort_order,&QComboBox::currentTextChanged,this,&MainWindow::render);
}

void MainWindow::render()
{
    ui->sorted_item_list->clear();
    ui->DataBase_list->clear();
}


MainWindow::~MainWindow()
{
    delete ui;
}


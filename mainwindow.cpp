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

void MainWindow::render(){
    currentItem=ui->sorted_item_list->currentRow();
    elementsListForRednder.clear();
    ui->sorted_item_list->clear();
    ui->DataBase_list->clear();
    SortingType config(ui->sort_type->currentIndex(),ui->sort_order->currentIndex());
    elementsListForRednder=dataBase.dataBaseElemetsSortedList(config);

    foreach(DataBaseItem str,this->elementsListForRednder){
        QListWidgetItem *newRenderItem=new QListWidgetItem;
        newRenderItem->setText(str.itemValue());
        newRenderItem->setData(Qt::UserRole,str.ItemId());
        ui->sorted_item_list->addItem(newRenderItem);
    }

    foreach(DataBaseItem str,dataBase.dataBaseElemetsList()){
        QListWidgetItem *newDataBaseItem=new QListWidgetItem;
        newDataBaseItem->setText(QString::number(str.ItemId())+"\t"+str.itemValue());
        newDataBaseItem->setData(Qt::UserRole,str.ItemId());
        ui->DataBase_list->addItem(newDataBaseItem);
    }
    ui->sorted_item_list->setCurrentRow(currentItem);
}


MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_addButton_clicked(){
    if(ui->lineEdit->text()!=nullptr){
        dataBase.addNewItem(ui->lineEdit->text());
    }
    ui->lineEdit->clear();
}

void MainWindow::on_changeValueButton_clicked(){
    int index=0;
    QListWidgetItem *currentItem = ui->sorted_item_list->currentItem();
    if(ui->sorted_item_list->currentItem()!=nullptr && ui->lineEdit->text()!=nullptr){
        // dataBase.dataBaseElemetsList()[ui->sorted_item_list->currentItem()->data(Qt::UserRole).toInt()].changeValue(ui->lineEdit->text());
        foreach(DataBaseItem str,dataBase.dataBaseElemetsList()){
            if(str.ItemId()==currentItem->data(Qt::UserRole).toInt()){
                break;
            }
            index++;
        }
    }
    dataBase.dataBaseElemetsList()[index].changeValue(ui->lineEdit->text());
    delete currentItem;
    ui->lineEdit->clear();

}

void MainWindow::on_deleteButton_clicked(){
    QListWidgetItem *currentItem = ui->sorted_item_list->currentItem();
    int currentIndex=0;
    if(ui->sorted_item_list->currentItem()!=nullptr){
        foreach(DataBaseItem str,dataBase.dataBaseElemetsList()){
            if(str.ItemId()==currentItem->data(Qt::UserRole).toInt()){
                break;
            }
            currentIndex++;
        }
        dataBase.dataBaseElemetsList().takeAt(currentIndex);
    }
    delete currentItem;
}

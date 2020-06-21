#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "databaseitem.h"
#include "sortingtype.h"
#include <QListWidgetItem>
#include <QString>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void render();

    void on_addButton_clicked();

    void on_changeValueButton_clicked();

private:
    Ui::MainWindow *ui;
QList<DataBaseItem> elementsListForRednder;
DataBase dataBase;
};
#endif // MAINWINDOW_H

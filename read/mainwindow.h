#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int r_id = 0, QWidget *parent = nullptr);
    ~MainWindow();
    void connectsql();
    int m_id;

private slots:
    void showpoints();
    void on_exit2_clicked();
    void showBookShelf();
    void showMystar();
    void on_search_botton_clicked();

    void on_changename_clicked();

    void on_passchange_clicked();

    void on_Del_clicked();

    void on_getpoint_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};
#endif // MAINWINDOW_H

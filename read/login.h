#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include <QPainter>
#include <QStyleOption>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void showMainWidget(); // 显示主界面
    void connectsql();
    int id;

private slots:
    void on_login_clicked();
    void on_exit_clicked();

signals:
    void sendLoginSuccess();

private:
    Ui::Login *ui;
    QSqlDatabase db;
};

#endif // LOGIN_H

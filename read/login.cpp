#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    connectsql();
    connect(ui->exit,&QPushButton::clicked,this,&Login::on_exit_clicked);
    connect(this, &Login::sendLoginSuccess, this, &Login::showMainWidget);
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_clicked()
{
    QString username = ui->id_number->text();
    QString password = ui->pass_number->text();
    QSqlQuery query(db);
    query.exec(QString("select * from reader where reader_id='%1' and readerpassword='%2'").arg(ui->id_number->text()).arg(ui->pass_number->text()));  //建立查询
    if(query.next())
    {
        id=query.value(0).toString().toInt();
        qDebug() <<id;
        emit sendLoginSuccess();
    }
    else {
        QMessageBox::information(this,"错误", "登录失败，用户名或密码错误！");
    }
}

void Login::on_exit_clicked()
{
    exit(0);
}

void Login::connectsql()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("read");
    db.setUserName("root");
    db.setPassword("Dskl930");
    db.open();
    bool ok=db.open();
    if(ok)
    {
        qDebug()<<"数据库连接成功！";
    }
    else
    {
        QMessageBox::information(this,"失败", "link failed");
        qDebug()<<"error open database because"<<db.lastError().text();
    }

}

void Login::showMainWidget()
{
    MainWindow* mainwindow=new MainWindow(id);
    this->close();
    mainwindow->show();
}



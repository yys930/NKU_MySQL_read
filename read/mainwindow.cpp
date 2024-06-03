#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QModelIndex>
#include "login.h"
MainWindow::MainWindow(int r_id, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_id = r_id;
    ui->maintab->setCurrentIndex(0);
    ui->changething->setCurrentIndex(0);


    connectsql();
    showpoints();
    showBookShelf();
    showMystar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit2_clicked()
{
    exit(0);
}

void MainWindow::connectsql()
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
        QMessageBox::information(this,"infor", "link failed");
        qDebug()<<"error open database because"<<db.lastError().text();
    }

}

void MainWindow::showpoints()
{
    QSqlQuery query(db);
    query.exec(QString("select readpoints from reader where reader_id = %1").arg(m_id));
    if (query.next()) {

        int tem = query.value(0).toInt();
        ui->points->setNum(tem);
    } else {
        qDebug() << "No data found for reader_id:" << m_id;
    }
}

void MainWindow::showBookShelf()
{
    QSqlQuery query1(db);
    query1.exec(QString("select bookname,author,content,type,end,bookid "
                        "from bookshelf "
                        "natural join book "
                        "where reader_id = %1").arg(m_id));
    QStringList headerLabels;
    headerLabels<<"书名"<<"作者"<<"内容"<<"类型"<<"状态"<<"删除";
    ui->book->setColumnCount(headerLabels.count());
    ui->book->setHorizontalHeaderLabels(headerLabels);
    ui->book->setRowCount(0);
    ui->book->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->book->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->book->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView *header = ui->book->horizontalHeader();
    header->setFont(QFont("Arial",10));

    while(query1.next())
    {
        QString b_name=query1.value(0).toString();
        QString b_a=query1.value(1).toString();
        QString b_i=query1.value(2).toString();
        QString b_t=query1.value(3).toString();
        QString b_e;
        QString b_id=query1.value(5).toString();
        if(query1.value(4).toInt()==1)
        {
            b_e="完结";
        }
        else
        {
            b_e="连载";
        }
        int r_num=ui->book->rowCount();
        ui->book->insertRow(r_num);
        ui->book->setItem(r_num,0,new QTableWidgetItem(b_name));
        ui->book->setItem(r_num,1,new QTableWidgetItem(b_a));
        ui->book->setItem(r_num,2,new QTableWidgetItem(b_i));
        ui->book->setItem(r_num,3,new QTableWidgetItem(b_t));
        ui->book->setItem(r_num,4,new QTableWidgetItem(b_e));
        QPushButton* delbook = new QPushButton("删除");
        connect(delbook,&QPushButton::clicked,this,[=](){
            int row = ui->book->indexAt(delbook->pos()).row();
            QSqlQuery tem(db);
            tem.exec(QString("delete from bookshelf where reader_id = %1 and bookid = %2").arg(m_id).arg(b_id));
            ui->book->removeRow(row);

        });
        ui->book->setCellWidget(r_num,5,delbook);


    }
}

void MainWindow::showMystar()
{
    QSqlQuery query1(db);
    query1.exec(QString("select bookname,author,type,end,bookid "
                        "from bookview "
                        "where reader_id = %1").arg(m_id));
    QStringList headerLabels;
    headerLabels<<"书名"<<"作者"<<"类型"<<"状态"<<"删除";
    ui->star->setColumnCount(headerLabels.count());
    ui->star->setHorizontalHeaderLabels(headerLabels);
    ui->star->setRowCount(0);
    ui->star->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->star->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->star->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView *header = ui->star->horizontalHeader();
    header->setFont(QFont("Arial",10));

    while(query1.next())
    {
        QString b_name=query1.value(0).toString();
        QString b_a=query1.value(1).toString();
        QString b_t=query1.value(2).toString();
        QString b_e;
        int b_id=query1.value(4).toInt();
        if(query1.value(3).toInt()==1)
        {
            b_e="完结";
        }
        else
        {
            b_e="连载";
        }
        int r_num=ui->star->rowCount();
        ui->star->insertRow(r_num);
        ui->star->setItem(r_num,0,new QTableWidgetItem(b_name));
        ui->star->setItem(r_num,1,new QTableWidgetItem(b_a));
        ui->star->setItem(r_num,2,new QTableWidgetItem(b_t));
        ui->star->setItem(r_num,3,new QTableWidgetItem(b_e));
        QPushButton* delstar = new QPushButton("删除");
        connect(delstar,&QPushButton::clicked,this,[=](){
            int row = ui->star->indexAt(delstar->pos()).row();
            ui->star->removeRow(row);
            QSqlQuery tem(db);
            tem.exec(QString("delete from star where reader_id = %1 and bookid = %2").arg(m_id).arg(b_id));

        });
        ui->star->setCellWidget(r_num,4,delstar);


    }
}

void MainWindow::on_search_botton_clicked()
{
    QString inf=ui->cin_name->text();
    QSqlQuery query1(db);
    query1.exec(QString("select * from book where bookname = '%1' or author = '%2' or type = '%3'").arg(inf).arg(inf).arg(inf));

    QStringList headerLabels;
    headerLabels<<"书名"<<"作者"<<"类型"<<"状态"<<"积分"<<"阅读"<<"收藏";
    ui->search_book->setColumnCount(headerLabels.count());
    ui->search_book->setHorizontalHeaderLabels(headerLabels);
    ui->search_book->setRowCount(0);
    ui->search_book->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->search_book->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->search_book->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView *header = ui->search_book->horizontalHeader();
    header->setFont(QFont("Arial",8));

    while(query1.next())
    {
        QString b_name=query1.value(1).toString();
        QString b_a=query1.value(2).toString();
        QString b_t=query1.value(4).toString();
        QString b_e;
        int b_p=query1.value(5).toString().toInt();
        int b_id=query1.value(0).toString().toInt();
        if(query1.value(3).toInt()==1)
        {
            b_e="完结";
        }
        else
        {
            b_e="连载";
        }
        int r_num=ui->search_book->rowCount();
        ui->search_book->insertRow(r_num);
        ui->search_book->setItem(r_num,0,new QTableWidgetItem(b_name));
        ui->search_book->setItem(r_num,1,new QTableWidgetItem(b_a));
        ui->search_book->setItem(r_num,2,new QTableWidgetItem(b_t));
        ui->search_book->setItem(r_num,3,new QTableWidgetItem(b_e));
        ui->search_book->setItem(r_num,4,new QTableWidgetItem(query1.value(5).toString()));
        QPushButton* b_read = new QPushButton("阅读");
        connect(b_read,&QPushButton::clicked,this,[=](){
            int row = ui->search_book->indexAt(b_read->pos()).row();
            QSqlQuery tem(db);
            bool ok;
            ok=tem.exec(QString("insert into bookshelf(reader_id, bookid) values (%1,%2)").arg(m_id).arg(b_id));
            if(ok)
            {
                QSqlQuery tem1(db);
                tem1.exec(QString("select readpoints from reader where reader_id = %1 ").arg(m_id));
                QSqlQuery tem2(db);
                tem2.exec(QString("select needpoints from book where bookid = %1 ").arg(b_id));
                tem1.next();
                tem2.next();
                int a=tem1.value(0).toString().toInt();
                int b=tem2.value(0).toString().toInt();
                int n=a-b;
                QSqlQuery tem3(db);
                tem3.exec(QString("UPDATE reader "
                                  "SET readpoints = %1 "
                                  "WHERE reader_id = %2 ").arg(n).arg(m_id));
                ui->search_book->removeRow(row);
                showpoints();
                showBookShelf();
                showMystar();


            }
            else
            {
                QMessageBox::information(this,"失败","正在阅读或者积分不足!");
                showpoints();
                showBookShelf();
                showMystar();
            }

        });
        ui->search_book->setCellWidget(r_num,5,b_read);


        QPushButton* b_star = new QPushButton("收藏");
        connect(b_star,&QPushButton::clicked,this,[=](){
            int row = ui->search_book->indexAt(b_star->pos()).row();
            QSqlQuery tem(db);
            bool ok;
            ok=tem.exec(QString("insert into star(reader_id, bookid) values (%1,%2)").arg(m_id).arg(b_id));
            if(ok)
            {
                showpoints();
                showBookShelf();
                showMystar();


            }
            else
            {
                QMessageBox::information(this,"失败","已收藏!");
                showpoints();
                showBookShelf();
                showMystar();
            }

        });
        ui->search_book->setCellWidget(r_num,6,b_star);


    }
}




void MainWindow::on_changename_clicked()
{
    QString old=ui->oldname->text();
    QString New=ui->newname->text();
    QSqlQuery query(db);
    query.exec(QString("select readername from reader where reader_id = %1").arg(m_id));
    if(query.next())
    {
        QString tem=query.value(0).toString();
        if(tem==old)
        {
            QSqlQuery query1(db);
            bool ok;
            ok = query1.exec(QString("CALL UpdateReadername('%1', '%2') ").arg(old).arg(New));
            if(!ok)
            {
                QMessageBox::information(this,"失败","新昵称已存在!");
            }
            else
            {
                QMessageBox::information(this,"成功","修改成功!");
            }
        }
        else
        {
            QMessageBox::information(this,"失败","当前昵称错误!");
        }
    }
}


void MainWindow::on_passchange_clicked()
{
    QString old=ui->oldpass->text();
    QString New=ui->newpass->text();
    QSqlQuery query(db);
    query.exec(QString("select readerpassword from reader where reader_id = %1").arg(m_id));
    if(query.next())
    {
        QString tem=query.value(0).toString();
        if(tem==old)
        {
            QSqlQuery query1(db);
            query1.exec(QString("CALL UpdateReaderpassword('%1', '%2', %3) ").arg(old).arg(New).arg(m_id));
            QMessageBox::information(this,"成功","修改成功!");

        }
        else
        {
            QMessageBox::information(this,"失败","当前密码错误!");
        }
    }
}


void MainWindow::on_Del_clicked()
{
    QString inf=ui->delme->text();
    if(inf=="我要注销当前账号")
    {
        QSqlQuery query(db);
        bool ok;
        ok=query.exec(QString("CALL delete_reader_with_transactions(%1)").arg(m_id));
        if(ok)
        {
            QMessageBox::information(this,"成功","注销成功!");
            Login * relogin = new Login();
            this->close();
            relogin->show();

        }

    }
    else
    {
        QMessageBox::information(this,"错误","请重新输入!");
    }
}


void MainWindow::on_getpoint_clicked()
{
    QSqlQuery query1(db);
    query1.exec(QString("select bookname,bookid from book "));
    QStringList headerLabels;
    headerLabels<<"书名"<<"领取积分";
    ui->getp->setColumnCount(headerLabels.count());
    ui->getp->setHorizontalHeaderLabels(headerLabels);
    ui->getp->setRowCount(0);
    ui->getp->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->getp->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->getp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView *header = ui->getp->horizontalHeader();
    header->setFont(QFont("Arial",10));

    while(query1.next())
    {
        QString b_name=query1.value(0).toString();
        int b_id=query1.value(1).toInt();
        int r_num=ui->getp->rowCount();
        ui->getp->insertRow(r_num);
        ui->getp->setItem(r_num,0,new QTableWidgetItem(b_name));

        QPushButton* get_point = new QPushButton("10积分");
        connect(get_point,&QPushButton::clicked,this,[=](){
            int row = ui->getp->indexAt(get_point->pos()).row();
            QSqlQuery tem(db);
            bool ok;
            ok=tem.exec(QString("CALL update_reader_points_based_on_bookshelf(%1, %2)").arg(m_id).arg(b_id));
            if(ok)
            {
                QMessageBox::information(this,"成功","获得10积分!");
                ui->getp->removeRow(row);
                showpoints();
                showBookShelf();
                showMystar();

            }
            else{
                QMessageBox::information(this,"失败","书架中没有这本书哦!");
                showpoints();
                showBookShelf();
                showMystar();
            }

        });
        ui->getp->setCellWidget(r_num,1,get_point);


    }
}


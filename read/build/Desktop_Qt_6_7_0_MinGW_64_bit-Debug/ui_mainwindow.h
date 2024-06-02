/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *maintab;
    QWidget *bookshelf;
    QTableWidget *book;
    QWidget *my_star;
    QTableWidget *star;
    QWidget *search;
    QTableWidget *search_book;
    QWidget *widget;
    QLineEdit *cin_name;
    QPushButton *search_botton;
    QWidget *tab;
    QLabel *introduce;
    QPushButton *getpoint;
    QTableWidget *getp;
    QWidget *change;
    QTabWidget *changething;
    QWidget *name;
    QWidget *widget_6;
    QPushButton *changename;
    QWidget *widget_7;
    QLineEdit *newname;
    QLabel *name2;
    QWidget *widget_8;
    QLineEdit *oldname;
    QLabel *name1;
    QWidget *pass;
    QWidget *widget_9;
    QPushButton *passchange;
    QWidget *widget_10;
    QLineEdit *newpass;
    QLabel *pass2;
    QWidget *widget_11;
    QLineEdit *oldpass;
    QLabel *pass1;
    QWidget *deleteme;
    QLineEdit *delme;
    QPushButton *Del;
    QPushButton *exit2;
    QLabel *point;
    QLabel *points;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 500);
        MainWindow->setMinimumSize(QSize(500, 500));
        MainWindow->setMaximumSize(QSize(500, 500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        maintab = new QTabWidget(centralwidget);
        maintab->setObjectName("maintab");
        maintab->setGeometry(QRect(10, 10, 480, 680));
        maintab->setMinimumSize(QSize(480, 680));
        maintab->setMaximumSize(QSize(480, 680));
        maintab->setIconSize(QSize(16, 16));
        bookshelf = new QWidget();
        bookshelf->setObjectName("bookshelf");
        book = new QTableWidget(bookshelf);
        book->setObjectName("book");
        book->setGeometry(QRect(0, 0, 480, 620));
        book->setMinimumSize(QSize(480, 620));
        book->setMaximumSize(QSize(480, 620));
        maintab->addTab(bookshelf, QString());
        my_star = new QWidget();
        my_star->setObjectName("my_star");
        star = new QTableWidget(my_star);
        star->setObjectName("star");
        star->setGeometry(QRect(0, 0, 480, 620));
        star->setMinimumSize(QSize(480, 620));
        star->setMaximumSize(QSize(480, 620));
        maintab->addTab(my_star, QString());
        search = new QWidget();
        search->setObjectName("search");
        search_book = new QTableWidget(search);
        search_book->setObjectName("search_book");
        search_book->setGeometry(QRect(0, 60, 480, 560));
        search_book->setMinimumSize(QSize(480, 560));
        search_book->setMaximumSize(QSize(480, 560));
        widget = new QWidget(search);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 570, 480, 50));
        cin_name = new QLineEdit(search);
        cin_name->setObjectName("cin_name");
        cin_name->setGeometry(QRect(10, 15, 360, 30));
        cin_name->setMaxLength(100);
        search_botton = new QPushButton(search);
        search_botton->setObjectName("search_botton");
        search_botton->setGeometry(QRect(380, 15, 80, 30));
        maintab->addTab(search, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        introduce = new QLabel(tab);
        introduce->setObjectName("introduce");
        introduce->setGeometry(QRect(40, 40, 400, 100));
        QFont font;
        font.setPointSize(40);
        introduce->setFont(font);
        introduce->setAlignment(Qt::AlignCenter);
        getpoint = new QPushButton(tab);
        getpoint->setObjectName("getpoint");
        getpoint->setGeometry(QRect(180, 150, 120, 20));
        getp = new QTableWidget(tab);
        getp->setObjectName("getp");
        getp->setGeometry(QRect(0, 180, 480, 240));
        maintab->addTab(tab, QString());
        change = new QWidget();
        change->setObjectName("change");
        changething = new QTabWidget(change);
        changething->setObjectName("changething");
        changething->setGeometry(QRect(0, 0, 480, 600));
        name = new QWidget();
        name->setObjectName("name");
        widget_6 = new QWidget(name);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(0, 50, 480, 400));
        changename = new QPushButton(widget_6);
        changename->setObjectName("changename");
        changename->setGeometry(QRect(170, 240, 140, 30));
        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(0, 120, 480, 50));
        newname = new QLineEdit(widget_7);
        newname->setObjectName("newname");
        newname->setGeometry(QRect(140, 10, 280, 30));
        name2 = new QLabel(widget_7);
        name2->setObjectName("name2");
        name2->setGeometry(QRect(40, 10, 40, 30));
        widget_8 = new QWidget(widget_6);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(0, 20, 480, 50));
        oldname = new QLineEdit(widget_8);
        oldname->setObjectName("oldname");
        oldname->setGeometry(QRect(140, 10, 280, 30));
        name1 = new QLabel(widget_8);
        name1->setObjectName("name1");
        name1->setGeometry(QRect(40, 10, 60, 30));
        changething->addTab(name, QString());
        pass = new QWidget();
        pass->setObjectName("pass");
        widget_9 = new QWidget(pass);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(0, 50, 480, 400));
        passchange = new QPushButton(widget_9);
        passchange->setObjectName("passchange");
        passchange->setGeometry(QRect(170, 240, 140, 30));
        widget_10 = new QWidget(widget_9);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(0, 120, 480, 50));
        newpass = new QLineEdit(widget_10);
        newpass->setObjectName("newpass");
        newpass->setGeometry(QRect(140, 10, 280, 30));
        pass2 = new QLabel(widget_10);
        pass2->setObjectName("pass2");
        pass2->setGeometry(QRect(40, 10, 40, 30));
        widget_11 = new QWidget(widget_9);
        widget_11->setObjectName("widget_11");
        widget_11->setGeometry(QRect(0, 20, 480, 50));
        oldpass = new QLineEdit(widget_11);
        oldpass->setObjectName("oldpass");
        oldpass->setGeometry(QRect(140, 10, 280, 30));
        pass1 = new QLabel(widget_11);
        pass1->setObjectName("pass1");
        pass1->setGeometry(QRect(40, 10, 60, 30));
        changething->addTab(pass, QString());
        deleteme = new QWidget();
        deleteme->setObjectName("deleteme");
        delme = new QLineEdit(deleteme);
        delme->setObjectName("delme");
        delme->setGeometry(QRect(100, 130, 280, 30));
        Del = new QPushButton(deleteme);
        Del->setObjectName("Del");
        Del->setGeometry(QRect(190, 200, 100, 31));
        changething->addTab(deleteme, QString());
        maintab->addTab(change, QString());
        exit2 = new QPushButton(centralwidget);
        exit2->setObjectName("exit2");
        exit2->setGeometry(QRect(410, 0, 71, 21));
        point = new QLabel(centralwidget);
        point->setObjectName("point");
        point->setGeometry(QRect(330, 0, 41, 21));
        QFont font1;
        font1.setPointSize(10);
        point->setFont(font1);
        point->setAlignment(Qt::AlignCenter);
        points = new QLabel(centralwidget);
        points->setObjectName("points");
        points->setGeometry(QRect(350, 0, 71, 21));
        points->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        maintab->setCurrentIndex(4);
        changething->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\273\347\225\214\351\235\242", nullptr));
        maintab->setTabText(maintab->indexOf(bookshelf), QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\344\271\246\346\236\266", nullptr));
        maintab->setTabText(maintab->indexOf(my_star), QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\346\224\266\350\227\217", nullptr));
        cin_name->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245", nullptr));
        search_botton->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        maintab->setTabText(maintab->indexOf(search), QCoreApplication::translate("MainWindow", "\345\217\221\347\216\260\344\271\246\347\261\215", nullptr));
        introduce->setText(QCoreApplication::translate("MainWindow", "\350\257\273\344\271\246\351\242\206\347\247\257\345\210\206", nullptr));
        getpoint->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\346\237\245\347\234\213", nullptr));
        maintab->setTabText(maintab->indexOf(tab), QCoreApplication::translate("MainWindow", "\347\247\257\345\210\206\350\216\267\345\276\227", nullptr));
        changename->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
        name2->setText(QCoreApplication::translate("MainWindow", "\346\226\260\346\230\265\347\247\260", nullptr));
        name1->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\230\265\347\247\260", nullptr));
        changething->setTabText(changething->indexOf(name), QCoreApplication::translate("MainWindow", "\346\230\265\347\247\260", nullptr));
        passchange->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
        pass2->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\257\206\347\240\201", nullptr));
        pass1->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\345\257\206\347\240\201", nullptr));
        changething->setTabText(changething->indexOf(pass), QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        delme->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\342\200\234\346\210\221\350\246\201\346\263\250\351\224\200\345\275\223\345\211\215\350\264\246\345\217\267\342\200\235", nullptr));
        Del->setText(QCoreApplication::translate("MainWindow", "\346\263\250\351\224\200", nullptr));
        changething->setTabText(changething->indexOf(deleteme), QCoreApplication::translate("MainWindow", "\346\263\250\351\224\200", nullptr));
        maintab->setTabText(maintab->indexOf(change), QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        exit2->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        point->setText(QCoreApplication::translate("MainWindow", "\347\247\257\345\210\206\357\274\232", nullptr));
        points->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

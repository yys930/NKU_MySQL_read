/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *login;
    QPushButton *exit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *password;
    QLineEdit *pass_number;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *user_id;
    QLineEdit *id_number;
    QLabel *title;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(399, 281);
        Login->setMinimumSize(QSize(399, 281));
        Login->setMaximumSize(QSize(399, 281));
        widget = new QWidget(Login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 190, 221, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        login = new QPushButton(widget);
        login->setObjectName("login");

        horizontalLayout->addWidget(login);

        exit = new QPushButton(widget);
        exit->setObjectName("exit");

        horizontalLayout->addWidget(exit);

        widget_2 = new QWidget(Login);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(90, 110, 221, 71));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        password = new QLabel(widget_2);
        password->setObjectName("password");

        horizontalLayout_2->addWidget(password);

        pass_number = new QLineEdit(widget_2);
        pass_number->setObjectName("pass_number");
        pass_number->setMaxLength(10);
        pass_number->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(pass_number);

        widget_3 = new QWidget(Login);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(90, 50, 221, 71));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        user_id = new QLabel(widget_3);
        user_id->setObjectName("user_id");

        horizontalLayout_3->addWidget(user_id);

        id_number = new QLineEdit(widget_3);
        id_number->setObjectName("id_number");
        id_number->setMaxLength(6);
        id_number->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(id_number);

        title = new QLabel(Login);
        title->setObjectName("title");
        title->setGeometry(QRect(170, 20, 61, 21));
        QFont font;
        font.setPointSize(14);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        login->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        exit->setText(QCoreApplication::translate("Login", "\351\200\200\345\207\272", nullptr));
        password->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\257\206\347\240\201", nullptr));
        pass_number->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        user_id->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267   ID", nullptr));
        id_number->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267id", nullptr));
        title->setText(QCoreApplication::translate("Login", "\351\230\205\350\257\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

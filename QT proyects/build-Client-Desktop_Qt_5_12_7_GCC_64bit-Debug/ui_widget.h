/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *conectar;
    QLabel *label;
    QListWidget *listWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 541);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 205, 193);"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 30, 701, 481));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        conectar = new QPushButton(widget);
        conectar->setObjectName(QString::fromUtf8("conectar"));
        QFont font;
        font.setPointSize(12);
        conectar->setFont(font);
        conectar->setStyleSheet(QString::fromUtf8("background-color: rgb(133, 244, 81);\n"
"background-color: rgb(77, 172, 38);"));

        verticalLayout->addWidget(conectar);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(18);
        font1.setItalic(true);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        verticalLayout->addWidget(listWidget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        conectar->setText(QApplication::translate("Widget", "Conectar al Servidor", nullptr));
        label->setText(QApplication::translate("Widget", "Datos recibidos por el cliente:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

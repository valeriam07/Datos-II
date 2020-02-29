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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *iniciar;
    QPushButton *enviar;
    QPushButton *quitar;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_9;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *msj;
    QLabel *label_2;
    QLineEdit *msj_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(676, 577);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 205, 193);"));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 510, 391, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        iniciar = new QPushButton(layoutWidget);
        iniciar->setObjectName(QString::fromUtf8("iniciar"));
        QFont font;
        font.setPointSize(13);
        iniciar->setFont(font);
        iniciar->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        horizontalLayout->addWidget(iniciar);

        enviar = new QPushButton(layoutWidget);
        enviar->setObjectName(QString::fromUtf8("enviar"));
        enviar->setFont(font);
        enviar->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        horizontalLayout->addWidget(enviar);

        quitar = new QPushButton(layoutWidget);
        quitar->setObjectName(QString::fromUtf8("quitar"));
        quitar->setFont(font);
        quitar->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        horizontalLayout->addWidget(quitar);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 220, 171, 21));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 320, 131, 16));
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 30, 131, 21));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_9->setFont(font2);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 70, 571, 131));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font3;
        font3.setPointSize(16);
        font3.setItalic(true);
        label->setFont(font3);

        verticalLayout->addWidget(label);

        msj = new QLineEdit(widget);
        msj->setObjectName(QString::fromUtf8("msj"));
        msj->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        verticalLayout->addWidget(msj);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font3);

        verticalLayout->addWidget(label_2);

        msj_2 = new QLineEdit(widget);
        msj_2->setObjectName(QString::fromUtf8("msj_2"));
        msj_2->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        verticalLayout->addWidget(msj_2);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(150, 350, 351, 121));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(widget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        lineEdit_3 = new QLineEdit(widget1);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(widget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        lineEdit_4 = new QLineEdit(widget1);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        horizontalLayout_4->addWidget(lineEdit_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        widget2 = new QWidget(Widget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(50, 260, 461, 51));
        horizontalLayout_5 = new QHBoxLayout(widget2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        lineEdit = new QLineEdit(widget2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        horizontalLayout_5->addWidget(lineEdit);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        iniciar->setText(QApplication::translate("Widget", "Iniciar Servidor", nullptr));
        enviar->setText(QApplication::translate("Widget", "Enviar", nullptr));
        quitar->setText(QApplication::translate("Widget", "Cerrar App", nullptr));
        label_3->setText(QApplication::translate("Widget", "Otras funciones:", nullptr));
        label_5->setText(QApplication::translate("Widget", "A\303\261adir conexion:  ", nullptr));
        label_9->setText(QApplication::translate("Widget", "Dijkstra:", nullptr));
        label->setText(QApplication::translate("Widget", "Origen:", nullptr));
        label_2->setText(QApplication::translate("Widget", "Destino:", nullptr));
        label_6->setText(QApplication::translate("Widget", "Origen:", nullptr));
        label_7->setText(QApplication::translate("Widget", "Destino:", nullptr));
        label_8->setText(QApplication::translate("Widget", "Valor:", nullptr));
        label_4->setText(QApplication::translate("Widget", "A\303\261adir Nodo: (nombre)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

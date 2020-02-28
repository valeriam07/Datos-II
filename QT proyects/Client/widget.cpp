#include "widget.h"
#include "ui_widget.h"
#include <QLocalSocket>
#include <iostream>

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QLocalSocket(this);

    connect(mSocket, &QLocalSocket::readyRead, [&](){
        cout <<"enviando..."<<endl;
        QTextStream T(mSocket);
        QString s = T.readAll();
        ui -> listWidget -> addItem(s);
        std::cout << s.toUtf8().constData() << std::endl;


    });


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_conectar_clicked()
{
    //cout << "conectando..." << endl;
    mSocket->connectToServer("MiServidor");

}

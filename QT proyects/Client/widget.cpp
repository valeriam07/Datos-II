#include "widget.h"
#include "ui_widget.h"
#include <QLocalSocket>
#include <iostream>

using namespace std;

/**
 * @brief Widget::Widget
 * Es la funcion principal de la interfaz grafica del cliente, esta recibe
 * los datos enviados por el servidor por medio de sockets y los muestra en la ventana
 *
 * @param parent ventana principal
 */

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

        QTextStream Node(mSocket);
        QString s2 = Node.readAll();
        ui -> listWidget -> addItem(s2);


        QTextStream Edge(mSocket);
        QString s3 = Node.readAll();
        ui -> listWidget -> addItem(s3);


        std::cout << s.toUtf8().constData() << std::endl;


    });


}


Widget::~Widget()
{
    delete ui;
}

/**
 * @brief Widget::on_conectar_clicked
 * Al presional el boton conectar, el cliente realiza la conexion con el servidor
 *
 */


void Widget::on_conectar_clicked()
{
    cout << "conectando..." << endl;
    mSocket->connectToServer("MiServidor54");

}

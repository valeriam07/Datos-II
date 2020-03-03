#include <stdio.h>
#include <iostream>
#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QTextStream>
#include "fstream"
#include "graph.h"

static Graph g;
using namespace std;

/**
 * @brief Widget::Widget
 * Inicializa la ventana principal del servidor
 * @param parent
 */
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mLocalServer = new localServer(this);

}

Widget::~Widget()
{
    delete ui;
}

/**
 * @brief Widget::on_iniciar_clicked
 * Al presionar el boton iniciar servidor se conecta a un servidor y espera a que el cliente se conecte
 */
void Widget::on_iniciar_clicked()
{
    if( !mLocalServer -> listen("MiServidor68")){
        cout << "Error en el server" <<endl;
    }else{
        cout<< "Se inicio el enlace..." <<endl;

    }

}

/**
 * @brief Widget::on_enviar_clicked
 * Al presionar el boton enviar se envian todos los datos obtenidos de la interfaz grafica al cliente
 */
void Widget::on_enviar_clicked()
{

    mLocalServer -> envia(ui->Dj_origen->text(), ui->Dj_destino->text(), ui->name->text(), ui->origen->text(), ui->destino->text(), ui->value->text(),g);
    cout << "enviando..." <<endl;



}

/**
 * @brief Widget::on_quitar_clicked
 * Al presionar el boton quitar se cerrara la aplicacion
 */
void Widget::on_quitar_clicked()
{

    close();
}




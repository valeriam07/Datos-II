#include <stdio.h>
#include <iostream>
#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QTextStream>
#include "graph.h"

using namespace std;

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


void Widget::on_iniciar_clicked()
{
    cout << "entra" <<endl;
    if( !mLocalServer -> listen("MiServidor")){
        cout << "Error en el server" <<endl;
    }else{
        cout<< "Se inicio el enlace..." <<endl;

    }

}

void Widget::on_enviar_clicked()
{
    mLocalServer -> envia(ui->Dj_origen->text(), ui->Dj_destino->text(), ui->name->text(), ui->origen->text(), ui->destino->text(), ui->value->text());
    cout << "enviando..." <<endl;



}

void Widget::on_quitar_clicked()
{
    close();
}



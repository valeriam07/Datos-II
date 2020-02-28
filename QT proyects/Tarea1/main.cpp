#include "mainwindow.h"
#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <QApplication>

using  namespace std;

int open_socket();
void bindToPort(int,int);

const int PORT = 5000;
//char *advice[] = {"RESPUESTA 1 \n ", "RESPUESTA 2 \n"};

int *info = (int *)malloc(2* sizeof(int *));

void ingresarDatos(){
    int inicio;
    int final;
    cout << "Ingrese el nodo inicio del recorrido: \n";
    cin >> inicio;
    info[0] = inicio;
    cout << "\nIngrese el nodo final del recorrido: \n";
    cin >> final;
    info[1] = final;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    int listener = open_socket();

    if(listener == -1){
            cout << "Error en el listener"<< endl;
            return 0;
        }

        bindToPort(listener, PORT);
        if(listen(listener, 10) == -1){
            cout<< "\n No es posible escuchar el puerto \n" << endl;
            return 0;

        }

        printf("Enlazado al puerto\n");
        ingresarDatos();

        while(1){
            //cuando el boton de enviar sea presionado debe entrar en el while, de ahi se obtienen los datos para enviar a la funcion dijkstra
            struct sockaddr_storage client;
            unsigned int addres_size = sizeof(client);
            printf("Esperando al cliente \n");
            int connect = accept (listener, (struct sockaddr*) &client, &addres_size);
            if(connect == -1){
                printf("no se puede conectar socket secundario \n");
            }

            //cuando (if) se presione enviar (de la interfaz) debe haber un recive de los datos de inicio y final los cuales estaran guardados en una lista

            printf("Atendiendo al cliente \n");
            char* msg;
            send(connect,msg,strlen(msg),0); //send debe ir luego de obtener el resultado del dijkstra
            msg = NULL;

            close(connect);
        }


    }

    int open_socket(){
        int s = socket(PF_INET,SOCK_STREAM, 0);
        if(s == -1){
            printf("Error al abrir el socket \n");
            return s;
        }
    }

    void bindToPort(int socket, int port){
        struct sockaddr_in name;
        name.sin_family = PF_INET;
        name.sin_port = (in_port_t)htons(port);
        name.sin_addr.s_addr = htonl(INADDR_ANY);
        int reuse = 1;
        if(setsockopt(socket,SOL_SOCKET,SO_REUSEADDR,(char*) &reuse, sizeof(int)) == 1){
            printf("No es posible reusar el socket\n");
        }
        int c = bind(socket, (struct sockaddr*) &name, sizeof(name));
        if(c== -1){
            perror("No se puede enlazar el puerto");
        }



}

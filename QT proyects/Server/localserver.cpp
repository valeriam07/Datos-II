#include "localserver.h"
#include <QLocalSocket>
#include <QTextStream>
#include "graph.h"



localServer::localServer(QObject *parent) : QLocalServer(parent)
{
    mSocket = nullptr;
    connect(this, &localServer :: newConnection, [&](){
        mSocket = nextPendingConnection();

    });
}


void localServer :: envia(const QString &Dj_origen, const QString &Dj_destino, const QString name, const QString origen,const QString destino, QString value){

    cout<< "se inicio el grafo"<< endl;

    if(mSocket){
        QTextStream T(mSocket);
        QTextStream Node(mSocket);
        QTextStream Edge(mSocket);


        if(Dj_origen != NULL && Dj_destino != NULL){
            T << "\n\n\n*** Dijkstra ***\nOrigen: " + Dj_origen;
            T << "\nDestino: " + Dj_destino;
            //g.dijkstra(Dj_origen.toStdString(), Dj_destino.toStdString());



        }else{
            T << "\n\n\n*** Dijkstra ***\nNo se puede realizar la operacion, datos incompletos.";
        }

        if(name != NULL){

            Node << "\n\n\n*** Nuevo Nodo ***\nNombre del nuevo nodo: " + name;
        }else{
            Node << "\n\n\n*** Nuevo Nodo ***\nNo se puede realizar la operacion, datos incompletos.";
        }

        if(origen.isNull() != true && destino.isNull() != true && value !=0){

            Edge << "*** Nuevo Edge ***\nOrigen del nuevo Edge: " + origen;
            Edge << "\nDestino del nuevo Edge: " +destino;
            Edge << "\nValor del nuevo Edge: " +value;

            cout << g.getNode(origen.toStdString())->name << endl;
            cout<< g.getNode(destino.toStdString())->name << endl;

            if(g.getNode(origen.toStdString())!= NULL){
                    if(g.getNode(destino.toStdString()) != NULL){
                        g.addEdge(g.getNode(origen.toStdString())->name, g.getNode(destino.toStdString())->name, value.toInt());
                    }else{
                        g.addNode(destino.toStdString());
                        g.addEdge(g.getNode(origen.toStdString())->name, g.getNode(destino.toStdString())->name, value.toInt());
                    }

            }else if(g.getNode(destino.toStdString()) != NULL){
                 g.addNode(origen.toStdString());
                 g.addEdge(g.getNode(origen.toStdString())->name, g.getNode(destino.toStdString())->name, value.toInt());
            }else{
                g.addNode(origen.toStdString());
                g.addNode(destino.toStdString());
                g.addEdge(g.getNode(origen.toStdString())->name, g.getNode(destino.toStdString())->name, value.toInt());
            }

        }else{
            Edge << "*** Nuevo Edge ***\nNo se puede realizar la operacion, datos incompletos.";
        }
        mSocket -> flush();

    }
}

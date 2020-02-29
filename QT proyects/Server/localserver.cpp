#include "localserver.h"
#include <QLocalSocket>
#include <QTextStream>



localServer::localServer(QObject *parent) : QLocalServer(parent)
{
    mSocket = nullptr;
    connect(this, &localServer :: newConnection, [&](){
        mSocket = nextPendingConnection();

    });
}


void localServer :: envia(const QString &Dj_origen, const QString &Dj_destino, const QString name, const QString origen,const QString destino, QString value){
    if(mSocket){
        QTextStream T(mSocket);
        QTextStream Node(mSocket);
        QTextStream Edge(mSocket);

        if(Dj_origen.isNull() != true && Dj_destino.isNull() != true){
            T << "\n\n\n*** Dijkstra ***\nOrigen: " + Dj_origen;
            T << "\nDestino: " + Dj_destino;


        }else{
            T << "*** Dijkstra ***\nNo se puede realizar la operacion, datos incompletos.";
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
        }else{
            Edge << "*** Nuevo Edge ***\nNo se puede realizar la operacion, datos incompletos.";
        }
        mSocket -> flush();

    }
}

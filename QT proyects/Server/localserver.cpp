#include "localserver.h"
#include <QLocalSocket>
#include <QTextStream>
#include "graph.h"

static string inicio;
static string final;

localServer::localServer(QObject *parent) : QLocalServer(parent)
{
    mSocket = nullptr;
    connect(this, &localServer :: newConnection, [&](){
        mSocket = nextPendingConnection();

    });
}

string localServer :: getInicio(){
    return inicio;
}

void localServer :: sendDijkstra(){

        Graph g;

        g.init();
        g.addNode("A");
        g.addNode("B");
        g.addNode("C");
        g.addNode("D");
        g.addNode("E");

        g.addEdge("A","B",2);
        try {
            g.addEdge("B", "C",2);
            g.addEdge("A","D", 10);
            g.addEdge("C", "D", 3);
            g.addEdge("D", "E", 2);
            g.addEdge("A", "C", 5);

        } catch (...) {
            cout<< "ERROR"<< endl;
        }

        g.dijkstra(inicio, final);

}




void localServer :: envia(const QString &Dj_origen, const QString &Dj_destino, const QString name, const QString origen,const QString destino, QString value, Graph g){

    if(mSocket){
        QTextStream T(mSocket);
        QTextStream Node(mSocket);
        QTextStream Edge(mSocket);


        if(Dj_origen != NULL && Dj_destino != NULL){
            T << "\n\n\n*** Dijkstra ***\nOrigen: " + Dj_origen;
            T << "\nDestino: " + Dj_destino;

            inicio = Dj_origen.toStdString();
            final = Dj_destino.toStdString();

            cout<< "INICIO: "<< inicio<< endl;
            cout<< "FINAL: "<< final<< endl;

            sendDijkstra();

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

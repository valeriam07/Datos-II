#include "localserver.h"
#include <QLocalSocket>
#include <QTextStream>
#include "graph.h"

static string inicio;
static string final;

/**
 * @brief localServer::localServer
 * Inicializa el servidor local y genera la conexion del mismo
 * @param parent
 */
localServer::localServer(QObject *parent) : QLocalServer(parent)
{
    mSocket = nullptr;
    connect(this, &localServer :: newConnection, [&](){
        mSocket = nextPendingConnection();

    });
}

/**
 * @brief localServer::sendDijkstra
 * Genera un grafo predeterminado y con la informacion recolectada de los sockets
 * envia a la funcion dijkstra
 */
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



/**
 * @brief localServer::envia
 * Funcion que envia los datos desde el servidor al cliente
 * @param Dj_origen Nodo de origen para la funcion dijkstra
 * @param Dj_destino Nodo de destino para la funcion dijkstra
 * @param name nombre para crear un nuevo nodo
 * @param origen nombre del origen para crear una nueva arista
 * @param destino nombre del destino para crear una nueva arista
 * @param value valor de la nueva arista
 * @param g grafo al cual se le ralizan algunas funciones
 */
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

                g.addNode(origen.toStdString());
                g.addNode(destino.toStdString());
                g.addEdge(g.getNode(origen.toStdString())->name, g.getNode(destino.toStdString())->name, value.toInt());

        }else{
            Edge << "*** Nuevo Edge ***\nNo se puede realizar la operacion, datos incompletos.";
        }
        mSocket -> flush();

    }
}

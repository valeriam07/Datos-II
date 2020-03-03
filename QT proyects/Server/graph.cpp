#include "graph.h"
#include <fstream>
#include <QMessageBox>

void Graph::init()
{
    h = NULL;       //referencia inicial
}

bool Graph::empty(){
    if(h == NULL){
        //cout << "esta vacio" << endl;
        return true;

    }else{
        //cout << "NO esta vacio" << endl;
        return false;
    }
}

int Graph::size(){

   int cont = 0;
    Node *aux;
    aux = h;

    while (aux != NULL){
        aux = aux -> sig;
        cont ++;
    }

    cout << cont << endl;
    return cont;

}

Node *Graph :: getNode(string name){
    Node *aux;
    aux = h;


    while (aux != NULL){
        if(aux -> name == name){
            //cout << aux << endl;
            return aux;
        }
        aux = aux -> sig;
    }

    return NULL;
}

int Graph :: exists(string name){

    Node *aux = new Node;

    ifstream myfile("GraphData.txt");

    std::string cadena;

    myfile >> cadena;

    cout<< "cadena "<< cadena << endl;


    for(std::string::size_type i = 0; i < cadena.size(); ++i) {
        if(cadena.compare(i, 1, name) == 0){ //i = indice, 1 = num chars
           aux->name = name;
           cout<<"El nodo ya existe pero est nuevo"<<endl;
           return 1;
        }

    }
    cout<< "No existe"<< endl;
    return 0;

}

void Graph :: addNode(string name){
    Node  *nuevo = new Node;
    nuevo -> name = name;
    nuevo -> sig = NULL;
    nuevo -> adyacente = NULL;

    if( empty()){
        h = nuevo;
    }else{
        Node *aux;
        aux = h;
        while(aux-> sig !=NULL ){
            aux = aux -> sig;
        }

        aux->sig = nuevo;
    }

    cout << "se añadio un nuevo nodo: "<< name << endl;
}

void Graph :: addEdge(string origenName, string destinoName, int value){

    try{
        Node *origen = getNode(origenName);
        Node *destino = getNode(destinoName);
        Edge *nueva = new Edge;
        nueva-> value = value;
        nueva->sig = NULL;
        nueva->adyacente = NULL;

        Edge *aux;
        aux = origen ->adyacente;

        if(aux == NULL){                //cuando no hay conexiones
            origen ->adyacente = nueva;
            nueva -> adyacente = destino;
            origen->edges[0] = nueva;
            origen->edgesNum++;

        }else{
            origen->edges[origen->edgesNum] = nueva;
            nueva->adyacente = destino;
            origen->edgesNum++;
        }


        save(origen, destino, value);
        cout << "\n** Se añadio un nuevo edge: ** \norigen: " << origen->name << "\ndestino: " << destino ->name << "\nvalue: " << value << "\n" << endl;

    }catch(...){
        cout<< "ERROR"<< endl;
    }
}

void Graph :: listaAdyacencia(){    //lista de conexiones entre los nodos
    Node *nodeAux;
    Edge *edgeAux;

    nodeAux = h;
    while(nodeAux != NULL){

        cout <<nodeAux ->name << "->";
         edgeAux = nodeAux ->adyacente;
         while(edgeAux != NULL){

             cout<< edgeAux ->adyacente->name << "->";
             edgeAux = edgeAux ->sig;
         }
        nodeAux = nodeAux ->sig;
        cout <<endl;

    }
}

void Graph :: anular(){         //elimina el grafo completo
    Node *aux;

    while (h != NULL){
        aux =h;
        h = h->sig;
        delete(aux);

    }
}

void Graph ::deleteEdge(Node *origen, Node *destino){

    int band = 0;
    Edge *actual, *anterior;

    actual = origen ->adyacente;

    if(actual == NULL){
        cout << "EL vertice origen no tiene aristas"<< endl;

    }else if(actual ->adyacente == destino){
        origen ->adyacente = actual->sig;
        delete(actual);

    }else{
        while(actual->adyacente != NULL ){

            if(actual->adyacente == destino){
                band = 1;
                anterior ->sig = actual ->sig;
                delete(actual);
                break;
            }
            anterior = actual;
            actual = actual->sig;

        }
        if (band == 0){
            cout << "esos dos vertices no estan conectados"<< endl;
        }

    }
}

void Graph::save(Node *origen, Node *destino, int value){
    ofstream myfile;
    myfile.open("GraphData.txt",fstream::out | fstream::app);

    cout<<"in"<<endl;

    if(myfile.fail()){
        cout<< "no se pudo abrir el archivo" <<endl;
    }
    myfile << origen->name +",";
    myfile << destino ->name +".";
    myfile << value << ":";


    myfile.close();

}

void Graph :: init_dijkstra(string origenName, string destinoName){


    init();
    addNode("A");
    addNode("B");
    addNode("C");
    addNode("D");
    addNode("E");

    addEdge("A","B",2);
    addEdge("B", "C",2);
    addEdge("A","D", 10);
    addEdge("C", "D", 3);
    addEdge("D", "E", 2);;

    //dijkstra("A", "E");

    /*ifstream myfile("GraphData.txt");

    std::string cadena;

    myfile >> cadena;

    cout<< "cadena "<< cadena << endl;


    for(std::string::size_type i = 0; i <= cadena.size(); ++i) {


        if(cadena.compare(i, 1, ",") == 0){ //i = indice, 1 = num chars
            std::string s(1,cadena[i-1]);
            std::string s2(1,cadena[i+1]);
            std::string s3(1,cadena[i+3]);
            int value = std::stoi(s3);


            cout<< "s: "<<s<< endl;
            cout<< "s2: "<<s2<< endl;
            cout<< "value: "<<value<< endl;


            if(getNode(s2) == NULL){
                addNode(s2);
            }


            if(getNode(s) == NULL){
                addNode(s);
            }

            addEdge(s,s2,value);


        }else if(cadena.compare(i,1,":")==0 || cadena.compare(i,1,".")==0){

        }else{*/

            /*std::string s(1,cadena[i]);
            if(g.getNode(s) == NULL){
                g.addNode(s);*/

            //}
       // }



      //dijkstra(origenName,destinoName);


}

void Graph :: dijkstra(string origenName, string destinoName){

    //init_dijkstra(origenName, destinoName);
    Node *origen = getNode(origenName);
    Node *destino = getNode(destinoName);
    int distanciaRecorrida=0;
    Node prev;
    string camino = origenName + " ,";
    int i=0;


    QMessageBox result;


    while(origen->edges[i] != NULL){
        cout<< "ENTRA"<<endl;
        int d1 =0;
        int d2 =0;

        if(origen->edges[i]->adyacente->name == destinoName || origen->edges[i+1]== NULL){
            cout<< "\nEl camino mas corto es: "<< camino<< destinoName<<endl;
            QString res = QString::fromStdString(camino+ destinoName);
            result.setText("El camino mas corto es: " + res);
            result.exec();
            break;

        }else if(origen->edges[i+1]->adyacente->name == destinoName){
            cout<< "\nEl camino mas corto es: "<< camino<< destinoName<<endl;
            QString res = QString::fromStdString(camino+ destinoName);
            result.setText("El camino mas corto es: " + res);
            result.exec();
            break;

        }else{


            d1 =origen->edges[i]->value;

            //cout<<"VAL: "<<  origen->edges[i+1]->value<<endl;
            if(origen->edges[i+1] != NULL){
                d2 = origen->edges[i+1]->value;

                if(d1<=d2 && origen->edges[i+1]->adyacente->name == destinoName){
                    cout<< "\nEl camino mas corto es: "<< camino+ destinoName<< endl;
                    QString res = QString::fromStdString(camino + destinoName);
                    result.setText("El camino mas corto es: " + res);
                    result.exec();
                    break;
                }
            }else{
                d2 = 0;
            }
            cout <<"D1: " <<d1<<endl;
            cout <<"D2: " << d2<<endl;
            cout<<"ORIGEN: "<<origen->name<< endl;
            cout<<"DESTINO: "<<destino->name<<endl;

            if(d2 >= 0 && d1<100 && d2<100 && d1 > 0){

                if(d1<=d2){


                    if(origen->edges[i+2] != NULL){
                        cout<<"falta lista"<<endl;
                        i++;

                    }else{
                        cout<<"pasa por:"<<origen->edges[i]->adyacente->name<< endl;
                        distanciaRecorrida += d1;
                        camino += origen->edges[i]->adyacente->name + " ,";
                        origen = origen ->edges[i]->adyacente;
                        cout<<"el nuevo origen es: "<<origen->name<< endl;
                        i=0;
                    }


                }else{

                    if(origen->edges[i+2] != NULL){
                        cout<<"falta lista"<<endl;
                        i++;
                    }else{
                        distanciaRecorrida += d2;
                        cout<<"pasa por:"<<origen->edges[i+1]->adyacente->name;
                        camino += origen->edges[i+1]->adyacente->name + " ,";
                        origen = origen ->edges[i+1]->adyacente;
                        cout<<"\nel nuevo origen es: "<<origen->name<< endl;
                        //cout<<origen->edges[0]<<endl;
                        i=0;
                    }

                }
            }

        }


    }
    cout<< "\n" << distanciaRecorrida;


}



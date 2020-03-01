#include "graph.h"
#include <fstream>


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

    for(int j=1; origen->edges[j-1]!=0;j++){
        cout << origen->edges[j-1]->value<< ", ";
    }

    save(origen, destino, value);
    cout << "\n** Se añadio un nuevo edge: ** \norigen: " << origen->name << "\ndestino: " << destino ->name << "\nvalue: " << value << "\n" << endl;
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
    myfile << destino ->name +",";
    myfile << value << ":";


    myfile.close();

}

void Graph :: dijkstra(string origenName, string destinoName){
    Node *origen = getNode(origenName);
    Node *destino = getNode(destinoName);
    int distanciaRecorrida=0;
    Node prev;
    string camino = origenName + " ,";
    int i=0;

    while(origen->edges[i] != NULL){
        int d1 =0;
        int d2 =0;

        if(origen->edges[i]->adyacente->name == destinoName && origen->edges[i+1]== NULL){
            cout<< "\nEl camino mas corto es: "<< camino<< destinoName<<endl;
            break;
        }else{
            d1 = distanciaRecorrida + origen->edges[i]->value;
            if(origen->edges[i+1] != NULL){
                d2 = distanciaRecorrida +origen->edges[i+1]->value;
            }
            cout <<d1<<endl;
            cout <<d2<<endl;
            cout<<origen->edges[i]->adyacente->name<< endl;
            cout<<destino->name<<endl;

            if(d1<=d2 && origen->edges[i+1]->adyacente->name == destinoName){
                cout<< "\nEl camino mas corto es: "<< camino+ destinoName<< endl;
            }

            else if(d1<=d2){


                if(origen->edges[i+2] != NULL){
                    i++;

                }else{
                    cout<<"pasa por:"<<origen->edges[i]->adyacente->name;
                    distanciaRecorrida = d1;
                    camino += origen->edges[i]->adyacente->name + " ,";
                    origen = origen ->edges[i]->adyacente;
                    i=0;
                }


            }else{

                if(origen->edges[i+2] != NULL){
                    cout<<"falta lista"<<endl;
                    i++;
                }else{

                    cout<<"pasa por:"<<origen->edges[i]->adyacente->name;
                    camino += origen->edges[i]->adyacente->name + " ,";
                    origen = origen ->edges[i]->adyacente;
                    cout<<"\nel nuevo origen es: "<<origen->name<< endl;;
                    cout<<origen->edges[0]<<endl;
                    i=0;
                }

            }


        }


    }
    cout<< "\n" << distanciaRecorrida;


}



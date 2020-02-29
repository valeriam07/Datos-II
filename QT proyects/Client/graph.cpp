#include "graph.h"

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
            cout << aux << endl;
            return aux;
        }
        aux = aux -> sig;
    }
    return NULL;
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

    cout << "se añadio un nuevo nodo: "<< nuevo << name << endl;
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

    if(aux == NULL){
        origen ->adyacente = nueva;
        nueva -> adyacente = destino;

    }else{
        while (aux != NULL) {
            aux = aux->sig;

        }
        aux->sig =nueva;
        nueva->adyacente = destino;

    }

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

    if(actual = NULL){
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

#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

using namespace std;

class Edge;

class Node{         //vertice
    Node *sig;
    Edge *adyacente;  //conexion entre dos vertices
    string name;
    friend class Graph;

};

class Edge{     //arista
    Edge *sig;
    Node *adyacente;
    int value;
    friend class Graph;

};

class Graph
{
    Node *h;

public:
    void init();
    bool empty();
    int size();
    Node *getNode(string name);  //devuelve el nodo con x name
    void addEdge(string origenName, string destino, int value);
    void addNode(string name);
    void listaAdyacencia();
    void deleteEdge(Node *origen, Node *destino);
    void anular();

};

#endif // GRAPH_H

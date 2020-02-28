#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

using namespace std;


typedef struct edge edge;
typedef struct node node;
struct node *CAB = NULL;

struct edge{
    node *recorrido;
    edge *sig;
};

struct node{
    edge *cab;
    node *sig;
    node *anterior;
    int name;

};

node addNode(int name){
    node *p, *q, *newNode;
    newNode = new(node);

    if(newNode == NULL){
        cout << "nodo null" <<endl;
    }

    p= NULL;
    q = NULL;


}

#endif // GRAPH_H

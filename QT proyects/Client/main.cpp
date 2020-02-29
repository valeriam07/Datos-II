#include "widget.h"
#include "graph.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Graph g;
    g.init();
    g.addNode("Nodo1");
    g.addNode("Nodo2");
    g.addEdge("Nodo1", "Nodo2", 10);
    g.size();

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

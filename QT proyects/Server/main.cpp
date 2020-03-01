#include "widget.h"
#include "graph.h"

#include <QApplication>




void generateGraph(){
    g.init();
    g.addNode("A");
    g.addNode("B");
    g.addNode("C");
    g.addNode("D");
    g.addNode("E");

    g.addEdge("A","B",2);
    g.addEdge("B", "C",2);
    g.addEdge("A","D", 10);
    g.addEdge("C", "D", 3);
    g.addEdge("D", "E", 2);

    g.exists("F");

    g.dijkstra("A", "E");
}


int main(int argc, char *argv[])
{
    remove("GraphData.txt");
    generateGraph();
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Widget w;
    w.show();
    return a.exec();
}


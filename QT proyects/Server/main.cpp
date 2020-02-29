#include "widget.h"
#include "graph.h"

#include <QApplication>

void generateGraph(){
    Graph g;
    g.addNode("A");
    g.addNode("B");
    g.addEdge("A","B",10);

}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Widget w;
    w.show();
    return a.exec();
}


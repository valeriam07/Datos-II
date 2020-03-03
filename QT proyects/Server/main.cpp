#include "widget.h"
#include "graph.h"
#include "localserver.h"

#include <QApplication>




int main(int argc, char *argv[])
{
    remove("GraphData.txt");
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Widget w;
    w.show();
    //generateGraph();
    return a.exec();

}


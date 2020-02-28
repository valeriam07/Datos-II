#include "localserver.h"
#include <QLocalSocket>
#include <QTextStream>

localServer::localServer(QObject *parent) : QLocalServer(parent)
{
    mSocket = nullptr;
    connect(this, &localServer :: newConnection, [&](){
        mSocket = nextPendingConnection();

    });
}


void localServer :: envia(const QString &msj){
    if(mSocket){
    QTextStream T(mSocket);
    T << msj;
    mSocket -> flush();

    }
}

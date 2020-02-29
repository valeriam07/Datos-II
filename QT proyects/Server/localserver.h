#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QLocalServer>

class QLocalSocket;

class localServer : public QLocalServer
{
    Q_OBJECT
public:
    explicit localServer(QObject *parent = 0);

    void envia(const QString &Dj_origen, const QString &Dj_destino, const QString name, const QString origen,const QString destino, const QString value);

private:
    QLocalSocket *mSocket;

};

#endif // LOCALSERVER_H

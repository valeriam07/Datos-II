#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QObject>

class localServer : public QObject
{
    Q_OBJECT
public:
    explicit localServer(QObject *parent = nullptr);

signals:

};

#endif // LOCALSERVER_H

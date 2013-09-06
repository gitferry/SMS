#ifndef CLIENTSERVER_H
#define CLIENTSERVER_H

#include <QTcpServer>

class ClientServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit ClientServer(QObject *parent = 0);
    
signals:
protected:
    void incomingConnection(int socketDescriptor);
public slots:
    
};

#endif // CLIENTSERVER_H

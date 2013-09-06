#include "clientserver.h"
#include "clientthread.h"

ClientServer::ClientServer(QObject *parent) :
    QTcpServer(parent)
{
}
void ClientServer::incomingConnection(int socketDescriptor)//建立新线程
{
    ClientThread *thread = new ClientThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

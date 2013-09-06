#include "clientthread.h"


ClientThread::ClientThread(int socketDescriptor, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor)
{
    blockSize = 0;

}

void ClientThread::run()
{
    tcpSocket = new QTcpSocket;
    if (!tcpSocket->setSocketDescriptor(socketDescriptor))
    {
        emit error(tcpSocket->error());
        return;
    }
    connect(tcpSocket, SIGNAL(readyRead()), this,
        SLOT(readMessage()), Qt::DirectConnection);
    exec();
}

void ClientThread::readMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_6);
    in >> blockSize;
    in >> getDateTime;
    in >> getFromNum;
    in >> getMessage;
    blockSize = 0;
    tcpSocket->close();
}


void ClientThread::sendMessage(QString theString)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);

    out << (quint16)0;
    out << theString;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    tcpSocket->write(block);
}

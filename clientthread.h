#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QtNetwork>

class ClientThread : public QThread
{
public:
    ClientThread();
    Q_OBJECT
public:
    ClientThread(int socketDescriptor, QObject *parent);
    void run();
private:
    int socketDescriptor;
    QTcpSocket *tcpSocket;
    qint16 blockSize;
    qint16 mark;
    QString loginInfo;
    QString getFromNum;
    QString getDateTime;
    QString getMessage;
public slots:
    void readMessage();
    void sendMessage(QString theString);
signals:
    void error(QTcpSocket::SocketError socketError);
};

#endif // CLIENTTHREAD_H

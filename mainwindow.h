#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "clientserver.h"
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString localIP;
    quint16 localPort;
    //quint16 listenPort;
    
private slots:
    void on_teBtn_clicked();
    void on_ibBtn_clicked();
    void on_sbBtn_clicked();
    void on_drBtn_clicked();
    void on_ctBtn_clicked();
    void on_trBtn_clicked();
    void on_text1_textChanged(const QString &arg1);
    void on_text2_textChanged(const QString &arg1);

    void displayError(QAbstractSocket::SocketError socketError);
    void newConnect();
    void readMessage();
    void sendMessage();
    void openListen();

    void on_openBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::MainWindow *ui;

//    QLineEdit *serverIpEdit;
//    QLabel *label;
//    QLineEdit *strEdit;
//    QPushButton *startButton;
    QTcpSocket *tcpClient;
    quint16 blockSize;
    QString telNumber;
    QString readString;
    ClientServer *server;

};

#endif // MAINWINDOW_H

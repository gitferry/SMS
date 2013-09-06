#include "mainwindow.h"
#include "edicttext.h"
#include "ui_mainwindow.h"
#include "sentbox.h"
#include "inbox.h"
#include "stdio.h"
#include "drafts.h"
#include "contactor.h"
#include "trsh.h"
#include "QMessageBox"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->closeBtn->setEnabled(false);
    QRegExp regExp2("[0-9]{11}");                                                   //利用正则表达式来限制输入
    ui->text2->setValidator(new QRegExpValidator(regExp2, this));
    ui->openBtn->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_teBtn_clicked()                                                 //编写信息
{
    EdictText *et = new EdictText(this);
    et->show();
}

void MainWindow::on_ibBtn_clicked()                                                 //收件箱
{
    InBox *ib = new InBox(this);
    ib->show();
}

void MainWindow::on_sbBtn_clicked()                                                 //发件箱
{
    SentBox *sb = new SentBox(this);
    sb->show();
}

void MainWindow::on_drBtn_clicked()
{
    Drafts *dr = new Drafts(this);
    dr->show();
}

void MainWindow::on_ctBtn_clicked()
{
    Contactor *ct = new Contactor(this);
    ct->show();
}

void MainWindow::on_trBtn_clicked()
{
    Trsh *tr = new Trsh(this);
    tr->show();
}

void MainWindow::newConnect()
{
    tcpClient = new QTcpSocket(this);
    connect(tcpClient, SIGNAL(connected()), this, SLOT(sendMessage()));             //连接建立后发送信息
    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(readMessage()));             //有数据来时读取信息
    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)),                 //错误输出
        this, SLOT(displayError(QAbstractSocket::SocketError)));
    //获取本机IP
    blockSize = 0;                                                      //数据块大小初始化
    tcpClient->abort();                                                 //放弃之前的连接
    tcpClient->connectToHost(QHostAddress::LocalHost, 6666);            //发出连接请求
}

void MainWindow::sendMessage()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);                            //以数据流的方式发送数据
    out.setVersion(QDataStream::Qt_4_0);
    telNumber = ui->text2->text();                                           //获取电话号码
    out << (quint32)0;
    out << telNumber;                                                        //本机电话号码
    out << localIP;                                                           //本机IP地址
    out << localPort;                                                        //本进程端口
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));                         //数据流的前两字节用来存储文本块大小
    out << (quint16) 0;
    tcpClient->write(block);
    //tcpClient->close();//发送数据流
}

void MainWindow::readMessage()
{
    QDataStream in(tcpClient);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0)
    {
        if (tcpClient->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }
    if (tcpClient->bytesAvailable() < blockSize)
        return;

    in >> readString;
    ui->label_3->setText(readString);
    tcpClient->close();
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Fortune Client"),
            tr("The host was not found. Please check the "
            "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Fortune Client"),
            tr("The connection was refused by the peer. "
            "Make sure the fortune server is running, "
            "and check that the host name and port "
            "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Fortune Client"),
            tr("The following error occurred: %1.")
            .arg(tcpClient->errorString()));
    }
}

void MainWindow::openListen()
{
    server = new ClientServer(this);
    if (!server->listen(QHostAddress::LocalHost, 8888))//启动监听,并做异常处理
    {
        QMessageBox::critical(this, tr("Threaded Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(server->errorString()));
        close();
        return;
    }
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            localIP = ipAddressesList.at(i).toString();
            break;
        }
    }
    if (localIP.isEmpty())
        localIP = QHostAddress(QHostAddress::LocalHost).toString();
    localPort = server->serverPort();
    ui->closeBtn->setEnabled(true);
}
void MainWindow::on_text1_textChanged(const QString &arg1)
{
    ui->openBtn->setEnabled(ui->text2->hasAcceptableInput());
}

void MainWindow::on_text2_textChanged(const QString &arg1)
{
     ui->openBtn->setEnabled(ui->text2->hasAcceptableInput());
}

void MainWindow::on_openBtn_clicked()
{
    openListen();
    newConnect();
    ui->text1->setEnabled(false);
    ui->text2->setEnabled(false);
    ui->openBtn->setEnabled(false);
}

void MainWindow::on_closeBtn_clicked()
{
    server->close();
    if(!server->isListening())
    {
        ui->openBtn->setEnabled(true);
        ui->closeBtn->setEnabled(false);
        ui->label_3->setText(tr("OFF"));
        ui->text1->setEnabled(true);
        ui->text2->setEnabled(true);
    }
}

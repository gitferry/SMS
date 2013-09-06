#include "edicttext.h"
#include "mainwindow.h"
#include "ui_edicttext.h"
#include "QMessageBox"


EdictText::EdictText(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EdictText)
{
    ui->setupUi(this);
}

EdictText::~EdictText()
{
    delete ui;
}


void EdictText::sendMessage()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);                           //以数据流的方式发送数据
    out.setVersion(QDataStream::Qt_4_6);
    sendContent = ui->plainTextEdit->toPlainText();
    out << (quint32)0;
    localNum = "12345678911";
    QString tonum = "11111111111";
    out << localNum;                                                        //本机电话号码
    out << tonum;                                                              //接收方电话号码
    out << sendContent;                                    //信息内容
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));                        //数据流的前两字节用来存储文本块大小
    out << (quint16) 1;
    tcpClient->write(block);                                                 //发送数据流
    //关闭socket
    QMessageBox::information(this, tr("Congratulations!"),
        tr("Sent Success!"));
}
void EdictText::sendConnect()
{
    tcpClient = new QTcpSocket(this);
    connect(tcpClient, SIGNAL(connected()), this, SLOT(sendMessage()));            //连接建立后发送信息
//    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(readMessage()));             //有数据来时读取信息
//    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)),                 //错误输出
//        this, SLOT(displayError(QAbstractSocket::SocketError)));
    blockSize = 0;                                                            //数据块大小初始化
    tcpClient->abort();                                                       //放弃之前的连接
    tcpClient->connectToHost(QHostAddress::LocalHost, 6666);                  //发出连接请求
//    if(tcpClient-)
//    {
//        //ui->openBtn->setEnabled(false);
//        sendMessage("11111111111");                                                      //发送信息
//    }

}

void EdictText::on_commandLinkButton_clicked()
{
    sendConnect();
    close();
}

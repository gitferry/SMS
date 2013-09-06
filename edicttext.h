#ifndef EDICTTEXT_H
#define EDICTTEXT_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class EdictText;
}

class EdictText : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit EdictText(QWidget *parent = 0);
    ~EdictText();
    
private slots:
    void on_commandLinkButton_clicked();
    void sendConnect();
    void sendMessage();

private:
    Ui::EdictText *ui;
    QTcpSocket *tcpClient;
    quint16 blockSize;
    QString sendContent;
    QString localNum;
};

#endif // EDICTTEXT_H

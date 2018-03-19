#ifndef MYSOCKET_H
#define MYSOCKET_H
#include <QTcpSocket>
#include <QThread>

class MySocket : public QTcpSocket
{
    Q_OBJECT

public:
    MySocket(QObject *parent = NULL);
    ~MySocket();

private slots:
    void onReadyRead();
};

#endif // MYSOCKET_H

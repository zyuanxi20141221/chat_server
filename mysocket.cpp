#include "mysocket.h"

MySocket::MySocket(QObject *parent)
    :QTcpSocket(parent)
{
    printf("MySocket\n");
    connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

MySocket::~MySocket()
{
    printf("~MySocket\n");
    close();
}

void MySocket::onReadyRead()
{
    printf("MySocket::onReadyRead \n");
    char data[1024] = { 0 };
    int len = read(data, 1024);
    printf("len: %d\n", len);
    if(len <= 0)
    {
        printf("MySocket::OnReadyRead() read data failed !\n");
        return;
    }
    printf("Receive data: %s \n", data);
    if(write(data, 1024) <= 0) {
        printf("MySocket::OnReadyRead() write data failed !\n");
    }else {
        waitForBytesWritten(-1);
        printf("send data %s \n", data);
    }
}

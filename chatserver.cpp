#include "chatserver.h"
#include <QHostAddress>

ChatServer::ChatServer(QObject *parent)
     :QTcpServer(parent)
{
    m_mysocket.empty();
}

ChatServer::~ChatServer() {
    qDeleteAll(m_mysocket);
    m_mysocket.clear();
}

void ChatServer::run(qint16 port) {
    if(!this->listen(QHostAddress::Any,port))
    {
        printf("ChatServer listen failed!\n");
        return;
    }
    printf("ChatServer listen success!\n");
}


void ChatServer::incomingConnection(int handle)
{
    printf("incomingConnection(): %d\n", handle);
    MySocket *mysocket = new MySocket(this);
    mysocket->setSocketDescriptor(handle);
    connect(mysocket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    m_mysocket.append(mysocket);
}

void ChatServer::clientDisconnected()
{
    printf("client disconnected! \n");
    QList<MySocket*>::iterator iter;
    for(iter = m_mysocket.begin(); iter!=m_mysocket.end(); iter++)
    {
        if((*iter)->socketDescriptor() == -1)
        {
            m_mysocket.erase(iter);
            return;
        }
    }
}



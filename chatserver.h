#ifndef CHATSERVER_H
#define CHATSERVER_H
#include <QTcpServer>
#include <mysocket.h>

class MySocket;

class ChatServer : public QTcpServer
{
    Q_OBJECT

public:
    ChatServer(QObject *parent = NULL);
    ~ChatServer();
    void run(qint16 port);

protected:
    void incomingConnection(qintptr handle);

private slots:
   void clientDisconnected();

private:
    quint16 m_port;
    QList<MySocket *> m_mysocket;
};

#endif // CHATSERVER_H

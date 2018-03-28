#include <QCoreApplication>
#include <chatserver.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ChatServer server;
    server.run(63308);
    return a.exec();
}

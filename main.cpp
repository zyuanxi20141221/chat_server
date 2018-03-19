#include <QCoreApplication>
#include <chatserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ChatServer server;
    server.run(33333);
    return a.exec();
}

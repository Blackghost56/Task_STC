#include "server.h"

Server::Server(const quint16 port, QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    if(!server->listen(QHostAddress::Any, port)){
        qDebug() << "\nWeb server could not start";
        qDebug() << server->errorString();
        exit(0);
    } else {
        qDebug() << "\nWeb server is waiting for a connection on port: " << port;
    }
    connect(server, &QTcpServer::newConnection, this, &Server::newConnection);
}

Server::~Server()
{
    server->close();
}

void Server::newConnection()
{
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            [=](QAbstractSocket::SocketError socketError){ qDebug() << socketError; qDebug() << "Error string:" << socket->errorString();});
}

void Server::readyRead()
{
    QByteArray req = socket->readAll();
    qDebug() << "Request: " << req;

    QByteArray data;
    data.push_back(QString::number(QRandomGenerator::global()->generate()).toLatin1());

    // Headers
    socket->write("HTTP/1.1 200 OK\r\n");       // \r needs to be before \n
    QLocale locale(QLocale::English);
    socket->write(QString("Date: " + locale.toString(QDateTime::currentDateTimeUtc()) + "\r\n").toLatin1());
    socket->write("Content-Type: text/html\r\n");
    socket->write(QString("Content-length: " + QString::number(data.length()) + "\r\n").toLatin1());
    socket->write("Connection: close\r\n");
    socket->write("\r\n");

    socket->write(data);
    socket->flush();

    socket->disconnectFromHost();
}

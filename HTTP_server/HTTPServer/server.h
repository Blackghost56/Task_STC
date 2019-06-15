#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QRandomGenerator>
#include <QDateTime>


class Server : public QObject
{
    Q_OBJECT
private:
    QTcpServer *server;
    QTcpSocket *socket;
public:
    explicit Server(const quint16 port, QObject *parent = nullptr);
    ~Server();

signals:

private slots:
    void newConnection();
    void readyRead();

public slots:
};

#endif // SERVER_H

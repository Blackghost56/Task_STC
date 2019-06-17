#ifndef WINCHECK_H
#define WINCHECK_H

#include <QObject>
#include <QVector>
#include "enum.h"
#include <QDebug>

class WinCheck : public QObject
{
    Q_OBJECT
private:
    int victorySize;
    int size;
    int begin = -1;
    int end = -1;

public:
    explicit WinCheck(const int size, const int victorySize, QObject *parent = nullptr);
    void setVictorySize(const int victorySize);
    bool check(const QVector<qint8> &data, const qint8 player);
    bool checkMoves(const QVector<qint8> &data);
    void getBeginEnd(int &begin, int &end);

signals:

public slots:
};

#endif // WINCHECK_H

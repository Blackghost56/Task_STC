#ifndef PLAYERVSAIS_H
#define PLAYERVSAIS_H

#include <QObject>
#include <QRandomGenerator>
#include "playingfield.h"
#include "wincheck.h"

class PlayerVsAIS : public QObject
{
    Q_OBJECT
private:
    int size;
    int victorySize;
    qint8 playerSymbol;
    qint8 AISymbol;
    PlayingField *playField;
    WinCheck *checker;

    int AI(QVector<qint8> &cellState, qint8 player);
    QVector<int> emptyIndex(QVector<qint8> &cellState);

public:
    explicit PlayerVsAIS(PlayingField *field, const int size, const int victorySize, const qint8 playerSymbol, QObject *parent = nullptr);
    ~PlayerVsAIS();

signals:
    void endGame();

public slots:

private slots:
    void cellPressedV(QVector<qint8> cellState, qint8 player);

};

#endif // PLAYERVSAIS_H

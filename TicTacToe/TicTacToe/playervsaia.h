#ifndef PLAYERVSAIA_H
#define PLAYERVSAIA_H

#include <QObject>
#include <QRandomGenerator>
#include "playingfield.h"
#include "wincheck.h"

class PlayerVsAIA : public QObject
{
    Q_OBJECT
private:
    int maxSize = 10000;
    int size;
    int victorySize;
    int depthAI;
    qint8 playerSymbol;
    qint8 AISymbol;
    PlayingField *playField;
    WinCheck *checker;

    int AI(QVector<qint8> &cellState, qint8 player);
    int miniMax(QVector<qint8> &cell, int depth, bool isMax);
    int miniMax(QVector<qint8> &cell, int depth, bool isMax, int alpha, int beta);
    int evaluate(QVector<qint8> &cell);

public:
    explicit PlayerVsAIA(PlayingField *field, const int size, const int victorySize, const qint8 playerSymbol, const int depth, QObject *parent = nullptr);
    ~PlayerVsAIA();

signals:
    void endGame();

public slots:

private slots:
    void cellPressedV(QVector<qint8> cellState, qint8 player);

};

#endif // PLAYERVSAIA_H

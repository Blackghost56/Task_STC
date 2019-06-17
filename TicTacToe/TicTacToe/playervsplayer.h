#ifndef PLAYERVSPLAYER_H
#define PLAYERVSPLAYER_H

#include <QObject>
#include "playingfield.h"
#include "wincheck.h"

class PlayerVsPlayer : public QObject
{
    Q_OBJECT
private:
    int size;
    int victorySize;
    PlayingField *playField;
    WinCheck *checker;

public:
    explicit PlayerVsPlayer(PlayingField *field, const int size, const int victorySize, QObject *parent = nullptr);
    ~PlayerVsPlayer();

signals:
    void endGame();

private slots:
    void cellPressedV(QVector<qint8> cellState, qint8 player);

};

#endif // PLAYERVSPLAYER_H

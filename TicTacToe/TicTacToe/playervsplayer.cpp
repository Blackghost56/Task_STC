#include "playervsplayer.h"

PlayerVsPlayer::PlayerVsPlayer(PlayingField *field, const int size, const int victorySize, QObject *parent) : QObject(parent)
{
    this->size = size;
    this->victorySize = victorySize;
    this->playField = field;

    checker = new WinCheck(size, victorySize, this);

    playField->setActivePlayer(CROSS);
    connect(playField, &PlayingField::cellPressedV, this, &PlayerVsPlayer::cellPressedV);
}

PlayerVsPlayer::~PlayerVsPlayer()
{

}

void PlayerVsPlayer::cellPressedV(QVector<qint8> cellState, qint8 player)
{
    if (player == CROSS)
    {
        bool st = checker->check(cellState, player);
        if (st){
            int begin;
            int end;
            checker->getBeginEnd(begin, end);
            playField->drawWin(begin, end, "Player 1 win!");
            emit endGame();
        }
        if (checker->checkMoves(cellState)){
            playField->drawStandoff("Standoff!");
            emit endGame();
            return;
        }
        playField->setActivePlayer(ZERO);
    } else if (player == ZERO) {
        bool st = checker->check(cellState, player);
        if (st){
            int begin;
            int end;
            checker->getBeginEnd(begin, end);
            playField->drawWin(begin, end, "Player 2 win!");
            emit endGame();
        }
        if (checker->checkMoves(cellState)){
            playField->drawStandoff("Standoff!");
            emit endGame();
            return;
        }
        playField->setActivePlayer(CROSS);
    }
}


#include "playervsais.h"


PlayerVsAIS::PlayerVsAIS(PlayingField *field, const int size, const int victorySize, const qint8 playerSymbol, QObject *parent) : QObject(parent)
{
    this->size = size;
    this->victorySize = victorySize;
    this->playField = field;
    this->playerSymbol = playerSymbol;

    checker = new WinCheck(size, victorySize, this);

    if (playerSymbol == ZERO){
        AISymbol = CROSS;
        QVector<qint8> vec;
        vec.resize(size * size);
        playField->setCell(AI(vec, AISymbol), AISymbol);
        playField->setActivePlayer(playerSymbol);
    } else {
        AISymbol = ZERO;
        playField->setActivePlayer(playerSymbol);
    }
    connect(playField, &PlayingField::cellPressedV, this, &PlayerVsAIS::cellPressedV);
}

PlayerVsAIS::~PlayerVsAIS()
{

}

void PlayerVsAIS::cellPressedV(QVector<qint8> cellState, qint8 player)
{
    playField->disable();
    bool st = checker->check(cellState, player);
    if (st){
        int begin;
        int end;
        checker->getBeginEnd(begin, end);
        playField->drawWin(begin, end, "You win!");
        emit endGame();
        return;
    }
    if (checker->checkMoves(cellState)){
        playField->drawStandoff("Standoff!");
        emit endGame();
        return;
    }
    playField->setCell(AI(cellState, AISymbol), AISymbol);
    st = checker->check(cellState, AISymbol);
    if (st){
        int begin;
        int end;
        checker->getBeginEnd(begin, end);
        playField->drawWin(begin, end, "You lose!");
        emit endGame();
    }
    if (checker->checkMoves(cellState)){
        playField->drawStandoff("Standoff!");
        emit endGame();
        return;
    }
    playField->enable();
}

int PlayerVsAIS::AI(QVector<qint8> &cellState, qint8 player)
{
    int random = int(QRandomGenerator::global()->bounded(quint32(size * size)));
    bool flag = true;
    while (flag){
        if ((cellState.at(random) != playerSymbol) && (cellState.at(random) != AISymbol)){
           flag = false;
           cellState[random] = AISymbol;
           return random;
        }
        random = int(QRandomGenerator::global()->bounded(quint32(size * size)));
    }
    return 0;
}

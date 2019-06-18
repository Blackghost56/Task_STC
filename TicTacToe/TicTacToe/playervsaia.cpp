#include "playervsaia.h"


PlayerVsAIA::PlayerVsAIA(PlayingField *field, const int size, const int victorySize, const qint8 playerSymbol, const int depth, QObject *parent) : QObject(parent)
{
    this->size = size;
    this->victorySize = victorySize;
    this->playField = field;
    this->playerSymbol = playerSymbol;
    this->depthAI = depth;

    checker = new WinCheck(size, victorySize, this);

    if (playerSymbol == ZERO){
        AISymbol = CROSS;
        int random = int(QRandomGenerator::global()->bounded(size * size));
        playField->setCell(random, AISymbol);
        playField->setActivePlayer(playerSymbol);
    } else {
        AISymbol = ZERO;
        playField->setActivePlayer(playerSymbol);
    }
    connect(playField, &PlayingField::cellPressedV, this, &PlayerVsAIA::cellPressedV);
}

PlayerVsAIA::~PlayerVsAIA()
{

}

void PlayerVsAIA::cellPressedV(QVector<qint8> cellState, qint8 player)
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
        return;
    }
    if (checker->checkMoves(cellState)){
        playField->drawStandoff("Standoff!");
        emit endGame();
        return;
    }
    playField->enable();
}


int PlayerVsAIA::AI(QVector<qint8> &cellState, qint8 player)
{
    QVector<qint8> cell(cellState);
    int bestVal = -maxSize;
    int bestMove = -1;
    int moveVal;
    int alpha = bestVal;
    int beta = -bestVal;

    for (int i = 0; i < cell.size(); i++)
    {
        if (cell.at(i) == NOPE)
        {
            cell[i] = AISymbol;
            //moveVal = miniMax(cell, 0, false);
            moveVal = miniMax(cell, 0, false, alpha, beta);
            cell[i] = NOPE;
            if (moveVal > bestVal)
            {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    if (bestMove >= 0)
        cellState[bestMove] = AISymbol;
    return bestMove;
}

int PlayerVsAIA::miniMax(QVector<qint8> &cell, int depth, bool isMax)
{
    //static int count = 0;
    //qDebug() << count++;

    int score = evaluate(cell);

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (depth > depthAI)
        return score;

    if (checker->checkMoves(cell) == true)
        return 0;
    int buf;

    if (isMax)
    {
        int best = -maxSize;
        for (int i = 0; i < cell.size(); i++)
        {
            if (cell.at(i) == NOPE)
            {
                cell[i] = AISymbol;
                buf = miniMax(cell, depth + 1, !isMax);
                if (best < buf){
                    best = buf;
                }
                cell[i] = NOPE;
            }
        }
        return best;
    } else     {
        int best = maxSize;
        for (int i = 0; i < cell.size(); i++)
        {
            if (cell.at(i) == NOPE)
            {
                cell[i] = playerSymbol;
                buf = miniMax(cell, depth + 1, !isMax);
                if (best > buf){
                    best = buf;
                }
                cell[i] = NOPE;
            }
        }
        return best;
    }
}

int PlayerVsAIA::miniMax(QVector<qint8> &cell, int depth, bool isMax, int alpha, int beta)
{
    //static int count = 0;
    //qDebug() << count++;

    int score = evaluate(cell);

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (depth > depthAI)
        return score;

    if (checker->checkMoves(cell) == true)
        return 0;
    int buf;

    if (isMax)
    {
        int best = alpha;
        for (int i = 0; i < cell.size(); i++)
        {
            if (cell.at(i) == NOPE)
            {
                cell[i] = AISymbol;
                buf = miniMax(cell, depth + 1, !isMax, -alpha, -beta);
                if (best < buf){
                    best = buf;
                }
                cell[i] = NOPE;
                if (best >= beta)
                    return best;
            }
        }
        return best;
    } else     {
        int best = beta;
        for (int i = 0; i < cell.size(); i++)
        {
            if (cell.at(i) == NOPE)
            {
                cell[i] = playerSymbol;
                buf = miniMax(cell, depth + 1, !isMax, -alpha, -beta);
                if (best > buf){
                    best = buf;
                }
                cell[i] = NOPE;
                if (best <= alpha)
                    return best;
            }
        }
        return best;
    }
}

int PlayerVsAIA::evaluate(QVector<qint8> &cell)
{
    if(checker->check(cell, AISymbol)){
        return 10;
    } else if (checker->check(cell, playerSymbol)) {
        return -10;
    }
    return 0;
}

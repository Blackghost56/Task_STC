#include "wincheck.h"

WinCheck::WinCheck(const int size, const int victorySize, QObject *parent) : QObject(parent)
{
    this->victorySize = victorySize;
    this->size = size;
}

void WinCheck::setVictorySize(const int victorySize)
{
    this->victorySize = victorySize;
}

bool WinCheck::check(const QVector<qint8> &data, const quint8 player)
{
    int x;
    int y ;
    bool flag;

    for (int i = 0; i < data.size(); i++) {
        x = i % size;
        y = i / size;
        if (data.at(i) == player){
            if ((x + victorySize) <= size){                                         // -
                flag = true;
                for (int j = 1; j < victorySize; j++) {
                    if (data.at(i + j) != player){
                        flag = false;
                        break;
                    }
                }
                if (flag == true){
                    begin = i;
                    end = i + victorySize - 1;
                    return true;
                }
            }

            if ((y + victorySize) <= size){                                         // |
                flag = true;
                for (int j = 1; j < victorySize; j++) {
                    if (data.at(i + (j * size)) != player){
                        flag = false;
                        break;
                    }
                }
                if (flag == true){
                    begin = i;
                    end = i + (victorySize - 1) * size;
                    return true;
                }
            }

            if (((y + victorySize) <= size) && ((x + victorySize) <= size)){        // \.
                flag = true;
                for (int j = 1; j < victorySize; j++) {
                    if (data.at(i + (j * size) + j) != player){
                        flag = false;
                        break;
                    }
                }
                if (flag == true){
                    begin = i;
                    end = i + (victorySize - 1) * size + (victorySize - 1);
                    return true;
                }
            }

            if (((y + victorySize) <= size) && ((x - (victorySize - 1)) >= 0)){     // /
                flag = true;
                for (int j = 1; j < victorySize; j++) {
                    if (data.at(i + (j * size) - j) != player){
                        flag = false;
                        break;
                    }
                }
                if (flag == true){
                    begin = i;
                    end = i + (victorySize - 1) * size - (victorySize - 1);
                    return true;
                }
            }
        }
    }
    return false;
}

void WinCheck::getBeginEnd(int &begin, int &end)
{
    begin = this->begin;
    end = this->end;
}

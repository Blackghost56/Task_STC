#ifndef LOGICINTERFACE_H
#define LOGICINTERFACE_H

//#include <QObject>

//class LogicInterface : public QObject
class LogicInterface
{
private:

public:
    //explicit LogicInterface(const int size, const int victorySize, QObject *parent = nullptr);
    //LogicInterface(const int size, const int victory_size);
    //LogicInterface(const int size, const int victory_size);
    virtual ~LogicInterface() = default;



//    void setSize(const int n);
//    void enable();
//    void disable();
//    void clear();
//    void setCell(const int cell, const qint8 state);
//    void setCellActivePlayer(const int cell);
//    void setActivePlayer(const qint8 player);
//    void drawWin(const int beginCell, const int endCell, const QString &str);

//signals:
//      void ActivePlayerChange(const quint8 activePlayer);

//public slots:
//      void cellPressed(int cell);
      //    void cellPressed(int cell, qint8 state);
      //    void cellPressedV(QVector<qint8> cellState);
};

#endif // LOGICINTERFACE_H

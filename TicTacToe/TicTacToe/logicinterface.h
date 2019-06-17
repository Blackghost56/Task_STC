#ifndef LOGICINTERFACE_H
#define LOGICINTERFACE_H

//#include <QObject>

//class LogicInterface : public QObject
class LogicInterface
{
private:

public:
    //explicit LogicInterface(const int size, const int victorySize, QObject *parent = nullptr);

    virtual ~LogicInterface() = default;

//signals:
//      void ActivePlayerChange(const quint8 activePlayer);

//public slots:
//      void cellPressed(int cell);
      //    void cellPressed(int cell, qint8 state);
      //    void cellPressedV(QVector<qint8> cellState);
};

#endif // LOGICINTERFACE_H

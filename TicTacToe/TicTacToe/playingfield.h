#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "enum.h"

class PlayingField : public QWidget
{
    Q_OBJECT
private:
    enum STATE_ENUM: bool {ENABLE = true, DISABLE = false};
    bool state = DISABLE;
    QVector<qint8> cellState = {NOPE, NOPE, NOPE, // default all cell empty
                                NOPE, NOPE, NOPE ,
                                NOPE, NOPE, NOPE };
    int size = 3;
    qint8 activePlayer = NOPE;
    QString text = " ";
    int winBeginCell = 0;
    int winEndCell = 0;
    bool winDraw = false;
    bool drawTextF = false;

    void drawCell(QPainter &paint, const qreal x1, const qreal y1, const qreal x2, const qreal y2, const qreal borderScale, const qint8 state);
    void drawWin(QPainter &painter);
    void drawText(QPainter &painter);


public:
    explicit PlayingField(QWidget *parent = nullptr);

    void setSize(const int n);
    void enable();
    void disable();
    void clear();
    void setCell(const int cell, const qint8 state);
    void setCellActivePlayer(const int cell);
    void setActivePlayer(const qint8 player);
    void drawWin(const int beginCell, const int endCell, const QString &str);
    void drawStandoff(const QString &str);

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *event);

signals:
    void cellPressed(int cell);
    void cellPressed(int cell, qint8 player);
    void cellPressedV(QVector<qint8> cellState, qint8 player);

public slots:
};

#endif // PLAYINGFIELD_H

#include "playingfield.h"

PlayingField::PlayingField(QWidget *parent) : QWidget(parent)
{

}

void PlayingField::setSize(const int n)
{
    size = n;
    cellState.clear();
    cellState.resize(size * size);
    repaint();
}

void PlayingField::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::blue, 3));

    // vertical line
    for (int i = 1; i < size; i++){
        painter.drawLine(QPointF(i * width() / size, 0), QPointF(i * width() / size, height()));
    }
    // ---------

    // horizontal line
    for (int i = 1; i < size; i++){
        painter.drawLine(QPointF(0, i * height() / size), QPointF(width(), i * height() / size));
    }
    // ---------

    // cell fill
    int count = 0;
    for (int y = 0; y < size; y++){
        for (int x = 0; x < size; x++){
            drawCell(painter, x * width() / size, y * height() / size, (x + 1) * width() / size, (y + 1) * height() / size, 0.04, cellState.at(count));
            count++;
        }
    }
    // ---------

    // win
    if(winDraw)
        drawWin(painter);
    // ---------
    if(drawTextF)
        drawText(painter);

    painter.end();
}

void PlayingField::drawCell(QPainter &paint, const qreal x1, const qreal y1, const qreal x2, const qreal y2, const qreal borderScale, const qint8 state)
{
    qreal border_x = borderScale * width();
    qreal border_y = borderScale * height();
    qreal bx1 = x1 + border_x;
    qreal by1 = y1 + border_y;
    qreal bx2 = x2 - border_x;
    qreal by2 = y2 - border_y;

    switch (state) {
    case ZERO:
        paint.drawEllipse(QRectF(bx1, by1, bx2 - bx1, by2 - by1));
        break;
    case CROSS:
        paint.drawLine(QPointF(bx1, by1), QPointF(bx2, by2));
        paint.drawLine(QPointF(bx1, by2), QPointF(bx2, by1));
        break;
    }
}

void PlayingField::drawWin(QPainter &painter)
{
    int cell_w = width() / size;
    int cell_h = height() / size;
    int halfCell_w = cell_w / 2;
    int halfCell_h = cell_h / 2;

    int x1 = cell_w * (winBeginCell % size);
    int y1 = cell_h * (winBeginCell / size);
    int x2 = cell_w * (winEndCell % size);
    int y2 = cell_h * (winEndCell / size);

    painter.setPen(QPen(QColor(200, 0, 0), 5));
    painter.drawLine(QPointF(x1 + halfCell_w, y1 + halfCell_h), QPointF(x2 + halfCell_w, y2 + halfCell_h));   
}

void PlayingField::drawText(QPainter &painter)
{
    painter.setPen(QPen(Qt::red, 4));
    int font_size_def = 10;
    QFont font("Helvetica [Cronyx]", font_size_def, QFont::Normal);
    QFontMetrics fm(font);
    double coeff = double(width()) / double(fm.width(text));
    font.setPointSize(int(coeff * font_size_def));
    fm = QFontMetrics(font);
    painter.setFont(font);
    painter.drawText(QPointF((width() - fm.width(text)) / 2, height() / 2), text);
}

void PlayingField::mousePressEvent(QMouseEvent *event)
{
    if (state == ENABLE)
    {
        int cellColumn = event->x() * size / width();
        int cellRow = event->y() * size / height();
        int num = (cellRow * size) + cellColumn;
        if ((num < 0) && (num >= cellState.size()))
            return;
        if (cellState.at(num) == NOPE){
            cellState[num] = activePlayer;
            repaint();
            emit cellPressed(num);
            emit cellPressed(num, activePlayer);
            emit cellPressedV(cellState, activePlayer);
        }
    }
}

void PlayingField::enable()
{
    state = ENABLE;
}

void PlayingField::disable()
{
    state = DISABLE;
}

void PlayingField::clear()
{
    for (int i = 0; i < cellState.size(); i++)
        cellState[i] = NOPE;
    winDraw = false;
    drawTextF = false;
    repaint();
}

void PlayingField::setCell(const int cell, const qint8 state)
{
    if ((cell >= 0) && (cell < cellState.size()))
        cellState[cell] = state;
    repaint();
}

void PlayingField::setCellActivePlayer(const int cell)
{
    if ((cell >= 0) && (cell < cellState.size()))
        cellState[cell] = activePlayer;
    repaint();
}

void PlayingField::setActivePlayer(const qint8 player)
{
    activePlayer = player;
}

void PlayingField::drawWin(const int beginCell, const int endCell, const QString &str)
{
    text = str;
    winBeginCell = beginCell;
    winEndCell = endCell;
    winDraw = true;
    drawTextF = true;
    repaint();
}

void PlayingField::drawStandoff(const QString &str)
{
    text = str;
    drawTextF = true;
    repaint();
}

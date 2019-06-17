#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "playingfield.h"
#include "enum.h"
#include <QDebug>
#include "wincheck.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_start_pushButton_clicked();

    void on_stop_pushButton_clicked();

    void on_fild_size_spinBox_valueChanged(int arg1);

    void cellPressedV(QVector<qint8> cellState);

private:
    Ui::MainWidget *ui;
    int defaultSize = 4;
};

#endif // MAINWIDGET_H

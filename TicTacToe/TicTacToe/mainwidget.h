#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "playingfield.h"
#include "enum.h"
#include <QDebug>
#include "wincheck.h"
#include "playervsplayer.h"
#include "playervsais.h"

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

    void on_mode_radioButton_1_clicked(bool checked);

    void on_mode_radioButton_2_clicked(bool checked);

    void on_mode_radioButton_3_clicked(bool checked);

    void on_FM_radioButton_1_clicked(bool checked);

    void on_FM_radioButton_2_clicked(bool checked);

private:
    enum FIRST_MOVE_ENUM: qint8 {PLAYER = 1, PC = 2};
    Ui::MainWidget *ui;
    int defaultSize = 4;
    FIRST_MOVE_ENUM firstPlayer = PLAYER;
    PlayerVsPlayer  *playerVsPlayer = nullptr;
    PlayerVsAIS     *playerVsAIs = nullptr;
};

#endif // MAINWIDGET_H

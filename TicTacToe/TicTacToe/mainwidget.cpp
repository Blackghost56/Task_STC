#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    ui->stop_pushButton->setEnabled(false);

    ui->fild_size_spinBox->setValue(defaultSize);
    ui->fild_size_spinBox->setMinimum(3);
    ui->play_field_widget->setSize(defaultSize);
    ui->VC_spinBox->setValue(defaultSize);
    ui->VC_spinBox->setMinimum(3);
    ui->VC_spinBox->setMaximum(ui->fild_size_spinBox->value());
    //ui->play_field_widget->setCell(2, 1);
    //ui->play_field_widget->setCell(4, 2);
    //ui->play_field_widget->clear();
    //ui->play_field_widget->setActivePlayer(PlayingField::CROSS);
    //ui->play_field_widget->setCellActivePlayer(3);
    //ui->play_field_widget->drawWin(0, 3, "Player 1 win!");
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_start_pushButton_clicked()
{
    ui->mode_groupBox->setEnabled(false);
    ui->fild_size_spinBox->setEnabled(false);
    ui->fild_size_label->setEnabled(false);
    ui->VC_label->setEnabled(false);
    ui->VC_spinBox->setEnabled(false);
    ui->start_pushButton->setEnabled(false);
    ui->stop_pushButton->setEnabled(true);
    ui->play_field_widget->enable();
    ui->play_field_widget->clear();
}

void MainWidget::on_stop_pushButton_clicked()
{
    ui->mode_groupBox->setEnabled(true);
    ui->fild_size_spinBox->setEnabled(true);
    ui->fild_size_label->setEnabled(true);
    ui->VC_label->setEnabled(true);
    ui->VC_spinBox->setEnabled(true);
    ui->start_pushButton->setEnabled(true);
    ui->stop_pushButton->setEnabled(false);
    ui->play_field_widget->disable();
}

void MainWidget::on_fild_size_spinBox_valueChanged(int arg1)
{
    ui->play_field_widget->setSize(arg1);
    ui->play_field_widget->clear();
    ui->VC_spinBox->setMaximum(arg1);
    if (ui->VC_spinBox->value() > arg1)
        ui->VC_spinBox->setValue(arg1);
}

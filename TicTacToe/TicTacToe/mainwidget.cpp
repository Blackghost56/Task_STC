#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    ui->stop_pushButton->setEnabled(false);
    ui->mode_radioButton_1->setChecked(true);
    ui->FM_radioButton_1->setChecked(true);
    ui->fild_size_spinBox->setValue(defaultSize);
    ui->fild_size_spinBox->setMinimum(minSizeDef);
    ui->fild_size_spinBox->setMaximum(maxSizeDef);
    ui->play_field_widget->setSize(defaultSize);
    ui->VC_spinBox->setValue(defaultSize);
    ui->VC_spinBox->setMinimum(minSizeDef);
    ui->VC_spinBox->setMaximum(ui->fild_size_spinBox->value());
    ui->FM_groupBox->setVisible(false);
    ui->difficulty_label->setVisible(false);
    ui->difficulty_spinBox->setVisible(false);
    ui->difficulty_spinBox->setMinimum(minDifficulty);
    ui->difficulty_spinBox->setMaximum(maxDifficulty);
    ui->difficulty_spinBox->setValue(defaultDifficulty);
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
    ui->FM_groupBox->setEnabled(false);
    ui->difficulty_label->setEnabled(false);
    ui->difficulty_spinBox->setEnabled(false);
    ui->play_field_widget->enable();
    ui->play_field_widget->clear();

    if (ui->mode_radioButton_1->isChecked()){
        playerVsPlayer = new PlayerVsPlayer(ui->play_field_widget, ui->fild_size_spinBox->value(), ui->VC_spinBox->value(), this);
        connect(playerVsPlayer, &PlayerVsPlayer::endGame, ui->stop_pushButton, &QPushButton::click);
    }
    if (ui->mode_radioButton_2->isChecked()){
        playerVsAIs = new PlayerVsAIS(ui->play_field_widget, ui->fild_size_spinBox->value(), ui->VC_spinBox->value(), firstPlayer, this);
        connect(playerVsAIs, &PlayerVsAIS::endGame, ui->stop_pushButton, &QPushButton::click);
    }
    if (ui->mode_radioButton_3->isChecked()){
        playerVsAIa = new PlayerVsAIA(ui->play_field_widget, ui->fild_size_spinBox->value(), ui->VC_spinBox->value(), firstPlayer,
                                      ui->difficulty_spinBox->value(), this);
        connect(playerVsAIa, &PlayerVsAIA::endGame, ui->stop_pushButton, &QPushButton::click);
    }
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
    ui->FM_groupBox->setEnabled(true);
    ui->difficulty_label->setEnabled(true);
    ui->difficulty_spinBox->setEnabled(true);
    ui->play_field_widget->disable();

    if (playerVsPlayer != nullptr){
        delete playerVsPlayer;
        playerVsPlayer = nullptr;
    }
    if (playerVsAIs != nullptr){
        delete playerVsAIs;
        playerVsAIs = nullptr;
    }
    if (playerVsAIa != nullptr){
        delete playerVsAIa;
        playerVsAIa = nullptr;
    }
}

void MainWidget::on_fild_size_spinBox_valueChanged(int arg1)
{
    ui->play_field_widget->setSize(arg1);
    ui->play_field_widget->clear();
    ui->VC_spinBox->setMaximum(arg1);
    if (ui->VC_spinBox->value() > arg1)
        ui->VC_spinBox->setValue(arg1);
}

void MainWidget::on_mode_radioButton_1_clicked(bool checked)
{
    if (checked == true){
        ui->FM_groupBox->setVisible(false);
        ui->difficulty_label->setVisible(false);
        ui->difficulty_spinBox->setVisible(false);
    }
    ui->fild_size_spinBox->setMaximum(maxSizeDef);
    ui->VC_spinBox->setMaximum(maxSizeDef);
}

void MainWidget::on_mode_radioButton_2_clicked(bool checked)
{
    if (checked == true){
        ui->FM_groupBox->setVisible(true);
        ui->difficulty_label->setVisible(false);
        ui->difficulty_spinBox->setVisible(false);
    }
    ui->fild_size_spinBox->setMaximum(maxSizeDef);
    ui->VC_spinBox->setMaximum(maxSizeDef);
}

void MainWidget::on_mode_radioButton_3_clicked(bool checked)
{
    if (checked == true){
        ui->FM_groupBox->setVisible(true);
        ui->difficulty_label->setVisible(true);
        ui->difficulty_spinBox->setVisible(true);
    }
    ui->fild_size_spinBox->setMaximum(maxSizeAdv);
    if (ui->fild_size_spinBox->value() > maxSizeAdv)
        ui->fild_size_spinBox->setValue(maxSizeAdv);
    ui->VC_spinBox->setMaximum(maxSizeAdv);
    if (ui->VC_spinBox->value() > maxSizeAdv)
        ui->VC_spinBox->setValue(maxSizeAdv);
}

void MainWidget::on_FM_radioButton_1_clicked(bool checked)
{
    if (checked == true)
        firstPlayer = PLAYER;
}

void MainWidget::on_FM_radioButton_2_clicked(bool checked)
{
    if (checked == true)
        firstPlayer = PC;
}

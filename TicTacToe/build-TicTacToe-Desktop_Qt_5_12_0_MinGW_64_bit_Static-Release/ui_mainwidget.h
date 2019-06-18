/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "playingfield.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *menu_groupBox;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QPushButton *start_pushButton;
    QPushButton *stop_pushButton;
    QGroupBox *mode_groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *mode_radioButton_1;
    QRadioButton *mode_radioButton_2;
    QRadioButton *mode_radioButton_3;
    QFormLayout *formLayout;
    QLabel *fild_size_label;
    QSpinBox *fild_size_spinBox;
    QLabel *VC_label;
    QSpinBox *VC_spinBox;
    QGroupBox *FM_groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *FM_radioButton_1;
    QRadioButton *FM_radioButton_2;
    QSpacerItem *verticalSpacer;
    PlayingField *play_field_widget;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(532, 420);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWidget->sizePolicy().hasHeightForWidth());
        MainWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(MainWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        menu_groupBox = new QGroupBox(MainWidget);
        menu_groupBox->setObjectName(QString::fromUtf8("menu_groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(menu_groupBox->sizePolicy().hasHeightForWidth());
        menu_groupBox->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(menu_groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        start_pushButton = new QPushButton(menu_groupBox);
        start_pushButton->setObjectName(QString::fromUtf8("start_pushButton"));
        start_pushButton->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(start_pushButton, 0, 0, 1, 1);

        stop_pushButton = new QPushButton(menu_groupBox);
        stop_pushButton->setObjectName(QString::fromUtf8("stop_pushButton"));
        stop_pushButton->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(stop_pushButton, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        mode_groupBox = new QGroupBox(menu_groupBox);
        mode_groupBox->setObjectName(QString::fromUtf8("mode_groupBox"));
        verticalLayout = new QVBoxLayout(mode_groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mode_radioButton_1 = new QRadioButton(mode_groupBox);
        mode_radioButton_1->setObjectName(QString::fromUtf8("mode_radioButton_1"));
        mode_radioButton_1->setChecked(true);

        verticalLayout->addWidget(mode_radioButton_1);

        mode_radioButton_2 = new QRadioButton(mode_groupBox);
        mode_radioButton_2->setObjectName(QString::fromUtf8("mode_radioButton_2"));

        verticalLayout->addWidget(mode_radioButton_2);

        mode_radioButton_3 = new QRadioButton(mode_groupBox);
        mode_radioButton_3->setObjectName(QString::fromUtf8("mode_radioButton_3"));

        verticalLayout->addWidget(mode_radioButton_3);


        verticalLayout_3->addWidget(mode_groupBox);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        fild_size_label = new QLabel(menu_groupBox);
        fild_size_label->setObjectName(QString::fromUtf8("fild_size_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, fild_size_label);

        fild_size_spinBox = new QSpinBox(menu_groupBox);
        fild_size_spinBox->setObjectName(QString::fromUtf8("fild_size_spinBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, fild_size_spinBox);

        VC_label = new QLabel(menu_groupBox);
        VC_label->setObjectName(QString::fromUtf8("VC_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, VC_label);

        VC_spinBox = new QSpinBox(menu_groupBox);
        VC_spinBox->setObjectName(QString::fromUtf8("VC_spinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, VC_spinBox);


        verticalLayout_3->addLayout(formLayout);

        FM_groupBox = new QGroupBox(menu_groupBox);
        FM_groupBox->setObjectName(QString::fromUtf8("FM_groupBox"));
        verticalLayout_2 = new QVBoxLayout(FM_groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        FM_radioButton_1 = new QRadioButton(FM_groupBox);
        FM_radioButton_1->setObjectName(QString::fromUtf8("FM_radioButton_1"));

        verticalLayout_2->addWidget(FM_radioButton_1);

        FM_radioButton_2 = new QRadioButton(FM_groupBox);
        FM_radioButton_2->setObjectName(QString::fromUtf8("FM_radioButton_2"));

        verticalLayout_2->addWidget(FM_radioButton_2);


        verticalLayout_3->addWidget(FM_groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(menu_groupBox);

        play_field_widget = new PlayingField(MainWidget);
        play_field_widget->setObjectName(QString::fromUtf8("play_field_widget"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(play_field_widget->sizePolicy().hasHeightForWidth());
        play_field_widget->setSizePolicy(sizePolicy2);
        play_field_widget->setMinimumSize(QSize(350, 350));

        horizontalLayout->addWidget(play_field_widget);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", nullptr));
        menu_groupBox->setTitle(QString());
        start_pushButton->setText(QApplication::translate("MainWidget", "Start game", nullptr));
        stop_pushButton->setText(QApplication::translate("MainWidget", "Stop game", nullptr));
        mode_groupBox->setTitle(QApplication::translate("MainWidget", "Mode", nullptr));
        mode_radioButton_1->setText(QApplication::translate("MainWidget", "Two players", nullptr));
        mode_radioButton_2->setText(QApplication::translate("MainWidget", "Simple AI", nullptr));
        mode_radioButton_3->setText(QApplication::translate("MainWidget", "Advanced AI", nullptr));
        fild_size_label->setText(QApplication::translate("MainWidget", "Field size:", nullptr));
        VC_label->setText(QApplication::translate("MainWidget", "Victory condition:", nullptr));
        FM_groupBox->setTitle(QApplication::translate("MainWidget", "First move", nullptr));
        FM_radioButton_1->setText(QApplication::translate("MainWidget", "Player", nullptr));
        FM_radioButton_2->setText(QApplication::translate("MainWidget", "PC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H

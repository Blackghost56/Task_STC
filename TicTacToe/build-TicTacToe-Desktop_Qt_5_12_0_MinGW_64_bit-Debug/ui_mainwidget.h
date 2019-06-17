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
    QVBoxLayout *verticalLayout_2;
    QGroupBox *mode_groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *mode_radioButton;
    QRadioButton *mode_radioButton_2;
    QRadioButton *mode_radioButton_3;
    QFormLayout *fild_size_formLayout;
    QLabel *fild_size_label;
    QSpinBox *fild_size_spinBox;
    QFormLayout *VC_formLayout;
    QLabel *VC_label;
    QSpinBox *VC_spinBox;
    QPushButton *start_pushButton;
    QPushButton *stop_pushButton;
    QSpacerItem *verticalSpacer;
    PlayingField *play_field_widget;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(485, 325);
        horizontalLayout = new QHBoxLayout(MainWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        menu_groupBox = new QGroupBox(MainWidget);
        menu_groupBox->setObjectName(QString::fromUtf8("menu_groupBox"));
        verticalLayout_2 = new QVBoxLayout(menu_groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        mode_groupBox = new QGroupBox(menu_groupBox);
        mode_groupBox->setObjectName(QString::fromUtf8("mode_groupBox"));
        verticalLayout = new QVBoxLayout(mode_groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mode_radioButton = new QRadioButton(mode_groupBox);
        mode_radioButton->setObjectName(QString::fromUtf8("mode_radioButton"));
        mode_radioButton->setChecked(true);

        verticalLayout->addWidget(mode_radioButton);

        mode_radioButton_2 = new QRadioButton(mode_groupBox);
        mode_radioButton_2->setObjectName(QString::fromUtf8("mode_radioButton_2"));

        verticalLayout->addWidget(mode_radioButton_2);

        mode_radioButton_3 = new QRadioButton(mode_groupBox);
        mode_radioButton_3->setObjectName(QString::fromUtf8("mode_radioButton_3"));

        verticalLayout->addWidget(mode_radioButton_3);


        verticalLayout_2->addWidget(mode_groupBox);

        fild_size_formLayout = new QFormLayout();
        fild_size_formLayout->setSpacing(6);
        fild_size_formLayout->setObjectName(QString::fromUtf8("fild_size_formLayout"));
        fild_size_label = new QLabel(menu_groupBox);
        fild_size_label->setObjectName(QString::fromUtf8("fild_size_label"));

        fild_size_formLayout->setWidget(0, QFormLayout::LabelRole, fild_size_label);

        fild_size_spinBox = new QSpinBox(menu_groupBox);
        fild_size_spinBox->setObjectName(QString::fromUtf8("fild_size_spinBox"));

        fild_size_formLayout->setWidget(0, QFormLayout::FieldRole, fild_size_spinBox);


        verticalLayout_2->addLayout(fild_size_formLayout);

        VC_formLayout = new QFormLayout();
        VC_formLayout->setSpacing(6);
        VC_formLayout->setObjectName(QString::fromUtf8("VC_formLayout"));
        VC_label = new QLabel(menu_groupBox);
        VC_label->setObjectName(QString::fromUtf8("VC_label"));

        VC_formLayout->setWidget(0, QFormLayout::LabelRole, VC_label);

        VC_spinBox = new QSpinBox(menu_groupBox);
        VC_spinBox->setObjectName(QString::fromUtf8("VC_spinBox"));

        VC_formLayout->setWidget(0, QFormLayout::FieldRole, VC_spinBox);


        verticalLayout_2->addLayout(VC_formLayout);

        start_pushButton = new QPushButton(menu_groupBox);
        start_pushButton->setObjectName(QString::fromUtf8("start_pushButton"));

        verticalLayout_2->addWidget(start_pushButton);

        stop_pushButton = new QPushButton(menu_groupBox);
        stop_pushButton->setObjectName(QString::fromUtf8("stop_pushButton"));

        verticalLayout_2->addWidget(stop_pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addWidget(menu_groupBox);

        play_field_widget = new PlayingField(MainWidget);
        play_field_widget->setObjectName(QString::fromUtf8("play_field_widget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(play_field_widget->sizePolicy().hasHeightForWidth());
        play_field_widget->setSizePolicy(sizePolicy);
        play_field_widget->setMinimumSize(QSize(200, 200));

        horizontalLayout->addWidget(play_field_widget);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", nullptr));
        menu_groupBox->setTitle(QString());
        mode_groupBox->setTitle(QApplication::translate("MainWidget", "Mode", nullptr));
        mode_radioButton->setText(QApplication::translate("MainWidget", "Two players", nullptr));
        mode_radioButton_2->setText(QApplication::translate("MainWidget", "Simple AI", nullptr));
        mode_radioButton_3->setText(QApplication::translate("MainWidget", "Advanced AI", nullptr));
        fild_size_label->setText(QApplication::translate("MainWidget", "Field size:", nullptr));
        VC_label->setText(QApplication::translate("MainWidget", "Victory condition:", nullptr));
        start_pushButton->setText(QApplication::translate("MainWidget", "Start game", nullptr));
        stop_pushButton->setText(QApplication::translate("MainWidget", "Stop game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H

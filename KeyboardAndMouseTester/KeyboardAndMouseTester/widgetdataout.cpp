#include "widgetdataout.h"
#include "ui_widgetdataout.h"

WidgetDataOut::WidgetDataOut(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetDataOut)
{
    ui->setupUi(this);
}

WidgetDataOut::~WidgetDataOut()
{
    delete ui;
}

void WidgetDataOut::setLabel(const QString &str)
{
    ui->label->setText(str);
}

void WidgetDataOut::setText(const QString &str)
{
    ui->text->setText(str);
}

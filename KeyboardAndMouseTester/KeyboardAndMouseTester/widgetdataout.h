#ifndef WIDGETDATAOUT_H
#define WIDGETDATAOUT_H

#include <QWidget>

namespace Ui {
class WidgetDataOut;
}

class WidgetDataOut : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetDataOut(QWidget *parent = nullptr);
    ~WidgetDataOut();
    void setLabel(const QString &str);
    void setText(const QString &str);

private:
    Ui::WidgetDataOut *ui;
};

#endif // WIDGETDATAOUT_H

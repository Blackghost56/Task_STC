#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    keyBoard = new WidgetDataOut(this);
    keyBoard->setLabel(tr("Number pressed: "));
    keyBoard->setText("[-]");
    ui->toolBar->addWidget(keyBoard);

    ui->toolBar->addSeparator();

    mouse = new WidgetDataOut(this);
    mouse->setLabel(tr("Mouse clicked: "));
    mouse->setText("[X: -; Y: -]");
    ui->toolBar->addWidget(mouse);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if ((key >= Qt::Key_0) && (key <= Qt::Key_9)) {
        if (event->modifiers() == Qt::NoModifier)
            keyBoard->setText("[" + QString(QChar(key)) + "]");
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mouse->setText("[X: " + QString::number(event->x()) + "; Y: " + QString::number(event->y()) + "]");
}

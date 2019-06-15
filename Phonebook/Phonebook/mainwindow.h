#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_find_pushButton_clicked();
    void on_add_pushButton_clicked();
    void on_delete_pushButton_clicked();
    void on_find_lineEdit_returnPressed();
    void itemChanged(QStandardItem *item);

private:
    Ui::MainWindow *ui;
    QLabel  *status;
    QStandardItemModel *model;
    QStandardItemModel *model_buf = nullptr;
    QList<QStandardItem*> findList;

    QStringList horizontalHeader  = { tr("Full Name"), tr("Phone number") };
    QStringList verticalHeader;
    const QString statusAdd = {tr("Record added")};
    const QString statusDelete = {tr("Record deleted")};
    const QString fileName = "autosave.json";

    void find();
    void load();
    void save();
};

#endif // MAINWINDOW_H

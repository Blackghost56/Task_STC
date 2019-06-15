#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    status = new QLabel;
    ui->statusBar->addWidget(status);

    //ui->add_number_lineEdit->setInputMask("+9-999-999-99-99");

    model = new QStandardItemModel;
    connect(model, &QStandardItemModel::itemChanged, this, &MainWindow::itemChanged);

    model->setHorizontalHeaderLabels(horizontalHeader);
    model->setVerticalHeaderLabels(verticalHeader);

    load();

    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

MainWindow::~MainWindow()
{
    save();
    delete ui;
}

void MainWindow::on_find_pushButton_clicked()
{
    find();
}

void MainWindow::on_add_pushButton_clicked()
{
    int newRow = model->rowCount();
    QString str = ui->add_name_lineEdit->text();
    model->setItem(newRow, 0, new QStandardItem(str));
    model->setItem(newRow, 1, new QStandardItem(ui->add_number_lineEdit->text()));
    status->setText(tr("Record '") + str + tr("' added"));
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_delete_pushButton_clicked()
{
    int selectRow = ui->tableView->currentIndex().row();
    if (selectRow < 0)
        return;
    QString str;
    if (ui->tableView->model() == model){
        if (!(selectRow < model->rowCount()))
            return;
        str = model->item(selectRow)->text();
        model->removeRow(selectRow);
    } else {
        if (!(selectRow < findList.size()))
            return;
        str = findList.at(selectRow)->text();
        model->removeRow(findList.at(selectRow)->row());
        model_buf->removeRow(selectRow);
    }
    status->setText(tr("Record '") + str + tr("' deleted"));
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_find_lineEdit_returnPressed()
{
    find();
}

void MainWindow::itemChanged(QStandardItem *item)
{
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::find()
{
    QString str = ui->find_lineEdit->text();
    if (str == ""){
        ui->tableView->setModel(model);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        status->setText("");
        return;
    }
    //QList<QStandardItem*> list = model->findItems(str, Qt::MatchStartsWith, 0);
    findList = model->findItems(str, Qt::MatchContains, 0);

    if (model_buf != nullptr)
        delete model_buf;
    model_buf = new QStandardItemModel;
    model_buf->setHorizontalHeaderLabels(horizontalHeader);
    model_buf->setVerticalHeaderLabels(verticalHeader);

    int count = 0;
    int size = findList.size();
    if (size == 0){
        ui->tableView->setModel(model);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        status->setText("'" + str + "'" + tr(" not found"));
        return;
    }
    for (int i = 0; i < size; i++){
        model_buf->setItem(count, 0, new QStandardItem(findList.at(i)->text()));
        model_buf->setItem(count, 1, new QStandardItem(model->item(findList.at(i)->row(), findList.at(i)->column() + 1)->text()));
        count++;
        //qDebug() << list.at(i)->column() << "\t" << list.at(i)->row();
    }
    ui->tableView->setModel(model_buf);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    status->setText(tr("Found %1 item(s)").arg(count));
}

void MainWindow::load()
{
    QFile jsonFile(QDir::currentPath() + "/" + fileName);
    if (!jsonFile.open(QIODevice::ReadOnly))
    {
        status->setText(tr("Error open database"));
        return;
    }

    QByteArray data = jsonFile.readAll();
    jsonFile.close();
    QJsonDocument jsonDocument(QJsonDocument::fromJson(data));
    QJsonObject jObject;
    jObject = jsonDocument.object();

    int count = 0;
    for (auto it = jObject.begin(); it != jObject.end(); it++ ){
        model->setItem(count, 0, new QStandardItem(QString(it.key())));
        if (it.value().isString())
            model->setItem(count, 1, new QStandardItem(it.value().toString()));
        count++;
    }
    status->setText(tr("Load %1 item(s)").arg(count));
}

void MainWindow::save()
{
    QJsonObject jObject;
    for (int i = 0; i < model->rowCount(); i++){
        jObject[model->item(i, 0)->text()] = model->item(i, 1)->text();
    }

    QFile jsonFile(QDir::currentPath() + "/" + fileName);
    if (!jsonFile.open(QIODevice::WriteOnly))
    {
        return;
    }
    jsonFile.write(QJsonDocument(jObject).toJson(QJsonDocument::Indented));
    jsonFile.close();
}



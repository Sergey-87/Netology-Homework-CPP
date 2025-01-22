#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Widgets");

    ui->progressBar->setMaximum(100);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setFormat("%p%");
    ui->progressBar->setValue(0);

    ui->comboBox->addItem("Строка1");
    ui->comboBox->addItem("Строка2");
    ui->comboBox->addItem("Строка3");
    ui->comboBox->addItem("Строка4");
    ui->comboBox->addItem("Строка5");

    ui->pushButton->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


// void MainWindow::on_pushButton_clicked()
// {
//     int currentValue = ui->progressBar->value();
//     if(currentValue < 100)
//     {
//         ui->progressBar->setValue(currentValue + 10);
//     }
//     else
//     {
//         ui->progressBar->setValue(0);
//     }
// }


void MainWindow::on_pushButton_toggled(bool checked)
{
    int currentValue = ui->progressBar->value();
    if(currentValue < 100)
    {
        ui->progressBar->setValue(currentValue + 10);
    }
    else
    {
        ui->progressBar->setValue(0);
    }
}


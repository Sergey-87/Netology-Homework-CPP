#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Секундомер");
    watch = new Stopwatch(this);

    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setText("0:00");
    ui->pushButton_2->setText("Сбросить");
    ui->pushButton_3->setText("Круг");
    ui->pushButton->setText("Старт");
    ui->pushButton_3->setEnabled(false);
    ui->pushButton->setCheckable(true);

    connect(watch, &Stopwatch::sig_UpdateTime, this, &MainWindow::ReceiveTime);
    connect(this, &MainWindow::sig_Circle, watch, &Stopwatch::ReceiveCircle);
    connect(this, &MainWindow::sig_Clear, watch, &Stopwatch::ReceiveClear);
    connect(this, &MainWindow::sig_Start, watch, &Stopwatch::StartTimer);
    connect(this, &MainWindow::sig_Stop, watch, &Stopwatch::StopTimer);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ReceiveTime(QString &text)
{
    ui->label->setText(text);
}


void MainWindow::on_pushButton_toggled(bool checked) {
    if (checked) {
        ui->pushButton->setText("Стоп");
        ui->pushButton_3->setEnabled(true);
        emit sig_Start();

    } else {
        ui->pushButton->setText("Старт");
        ui->pushButton_3->setEnabled(false);
        emit sig_Stop();
    }
}


void MainWindow::on_pushButton_3_clicked() {
    emit sig_Circle();
    QString text = watch->GetCircleTime();
    ui->textBrowser->append(text);
}


void MainWindow::on_pushButton_2_clicked() {
    ui->textBrowser->clear();
    ui->label->setText("00:00");
    emit sig_Clear();
}

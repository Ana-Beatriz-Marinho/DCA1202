#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    //Quando o botão "Connect" é selecionado, a função tcpConnect é chamada

    connect(ui->pushButtonConnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpConnect()));

    connect(ui->pushButtonDisconnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpDisconnect()));

    connect(ui->horizontalSliderTiming,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setIntervaloTemp()));

    connect(ui->pushButtonStart,
            SIGNAL(clicked(bool)),
            this,
            SLOT(StartTemp()));

    connect(ui->pushButtonStop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(StopTemp()));

    connect(contTemp,
            SIGNAL(timeout()),
            this,
            SLOT(putData()));

}

void MainWindow::tcpConnect(){
    socket->connectToHost(ui->lineEditIP->text(), 1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
        conexao("Connected\n");
    }
    else{
        qDebug() << "Disconnect";
        conexao("Disconnected\n");
    }
}

void MainWindow::tcpDisconnect(){
    socket->disconnectFromHost();
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
        conexao("Connected\n");
    }
    else{
        qDebug() << "Disconnect";
        conexao("Disconnected\n");
    }
    contTemp->stop();
}

void MainWindow::setIntervaloTemp(){
    ui->textBrowser->setText(info);
    QScrollBar *q = ui->textBrowser->verticalScrollBar();
    q->setValue(q->maximum());
}

void MainWindow::StartTemp(){
    if(socket->waitForConnected(0)){
        contTemp->start(ui->horizontalSliderTiming->value()*1000);
    }
}

void MainWindow::StopTemp(){
    contTemp->stop();
}

void MainWindow::atualizaBrowse(QString s){
    info.append(s);
    ui->textBrowser->setText(info);
    QScrollBar *qsb = ui->textBrowser->verticalScrollBar();
    qsb->setValue(qsb->maximum());
}

void MainWindow::conexao(QString a){
    ui->labelConection->setText(a);
}

void MainWindow::putData(){
    QDateTime datetime;
    QString str;
    qint64 msecdate;


    if(socket->state()== QAbstractSocket::ConnectedState){
        int valorMin = ui->horizontalSliderMin->value();
        int valorMax = ui->horizontalSliderMax->value();

        if(valorMax<valorMin){
            int aux = valorMax;
            valorMax = valorMin;
            valorMin = aux;
        }

        if(socket->state()== QAbstractSocket::ConnectedState){

            int inter = (valorMax-valorMin)+valorMin;

            msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
            str = "set "+ QString::number(msecdate) + " " + QString::number(qrand()%inter)+"\r\n";

        }

    }
    atualizaBrowse(str);
    qDebug() << str;
    qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
    if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
    }
}

MainWindow::~MainWindow(){
    delete socket;
    delete ui;
    delete contTemp;
}

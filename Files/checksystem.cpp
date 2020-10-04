//#include "mainwindow.h"

//#include "QApplication"
#include "checksystem.h"
#include "ui_checksystem.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <QTimer>

#include <QPlainTextEdit>

using namespace std;

int valueOfProgress;
QTimer *timer = new QTimer();
CheckSystem::CheckSystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CheckSystem)
{
    setWindowFlags(Qt::FramelessWindowHint |Qt::WindowStaysOnTopHint); //Flaga okienka na wierzchu.
    ui->setupUi(this);
    setWindowTitle("Check System");
    //setFocus(true);
    //setAttribute(Qt::WA_ShowWithoutActivating);




    init();
//    MainWindow w;
//    w.show();

}

CheckSystem::~CheckSystem()
{
    delete ui;
}

void CheckSystem::updateProgress()
{
    QTextEdit *txt = new QTextEdit();

    QString txt1 = "Tworze katalogi";
    QString txt2 = "Tworze puste pliki Bazy Danych";
    QString txt3 = "Wypełniam Bazę Danych";
    QString txt4 = "Tworze cos tam przy 60";
    QString txt5 = "Tworze cos tam przy 80";
    QString txt6 = "Skonczone";

    ui->progressBar->setValue(ui->progressBar->value() + 1);
    valueOfProgress = ui->progressBar->value();
    if (valueOfProgress == 10) {
        cout << txt1.toStdString() << endl;
        ui->textEdit->setText(txt1);
        txt->append(txt1);


    } else if (valueOfProgress == 20) {

        ui->textEdit->append(txt2);
        txt->append(txt2);
        cout << txt2.toStdString() << endl;
    } else if (valueOfProgress == 40) {

        ui->textEdit->append(txt3);
        txt->append(txt3);
    } else if (valueOfProgress == 60) {

        ui->textEdit->append(txt4);
        txt->append(txt4);
    } else if (valueOfProgress == 80) {

        ui->textEdit->append(txt5);
        txt->append(txt5);
    } else if (valueOfProgress >= 100) {

        ui->textEdit->append(txt6);
        txt->append(txt6);
        cout << txt6.toStdString() << endl;
        timer->stop();
        (this->close());


        //exit(0);
        return;
    }
}
void CheckSystem::init()
{ /*QTextEdit *txt = new QTextEdit();*/
    cout << "Jestem w checksytme i w progress barze" << endl;

    ui->progressBar->setValue(0);
    //QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &CheckSystem::updateProgress);
    timer->start(100);
    //timer->stop();
}
//Info do Gita
void CheckSystem::on_pushButton_clicked()
{
    destroy();
}

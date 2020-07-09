#include "kontrahentshow.h"
#include "ui_kontrahentshow.h"
#include <iostream>
#include <String>
#include<QString>



using namespace std;



KontrahentShow::KontrahentShow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KontrahentShow)
{
    ui->setupUi(this);

    cout<<"Jestem w Kontrahebt show"<<endl;
}

KontrahentShow::KontrahentShow(QString pierwszazmienna)
{
    wyswietl(pierwszazmienna);
}

KontrahentShow::~KontrahentShow()
{
    delete ui;
}

void KontrahentShow::on_pushButton_2_clicked()
{
    destroy();
}

QString KontrahentShow::wyswietl (QString pierwszazmienna)
{
    //TODO: Przechwycic nazwe kontrahenta z KontrhanetLista

    cout<<"Chche wysiwretlic i dopisac do labeli wybranego kontrahenta"<<endl;
    cout<<"Pierwsa zmienne to :" <<pierwszazmienna.toStdString()<<endl;
    ui->label->setText(pierwszazmienna);
}

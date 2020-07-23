#include "kontrahentshow.h"
#include "ui_kontrahentshow.h"
#include <String>
#include <iostream>
#include <ostream>
#include <QString>

using namespace std;

QString tab[13];

KontrahentShow::KontrahentShow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentShow)
{
    ui->setupUi(this);

    cout << "Jestem w Kontrahebt show" << endl;
}

//KontrahentShow::KontrahentShow(QString pierwszazmienna)
//{
//    wyswietl(pierwszazmienna);
//}

KontrahentShow::~KontrahentShow()
{
    delete ui;
}

void KontrahentShow::on_pushButton_2_clicked()
{
    destroy();
}

QVariant KontrahentShow::wyswietl(QVariant p1,
                                  QVariant p2,
                                  QVariant p3,
                                  QVariant p4,
                                  QVariant p5,
                                  QVariant p6,
                                  QVariant p7,
                                  QVariant p8,
                                  QVariant p9,
                                  QVariant p10,
                                  QVariant p11,
                                  QVariant p12,
                                  QVariant p13)
{


    cout << "Chche wysiwretlic i dopisac do labeli wybranego kontrahenta" << endl;
    //cout<<"Pierwsa zmienne to :" +pierwsza.toString()<<endl;
    //ui->le->setText(pierwsza.toString());
    //ui->label_2->setText(druga.toString());

    ui->leNazwa->setText(p1.toString());
    ui->leImie->setText(p2.toString());
    ui->leNazwisko->setText(p3.toString());
    ui->leKraj->setText(p4.toString());
    ui->leRegion->setText(p5.toString());
    ui->leMiasto->setText(p6.toString());
    ui->leKod->setText(p7.toString());
    ui->leUlica->setText(p8.toString());
    ui->leNrDomu->setText(p9.toString());
    ui->leTelefon->setText(p10.toString());
    ui->leTelPryw->setText(p11.toString());
    ui->leEmail->setText(p12.toString());
    ui->leUrl->setText(p13.toString());
}
//Info do Gita
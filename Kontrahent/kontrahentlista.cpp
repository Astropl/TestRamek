#include "kontrahentlista.h"
#include "ui_kontrahentlista.h"
#include "tableviewlistakontrahentow.h"
#include <Info/info.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QString>
#include <QTimer>
#include <QTableView>
#include <QtWidgets>
#include <QApplication>

using namespace std;
time_t czasKontrahentLista;
tm timeinfoKontrahentLista;
int labelGodzinaKontrahentLista;
int labelDataKontrahentLista;
int wynikKontrahentLista;
int godzinaKontrahentLista, minutaKontrahentLista, sekundaKontrahentLista, dzienKontrahentLista, miesiacKontrahentLista, rokKontrahentLista;
int dzienTygodniaKontrahentLista;
string stringDzienTygodniaKontrahentLista;
string zmiennasKontrahentLista;

fstream plikczasKontrahentLista;

KontrahentLista::KontrahentLista(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KontrahentLista)
{
    ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================

    // Tworze modele do Qtable
    model = new QStandardItemModel (8,6,this);
    ui->tableView->setModel(model);
QModelIndex index;

    // Generate data
//    for(int row = 0; row < 4; row++)
//    {
//        for(int col = 0; col < 2; col++)
//        {

//            // 0 for all data
//            model->setData(index,0);
//        }
//    }
model->index(0,3,QModelIndex());
model->setData(index,"rujyeh"); // Index to połozenie rzedu i kolumny
//model->index(1,2,QModelIndex());
//model->setData(index,"drugi rzad i 3 kolumna");
//model->setItem(1,3,index);
//model->setData()
model->setHeaderData(0,Qt::Horizontal, "lp");
model->setHeaderData(1,Qt::Horizontal, "Nazwa");
model->setHeaderData(2,Qt::Horizontal, "Miasto");
model->setHeaderData(3,Qt::Horizontal, "Kod Pocztowy");
model->setHeaderData(4,Qt::Horizontal, "Telefon");


    //==========================
}

KontrahentLista::~KontrahentLista()
{
    delete ui;
}
void KontrahentLista::myfunctiontimer()
{
    time(&czasKontrahentLista);
    timeinfoKontrahentLista = *localtime(&czasKontrahentLista);
    godzinaKontrahentLista = timeinfoKontrahentLista.tm_hour;
    minutaKontrahentLista = timeinfoKontrahentLista.tm_min;
    sekundaKontrahentLista = timeinfoKontrahentLista.tm_sec;
    dzienKontrahentLista = timeinfoKontrahentLista.tm_mday;
    miesiacKontrahentLista = timeinfoKontrahentLista.tm_mon;
    rokKontrahentLista = timeinfoKontrahentLista.tm_year;
    dzienTygodniaKontrahentLista = timeinfoKontrahentLista.tm_wday;
    miesiacKontrahentLista = miesiacKontrahentLista + 1;
    rokKontrahentLista = rokKontrahentLista + 1900;

    zmianaLabela(godzinaKontrahentLista, minutaKontrahentLista, sekundaKontrahentLista, dzienKontrahentLista, miesiacKontrahentLista, rokKontrahentLista, dzienTygodniaKontrahentLista);
}
int KontrahentLista::zmianaLabela(
    int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia)
{
    // Dodoać zera do sekund gdy mniej niz 10
    QString qStrMin = QString::number(minuta);
    QString qStrGodz = QString::number(godzina);
    QString qStrSek = QString::number(sekunda);
    QString qStrDzien = QString::number( dzien);
    QString qStrMiesiac = QString::number(miesiac);
    if (sekunda<10)
    {
        qStrSek = "0"+QString::number(sekunda);
    }
    if (minuta <10)
    {
        qStrMin = "0"+QString::number(minuta);
    }
    if (godzina<10)
    {
        qStrGodz = "0"+QString::number(godzina);
    }
    if (miesiac <10)
    {
        qStrMiesiac = "0"+QString::number(miesiac);
    }
    if (dzien <10)
    {
        qStrDzien = "0"+QString::number(dzien);
    }


    ui->labelZegara->setText(qStrGodz + ":" + qStrMin + ":" + qStrSek);
    ui->labelDaty->setText(QString::number(rok) + "." + qStrMiesiac + "."
                           + qStrDzien);
    switch (dzienTygodnia) {
    case 1:
        stringDzienTygodniaKontrahentLista = "Poniedziałek";
        break;
    case 2:
        stringDzienTygodniaKontrahentLista = "Wtorek";
        break;
    case 3:
        stringDzienTygodniaKontrahentLista = "Środa";
        break;
    case 4:
        stringDzienTygodniaKontrahentLista = "Czwartek";
        break;
    case 5:
        stringDzienTygodniaKontrahentLista = "Piątek";
        break;
    case 6:
        stringDzienTygodniaKontrahentLista = "Sobota";
        break;
    case 0:
        stringDzienTygodniaKontrahentLista = "Niedziela";
        break;
    }
    ui->labelDzien->setText((stringDzienTygodniaKontrahentLista).c_str());
    return 1;
}


void KontrahentLista::on_pushButton_2_clicked()
{
    destroy();
}

void KontrahentLista::on_tableView_activated(const QModelIndex )
{
    //ui->tableView->set
//    QTableView listaKontrahentów;

//  TableViewListaKontrahentow myModel(0);
//  listaKontrahentów.setModel(&myModel);
//  listaKontrahentów.show();




}











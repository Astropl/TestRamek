#include "urzadzenialista.h"
#include "ui_urzadzenialista.h"
#include "Timery/timedate.h"
#include <Info/info.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include <QTableView>
#include <QTimer>
#include <QtWidgets>









using namespace std;
fstream fileUrzadzeniaLista;

UrzadzeniaLista::UrzadzeniaLista(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UrzadzeniaLista)
{
    ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================


    wczytajDane();

}

UrzadzeniaLista::~UrzadzeniaLista()
{
    delete ui;
}


void UrzadzeniaLista::wczytajDane()
{
    model = new QStandardItemModel(1, 5, this);
    ui->tableView->setModel(model);
    //QModelIndex *index;

    model->setHeaderData(0, Qt::Horizontal, "L.P.");
    model->setHeaderData(1, Qt::Horizontal, "Producent");
    model->setHeaderData(2, Qt::Horizontal, "Model");
    model->setHeaderData(3, Qt::Horizontal, "Nr Seryjny");
    model->setHeaderData(4, Qt::Horizontal, "Kontrahent");
    //    model->setHeaderData(5, Qt::Horizontal, "Region");
    //    model->setHeaderData(6, Qt::Horizontal, "Miasto");
    //    model->setHeaderData(7, Qt::Horizontal, "Kod Pocztowy");
    //    model->setHeaderData(8, Qt::Horizontal, "Ulica");
    //    model->setHeaderData(9, Qt::Horizontal, "Nr domu/mieszkania");
    //    model->setHeaderData(10, Qt::Horizontal, "Telefon");
    //    model->setHeaderData(11, Qt::Horizontal, "Telefon prywatny");
    //    model->setHeaderData(12, Qt::Horizontal, "Adres E-mail");
    //    model->setHeaderData(13, Qt::Horizontal, "Strona URL")
    //---------------------------------------------------------------
    ui->tableView->setColumnHidden(0,true); //Ukrywam kolumne z LP
     //---------------------------------------------------------------
    QStandardItem *dodajItem = new QStandardItem("Jakies cos");
fileUrzadzeniaLista.open("C:/Defaults/Pliki/Urzadzenie.txt", ios::in);
if (fileUrzadzeniaLista.good() == false)
{
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
 }
 string linia;
 int row = 0;
 int nr_lini = 0; // zmiana z int nr_lini = 1;
 while (getline(fileUrzadzeniaLista, linia)) {
     dodajItem = new QStandardItem(linia.c_str());

     {
         model->setItem(row, nr_lini, dodajItem); //row, nr_lini - 2, dodajItem
     }

     cout << linia.c_str() << endl;
     nr_lini++;
     if (nr_lini > 3) {
         row = row + 1;
         nr_lini = 0;
     }
 }

 fileUrzadzeniaLista.close();

 int rowDoSize = model->rowCount();
 for (int i = 0; i <= rowDoSize; i++) {
     ui->tableView->setRowHeight(i, 20);
 }
 ui->tableView->horizontalHeader()->setSectionResizeMode(
     QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
 ui->tableView->sortByColumn(0,
                             Qt::SortOrder(0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy

 //ui->tableView->setRowHeight(1,20);
 //ui->tableView->setRowHeight(2,20);
 //ui->tableView->setRowHeight(3,20);
 iloscWierszy();



}

void UrzadzeniaLista::iloscWierszy()
{
    int iloscWierszy = model->rowCount();
    QString qIloscWierszy;
    qIloscWierszy.setNum(iloscWierszy);
    ui->labelTest->setText("Ilosć Urządzeń: " + qIloscWierszy);
    cout << iloscWierszy;
}
void UrzadzeniaLista::myfunctiontimer()
{
    time_t czas;
    tm timeinfo;
    QString qStrMin, qStrGodz, qStrSek, qStrDzien, qStrMiesiac, stringDzienTygodnia;

    TimeDate *timeDate = new TimeDate();

    time(&czas);
    timeinfo = *localtime(&czas);
    int godzina = timeinfo.tm_hour;
    int minuta = timeinfo.tm_min;
    int sekunda = timeinfo.tm_sec;
    int dzien = timeinfo.tm_mday;
    int miesiac = timeinfo.tm_mon;
    int rok = timeinfo.tm_year;
    int dzienTygodnia = timeinfo.tm_wday;
    miesiac = miesiac + 1;
    rok = rok + 1900;
    dzienTygodnia = dzienTygodnia + 1;

    qStrMin = timeDate->changeStringsMin(minuta);
    qStrSek = timeDate->changeStringsSek(sekunda);
    qStrDzien = timeDate->changeStringsDzien(dzien);
    qStrGodz = timeDate->changeStringsGodz(godzina);
    qStrMiesiac = timeDate->changeStringsMiesiac(miesiac);
    stringDzienTygodnia = timeDate->changeStringsDzienTygodnia(dzienTygodnia);

    ui->labelZegara->setText(qStrGodz + ":" + qStrMin + ":" + qStrSek);
    ui->labelDaty->setText(QString::number(rok) + "." + qStrMiesiac + "." + qStrDzien);

    ui->labelDzien->setText(stringDzienTygodnia);


}
void UrzadzeniaLista::on_pushButton_clicked()
{
    //Odswiez
}

void UrzadzeniaLista::on_pushButton_2_clicked()
{
    //Zamknij
    destroy();

}

void UrzadzeniaLista::on_pushButton_3_clicked()
{
    //Usuń
}

void UrzadzeniaLista::on_pushButton_4_clicked()
{
    //Edytuj
}

void UrzadzeniaLista::on_pushButton_5_clicked()
{
    //Zapisz
}

#include "Baza.h"
#include "QApplication"
#include "Timery/timedate.h"
//#include "time.h"
#include "ui_pierwsza.h"
#include "Kontrahent/kontrahentinfo.h"
#include <Info/info.h>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <QString>
#include <QTimer>
#include <QTableView>
#include <QtWidgets>
#include <fstream>

using namespace std;

//int labelGodzinaPierwsza;
//int labelDataPierwsza;
//int wynikPierwsza;


fstream fileDataBase;


Pierwsza::Pierwsza(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pierwsza)
{
    ui->setupUi(this);
    ui->labelZegara->setText(" cos tam");
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    QString file1 = "C:/Defaults/Pliki/1.DB.txt";
    QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
    QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
    QString file4 = "C:/Defaults/Pliki/4.ZapisKraj.txt";
    QString file5 = "C:/Defaults/Pliki/5.ZapisMiasta.txt";
    QString file6 = "C:/Defaults/Pliki/6.ZapisWojewodztwa.txt";
    QString file7 = "C:/Defaults/Pliki/7.ZapisProducenta.txt";
    QString file8 = "C:/Defaults/Pliki/8.ZapisModel.txt";
    QString file9 = "C:/Defaults/Pliki/9.ZapisNrSeryjny.txt";
    QString file10 = "C:/Defaults/Pliki/10.CheckFlagsInMiasto.txt";
    QString file11 = "C:/Defaults/Pliki/11.CheckFlagsInKraj.txt";
    QString file12 = "C:/Defaults/Pliki/12.CheckFlagsInWojewodztwa.txt";
    QString file13 = "C:/Defaults/Pliki/13.CheckFlagsInKrajKontrahentShow.txt";
    QString file14 = "C:/Defaults/Pliki/14.CheckFlagsInMiastoKontrahentShow.txt";
    QString file15 = "C:/Defaults/Pliki/15.CheckFlagsInWojewodztwoKontrahentShow.txt";

    wczytajDane();

}
    void Pierwsza::wczytajDane()
    {
QString file1 = "C:/Defaults/Pliki/1.DB.txt";
        // Tworze modele do Qtable

        model = new QStandardItemModel(1, 19, this); //było 14
        ui->tableViewDB->setModel(model);
        //QModelIndex *index;
        model->setHeaderData(0, Qt::Horizontal, "L.P.");
        model->setHeaderData(1, Qt::Horizontal, "Producent"); //nazwa
        model->setHeaderData(2, Qt::Horizontal, "Model"); // Imie
        model->setHeaderData(3, Qt::Horizontal, "Nr Seryjny"); // Imie
         model->setHeaderData(4, Qt::Horizontal, "Przypisany ?"); // Imie
          //model->setHeaderData(5, Qt::Horizontal, "Nr Seryjny"); // Imie

        model->setHeaderData(5, Qt::Horizontal, "LP Kontrahenta"); //Nazwisko
        model->setHeaderData(6, Qt::Horizontal, "Nazwa");//Kraj
        model->setHeaderData(7, Qt::Horizontal, "Imie");//Region
        model->setHeaderData(8, Qt::Horizontal, "Nazwisko");//Miasto
        model->setHeaderData(9, Qt::Horizontal, "Kraj");//Kod Pocztowy
        model->setHeaderData(10, Qt::Horizontal, "Region");//Ulica
        model->setHeaderData(11, Qt::Horizontal, "Miasto");//Nr domu/mieszkania
        model->setHeaderData(12, Qt::Horizontal, "Kod Pocztowy");//Telefon
        model->setHeaderData(13, Qt::Horizontal, "Ulica");//Telefon prywatny
        model->setHeaderData(14, Qt::Horizontal, "Nr domu/mieszkania");//Adres E-mail
        model->setHeaderData(15, Qt::Horizontal, "Telefon");//Strona URL
        model->setHeaderData(16, Qt::Horizontal, "Telefon prywatny");//Telefon prywatny
        model->setHeaderData(17, Qt::Horizontal, "Adres E-mail");//Adres E-mail
        model->setHeaderData(18, Qt::Horizontal, "Strona URL");//Strona URL




        //    setSelectionBehavior(QAbstractItemView::SelectRows);
        //    setSelectionMode(QAbstractItemView::SingleSelection);
        //---------------------------------------------------------------
        ui->tableViewDB->setColumnHidden(0, true); //Ukrywam kolumne z LP urzadzenia
        ui->tableViewDB->setColumnHidden(4, true); // Ukrywam Kolumnę z info o przypsianiu
        ui->tableViewDB->setColumnHidden(5, true); // Ukrywam Kolumnę z LP kontrahenta
            //---------------------------------------------------------------
        //model->insertRow(model->rowCount());

        //ui->labelTest->text(QString::number(iloscWierszy));

        QStandardItem *dodajItem = new QStandardItem("Jakies cos");
        //    model->setItem(iloscWierszy,1,dodajItem);
        //    model->setItem(iloscWierszy, 1, dodajItem); // Dodoaje item i od razu wiersz.

        //Wczytuje kontrahentow z pliku

        //QStandardItem *dodajNumer = new QStandardItem("");
        fileDataBase.open(file1.toStdString(), ios::in);
        if (fileDataBase.good() == false) {
            cout << "Plik nie istnieje !!!!!";
            //exit(0);
        }
        string linia;
        int row = 0;
        int nr_lini = 0; // zmiana z int nr_lini = 1;

        //3 linia to LP - nie wyswietlamy
        while (getline(fileDataBase, linia)) {
            dodajItem = new QStandardItem(linia.c_str());
            //if (nr_lini > 0)
//            if (nr_lini ==3)
//            {
//                nr_lini++;
//            }else
            {
                model->setItem(row, nr_lini, dodajItem); //row, nr_lini - 2, dodajItem
            }
            //ui->comboBoxWczytajMiasta->addItem(linia.c_str());
            cout << linia.c_str() << endl;
            nr_lini++;
            if (nr_lini > 18) {
                row = row + 1;
                nr_lini = 0;
            }
        }

        fileDataBase.close();

        // pobierz ilosc rzedów
        int rowDoSize = model->rowCount();
        for (int i = 0; i <= rowDoSize; i++) {
            ui->tableViewDB->setRowHeight(i, 20);
        }
        ui->tableViewDB->horizontalHeader()->setSectionResizeMode(
            QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
        ui->tableViewDB->sortByColumn(0,
                                    Qt::SortOrder(0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy


        iloscWierszy();

        //TODO: Sprawdzic zaznaczenie całego wiersza
    }

    void Pierwsza::iloscWierszy()
    {
        int iloscWierszy = model->rowCount();
        QString qIloscWierszy;
        qIloscWierszy.setNum(iloscWierszy);
        ui->labelTest->setText("Ilosć Kontrahentów: " + qIloscWierszy);
        cout << iloscWierszy;
    }



void Pierwsza::myfunctiontimer()
{time_t czas;
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

Pierwsza::~Pierwsza()
{
    delete ui;
}

void Pierwsza::on_pushButton_clicked()
{timer->stop();
    destroy();
}

void Pierwsza::DataiCzas()
{
    cout << "Wszedłem do daty i czsu" << endl;
}
//Info do Gita
void Pierwsza::on_pushButton_2_clicked()
{
    // Informacje o knotrahencie
    KontrahentInfo *kontrInfo = new KontrahentInfo(this);
    kontrInfo ->show();

}

#include "Baza.h"
#include "QApplication"
#include "Timery/timedate.h"
//#include "time.h"
#include "Kontrahent/kontrahentinfo.h"
#include "ui_Baza.h"
#include <Info/info.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QString>
#include <QTableView>
#include <QTimer>
#include <QtWidgets>

using namespace std;

//int labelGodzinaPierwsza;
//int labelDataPierwsza;
//int wynikPierwsza;

fstream fileDataBase1, fileDataBase2, fileDataBase3;

Baza::Baza(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Baza)
{
    ui->setupUi(this);
    ui->labelZegara->setText(" cos tam");
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    //QString file1 = "C:/Defaults/Pliki/1.DB.txt";
    //QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
    //QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
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
void Baza::wczytajDane()
{
    QString file1 = "C:/Defaults/Pliki/1.DB.txt";
    QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
    QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
    // Tworze modele do Qtable

    model = new QStandardItemModel(1, 19, this); //było 14
    ui->tableViewDB->setModel(model);
    //QModelIndex *index;
    model->setHeaderData(0, Qt::Horizontal, "L.P.");
    model->setHeaderData(1, Qt::Horizontal, "Producent");    //nazwa
    model->setHeaderData(2, Qt::Horizontal, "Model");        // Imie
    model->setHeaderData(3, Qt::Horizontal, "Nr Seryjny");   // Imie
    model->setHeaderData(4, Qt::Horizontal, "Przypisany ?"); // Imie
        //model->setHeaderData(5, Qt::Horizontal, "Nr Seryjny"); // Imie
    model->setHeaderData(5, Qt::Horizontal, "LP Kontrahenta");      //Nazwisko
    model->setHeaderData(6, Qt::Horizontal, "Nazwa");               //Kraj
    model->setHeaderData(7, Qt::Horizontal, "Imie");                //Region
    model->setHeaderData(8, Qt::Horizontal, "Nazwisko");            //Miasto
    model->setHeaderData(9, Qt::Horizontal, "Kraj");                //Kod Pocztowy
    model->setHeaderData(10, Qt::Horizontal, "Region");             //Ulica
    model->setHeaderData(11, Qt::Horizontal, "Miasto");             //Nr domu/mieszkania
    model->setHeaderData(12, Qt::Horizontal, "Kod Pocztowy");       //Telefon
    model->setHeaderData(13, Qt::Horizontal, "Ulica");              //Telefon prywatny
    model->setHeaderData(14, Qt::Horizontal, "Nr domu/mieszkania"); //Adres E-mail
    model->setHeaderData(15, Qt::Horizontal, "Telefon");            //Strona URL
    model->setHeaderData(16, Qt::Horizontal, "Telefon prywatny");   //Telefon prywatny
    model->setHeaderData(17, Qt::Horizontal, "Adres E-mail");       //Adres E-mail
    model->setHeaderData(18, Qt::Horizontal, "Strona URL");         //Strona URL

    //    setSelectionBehavior(QAbstractItemView::SelectRows);
    //    setSelectionMode(QAbstractItemView::SingleSelection);
    //---------------------------------------------------------------
    //NOTE: ukrywam 3 linie

    ui->tableViewDB->setColumnHidden(0, true); //Ukrywam kolumne z LP urzadzenia
    ui->tableViewDB->setColumnHidden(4, true); // Ukrywam Kolumnę z info o przypsianiu
    ui->tableViewDB->setColumnHidden(5, true); // Ukrywam Kolumnę z LP kontrahenta
    //---------------------------------------------------------------
    //model->insertRow(model->rowCount());

    //ui->labelTest->text(QString::number(iloscWierszy));

    QStandardItem *dodajItem = new QStandardItem("Jakies cos");
    //QStandardItem *dodajItem1 = new QStandardItem("Jakies cos");
    //    model->setItem(iloscWierszy,1,dodajItem);
    //    model->setItem(iloscWierszy, 1, dodajItem); // Dodoaje item i od razu wiersz.

    //Wczytuje kontrahentow z pliku

    QString tempUrzadz;
    QString tempUrzadz1;
    string linia3;
    string linia2;
    string linia1;
    int row3 = 0;
    int nr_lini3 = 0;
    //int row2 = 0;
    //int nr_lini2 = 0;
    //int row1 = 0;
    int nr_lini1 = 0;
    { // wczytaj urzadzenia
        fileDataBase3.open(file3.toStdString(), ios::in);
        if (fileDataBase3.good() == false) {
            cout << "Plik nie istnieje !!!!!";
            //exit(0);
        }

        // zmiana z int nr_lini = 1;
        //cout << "cos sprawdzam1 " << endl;
        while (getline(fileDataBase3, linia3)) {
            //cout << "cos sprawdzam z id Urzadzenia " << endl;
            //ui->comboBox->addItem(linia3.c_str());
            //ui->lblUrzadzenie->setText(linia3.c_str());

            tempUrzadz = ui->lblUrzadzenie->text();
            ui->comboBox->addItem(linia3.c_str());
            //            int ostatni = ui->comboBox->count();
            //            tempUrzadz1 = ui->comboBox->itemText(ostatni).toStdString();
        }
    }
    fileDataBase3.close();

    // wczytaj kontrahentow
    fileDataBase2.open(file2.toStdString(), ios::in);
    if (fileDataBase2.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    // zmiana z int nr_lini = 1;
    //cout << "cos sprawdzam2 " << endl;
    while (getline(fileDataBase2, linia2)) {
        //cout << "cos sprawdzam2 " << endl;
        //ui->comboBox->addItem(linia3.c_str());
        //ui->lblKontrahent->setText(linia2.c_str());
        //string tempKontr = ui->lblKontrahent->text().toStdString();
        ui->comboBox_2->addItem(linia2.c_str()); //ui->comboBox_2->addItem(linia2.c_str());
        //int ostatni = ui->comboBox_2->count();
        //string tempKontr1 = ui->comboBox_2->itemText(ostatni).toStdString();
    }

    fileDataBase2.close();

    fileDataBase1.open(file1.toStdString(), ios::in);
    if (fileDataBase1.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }

    while (getline(fileDataBase1, linia1)) {
        dodajItem = new QStandardItem(linia1.c_str());
        //if (nr_lini > 0)
        if (nr_lini1 == 0) {
            ui->lblUrzadzenie->setText(dodajItem->text());
            ui->comboBox_3->addItem(linia1.c_str());

            nr_lini1++;
        } else if (nr_lini1 == 1) {
            ui->lblKontrahent->setText(dodajItem->text());
            ui->comboBox_4->addItem(linia1.c_str());
            string tempKontr1 = ui->lblKontrahent->text().toStdString();
            nr_lini1++;
        }
        if (nr_lini1 >= 2) {
            nr_lini1 = 0;
        }
    }
    fileDataBase1.close();

    // porownuje i sprawdzam czy sa takie same w combo boxach

    int iloscWcomboBox4 = ui->comboBox_4->count(); //krótki z DB kontrahenci
    int iloscWComboBox2 = ui->comboBox_2->count(); //dlugi kontrahneci
    for (int i = 0; i <= iloscWcomboBox4 - 1; i++) {
        QString itZComboBoxa4 = ui->comboBox_4->itemText(i);
        //tempUrzadz1 = ui->lblUrzadzenie->text();

        for (int z = 0; z <= iloscWComboBox2 - 1; z++) {
            QString itZComboBoxa2 = ui->comboBox_2->itemText(z);

            if (itZComboBoxa2 == itZComboBoxa4) {
                for (int k = 0; k < 14; k++) {
                    int naKtorejPozycji = ui->comboBox_2->findText(itZComboBoxa2);
                    //cout << " Pozycja nr" << naKtorejPozycji << endl;
                    QString tym1 = ui->comboBox_2->itemText(naKtorejPozycji + k);
                    dodajItem = new QStandardItem(tym1);
                    model->setItem(row3, nr_lini3 + k + 5, dodajItem);
                }
                row3++;
            }
        }
        //row3++;
    }
    row3 = 0;

    int iloscWcomboBox3 = ui->comboBox_3->count(); //CB4krótki z DB kontrahenci
    int iloscWComboBox = ui->comboBox->count();    //CB2dlugi kontrahneci
    for (int i = 0; i <= iloscWcomboBox3 - 1; i++) {
        QString itZComboBoxa3 = ui->comboBox_3->itemText(i);

        for (int z = 0; z <= iloscWComboBox - 1; z++) {
            QString itZComboBoxa = ui->comboBox->itemText(z);

            if (itZComboBoxa == itZComboBoxa3) {
                //cout << "Znalazłem" << endl;
                //cout << itZComboBoxa.toStdString() << endl;
                for (int k = 0; k < 5; k++) {
                    int naKtorejPozycji = ui->comboBox->findText(itZComboBoxa);
                    //cout << " Pozycja nr" << naKtorejPozycji << endl;
                    QString tym2 = ui->comboBox->itemText(naKtorejPozycji + k);

                    dodajItem = new QStandardItem(tym2);
                    model->setItem(row3, nr_lini3 + k, dodajItem);
                }
                row3++;
            }
        }
    }

    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableViewDB->setRowHeight(i, 20);
    }
    ui->tableViewDB->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableViewDB->sortByColumn(0,
                                  Qt::SortOrder(
                                      0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy

    iloscWierszy();
    row3 = 0;
    nr_lini3 = 0;
    //row2 = 0;
    //nr_lini2 = 0;

    nr_lini1 = 0;
    tempUrzadz = "";
    tempUrzadz1 = "";
    linia3 = "";
    linia2 = "";
    linia1 = "";

}

void Baza::iloscWierszy()
{
    int iloscWierszy = model->rowCount();
    QString qIloscWierszy;
    qIloscWierszy.setNum(iloscWierszy);
    ui->labelTest->setText("Ilosć Kontrahentów: " + qIloscWierszy);
    cout << iloscWierszy;
}

void Baza::myfunctiontimer()
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

Baza::~Baza()
{
    delete ui;
}

void Baza::on_pushButton_clicked()
{ //Zamknij
    timer->stop();

    destroy();
}

void Baza::DataiCzas()
{
    cout << "Wszedłem do daty i czsu" << endl;
}
//Info do Gita
void Baza::on_pushButton_2_clicked()
{
    // Informacje o knotrahencie
    KontrahentInfo *kontrInfo = new KontrahentInfo(this);
    int iloscColumn = model->columnCount();
    QString qIloscColumn;
    qIloscColumn.setNum(iloscColumn);

    //--------------
    int stringrowDoSize = (ui->tableViewDB->currentIndex().row()) + 1;
    //cout << "Zaznaczony rzad to: " << stringrowDoSize << endl;

    //ui->label_2->setText(QString::number(iloscColumn) + " " + QString::number(stringrowDoSize));
    QModelIndex index = ui->tableViewDB->selectionModel()->currentIndex();
    QVariant vartosc = index.sibling(index.row(), index.column()).data();
    QString QVartsoc = QVariant(vartosc).toString();
    //ui->label->setText(QVartsoc); //Pokazuje kliknietą komórkę.
    //Sprawdzam czy jest kliknięta komórka

    if (QVartsoc == "") {
        cout << "Pusty. Nie wykonujemy" << endl;

        QMessageBox::information(this, "Ostrzeżenie", "Zaznacz jakieś rekordy.");

    } else {
        QVariant tab[iloscColumn];
        QVariant wyslij;
        for (int i = 0; i <= iloscColumn; i++) {
            tab[i] = index.sibling(stringrowDoSize - 1, i).data();
        }

        kontrInfo->wyswietl(tab[0],
                            tab[1],
                            tab[2],
                            tab[3],
                            tab[4],
                            tab[5],
                            tab[6],
                            tab[7],
                            tab[8],
                            tab[9],
                            tab[10],
                            tab[11],
                            tab[12],
                            tab[13],
                            tab[14],
                            tab[15],
                            tab[16],
                            tab[17],
                            tab[18]);

        kontrInfo->show();
    }
}

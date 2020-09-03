#include "urzadzenialistakontrahent.h"
#include "ui_urzadzenialistakontrahent.h"
#include <iostream>
#include <QTableView>
#include <QTimer>
#include <fstream>
#include "Timery/timedate.h"


using namespace std;

fstream plikUrzadzeniaKontrahentLista;

UrzadzeniaListaKontrahent::UrzadzeniaListaKontrahent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UrzadzeniaListaKontrahent)
{

    ui->setupUi(this);
    ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    wczytajDane();


}

UrzadzeniaListaKontrahent::~UrzadzeniaListaKontrahent()
{
    delete ui;
}
void UrzadzeniaListaKontrahent::wczytajDane()
{
    // Tworze modele do Qtable

    model = new QStandardItemModel(1, 14, this);
    ui->tableView->setModel(model);
    //QModelIndex *index;
    model->setHeaderData(0, Qt::Horizontal, "L.P.");
    model->setHeaderData(1, Qt::Horizontal, "Nazwa");
    model->setHeaderData(2, Qt::Horizontal, "Imię");
    model->setHeaderData(3, Qt::Horizontal, "Nazwisko");
    model->setHeaderData(4, Qt::Horizontal, "Kraj");
    model->setHeaderData(5, Qt::Horizontal, "Region");
    model->setHeaderData(6, Qt::Horizontal, "Miasto");
    model->setHeaderData(7, Qt::Horizontal, "Kod Pocztowy");
    model->setHeaderData(8, Qt::Horizontal, "Ulica");
    model->setHeaderData(9, Qt::Horizontal, "Nr domu/mieszkania");
    model->setHeaderData(10, Qt::Horizontal, "Telefon");
    model->setHeaderData(11, Qt::Horizontal, "Telefon prywatny");
    model->setHeaderData(12, Qt::Horizontal, "Adres E-mail");
    model->setHeaderData(13, Qt::Horizontal, "Strona URL");


    //---------------------------------------------------------------
    ui->tableView->setColumnHidden(0,true); //Ukrywam kolumne z LP
        //---------------------------------------------------------------
    //model->insertRow(model->rowCount());

    //ui->labelTest->text(QString::number(iloscWierszy));

    QStandardItem *dodajItem = new QStandardItem("Jakies cos");
    //    model->setItem(iloscWierszy,1,dodajItem);
    //    model->setItem(iloscWierszy, 1, dodajItem); // Dodoaje item i od razu wiersz.

    //Wczytuje kontrahentow z pliku

    //QStandardItem *dodajNumer = new QStandardItem("");
    plikUrzadzeniaKontrahentLista.open("C:/Defaults/Pliki/Kontrahent.txt", ios::in);
    if (plikUrzadzeniaKontrahentLista.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;
    int row = 0;
    int nr_lini = 0; // zmiana z int nr_lini = 1;
    while (getline(plikUrzadzeniaKontrahentLista, linia)) {
        dodajItem = new QStandardItem(linia.c_str());
        //if (nr_lini > 0)
        {
            model->setItem(row, nr_lini, dodajItem); //row, nr_lini - 2, dodajItem
        }
        //ui->comboBoxWczytajMiasta->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
        if (nr_lini > 13) {
            row = row + 1;
            nr_lini = 0;
        }
    }

    plikUrzadzeniaKontrahentLista.close();

    // pobierz ilosc rzedów
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

    //TODO: Sprawdzic zaznaczenie całego wiersza

}

void UrzadzeniaListaKontrahent::iloscWierszy()
{
    int iloscWierszy = model->rowCount();
    QString qIloscWierszy;
    qIloscWierszy.setNum(iloscWierszy);
    ui->labelTest->setText("Ilosć Kontrahentów: " + qIloscWierszy);
    cout << iloscWierszy;
}
void UrzadzeniaListaKontrahent::myfunctiontimer()
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
void UrzadzeniaListaKontrahent::on_pushButton_clicked()
{
    // Przypisz


}

void UrzadzeniaListaKontrahent::on_pushButton_2_clicked()
{
    //zamknij
    timer->stop();
    destroy();
//TODO: Dlaczego nie działa button Zamknij

}

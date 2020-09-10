#include "urzadzenialistakontrahent.h"
#include "Timery/timedate.h"
#include "ui_urzadzenialistakontrahent.h"
#include <Info/info.h>
#include <fstream>
#include <iostream>
#include <QTableView>
#include <QTimer>
#include <QtWidgets>

using namespace std;

fstream fileDB, plikUrzadzeniaKontrahentLista;

UrzadzeniaListaKontrahent::UrzadzeniaListaKontrahent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaListaKontrahent)
{
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
void UrzadzeniaListaKontrahent::on_pushButton_clicked()
{
    // Przypisz
    cout << "przypisz klienta do analziatora" << endl;
    //pobierz z comboboxa

    int iloscColumn = model->columnCount();

    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    int stringrowDoSize = (ui->tableView->currentIndex().row()) + 1;
    QVariant tab[iloscColumn];
    QVariant wyslij;
    for (int i = 0; i <= iloscColumn-1; i++) {
        tab[i] = index.sibling(stringrowDoSize - 1, i).data();
        ui->comboBox_2->addItem(tab[i].toString());
    }

}

void UrzadzeniaListaKontrahent::on_pushButton_2_clicked()
{
    //zamknij

    cout << "Zamknij liste urzadzen z prypisania" << endl;
    timer->stop();
    destroy();
}

void UrzadzeniaListaKontrahent::wyswietl(QVariant p1, QVariant p2, QVariant p3, QVariant p4)
{
    ui->comboBox->addItem(p1.toString());
    ui->comboBox->addItem(p2.toString());
    ui->comboBox->addItem(p3.toString());
     ui->comboBox->addItem(p4.toString());
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

    //    setSelectionBehavior(QAbstractItemView::SelectRows);
    //    setSelectionMode(QAbstractItemView::SingleSelection);
    //---------------------------------------------------------------
    ui->tableView->setColumnHidden(0, true); //Ukrywam kolumne z LP
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

void UrzadzeniaListaKontrahent::on_pushButton_3_clicked()
{
    // Zapisz
fileDB.open("C:/Defaults/Pliki/DB.txt", ios::app);


int combBox1Size = ui->comboBox->count();
int combBox1Size2 = ui->comboBox_2->count();


string dane1, dane2;

for (int i =0;i<=combBox1Size-1;i++)

{dane1 = ui->comboBox->itemText(i).toStdString();

    fileDB<<dane1 <<endl;
}
for (int i =0;i<=combBox1Size2-1;i++)

{dane2 = ui->comboBox_2->itemText(i).toStdString();

    fileDB<<dane2 <<endl;
}
fileDB.close();
ui->comboBox->clear();
ui->comboBox_2->clear();

}
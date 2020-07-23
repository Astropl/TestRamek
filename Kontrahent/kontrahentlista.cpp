#include "kontrahentlista.h"
#include "kontrahentshow.h"
#include "tableviewlistakontrahentow.h"
#include "ui_kontrahentlista.h"
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
time_t czasKontrahentLista;
tm timeinfoKontrahentLista;
int labelGodzinaKontrahentLista;
int labelDataKontrahentLista;
int wynikKontrahentLista;
int godzinaKontrahentLista, minutaKontrahentLista, sekundaKontrahentLista, dzienKontrahentLista,
    miesiacKontrahentLista, rokKontrahentLista;
int dzienTygodniaKontrahentLista;
string stringDzienTygodniaKontrahentLista;
string zmiennasKontrahentLista;

fstream plikKontrahentLista;

KontrahentLista::KontrahentLista(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentLista)
{
    ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    wczytajDane();
}

KontrahentLista::~KontrahentLista()
{
    delete ui;
}
void KontrahentLista::wczytajDane()
{
    // Tworze modele do Qtable

    model = new QStandardItemModel(1, 13, this);
    ui->tableView->setModel(model);
    //QModelIndex *index;

    model->setHeaderData(0, Qt::Horizontal, "Nazwa");
    model->setHeaderData(1, Qt::Horizontal, "Imię");
    model->setHeaderData(2, Qt::Horizontal, "Nazwisko");
    model->setHeaderData(3, Qt::Horizontal, "Kraj");
    model->setHeaderData(4, Qt::Horizontal, "Region");
    model->setHeaderData(5, Qt::Horizontal, "Miasto");
    model->setHeaderData(6, Qt::Horizontal, "Kod Pocztowy");
    model->setHeaderData(7, Qt::Horizontal, "Ulica");
    model->setHeaderData(8, Qt::Horizontal, "Nr domu/mieszkania");
    model->setHeaderData(9, Qt::Horizontal, "Telefon");
    model->setHeaderData(10, Qt::Horizontal, "Telefon prywatny");
    model->setHeaderData(11, Qt::Horizontal, "Adres E-mail");
    model->setHeaderData(12, Qt::Horizontal, "Strona URL");

    //model->insertRow(model->rowCount());

    //ui->labelTest->text(QString::number(iloscWierszy));

    QStandardItem *dodajItem = new QStandardItem("Jakies cos");
    //    model->setItem(iloscWierszy,1,dodajItem);
    //    model->setItem(iloscWierszy, 1, dodajItem); // Dodoaje item i od razu wiersz.

    //Wczytuje kontrahentow z pliku

    //QStandardItem *dodajNumer = new QStandardItem("");
    plikKontrahentLista.open("C:/Defaults/Pliki/Kontrahent.txt", ios::in);
    if (plikKontrahentLista.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia;
    int row = 0;
    int nr_lini = 1;
    while (getline(plikKontrahentLista, linia)) {
        dodajItem = new QStandardItem(linia.c_str());
        if (nr_lini > 1) {
            model->setItem(row, nr_lini - 2, dodajItem);
        }
        //ui->comboBoxWczytajMiasta->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
        if (nr_lini > 14) {
            row = row + 1;
            nr_lini = 1;
        }
    }

    plikKontrahentLista.close();

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
}

void KontrahentLista::iloscWierszy()
{
    int iloscWierszy = model->rowCount();
    QString qIloscWierszy;
    qIloscWierszy.setNum(iloscWierszy);
    ui->labelTest->setText("Ilosć Kontrahentów: " + qIloscWierszy);
    cout << iloscWierszy;
}

void KontrahentLista::myfunctiontimer()
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


void KontrahentLista::on_pushButton_2_clicked()
{
    destroy();
}

void KontrahentLista::on_tableView_activated(const QModelIndex)
{
    //ui->tableView->set
    //    QTableView listaKontrahentów;

    //  TableViewListaKontrahentow myModel(0);
    //  listaKontrahentów.setModel(&myModel);
    //  listaKontrahentów.show();
}

void KontrahentLista::on_tableView_doubleClicked(const QModelIndex) //(const QModelIndex &index)
{
    QMessageBox msgBox;
    msgBox.setText("Click, Click, dwa razy");
    msgBox.exec();
}

void KontrahentLista::on_tableView_clicked(const QModelIndex) //(const QModelIndex &index)
{
    QMessageBox msgBox;
    //    msgBox.setText("Click,  tylko raz Click");
    //    msgBox.exec();
    QString pierwszazmienna = "Cos ik tam jest";
    KontrahentShow *kontrShow = new KontrahentShow(this);

    //rzad pokaz

    int stringrowDoSize = (ui->tableView->currentIndex().row()) + 1;
    cout << "Zaznaczony rzad to: " << stringrowDoSize << endl;

    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    QVariant vartosc = index.sibling(index.row(), index.column()).data();
    QString QVartsoc = QVariant(vartosc).toString();
    ui->label->setText(QVartsoc); //Pokazuje kliknietą komórkę.

    // stringrowDosize: zaznaczony rzad

    int iloscColumn = model->columnCount();
    QString qIloscColumn;
    qIloscColumn.setNum(iloscColumn);

    //--------------

    ui->label_2->setText(QString::number(iloscColumn) + " " + QString::number(stringrowDoSize));

    QVariant tab[iloscColumn];
    QVariant wyslij;
    for (int i = 0; i <= iloscColumn; i++) {
        tab[i] = index.sibling(stringrowDoSize - 1, i).data();
    }

    kontrShow->wyswietl(tab[0],
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
                        tab[12]);

    kontrShow->show();
}

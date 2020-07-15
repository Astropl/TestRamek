#include "kontrahentlista.h"
#include "kontrahentshow.h"
#include "tableviewlistakontrahentow.h"
#include "ui_kontrahentlista.h"
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
{//TODO: Wywalic to do nowego pliku.
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

    zmianaLabela(godzinaKontrahentLista,
                 minutaKontrahentLista,
                 sekundaKontrahentLista,
                 dzienKontrahentLista,
                 miesiacKontrahentLista,
                 rokKontrahentLista,
                 dzienTygodniaKontrahentLista);
}
int KontrahentLista::zmianaLabela(
    int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia)
{
    // Dodoać zera do sekund gdy mniej niz 10
    QString qStrMin = QString::number(minuta);
    QString qStrGodz = QString::number(godzina);
    QString qStrSek = QString::number(sekunda);
    QString qStrDzien = QString::number(dzien);
    QString qStrMiesiac = QString::number(miesiac);
    if (sekunda < 10) {
        qStrSek = "0" + QString::number(sekunda);
    }
    if (minuta < 10) {
        qStrMin = "0" + QString::number(minuta);
    }
    if (godzina < 10) {
        qStrGodz = "0" + QString::number(godzina);
    }
    if (miesiac < 10) {
        qStrMiesiac = "0" + QString::number(miesiac);
    }
    if (dzien < 10) {
        qStrDzien = "0" + QString::number(dzien);
    }

    ui->labelZegara->setText(qStrGodz + ":" + qStrMin + ":" + qStrSek);
    ui->labelDaty->setText(QString::number(rok) + "." + qStrMiesiac + "." + qStrDzien);
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

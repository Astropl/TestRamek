#include "urzadzenia.h"
#include "ui_urzadzenia.h"
#include "urzadzeniadodajmodel.h"
#include "urzadzeniadodajnrseryjny.h"
#include "urzadzeniadodajproducenta.h"

#include <fstream>
#include <iostream>
using namespace std;

string stringLabela4 = ("Producent: , Model: , Nr. Seryjny: ");
QString zaznaczono;
fstream plik;

Urzadzenia::Urzadzenia(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Urzadzenia)
{
    ui->setupUi(this);
    ui->comboBox->addItem("");
    ui->comboBox_2->addItem("");
    ui->comboBox_3->addItem("");

    //Wczytuje modele z pliku
    plik.open("C:/Qt/Pliki/ZapisModel.txt", ios::in);
    if (plik.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plik, linia)) {
        ui->comboBox_2->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }

    plik.close();
    // wczytuj pliki z producenta
    plik.open("C:/Qt/Pliki/ZapisProducenta.txt", ios::in);
    if (plik.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia1;
    int nr_lini1 = 1;
    while (getline(plik, linia1)) {
        ui->comboBox->addItem(linia1.c_str());
        cout << linia1.c_str() << endl;
        nr_lini1++;
    }
    plik.close();
    //wczytaj numery seryjne z pliku
    plik.open("C:/Qt/Pliki/ZapisNrSeryjny.txt", ios::in);
    if (plik.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        exit(0);
    }
    string linia2;
    int nr_lini2 = 1;
    while (getline(plik, linia2)) {
        ui->comboBox_3->addItem(linia2.c_str());
        cout << linia2.c_str() << endl;
        nr_lini2++;
    }
    plik.close();

    countriesListModel = new QStringListModel(this);
    //    countriesListModel->setStringList({"Polska", "Czechy", "Słowacja"}
    //                                      // dodaję parę początkowych pozycji
    //    );
    ui->countriesList->setModel(countriesListModel);
    int row = countriesListModel->rowCount(); // pobieram liczbę wierszy

    countriesListModel->insertRow(row);                    // wstawiam dodatkowy wiersz na końcu
    QModelIndex index = countriesListModel->index(row, 0); // pobieram obiekt wstawionego indeksu
    countriesListModel->setData(index, QVariant("*"));
}

Urzadzenia::~Urzadzenia()
{
    delete ui;
}

void Urzadzenia::on_BtnUrzaZapisz_clicked()
{
    cout << "Zapisz" << endl;
}

void Urzadzenia::on_BtnUrzaZamknij_clicked()
{
    cout << "Zamknij" << endl;
    destroy();
}

void Urzadzenia::on_countriesList_clicked(const QModelIndex &index)
{
    cout << "Zaznaczono: " << endl;
    int rowCount = countriesListModel->rowCount();
    countriesListModel->insertRow(rowCount);
    //QModelIndex index = countriesListModel->index(rowCount, 0); // pobieram jej obiekt
    countriesListModel->setData(index, QVariant("Cos innego")); // i ustawiam tekst na "*"

    // Musze dodoać to co zaznacze do Labela 4
todo:
    "Musze dodoać to co zaznacze do Labela 4";

    // Do combo boxa

    ui->label_4->setText(zaznaczono + " " + ui->comboBox->currentText());
}

void Urzadzenia::on_comboBox_textActivated(const QString &arg1)
{
    //QString zaznaczono =ui->label_4->text();
    ui->label_4->setText("Producent: " + ui->comboBox->currentText()
                         + ", Model: " + ui->comboBox_2->currentText()
                         + ", NumerSeryjny: " + ui->comboBox_3->currentText());
}

void Urzadzenia::on_comboBox_2_textActivated(const QString &arg1)
{
    //ui->label_4->setText(ui->comboBox->currentText());
    ui->label_4->setText("Producent: " + ui->comboBox->currentText()
                         + ", Model: " + ui->comboBox_2->currentText()
                         + ", NumerSeryjny: " + ui->comboBox_3->currentText());
    // Drugi Combo dla modelu
}

void Urzadzenia::on_comboBox_3_textActivated(const QString &arg1)
{
    //ui->label_4->setText(ui->comboBox->currentText());
    // Trzeci combo dla nr seryjnego
    ui->label_4->setText("Producent: " + ui->comboBox->currentText()
                         + ", Model: " + ui->comboBox_2->currentText()
                         + ", NumerSeryjny: " + ui->comboBox_3->currentText());
}

void Urzadzenia::on_actionDodaj_Model_triggered()
{
    cout << "Dodoaje model z menu" << endl;
    //UrzadzeniaDodajModel

    UrzadzeniaDodajModel *urzDodModel = new UrzadzeniaDodajModel(this);
    urzDodModel->show();
}

void Urzadzenia::on_actionDodaj_Producenta_triggered()
{
    cout << "dodoaje producenta z menu" << endl;

    UrzadzeniaDodajProducenta *urzDodProd = new UrzadzeniaDodajProducenta(this);
    urzDodProd->show();
}

void Urzadzenia::on_actionDodaj_Numer_Seryjny_triggered()
{
    cout << "Dodaje Nr seryjny z menu" << endl;
    UrzadzeniaDodajNrSeryjny *urzDodNrSer = new UrzadzeniaDodajNrSeryjny(this);
    urzDodNrSer->show();
}

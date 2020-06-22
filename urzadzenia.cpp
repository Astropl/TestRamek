#include "urzadzenia.h"
#include "ui_urzadzenia.h"
#include <iostream>
#include "urzadzeniadodajmodel.h"

using namespace std;

string stringLabela4 = ("Producent: , Model: , Nr. Seryjny: ");

Urzadzenia::Urzadzenia(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Urzadzenia)
{
    ui->setupUi(this);
    ui->comboBox->addItem("1");
    ui->comboBox->addItem("1.1");
    ui->comboBox->addItem("1.2");

    ui->comboBox_2->addItem("2");
    ui->comboBox_2->addItem("2.1");
    ui->comboBox_2->addItem("2.2");

    ui->comboBox_3->addItem("3");
    ui->comboBox_3->addItem("3.1");
    ui->comboBox_3->addItem("3.2");

    countriesListModel = new QStringListModel(this);
    countriesListModel->setStringList({"Polska", "Czechy", "Słowacja"}
                                      // dodaję parę początkowych pozycji
    );
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

///*void Urzadzenia::on_listViewUrzaProducent_clicked(const QModelIndex &index)
//{ // Zaznaczono item
//    cout << "Zaznaczono: " << endl;
//    int rowCount = countriesListModel->rowCount();
//    countriesListModel->insertRow(rowCount);
//    //QModelIndex index = countriesListModel->index(rowCount, 0); // pobieram jej obiekt
//    countriesListModel->setData(index, QVariant("Cos innego")); // i ustawiam tekst na "**/"
////}

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
    //QString zaznaczono =ui->comboBox->currentText();
    //countriesListModel->getSelectionMark(index);
    // ui->label_4->setText(zaznaczono+"dodany");
    // Do combo boxa
    QString zaznaczono;
    ui->label_4->setText(zaznaczono + " " + ui->comboBox->currentText());
}

void Urzadzenia::on_comboBox_textActivated(const QString &arg1)
{
    //QString zaznaczono =ui->label_4->text();
    ui->label_4->setText(ui->comboBox->currentText());
}

void Urzadzenia::on_comboBox_2_textActivated(const QString &arg1)
{
    ui->label_4->setText(ui->comboBox->currentText());
    // Drugi Combo dla modelu
}

void Urzadzenia::on_comboBox_3_textActivated(const QString &arg1)
{
    ui->label_4->setText(ui->comboBox->currentText());
    // Trzeci combo dla nr seryjnego
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
}

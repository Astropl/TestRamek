#include "kontrahentshow.h"
#include "ui_kontrahentshow.h"
#include <String>
#include <iostream>
#include <ostream>
#include <fstream>
#include <QString>

using namespace std;

QString tab[13];

KontrahentShow::KontrahentShow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentShow)
{
    ui->setupUi(this);

    cout << "Jestem w Kontrahebt show" << endl;
}



KontrahentShow::~KontrahentShow()
{
    delete ui;
}

void KontrahentShow::on_pushButton_2_clicked()
{// button zamknij
    destroy();
}

QVariant KontrahentShow::wyswietl(QVariant p1,
                                  QVariant p2,
                                  QVariant p3,
                                  QVariant p4,
                                  QVariant p5,
                                  QVariant p6,
                                  QVariant p7,
                                  QVariant p8,
                                  QVariant p9,
                                  QVariant p10,
                                  QVariant p11,
                                  QVariant p12,
                                  QVariant p13)
{


    cout << "Chche wysiwretlic i dopisac do labeli wybranego kontrahenta" << endl;


    ui->leNazwa->setText(p1.toString());
    ui->leImie->setText(p2.toString());
    ui->leNazwisko->setText(p3.toString());
    ui->leKraj->setText(p4.toString());
    ui->comboBoxKraj->addItem(p4.toString());
    ui->comboBoxMiasta->addItem(p6.toString());
    ui->comboBoxWojewodztwa->addItem(p5.toString());
    ui->leRegion->setText(p5.toString());
    ui->leMiasto->setText(p6.toString());
    ui->leKod->setText(p7.toString());
    ui->leUlica->setText(p8.toString());
    ui->leNrDomu->setText(p9.toString());
    ui->leTelefon->setText(p10.toString());
    ui->leTelPryw->setText(p11.toString());
    ui->leEmail->setText(p12.toString());
    ui->leUrl->setText(p13.toString());
}
//Info do Gita
void KontrahentShow::on_pushButton_clicked()
{
    // Edycja wybranego kontrahenta

    // Odblokować pola edycyjne
    ui->leNazwa->setEnabled(true);
    ui->leImie->setEnabled(true);
    ui->leNazwisko->setEnabled(true);
    ui->leKraj->setEnabled(true);
    ui->leRegion->setEnabled(true);
    ui->comboBoxKraj->setEnabled(true);
    ui->comboBoxWojewodztwa->setEnabled(true);
    ui->comboBoxMiasta->setEnabled(true);
    ui->leMiasto->setEnabled(true);
    ui->leKod->setEnabled(true);
    ui->leUlica->setEnabled(true);
    ui->leNrDomu->setEnabled(true);
    ui->leTelefon->setEnabled(true);
    ui->leTelPryw->setEnabled(true);
    ui->leEmail->setEnabled(true);
    ui->leUrl->setEnabled(true);

    ui->leNazwa->setReadOnly(false);
    ui->leImie->setReadOnly(false);
    ui->leNazwisko->setReadOnly(false);
    ui->leKraj->setReadOnly(false);
    ui->leRegion->setReadOnly(false);
    ui->leMiasto->setReadOnly(false);
    ui->comboBoxKraj->setEditable(true);
    ui->comboBoxWojewodztwa->setEditable(true);
    ui->comboBoxMiasta->setEditable(true);

    //ui->comboBoxKraj->setEditable(true);
    ui->leKod->setReadOnly(false);
    ui->leUlica->setReadOnly(false);
    ui->leNrDomu->setReadOnly(false);
    ui->leTelefon->setReadOnly(false);
    ui->leTelPryw->setReadOnly(false);
    ui->leEmail->setReadOnly(false);
    ui->leUrl->setReadOnly(false);

    showCities();
    showWojewodztwa();
    //wczytać kraj, wojewodztwa i miasta do comboboxów



    // ustawić w vombo boxach aktualne nazwy z wyboru


    //zapisac



    //Zmienić region w UI -> Wojewodzwtwo
}
void KontrahentShow::showWojewodztwa(){
     // wczytuje wojewodztwa do comboBoxa
     fstream plikOdczytDodajwojewodztwo;
     // wczytuje miasta do comboBoxa
     ui->comboBoxWojewodztwa->clear();
     plikOdczytDodajwojewodztwo.open("C:/Defaults/Pliki/ZapisWojewodztwa.txt", ios::in);
     if (plikOdczytDodajwojewodztwo.good() == false) {
         cout << "Plik nie istnieje !!!!!";
         //exit(0);
     }
     string linia;
     int nr_lini = 1;
     while (getline(plikOdczytDodajwojewodztwo, linia)) {
         ui->comboBoxWojewodztwa->addItem(linia.c_str());
         cout << linia.c_str() << endl;
         nr_lini++;
     }
     plikOdczytDodajwojewodztwo.close();
     ui->comboBoxWojewodztwa->setCurrentText(ui->leRegion->text());

//TODO: Posortować.



}
void KontrahentShow::showCities()
{fstream plikOdczytDodajMiasto;
    // wczytuje miasta do comboBoxa
    ui->comboBoxMiasta->clear();
    plikOdczytDodajMiasto.open("C:/Defaults/Pliki/ZapisMiasta.txt", ios::in);
    if (plikOdczytDodajMiasto.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikOdczytDodajMiasto, linia)) {
        ui->comboBoxMiasta->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }
      plikOdczytDodajMiasto.close();
     ui->comboBoxMiasta->setCurrentText(ui->leMiasto->text());

}
void KontrahentShow::on_pushButton_3_clicked()
{
    //ZAPISZ wszytsko
    cout<<"Zapisuje po edycji"<<endl;
}

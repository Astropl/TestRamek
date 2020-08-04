#include "kontrahentdodajmiasto.h"
#include "ui_kontrahentdodajmiasto.h"
#include <fstream>
#include <iostream>
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QtWidgets>

using namespace std;

fstream plikOdczytDodajMiasto;



KontrahentDodajMiasto::KontrahentDodajMiasto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentDodajMiasto)
{
    ui->setupUi(this);
    cout << "Wczytac itemy z pliku" << endl;

    //---------------------------------------------------------

    plikOdczytDodajMiasto.open("C:/Defaults/Pliki/ZapisMiasta.txt", ios::in);
    if (plikOdczytDodajMiasto.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;

    int nr_lini = 1;
    while (getline(plikOdczytDodajMiasto, linia)) {
        ui->comboBoxDodajMiasto->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }
    //plikOdczytDodajMiasto.clear();

    plikOdczytDodajMiasto.close();
    //ui->comboBoxDodajMiasto->sor
}

KontrahentDodajMiasto::~KontrahentDodajMiasto()
{
    delete ui;
}

void KontrahentDodajMiasto::on_pushButton_clicked() //zapisz
{fstream checkFlags;
    cout << "Zapisuje " << endl;
    // musze zapisać do pliku
    plikOdczytDodajMiasto
        .open("C:/Defaults/Pliki/ZapisMiasta.txt",
              ios::out
                  | ios::trunc); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.

    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;

    iloscElementowWcombo = ui->comboBoxDodajMiasto->count();
    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;
        plikOdczytDodajMiasto << ui->comboBoxDodajMiasto->itemText(i).toStdString() << endl;
    }
    plikOdczytDodajMiasto.close();
    //
    checkFlags
        .open("C:/Defaults/Pliki/CheckFlagsInMiasto.txt",
              ios::in
                  | ios::trunc); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    checkFlags<<"1";
    checkFlags.close();


    //ui->Jak zrobic aby comboxy na urzadzeniach się odswiezały
    //ui->comboBoxDodajMiasto->rep
    //destroy();
}

void KontrahentDodajMiasto::on_pushButton_2_clicked() //dodoaj do comboboxa
{
    QMessageBox msgBox;
    bool porownanieMiast = false;
    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.

    // Pobrac ilosc elementów z ComboBoxa
    int iloscElementowwCombo = ui->comboBoxDodajMiasto->count();
    // Zrobic cos aby najpierw sprawdzało czy jest puste a potm przeszukiwało itemy z comboxa
    //TODO: jak wyzje;

    if (ui->lineEditDodajMiasto->text() != "") {
        cout << "Dodaje miasto" << endl;
        for (int i = 0; i <= iloscElementowwCombo; i++) {
            QVariant zmienna1 = ui->lineEditDodajMiasto->text();
            //QString zmienna2=QVariant(ui->comboBoxDodajMiasto->itemData(i));
            cout << "Wyswietlam po koleji itemy z comboboxa dodaj miasta" << endl;
            cout << ui->comboBoxDodajMiasto->itemText(i).toStdString() << endl;
            ;
            if (zmienna1 != (ui->comboBoxDodajMiasto->itemText(i))) {
                cout << "Miasto numer :" << i << " "
                     << ui->comboBoxDodajMiasto->itemText(i).toStdString() << endl;
                porownanieMiast = false;

                //Wrzucic do tabeli. Przeleciec tabele. jezeli bedzie wyraz z listy zakonczyc. Jezeli nie dodoać do combo boa.

                // if (ui->lineEditDodajMiasto->text() == ui->comboBoxDodajMiasto->itemData(i)) {
//
//                break;
            } else {
                msgBox.setText("Te miasto jezst juz na liscie");
                QMessageBox::information(this, "Ostrzeżenie", "Te miasto już znajduje się na liście.");
                porownanieMiast = true;

                break;
            }
        }

        if (porownanieMiast==false) // domyslnie true?
        {
            cout << "dodoaje miasto" << endl;
            QString dodajMiasto = ui->lineEditDodajMiasto->text();
            ui->comboBoxDodajMiasto->addItem(dodajMiasto);
            ui->lineEditDodajMiasto->setText("");
        }else{
            cout<<"Przeszukałem wszytskie miasta. Jest na liscie."<<endl;
        }
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego miasta.");
    }
    ui->comboBoxDodajMiasto->setDuplicatesEnabled(false); // ustawiam aby nie było duplikatów
    ui->lineEditDodajMiasto->setText("");
}

// zrobic petle i sprawdac czy text wprowadzony juz jest po kazdym elemenecie.
// jezeli jest wyswiwtlic msgbox ze juz jest.

//Próbuje srotowania
//string  items[] = ui->comboBoxDodajMiasto->count();

void KontrahentDodajMiasto::on_comboBoxDodajMiasto_activated(const QString)
{
    //string[] items = ui->comboBoxDodajMiasto->getItems();
}

void KontrahentDodajMiasto::on_pushButton_3_clicked() //usuń item
{
    //Usuń zaznaczony item
    //    comboBoxDodajMiasto-> Items->Remove(comboBoxDodajMiasto->text);

    //ui->comboBoxDodajMiasto->removeItem(text);
    //    QVariant sprawdz = ui->comboBoxDodajMiasto->itemData(ui->comboBoxDodajMiasto->currentIndex());
    ui->comboBoxDodajMiasto->removeItem(ui->comboBoxDodajMiasto->currentIndex());
    ;
    // cout<<sprawdz.toStdString>>endl;
}

void KontrahentDodajMiasto::on_pushButton_4_clicked() // zamknij bez zapisywania
{                                                 //zamknij be zpisywania
    destroy();
}
//Info do Gita
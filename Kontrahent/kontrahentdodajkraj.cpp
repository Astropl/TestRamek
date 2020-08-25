#include "kontrahentdodajkraj.h"
#include "ui_kontrahentdodajkraj.h"
#include <fstream>
#include <iostream>
#include <QMessageBox>

using namespace std;

fstream plikOdczytDodajKraj;


KontrahentDodajKraj::KontrahentDodajKraj(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KontrahentDodajKraj)
{
    ui->setupUi(this);

    plikOdczytDodajKraj.open("C:/Defaults/Pliki/ZapisKraj.txt",ios::in);
    if (plikOdczytDodajKraj.good() == false)
    {cout<<"Plik nie istnieje!!!";
    }
    string linia;

    int nr_lini = 1;
    while (getline(plikOdczytDodajKraj, linia)) {
        ui->comboBoxDodajKraj->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }
    //plikOdczytDodajMiasto.clear();

    plikOdczytDodajKraj.close();
    //ui->comboBoxDodajMiasto->sor
}

KontrahentDodajKraj::~KontrahentDodajKraj()
{
    delete ui;
}




void KontrahentDodajKraj::on_pushButton_2_clicked()
{
    // Dodoaj
    QMessageBox msgBox;
    bool porownanieKraj = false;
    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.

    // Pobrac ilosc elementów z ComboBoxa
    int iloscElementowwCombo = ui->comboBoxDodajKraj->count();
    // Zrobic cos aby najpierw sprawdzało czy jest puste a potm przeszukiwało itemy z comboxa


    if (ui->lineEditDodajKraj->text() != "") {
        cout << "Dodaje Kraj" << endl;
        for (int i = 0; i <= iloscElementowwCombo; i++) {
            QVariant zmienna1 = ui->lineEditDodajKraj->text();
            //QString zmienna2=QVariant(ui->comboBoxDodajMiasto->itemData(i));
            cout << "Wyswietlam po koleji itemy z comboboxa dodaj Kraj" << endl;
            cout << ui->comboBoxDodajKraj->itemText(i).toStdString() << endl;
            ;
            if (zmienna1 != (ui->comboBoxDodajKraj->itemText(i))) {
                cout << "Kraj numer :" << i << " "
                     << ui->comboBoxDodajKraj->itemText(i).toStdString() << endl;
                porownanieKraj = false;

                //Wrzucic do tabeli. Przeleciec tabele. jezeli bedzie wyraz z listy zakonczyc. Jezeli nie dodoać do combo boa.


            } else {
                msgBox.setText("Ten Kraj jezst juz na liscie");
                QMessageBox::information(this, "Ostrzeżenie", "Ten Kraj już znajduje się na liście.");
                porownanieKraj = true;

                break;
            }
        }

        if (porownanieKraj==false) // domyslnie true?
        {
            cout << "dodoaje Kraj" << endl;
            QString dodajKraj = ui->lineEditDodajKraj->text();
            ui->comboBoxDodajKraj->addItem(dodajKraj);
            ui->lineEditDodajKraj->setText("");
        }else{
            cout<<"Przeszukałem wszytskie Kraje. Jest na liscie."<<endl;
        }
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego Kraju.");
    }
    ui->comboBoxDodajKraj->setDuplicatesEnabled(false); // ustawiam aby nie było duplikatów
    ui->lineEditDodajKraj->setText("");


// zrobic petle i sprawdac czy text wprowadzony juz jest po kazdym elemenecie.
// jezeli jest wyswiwtlic msgbox ze juz jest.

//Próbuje srotowania
//string  items[] = ui->comboBoxDodajMiasto->count();

}

void KontrahentDodajKraj::on_pushButton_clicked()
{
    // Zapisz
    fstream checkFlagsinKraj;
    cout << "Zapisuje " << endl;
    // musze zapisać do pliku
    plikOdczytDodajKraj
        .open("C:/Defaults/Pliki/ZapisKraj.txt",
              ios::out
                  | ios::trunc); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.

    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;

    iloscElementowWcombo = ui->comboBoxDodajKraj->count();
    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;
        plikOdczytDodajKraj << ui->comboBoxDodajKraj->itemText(i).toStdString() << endl;
    }
    plikOdczytDodajKraj.close();
    //
    checkFlagsinKraj
        .open("C:/Defaults/Pliki/CheckFlagsInKraj.txt",
              ios::in
                  | ios::trunc); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    checkFlagsinKraj<<"1";
    checkFlagsinKraj.close();


    //ui->Jak zrobic aby comboxy na urzadzeniach się odswiezały
    //ui->comboBoxDodajMiasto->rep
    //destroy();


}

void KontrahentDodajKraj::on_pushButton_3_clicked()
{
    // Usuń
    ui->comboBoxDodajKraj->removeItem(ui->comboBoxDodajKraj->currentIndex());
}

void KontrahentDodajKraj::on_pushButton_4_clicked()
{
    // Zamknij
    destroy();

}

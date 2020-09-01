#include "ustawienia.h"
#include "Timery/timedate.h"
#include "time.h"
#include "ui_ustawienia.h"
#include <ctime>
#include <direct.h> //biblio do stworzenia katalogu poprzez mkdir
#include <direct.h>
#include <fstream>
#include <iostream>
#include <iterator> // do obliczenia rozmiaru tablicy FN
#include <windows.h>
#include <QMessageBox>

using namespace std;
QString aktHour;
fstream fileUstawienia, fileUstawienia1;
Ustawienia::Ustawienia(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ustawienia)
{
    ui->setupUi(this);

    cout << "Jestem w ustawieniach" << endl;
}

Ustawienia::~Ustawienia()
{
    delete ui;
}

QString Ustawienia::pobierzDate(QString aktHour)
{
    /*int tm_sec; //Sekundy. Zakres [0..61]
    int tm_min; //Minuty. Zakres [0..59]
    int tm_hour; //Godziny. Zakres [0..23]
    int tm_mday; //Dzień miesiąca. Zakres [1..31]
    int tm_mon; //Miesiąc. Zakres [0..11]
    int tm_year = 0; *///Obecny rok. Lata zaczynają się liczyć od roku 1900, czyli: wartość 0 = 1900 rok.
    //    /*int tm_wday; //Dzień tygodnia. Zakres [0..6]. 0 = Niedziela; 1 = Poniedziałek; itd...
    //    int tm_yday; //Dzień roku. Zakres [0..365].
    //    int tm_isdst; //Letnie/zimowe przesunięcie czasowe. Jeśli wartość jest większa od 0 to przesunięcie czasowe jest 'aktywne'. */Jeśli wartość mniejsza od 0 to informacja jest niedostępna.

    //    time_t czas;
    //    struct tm *data;
    //    char godzina [80];
    //    time

    time_t czas;
    tm timeinfo;
    QString qStrMin, qStrGodz, qStrSek, qStrDzien, qStrMiesiac, stringDzienTygodnia;
    //QString aktHour;
    TimeDate *timeDate = new TimeDate();

    time(&czas);
    timeinfo = *localtime(&czas);
    int godzina = timeinfo.tm_hour;
    int minuta = timeinfo.tm_min;
    int sekunda = timeinfo.tm_sec;
    int dzien = timeinfo.tm_mday;
    int miesiac = timeinfo.tm_mon;
    int rok = timeinfo.tm_year;
    //int dzienTygodnia = timeinfo.tm_wday;
    miesiac = miesiac + 1;
    rok = rok + 1900;
    //dzienTygodnia = dzienTygodnia + 1;

    qStrMin = timeDate->changeStringsMin(minuta);
    qStrSek = timeDate->changeStringsSek(sekunda);
    qStrDzien = timeDate->changeStringsDzien(dzien);
    qStrGodz = timeDate->changeStringsGodz(godzina);
    qStrMiesiac = timeDate->changeStringsMiesiac(miesiac);
    //stringDzienTygodnia = timeDate->changeStringsDzienTygodnia(dzienTygodnia);

    aktHour = QString::number(rok) + "." + qStrMiesiac + "." + qStrDzien + "." + qStrGodz + "."
              + qStrMin + "." + qStrSek;

    return aktHour;
    //cout<<aktHour<<endl;

    //    cout<<QString::number(rok) + "." + qStrMiesiac + "." + qStrDzien+qStrGodz + ":" + qStrMin + ":" + qStrSek<<endl;

    //    ui->labelZegara->setText(qStrGodz + ":" + qStrMin + ":" + qStrSek);
    //    ui->labelDaty->setText(QString::number(rok) + "." + qStrMiesiac + "." + qStrDzien);

    //    ui->labelDzien->setText(stringDzienTygodnia)

    //    cout <<tm_year<<endl;//+ "."+ tm_mon ;//+ "."  tm_mday"." tm_hour<<endl;
}

void Ustawienia::on_pushButton_clicked()
{
    string stringFile = "Backup/";
    string patchBasic = "C:/Defaults/Pliki/";
    string tableOfstrings[11] = {"Kontrahent.txt",
                     "CheckFlagsInMiasto.txt",
                     "CheckFlagsInWojewodztwo.txt",
                     "Urzadzenie.txt",
                     "ZapisNrSeryjny.txt",
                     "ZapisModel.txt",
                     "ZapisProducenta.txt",
                     "CheckFlagsInKraj.txt",
                     "ZapisMiasta.txt",
                     "ZapisWojewodztwa.txt",
                     "ZapisKraj.txt"};

    QString aktHours = pobierzDate(aktHour);
    ui->lblData->setText(aktHours);
    // Kopia danych plików
    string aktHours1 = aktHours.toStdString();
    string aktHours2 = patchBasic + stringFile + aktHours1 + "/";

    _mkdir(aktHours2.c_str());

    //TODO: dodac nowy katalog z dataa i godzina z minutami do Backupa

    //for (int i = 0;i<=sizeof(fN)-1;i++)
    int sizeOfTable = tableOfstrings->size();
    for (int i = 0; i < sizeOfTable; i++) {
        fileUstawienia.open(patchBasic + tableOfstrings[i], ios::in);
        fileUstawienia1.open(aktHours2 + tableOfstrings[i], ios::out);
        string linia;

        int nr_lini = 1;
        while (getline(fileUstawienia, linia)) {
            ui->comboBox->addItem(linia.c_str());
            fileUstawienia1 << linia.c_str() << endl;
            cout << linia.c_str() << endl;
            nr_lini++;
        }
        ui->comboBox->clear();

        fileUstawienia.close();
        fileUstawienia1.close();
        cout << "Zapisano: " + aktHours2 << endl;
    }
    //    QMessageBox msgBox;
    //    msgBox.setText("Kopia Bazy Danych zrobiona");
    QMessageBox::information(this, "Ostrzeżenie", "Kopia Bazy Danych zrobiona.");
}

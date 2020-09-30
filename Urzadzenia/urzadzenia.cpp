#include "urzadzenia.h"
#include "mainwindow.h"
#include "time.h"
#include "ui_urzadzenia.h"
#include "urzadzeniadodajmodel.h"
#include "urzadzeniadodajnrseryjny.h"
#include "urzadzeniadodajproducenta.h"
#include "Ustawienia/ustawienia.h"
#include "Files/checkfiles1.h"
#include "Timery/timedate.h"
#include <Info/info.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QString>
#include <QTimer>

using namespace std;

string stringLabela4 = ("Producent: , Model: , Nr. Seryjny: ");
QString zaznaczono;
fstream plikUrzadzenia;
int iloscUrzadzen =0;

int checkFlagsVariableProducent =0;
int checkFlagsVariableModel =0;

Urzadzenia::Urzadzenia(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Urzadzenia)
{
    ui->setupUi(this);
    ui->comboBox->addItem("");
    ui->comboBox_2->addItem("");
    ui->comboBox_3->addItem("");
    ui->lineEditNumber->setText(QString::number(iloscUrzadzen));

    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    QString file1 = "C:/Defaults/Pliki/1.DB.txt";
    QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
    QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
    QString file4 = "C:/Defaults/Pliki/4.ZapisKraj.txt";
    QString file5 = "C:/Defaults/Pliki/5.ZapisMiasta.txt";
    QString file6 = "C:/Defaults/Pliki/6.ZapisWojewodztwa.txt";
    QString file7 = "C:/Defaults/Pliki/7.ZapisProducenta.txt";
    QString file8 = "C:/Defaults/Pliki/8.ZapisModel.txt";
    QString file9 = "C:/Defaults/Pliki/9.ZapisNrSeryjny.txt";
    QString file10 = "C:/Defaults/Pliki/10.CheckFlagsInMiasto.txt";
    QString file11 = "C:/Defaults/Pliki/11.CheckFlagsInKraj.txt";
    QString file12 = "C:/Defaults/Pliki/12.CheckFlagsInWojewodztwa.txt";
    QString file13 = "C:/Defaults/Pliki/13.CheckFlagsInKrajKontrahentShow.txt";
    QString file14 = "C:/Defaults/Pliki/14.CheckFlagsInMiastoKontrahentShow.txt";
    QString file15 = "C:/Defaults/Pliki/15.CheckFlagsInWojewodztwoKontrahentShow.txt";

    howMuchDevice();

    //Wczytuje modele z pliku
    plikUrzadzenia.open(file8.toStdString(), ios::in);
    if (plikUrzadzenia.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikUrzadzenia, linia)) {
        ui->comboBox_2->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }

    plikUrzadzenia.close();
    // wczytuj pliki z producenta
    plikUrzadzenia.open(file7.toStdString(), ios::in);
    if (plikUrzadzenia.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia1;
    int nr_lini1 = 1;
    while (getline(plikUrzadzenia, linia1)) {
        ui->comboBox->addItem(linia1.c_str());
        cout << linia1.c_str() << endl;
        nr_lini1++;
    }
    plikUrzadzenia.close();
    //wczytaj numery seryjne z pliku
    plikUrzadzenia.open(file9.toStdString(), ios::in);
    if (plikUrzadzenia.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia2;
    int nr_lini2 = 1;
    while (getline(plikUrzadzenia, linia2)) {
        ui->comboBox_3->addItem(linia2.c_str());
        cout << linia2.c_str() << endl;
        nr_lini2++;
    }
    plikUrzadzenia.close();

    countriesListModel = new QStringListModel(this);

    ui->countriesList->setModel(countriesListModel);
    int row = countriesListModel->rowCount(); // pobieram liczbę wierszy

    countriesListModel->insertRow(row);                    // wstawiam dodatkowy wiersz na końcu
    QModelIndex index = countriesListModel->index(row, 0); // pobieram obiekt wstawionego indeksu
    //countriesListModel->setData(index, QVariant("*"));

    ui->pushButton->setEnabled(false);
    ui->BtnUrzaZapisz->setEnabled(false);


}


void Urzadzenia::howMuchDevice()
{
QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";

    plikUrzadzenia.open(file3.toStdString(), ios::in);
    if (plikUrzadzenia.good() ==false)
    {
        cout<<"Plik nie istnieje";

    }
    string linia;

    int nr_lini = 1;
    while (getline(plikUrzadzenia, linia))
    {
        iloscUrzadzen ++;
        cout << linia.c_str()<<endl;
        nr_lini++;
    }
    cout<<"ilosc Urzadzen wczytanych stringów: "<< iloscUrzadzen<<endl;
    iloscUrzadzen = iloscUrzadzen /4;
     cout<<"ilosc Urzadzen po 4: "<< iloscUrzadzen<<endl;
    ui->LblNumberAnaliz->setText(QString::number(iloscUrzadzen));
    plikUrzadzenia.close();
    iloscUrzadzen ++;
     cout<<"ilosc Urzadzen z nastepnym: "<< iloscUrzadzen<<endl;
     ui->lineEditNumber->setText(QString::number(iloscUrzadzen));


}
void Urzadzenia::myfunctiontimer()
{time_t czas;
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


Urzadzenia::~Urzadzenia()
{
    delete ui;
}

void Urzadzenia::on_BtnUrzaZapisz_clicked()
{QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
    cout << "Zapisz" << endl;

    plikUrzadzenia.open(file3.toStdString(),ios::out | ios::app);





    for (int i=0;i<=ui->comboBox_4->count()-1;i++) {
        plikUrzadzenia<<ui->comboBox_4->itemText(i).toStdString()<<endl;


    }

    plikUrzadzenia<<""<<endl; //- Tutuaj wrzucam pustą linię na info o przypsianiu
    plikUrzadzenia.close();
    ui->BtnUrzaZapisz->setEnabled(false);
}

void Urzadzenia::on_BtnUrzaZamknij_clicked()
{timer->stop();
    destroy();
}

void Urzadzenia::on_countriesList_clicked(const QModelIndex &index)
{
    int rowCount = countriesListModel->rowCount();
    countriesListModel->insertRow(rowCount);
    countriesListModel->setData(index, QVariant("Cos innego")); // i ustawiam tekst na "*"

    ui->label_4->setText(zaznaczono + " " + ui->comboBox->currentText());
}

void Urzadzenia::on_comboBox_textActivated(const QString )
{
    ui->label_4->setText("Producent: " + ui->comboBox->currentText());
    ui->label_6->setText("Model: "+ ui->comboBox_2->currentText());
    ui->label_7->setText("Numer Seryjny: "+ui->lineEditNrSeryjny->text());
}

void Urzadzenia::on_comboBox_2_textActivated(const QString )
{
    ui->label_4->setText("Producent: " + ui->comboBox->currentText());
    ui->label_6->setText("Model: "+ ui->comboBox_2->currentText());
    ui->label_7->setText("Numer Seryjny: "+ui->lineEditNrSeryjny->text());
}

void Urzadzenia::on_comboBox_3_textActivated(const QString )
{
    ui->label_4->setText("Producent: " + ui->comboBox->currentText());
    ui->label_6->setText("Model: "+ ui->comboBox_2->currentText());
    ui->label_7->setText("Numer Seryjny: "+ui->lineEditNrSeryjny->text());
}

void Urzadzenia::on_actionDodaj_Model_triggered()
{
    UrzadzeniaDodajModel *urzDodModel = new UrzadzeniaDodajModel(this);
    urzDodModel->show();
}

void Urzadzenia::on_actionDodaj_Producenta_triggered()
{
    UrzadzeniaDodajProducenta *urzDodProd = new UrzadzeniaDodajProducenta(this);
    urzDodProd->show();
}

void Urzadzenia::on_actionDodaj_Numer_Seryjny_triggered()
{
    UrzadzeniaDodajNrSeryjny *urzDodNrSer = new UrzadzeniaDodajNrSeryjny(this);
    urzDodNrSer->show();
}

void Urzadzenia::on_actionInformacja_triggered()
{
    Info *info= new Info(this);
    info->show();
}
//Info do Gita
void Urzadzenia::on_pushButton_clicked()
{
    // Dodaj do comboBoxa
    ui->comboBox_4->addItem(ui->lineEditNumber->text());
    ui->comboBox_4->addItem(ui->comboBox->currentText());
    ui->comboBox_4->addItem(ui->comboBox_2->currentText());
    ui->comboBox_4->addItem(ui->lineEditNrSeryjny->text());
    ui->BtnUrzaZapisz->setEnabled(true);
    ui->pushButton->setEnabled(false);
    ui->label_4->setText("Producent: " + ui->comboBox->currentText());
    ui->label_6->setText("Model: "+ ui->comboBox_2->currentText());
    ui->label_7->setText("Numer Seryjny: "+ui->lineEditNrSeryjny->text());
}
void Urzadzenia::on_actionOpcje_triggered()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}

void Urzadzenia::on_comboBox_highlighted(const QString )
{
    // Odswiiez producenta
    fstream checkFlags;
    QString file16 = "16.CheckFlagsInProducentUrzadzenia.txt";
    CheckFiles1 *checkFiles = new CheckFiles1(this);

    checkFlagsVariableProducent = checkFiles->checkFlagsProducent(checkFlagsVariableProducent);

    if (checkFlagsVariableProducent != 0) {
        cout << "textHighlighted" << endl;
        QStringList listaProducent = QStringList();

        ui->comboBox->clear();
        wczytajProducenta();
        int ostatniindex = ui->comboBox->count() - 1;
        for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
            listaProducent.push_back(ui->comboBox->itemText(iZmienna).toUtf8());
        }
        sort(listaProducent.begin(), listaProducent.end());
        ui->comboBox->clear();
        for (int kZmienna = 0; kZmienna <= listaProducent.count() - 1; kZmienna++) {
            ui->comboBox->addItem(listaProducent.at(kZmienna));
        }
    }
    checkFlags.open(file16.toStdString(), ios::out | ios::trunc);
    checkFlags << "0" << endl;
    checkFlags.close();


}

void Urzadzenia::wczytajProducenta()
{QString file7 = "C:/Defaults/Pliki/7.ZapisProducenta.txt";
    fstream plikKontrahent;
    //Wczytuje miasta z pliku
    plikKontrahent.open(file7.toStdString(), ios::in);
    if (plikKontrahent.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikKontrahent, linia)) {
        ui->comboBox->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }

    plikKontrahent.close();

}
void Urzadzenia::wczytajModel()
{QString file8 = "C:/Defaults/Pliki/8.ZapisModel.txt";
    fstream plikKontrahent;

    plikKontrahent.open(file8.toStdString(), ios::in);
    if (plikKontrahent.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikKontrahent, linia)) {
        ui->comboBox_2->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }

    plikKontrahent.close();

}
void Urzadzenia::on_comboBox_2_highlighted(const QString )
{
    // odwiez model.

    fstream checkFlags;
    QString file17 = "17.CheckFlagsInModelUrzadzenia.txt";
    CheckFiles1 *checkFiles = new CheckFiles1(this);

    checkFlagsVariableModel = checkFiles->checkFlagsModel(checkFlagsVariableModel);

    if (checkFlagsVariableModel != 0) {
        cout << "textHighlighted" << endl;
        QStringList listaModel = QStringList();

        ui->comboBox_2->clear();
        wczytajModel();
        int ostatniindex = ui->comboBox_2->count() - 1;
        for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
            listaModel.push_back(ui->comboBox_2->itemText(iZmienna).toUtf8());
        }
        sort(listaModel.begin(), listaModel.end());
        ui->comboBox_2->clear();
        for (int kZmienna = 0; kZmienna <= listaModel.count() - 1; kZmienna++) {
            ui->comboBox_2->addItem(listaModel.at(kZmienna));
        }
    }
    checkFlags.open(file17.toStdString(), ios::out | ios::trunc);
    checkFlags << "0" << endl;
    checkFlags.close();
    ui->pushButton->setEnabled(true);

}

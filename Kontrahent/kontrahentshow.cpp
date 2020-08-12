#include "kontrahentshow.h"
#include "ui_kontrahentshow.h"
#include <String>
#include <fstream>
#include <iostream>
#include <ostream>
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
{ // button zamknij
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
                                  QVariant p13,QVariant p14)
{
    cout << "Chche wysiwretlic i dopisac do labeli wybranego kontrahenta" << endl;
ui->lblNumerPorz->setText(p1.toString());
    ui->leNazwa->setText(p2.toString());
    ui->leImie->setText(p3.toString());
    ui->leNazwisko->setText(p4.toString());
    ui->leKraj->setText(p5.toString());
    ui->comboBoxKraj->addItem(p5.toString());
    ui->comboBoxMiasta->addItem(p6.toString());
    ui->comboBoxWojewodztwa->addItem(p7.toString());
    ui->leRegion->setText(p7.toString());
    ui->leMiasto->setText(p6.toString());
    ui->leKod->setText(p8.toString());
    ui->leUlica->setText(p9.toString());
    ui->leNrDomu->setText(p10.toString());
    ui->leTelefon->setText(p11.toString());
    ui->leTelPryw->setText(p12.toString());
    ui->leEmail->setText(p13.toString());
    ui->leUrl->setText(p14.toString());

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
void KontrahentShow::showWojewodztwa()
{
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
{
    fstream plikOdczytDodajMiasto;
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
    cout << "Zapisuje po edycji" << endl;
// Wczytać dane do cmoboBoxaPomoc.
    // Znalesc te same dane co sa w trybie edycji.
    // skasować te dane.
    // Dopisać te nowe
    //Zapisać wszytsko.
    //
    fstream file;
    string kontrahent;
    //Zapisz
    cout << "Zapisuje" << endl;

    file.open("C:/Defaults/Pliki/Kontrahent.txt", ios::out | ios::app);

    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;

    //TODO: Przypisac automatyczą numeracje WCZYTAJNUMER
    //tymczasowo

    ui->comboBoxPomoc->addItem(ui->lblNumerPorz->text());
    ui->comboBoxPomoc->addItem(ui->leNazwa->text());
    ui->comboBoxPomoc->addItem(ui->leImie->text());
    ui->comboBoxPomoc->addItem(ui->leNazwisko->text());
    ui->comboBoxPomoc->addItem(ui->comboBoxKraj->currentText());
    //Wczytaj wojewodztwo
    ui->comboBoxPomoc->addItem(ui->comboBoxWojewodztwa->currentText());
    //Wczytaj miasto
    ui->comboBoxPomoc->addItem(ui->comboBoxMiasta->currentText());
    ui->comboBoxPomoc->addItem(ui->leKod->text());
    ui->comboBoxPomoc->addItem(ui->leUlica->text());
    ui->comboBoxPomoc->addItem(ui->leNrDomu->text());
    ui->comboBoxPomoc->addItem(ui->leTelefon->text());
    ui->comboBoxPomoc->addItem(ui->leTelPryw->text());
    ui->comboBoxPomoc->addItem(ui->leEmail->text());
    ui->comboBoxPomoc->addItem(ui->leUrl->text());

    //TODO: Sprawdzam czy moge ominac comboBox Pomoc

    //plikKontrahent<<ui->


    // TODO: Zobaczc i porównac po id czy jest taki w plikach.

    //int QComboBox::findText(const QString &text, Qt::MatchFlags flags) const;

//    int findPosition  = ui->comboBoxPomoc->findText(ui->lblNumerPorz->text(), Qt::MatchContains);

    int findPosition  = ui->comboBoxPomoc->findText(ui->leNazwa->text(), Qt::MatchContains);
    ui->label_14->setText(QString::number(findPosition));

    fstream fileKontrahent;

    //fileKontrahent.open("C:/Defaults/Pliki/Kontrahent.txt", ios::in ||ios::trunc);
//    if (fileKontrahent.good() == false) {
//        cout << "Plik nie istnieje !!!!!";
//        //exit(0);
   // }
    string linia;
    while (getline(file, linia)) {
        ui->comboBoxPomoc1 ->addItem(linia.c_str());
        //if (nr_lini > 0)

        //ui->comboBoxWczytajMiasta->addItem(linia.c_str());
        cout << linia.c_str() << endl;

    }

    //fileKontrahent.close();

    int findPosition2 =  ui->comboBoxPomoc1->findText(ui->leNazwa->text(), Qt::MatchContains);

    ui->comboBoxPomoc1->removeItem(findPosition2-1);
    ui->comboBoxPomoc1->removeItem(findPosition2);
    ui->comboBoxPomoc1->removeItem(findPosition2+1);
    ui->comboBoxPomoc1->removeItem(findPosition2+2);
    ui->comboBoxPomoc1->removeItem(findPosition2+3);
    ui->comboBoxPomoc1->removeItem(findPosition2+4);
    ui->comboBoxPomoc1->removeItem(findPosition2+5);
    ui->comboBoxPomoc1->removeItem(findPosition2+6);
    ui->comboBoxPomoc1->removeItem(findPosition2+7);
    ui->comboBoxPomoc1->removeItem(findPosition2+8);
    ui->comboBoxPomoc1->removeItem(findPosition2+9);
    ui->comboBoxPomoc1->removeItem(findPosition2+10);
    ui->comboBoxPomoc1->removeItem(findPosition2+11);
    ui->comboBoxPomoc1->removeItem(findPosition2+12);
    ui->comboBoxPomoc1->removeItem(findPosition2+13);


    //teraz zapisac itemy z comboxaPomoc1

    int iloscWComboPomoc1 = ui->comboBoxPomoc1->count();

    for(int i=0;i<=iloscWComboPomoc1;i++)
    {
        file<<ui->comboBoxPomoc1->itemText(i).toStdString()<<endl;

    }



//    file << ui->lblNumerPorz->text().toStdString() << endl;
//    file << ui->leNazwa->text().toStdString() << endl;
//    file << ui->leImie->text().toStdString() << endl;
//    file << ui->leNazwisko->text().toStdString() << endl;
//    //TODO: Kraj na ComboBoxie
//    file << ui->comboBoxKraj->currentText().toStdString() << endl;
//    //file << ui->leKraj->text().toStdString() << endl;
//    //Wczytaj wojewodztwo
//    file << ui->comboBoxWojewodztwa->currentText().toStdString() << endl;
//    ;

//    //Wczytaj miasto
//    file << ui->comboBoxMiasta->currentText().toStdString() << endl;
//    ;

//    file << ui->leKod->text().toStdString() << endl;
//    file << ui->leUlica->text().toStdString() << endl;
//    file << ui->leNrDomu->text().toStdString() << endl;
//    file << ui->leTelefon->text().toStdString() << endl;
//    file << ui->leTelPryw->text().toStdString() << endl;
//    file << ui->leEmail->text().toStdString() << endl;
//    file << ui->leUrl->text().toStdString() << endl;

    iloscElementowWcombo = ui->comboBoxPomoc->count();

    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;
    }
    file.close();
    //ui->lineEditWczytajNumer->setText(QString::number(iloscKontrahentow));
    //
}

void KontrahentShow::on_pushButton_4_clicked()
{
    //Usuń kontrahenta
    cout << "Kontrahent usunięty" << endl;
}

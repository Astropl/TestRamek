#include "ustawienia.h"
#include "ui_ustawienia.h"
#include <iostream>
#include <fstream>
#include <direct.h> //biblio do stworzenia katalogu poprzez mkdir
#include <windows.h>

using namespace std;

fstream fileUstawienia,fileUstawienia1;
Ustawienia::Ustawienia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ustawienia)
{
    ui->setupUi(this);

    cout<<"Jestem w ustawieniach"<<endl;
}

Ustawienia::~Ustawienia()
{
    delete ui;
}

void Ustawienia::on_pushButton_clicked()
{
    // Kopia danych plików

    mkdir("C:/Defaults/Pliki/Backup");


    //char ch;

    string stringFile = "Backup/";
    string patchBasic ="C:/Defaults/Pliki/";
    string fN [11]= {"Kontrahent.txt","CheckFlagsInMiasto.txt","CheckFlagsInWojewodztwo.txt", "Urzadzenie.txt", "ZapisNrSeryjny.txt", "ZapisModel.txt", "ZapisProducenta.txt", "CheckFlagsInKraj.txt", "ZapisMiasta.txt", "ZapisWojewodztwa.txt", "ZapisKraj.txt"};




//TODO: dodac nowy katalog z dataa i godzina z minutami do Backupa


    for (int i = 0;i<=fN->size()-1;i++) {

        fileUstawienia.open(patchBasic+fN[i],ios::in);
        fileUstawienia1.open(patchBasic+stringFile+fN[i],ios::out);
        string linia;

        int nr_lini = 1;
        while (getline(fileUstawienia, linia))
        {
            //iloscUrzadzen ++;
            ui->comboBox->addItem( linia.c_str());
            fileUstawienia1<<linia.c_str()<<endl;
            cout<<linia.c_str()<<endl;
            nr_lini++;
        }
        ui->comboBox->clear();



//        ifstream file1(patchBasic+fN[i]);
//        ofstream file2(patchBasic+stringFile+fN[i]);

//        if (!file1)
//            cerr <<"Nie moge ptworzyc pliku wejsciowego\n";
//        if(!file2)
//            cerr << "Nie moge ptworzyc pliku wyjsciowego\n";
//        while(file1 && file1.get(ch))
//            file2.put(ch);

    }
    fileUstawienia.close();
fileUstawienia1.close();


//    while(file1 && file2.get(ch) )
    //          file2.put(ch);



}

#include "urzadzeniadodajmodel.h"
#include "ui_urzadzeniadodajmodel.h"
#include <iostream>
#include <QMessageBox>

using namespace std;

UrzadzeniaDodajModel::UrzadzeniaDodajModel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaDodajModel)
{
    ui->setupUi(this);
}

UrzadzeniaDodajModel::~UrzadzeniaDodajModel()
{
    delete ui;
}

void UrzadzeniaDodajModel::on_pushButton_clicked()
{ //sprawdzam czy label dodawania modelu jest pusty
    if (ui->lineEditDodajModel->text() != "") {
        cout << "Dodaje model analizatora" << endl;
        QString dodajModel = ui->lineEditDodajModel->text();

        ui->comboBoxDodajModel->addItem(dodajModel);
        ui->lineEditDodajModel->setText("");
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego modelu.");
    }
}

void UrzadzeniaDodajModel::on_pushButton_2_clicked()
{
    cout<<"Zapisuje i wychodze z okienka"<<endl;
    // musze zapisać do pliku

    destroy();
}

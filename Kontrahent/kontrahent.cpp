#include "kontrahent.h"
#include "ui_kontrahent.h"
#include <iostream>


using namespace std;

Kontrahent::Kontrahent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kontrahent)
{
    ui->setupUi(this);
}

Kontrahent::~Kontrahent()
{
    delete ui;
}

void Kontrahent::on_pushButton_clicked()
{
    //Zapisz
    cout<<"Zapisuje"<<endl;
}

void Kontrahent::on_pushButton_2_clicked()
{
    //Wyjdz
    cout<<"Wychodze z Kontrahentów"<<endl;
    destroy();
}

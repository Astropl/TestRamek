#include "ustawienia.h"
#include "ui_ustawienia.h"
#include <iostream>




using namespace std;
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

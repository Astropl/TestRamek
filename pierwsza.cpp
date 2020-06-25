#include "pierwsza.h"
#include "ui_pierwsza.h"
#include "Timery/zegary.h"
#include <iostream>
using namespace std;


//void Pierwsza::intZegary()
//{
//    cout<<"zmienamaiay zegar"<<endl;
//    Zegary *zegary = new Zegary();
//    zegary->intZegary();
//}

int godzina;
int wynik;
string zmiennas;
Pierwsza::Pierwsza(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pierwsza)
{
    ui->setupUi(this);
    ui->labelZegara->setText(" cos tam");
    //===================
    cout<<"zmienamaiay zegar"<<endl;
    Zegary *zegary = new Zegary();

     wynik= zegary->myfunctiontimer()  ;
    //zegary->intZegary();
    //=================
    //intZegary();
    cout<<wynik <<endl;
    //labelZegara
    zmianaLabela(wynik);
}

int Pierwsza::zmianaLabela(int sekunda)

{
    //std::string str = std::to_string(num);
    //int i = 42;
    //QString s = QString::number(i);
    cout<<"wzlasł"<<endl;
    ui->labelZegara->setText(QString(sekunda));
    return sekunda ;
}
Pierwsza::~Pierwsza()
{
    delete ui;
}

void Pierwsza::on_pushButton_clicked()
{
    destroy();
}
//labelZegara na Timery/zegary.h
//void Pierwsza::on_labelZegara_linkActivated(const QString &link)
//{
//    ui->labelZegara->setText("fdf");
//}


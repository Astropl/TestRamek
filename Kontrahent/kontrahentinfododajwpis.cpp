#include "kontrahentinfododajwpis.h"
#include "ui_kontrahentinfododajwpis.h"
#include "iostream"
#include <QTableView>

using namespace std;

KontrahentInfoDodajWpis::KontrahentInfoDodajWpis(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KontrahentInfoDodajWpis)
{
    ui->setupUi(this);
    show();
}

KontrahentInfoDodajWpis::~KontrahentInfoDodajWpis()
{
    delete ui;
}

void KontrahentInfoDodajWpis::on_pushButton_2_clicked()
{
    //Zapisz
}

void KontrahentInfoDodajWpis::on_pushButton_clicked()
{
    //Zamknij
    destroy();

}
void KontrahentInfoDodajWpis::init()
{
    cout<<"Jstem w show"<<endl;


}

void KontrahentInfoDodajWpis::on_checkBox_stateChanged(int arg1)
{
    //CheckBox zmiania

    if (ui->checkBox->isChecked())
    {
        cout <<"Zaznaczony"<<endl;
    }
    else
    {
        cout<<"Nie zazanaczony"<<endl;
    }

}

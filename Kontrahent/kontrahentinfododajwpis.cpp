#include "kontrahentinfododajwpis.h"
#include "iostream"
#include "ui_kontrahentinfododajwpis.h"
#include <QTableView>

using namespace std;

KontrahentInfoDodajWpis::KontrahentInfoDodajWpis(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentInfoDodajWpis)
{
    ui->setupUi(this);
    uncheckedCheckBox();
    show();
}
void KontrahentInfoDodajWpis::setDate()
{
    //Pousawiaj date do obrówki

}
void KontrahentInfoDodajWpis::checkedCheckBox()
{
    //Checked CheckBox
    cout << "Zaznaczony" << endl;
    ui->comboBox->setVisible(true);
    ui->textEdit_2->setVisible(true);
    ui->label_10->setVisible(true);
    ui->label_11->setVisible(true);
    ui->label_9->setVisible(true);
}
void KontrahentInfoDodajWpis::uncheckedCheckBox()
{
    //Unchecked CheckBox
    cout << "Nie zazanaczony" << endl;
    ui->comboBox->setVisible(false);
    ui->textEdit_2->setVisible(false);
    ui->label_10->setVisible(false);
    ui->label_11->setVisible(false);
    ui->label_9->setVisible(false);
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
    cout << "Jstem w show" << endl;
}

void KontrahentInfoDodajWpis::on_checkBox_stateChanged(int arg1)
{
    //CheckBox zmiania

    if (arg1 == 2) //if (ui->checkBox->isChecked())
    {              //Zaznaczony
        checkedCheckBox();
        cout << "Arg: " << arg1 << endl;

    } else if (arg1 == 0) {
        //Niezaznaczony
        uncheckedCheckBox();
        cout << "Arg: " << arg1 << endl;
    }
}

#include "kontrahentinfo.h"
#include "ui_kontrahentinfo.h"

#include "iostream"

using namespace std;

KontrahentInfo::KontrahentInfo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentInfo)
{
    ui->setupUi(this);
}

KontrahentInfo::~KontrahentInfo()
{
    delete ui;
}

void KontrahentInfo::on_pushButton_clicked()
{
    destroy();
}

void KontrahentInfo::wyswietl(QVariant p1,
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
                              QVariant p13,
                              QVariant p14,
                              QVariant p15,
                              QVariant p16,
                              QVariant p17,
                              QVariant p18,
                              QVariant p19)
{
    cout << "Jestem w kontrahent Info Wyswietl" << endl;
    QVariant przypisanyZp5 = p5; // info o przypisaniu analizatora do kontr.
    ui->lblUrzad_2->setText(p1.toString());
    ui->lblProduc_2->setText(p2.toString());
    ui->lblModel_2->setText(p3.toString());
    ui->lblNrSeryjny_2->setText(p4.toString());
    ui->lblNrKontrahent_2->setText(p6.toString());
    ui->lblNazwa_2->setText(p7.toString());
    ui->lblImie_2->setText(p8.toString());
    ui->lblNazwisko_2->setText(p9.toString());
    ui->lblKraj_2->setText(p10.toString());
     ui->lblRegion_2->setText(p11.toString());
    ui->lblMiasto_2->setText(p12.toString());
    ui->lblZipCode_2->setText(p13.toString());
    ui->lblUlica_2->setText(p14.toString());
    ui->lblNrDomu_2->setText(p15.toString());
    ui->lblTelefon_2->setText(p16.toString());
    ui->lblTelDodat_2->setText(p17.toString());
    ui->lblEmail_2->setText(p18.toString());
    ui->lblUrl_2->setText(p19.toString());
}
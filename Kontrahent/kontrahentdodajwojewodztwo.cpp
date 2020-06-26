#include "kontrahentdodajwojewodztwo.h"
#include "ui_kontrahentdodajwojewodztwo.h"

KontrahentDodajWojewodztwo::KontrahentDodajWojewodztwo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KontrahentDodajWojewodztwo)
{
    ui->setupUi(this);
}

KontrahentDodajWojewodztwo::~KontrahentDodajWojewodztwo()
{
    delete ui;
}

void KontrahentDodajWojewodztwo::on_pushButton_clicked()
{
    destroy();

}

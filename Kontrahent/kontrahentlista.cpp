#include "kontrahentlista.h"
#include "ui_kontrahentlista.h"

KontrahentLista::KontrahentLista(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KontrahentLista)
{
    ui->setupUi(this);
}

KontrahentLista::~KontrahentLista()
{
    delete ui;
}

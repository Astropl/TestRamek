#include "kontrahent.h"
#include "ui_kontrahent.h"

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

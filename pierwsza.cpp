#include "pierwsza.h"
#include "ui_pierwsza.h"

Pierwsza::Pierwsza(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pierwsza)
{
    ui->setupUi(this);
}

Pierwsza::~Pierwsza()
{
    delete ui;
}

void Pierwsza::on_pushButton_clicked()
{
    destroy(this);
}

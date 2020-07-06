#include "trzecia.h"
#include "ui_trzecia.h"
#include <Info/info.h>


Trzecia::Trzecia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Trzecia)
{
    ui->setupUi(this);
}

Trzecia::~Trzecia()
{
    delete ui;
}

void Trzecia::on_pushButton_clicked()
{
    destroy();
}

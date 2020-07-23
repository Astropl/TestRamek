#include "druga.h"
#include "ui_druga.h"
#include <Info/info.h>

Druga::Druga(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Druga)
{
    ui->setupUi(this);
}

Druga::~Druga()
{
    delete ui;
}

void Druga::on_pushButton_clicked()
{
        destroy();
}
//Info do Gita
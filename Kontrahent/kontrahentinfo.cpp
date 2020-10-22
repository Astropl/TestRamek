#include "kontrahentinfo.h"
#include "ui_kontrahentinfo.h"

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

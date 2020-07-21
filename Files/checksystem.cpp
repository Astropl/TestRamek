#include "checksystem.h"
#include "ui_checksystem.h"

CheckSystem::CheckSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckSystem)
{
    ui->setupUi(this);
}

CheckSystem::~CheckSystem()
{
    delete ui;
}

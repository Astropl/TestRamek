#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <pierwsza.h>
#include <druga.h>
#include <trzecia.h>

#include <Kontrahent/kontrahent.h>
#include <Urzadzenia/urzadzenia.h>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Pierwsza *pierwsza = new Pierwsza(this);
    pierwsza->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    Pierwsza *druga = new Pierwsza(this);
    druga->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    //trzecia
    Trzecia *trzecia = new Trzecia(this);
    trzecia->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    cout << "Zamknij" << endl;
    destroy();
}

void MainWindow::on_pushButton_5_clicked()
{
    Kontrahent *kontrahent = new Kontrahent(this);
    kontrahent->show();

}

void MainWindow::on_pushButton_6_clicked()
{
    Urzadzenia *urzadzenia = new Urzadzenia(this);
    urzadzenia ->show();

}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Kontrahent/kontrahentlista.h"
#include <QApplication>
#include <QMainWindow>
#include <pierwsza.h>
#include <druga.h>
#include <trzecia.h>
#include <Info/info.h>

#include <Kontrahent/kontrahent.h>
#include <Urzadzenia/urzadzenia.h>
#include <iostream>

using namespace std;
//time_t czas;
//tm timeinfo;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //------------

    //TODO:" //Sprawdzenie czy są puste pliki<<";
    //-----------------

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

void MainWindow::on_pushButton_7_clicked()
{
    KontrahentLista *kontrList = new KontrahentLista(this);
    kontrList ->show();
}

void MainWindow::on_actionO_programie_triggered()
{
    Info *info= new Info(this);
    info->show();
}

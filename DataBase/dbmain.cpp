#include "dbmain.h"
#include "ui_dbmain.h"
#include <QDebug>
#include <iostream>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

using namespace std;

DBMain::DBMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DBMain)
{
    ui->setupUi(this);
    // -- DATABASE INIT --
//    DatabaseConnect();
//    DatabaseInit();
//    DatabasePopulate();
//    init();

}

DBMain::~DBMain()
{
    delete ui;
}
void DBMain::DatabaseConnect()
{

}
void DBMain::init()
{// DatabaseConnect()
    cout<<"jestem w Init DB"<<endl;
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        db.setDatabaseName("C:/Users/pawel/Documents/Cplusplus/TestRamek/TestRamek/DataBase/asterixals.db");
        //db.setDatabaseName("asterixals.db");
        db.open("asterixals.db","true");
        if(!db.open())
            qWarning() << "1.MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
    }
    else
        qWarning() << "2.MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
    // DatabaseConnect()
    //    DatabaseInit();
    QSqlQuery query("CREATE TABLE people (id INTEGER PRIMARY KEY, name TEXT)");

    if(!query.isActive())
        qWarning() << "MainWindow::DatabaseInit - ERROR: " << query.lastError().text();
    //    DatabaseInit();
    //    DatabasePopulate();
    ////QSqlQuery query;

    if(!query.exec("INSERT INTO people(name) VALUES('Eddie Guerrero')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Gordon Ramsay')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Alan Sugar')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Dana Scully')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Lila	Wolfe')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Ashley Williams')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Karen Bryant')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Jon Snow')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Linus Torvalds')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Hayley Moore')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    //    DatabasePopulate();

//    DatabaseConnect();
//    DatabaseInit();
//    DatabasePopulate();
}


void DBMain::DatabaseInit()
{


}

void DBMain::DatabasePopulate()
{

}

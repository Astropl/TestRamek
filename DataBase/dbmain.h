//#pragma once
#ifndef DBMAIN_H
#define DBMAIN_H

#include <QMainWindow>

namespace Ui {
class DBMain;
}

class DBMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit DBMain(QWidget *parent = nullptr);
    ~DBMain();
//private:
public slots:
    void DatabaseConnect();
    void DatabaseInit();
    void DatabasePopulate();
    void init();

private:
    Ui::DBMain *ui;
};

#endif // DBMAIN_H

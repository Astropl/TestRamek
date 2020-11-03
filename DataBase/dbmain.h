#pragma once
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

    void DatabaseConnect();
    void DatabaseInit();
    void DatabasePopulate();

private:
    Ui::DBMain *ui;
};

#endif // DBMAIN_H

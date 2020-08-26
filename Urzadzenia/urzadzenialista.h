#ifndef URZADZENIALISTA_H
#define URZADZENIALISTA_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class UrzadzeniaLista;
}

class UrzadzeniaLista : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrzadzeniaLista(QWidget *parent = nullptr);
    ~UrzadzeniaLista();


public slots:

    void wczytajDane();
    void iloscWierszy();
    void myfunctiontimer();


private:
    Ui::UrzadzeniaLista *ui;
    QTimer *timer;
    QStandardItemModel *model;
};

#endif // URZADZENIALISTA_H

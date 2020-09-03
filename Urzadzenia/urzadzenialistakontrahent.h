#ifndef URZADZENIALISTAKONTRAHENT_H
#define URZADZENIALISTAKONTRAHENT_H

#include <QMainWindow>
#include <QDialog>
#include <QItemDelegate>

#include <QStandardItemModel>
#include <QTableView>
namespace Ui {
class UrzadzeniaListaKontrahent;
}

class UrzadzeniaListaKontrahent : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrzadzeniaListaKontrahent(QWidget *parent = nullptr);
    ~UrzadzeniaListaKontrahent();
public slots:

    void wczytajDane();
    void iloscWierszy();
    void myfunctiontimer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UrzadzeniaListaKontrahent *ui;
    QTimer *timer;
    QStandardItemModel *model;
};

#endif // URZADZENIALISTAKONTRAHENT_H

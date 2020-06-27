#ifndef KONTRAHENTLISTA_H
#define KONTRAHENTLISTA_H

#include <QMainWindow>

namespace Ui {
class KontrahentLista;
}

class KontrahentLista : public QMainWindow
{
    Q_OBJECT

public:
    explicit KontrahentLista(QWidget *parent = nullptr);
    ~KontrahentLista();
public slots:
    int zmianaLabela(
        int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia);
    void myfunctiontimer();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::KontrahentLista *ui;
    QTimer *timer;
};

#endif // KONTRAHENTLISTA_H

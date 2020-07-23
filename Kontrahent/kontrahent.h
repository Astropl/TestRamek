#ifndef KONTRAHENT_H
#define KONTRAHENT_H

#include <QMainWindow>

namespace Ui {
class Kontrahent;
}

class Kontrahent : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kontrahent(QWidget *parent = nullptr);
    ~Kontrahent();

public slots:

//    int zmianaLabela(
//        int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia);
    void myfunctiontimer();
    void wczytajMiasta();
    void wczytajWojewodztwa();
        //void DataiCzas();

        private slots :
            void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionDodaj_Miasto_triggered();

    void on_actionDodaj_Wojew_dztwo_triggered();

    //void on_lineEditWczytajNazwa_1_editingFinished();

    void on_lineEditWczytajNazwa_1_textChanged(const QString ); //(const QString &arg1)

    void on_actionInfo_triggered();

    //void on_comboBoxWczytajMiasta_activated(const QString &arg1);

    void on_comboBoxWczytajMiasta_highlighted(const QString); // (const QString &arg1)

private:
    Ui::Kontrahent *ui;
    QTimer *timer;
};

#endif // KONTRAHENT_H
//Info do Gita
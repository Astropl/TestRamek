#ifndef URZADZENIA_H
#define URZADZENIA_H

#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QShortcut>
#include <QStringListModel>

namespace Ui {
class Urzadzenia;
}

class Urzadzenia : public QMainWindow
{
    Q_OBJECT
    // Podpinam pierwszą listWiew
    QStringListModel *countriesListModel;
    QString country;
    QShortcut *shDelete;

public:
    explicit Urzadzenia(QWidget *parent = nullptr);
    ~Urzadzenia();

private slots:
    void on_BtnUrzaZapisz_clicked();

    void on_BtnUrzaZamknij_clicked();

    void on_countriesList_clicked(const QModelIndex &index);

    void on_comboBox_textActivated(const QString &arg1);

    void on_comboBox_2_textActivated(const QString &arg1);

    void on_comboBox_3_textActivated(const QString &arg1);

    void on_actionDodaj_Model_triggered();

    void on_actionDodaj_Producenta_triggered();

private:
    Ui::Urzadzenia *ui;
};

#endif // URZADZENIA_H

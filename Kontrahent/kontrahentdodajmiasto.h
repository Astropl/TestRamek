#ifndef KONTRAHENTDODAJMIASTO_H
#define KONTRAHENTDODAJMIASTO_H

#include <QMainWindow>

namespace Ui {
class KontrahentDodajMiasto;
}

class KontrahentDodajMiasto : public QMainWindow
{
    Q_OBJECT

public:
    explicit KontrahentDodajMiasto(QWidget *parent = nullptr);
    ~KontrahentDodajMiasto();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::KontrahentDodajMiasto *ui;
};

#endif // KONTRAHENTDODAJMIASTO_H

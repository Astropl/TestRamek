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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Kontrahent *ui;
};

#endif // KONTRAHENT_H

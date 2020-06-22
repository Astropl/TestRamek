#ifndef PIERWSZA_H
#define PIERWSZA_H

#include <QMainWindow>

namespace Ui {
class Pierwsza;
}

class Pierwsza : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pierwsza(QWidget *parent = nullptr);
    ~Pierwsza();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Pierwsza *ui;
};

#endif // PIERWSZA_H

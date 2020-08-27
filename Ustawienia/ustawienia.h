#ifndef USTAWIENIA_H
#define USTAWIENIA_H

#include <QMainWindow>

namespace Ui {
class Ustawienia;
}

class Ustawienia : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ustawienia(QWidget *parent = nullptr);
    ~Ustawienia();

private:
    Ui::Ustawienia *ui;
};

#endif // USTAWIENIA_H

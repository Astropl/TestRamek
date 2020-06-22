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

private:
    Ui::Kontrahent *ui;
};

#endif // KONTRAHENT_H

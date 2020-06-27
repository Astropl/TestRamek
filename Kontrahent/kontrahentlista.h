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

private:
    Ui::KontrahentLista *ui;
};

#endif // KONTRAHENTLISTA_H

#ifndef TRZECIA_H
#define TRZECIA_H

#include <QMainWindow>

namespace Ui {
class Trzecia;
}

class Trzecia : public QMainWindow
{
    Q_OBJECT

public:
    explicit Trzecia(QWidget *parent = nullptr);
    ~Trzecia();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Trzecia *ui;
};

#endif // TRZECIA_H
       //Info do Gita
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

public slots:
    void on_pushButton_clicked();
int zmianaLabela(int sekunda);
    //void on_labelZegara_linkActivated(const QString &link);

signals:

    void intZegary();

public:
    Ui::Pierwsza *ui;
   // Ui::labelZegara *ui;
};

#endif // PIERWSZA_H

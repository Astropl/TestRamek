#ifndef KONTRAHENTSHOW_H
#define KONTRAHENTSHOW_H

#include <QMainWindow>

namespace Ui {
class KontrahentShow;
}

class KontrahentShow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KontrahentShow(QWidget *parent = nullptr);
    ~KontrahentShow();

public slots:
    QVariant wyswietl (QVariant p1, QVariant p2, QVariant p3,QVariant p4,QVariant p5,QVariant p6,QVariant p7,QVariant p8,QVariant p9,QVariant p10,QVariant p11,QVariant p12,QVariant p13);
    //KontrahentShow(QString pierwszazmienna);


private slots:
    void on_pushButton_2_clicked();


private:
    Ui::KontrahentShow *ui;
};

#endif // KONTRAHENTSHOW_H

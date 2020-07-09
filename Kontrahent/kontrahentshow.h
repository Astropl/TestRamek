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
    QString wyswietl (QString pierwszazmienna);
    KontrahentShow(QString pierwszazmienna);


private slots:
    void on_pushButton_2_clicked();


private:
    Ui::KontrahentShow *ui;
};

#endif // KONTRAHENTSHOW_H

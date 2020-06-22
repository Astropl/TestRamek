#ifndef DRUGA_H
#define DRUGA_H

#include <QMainWindow>

namespace Ui {
class Druga;
}

class Druga : public QMainWindow
{
    Q_OBJECT

public:
    explicit Druga(QWidget *parent = nullptr);
    ~Druga();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Druga *ui;
};

#endif // DRUGA_H

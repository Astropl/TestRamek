#ifndef CHECKSYSTEM_H
#define CHECKSYSTEM_H

#include <QMainWindow>

namespace Ui {
class CheckSystem;
}

class CheckSystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckSystem(QWidget *parent = nullptr);
    ~CheckSystem();
public slots:


    void init();
    void updateProgress();

private slots:
//    void on_progressBar_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::CheckSystem *ui;
};

#endif // CHECKSYSTEM_H
//Info do Gita
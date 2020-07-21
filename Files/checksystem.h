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

private:
    Ui::CheckSystem *ui;
};

#endif // CHECKSYSTEM_H

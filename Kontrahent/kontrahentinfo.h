#ifndef KONTRAHENTINFO_H
#define KONTRAHENTINFO_H

#include <QMainWindow>

namespace Ui {
class KontrahentInfo;
}

class KontrahentInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit KontrahentInfo(QWidget *parent = nullptr);
    ~KontrahentInfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::KontrahentInfo *ui;
};

#endif // KONTRAHENTINFO_H

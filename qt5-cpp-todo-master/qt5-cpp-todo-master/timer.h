#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>

namespace Ui {
class timer;
}

class timer : public QMainWindow
{
    Q_OBJECT

public:
    explicit timer(QWidget *parent = nullptr);
    ~timer();

public slots:
    void theclock();
    void thedate();

private slots:
    void on_label4_linkHovered(const QString &link);

private:
    Ui::timer *ui;
    QTimer *timer1;
    QDate *date;
};

#endif // TIMER_H

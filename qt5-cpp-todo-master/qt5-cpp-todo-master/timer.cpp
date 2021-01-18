#include "timer.h"
#include "ui_timer.h"
#include <QDateTime>
#include <QtDebug>
#include <QPixmap>

timer::timer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::timer)
{
    ui->setupUi(this);
    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(theclock()));
    timer1->start(1000);

    date=new QDate();
    connect(timer1,SIGNAL(timeout()),this,SLOT(thedate()));
    timer1->start(1000);

    QPixmap pic(":/new/prefix1/imgs/c1.png");
    ui->label4->setPixmap(pic.scaled(100,100,Qt::KeepAspectRatio));  //images

    QPixmap pic1(":/new/prefix1/imgs/drinking-water-while-working-with-laptop-computer_109710-5073.jpg");
    ui->label_4->setPixmap(pic1.scaled(100,100,Qt::KeepAspectRatio));  //images

    QPixmap pic2(":/new/prefix1/imgs/Apps-to-Help-You-Move-More-at-Work-11.png");
    ui->label_5->setPixmap(pic2.scaled(100,100,Qt::KeepAspectRatio));  //images

    QPixmap pic3(":/new/prefix1/imgs/6557f516afe5485.jpg");
    ui->label_6->setPixmap(pic3.scaled(100,100,Qt::KeepAspectRatio));  //images




}

timer::~timer()
{
    delete ui;
}

void timer::theclock()
{
QTime time=QTime::currentTime();
QString timetostring=time.toString("hh:mm:ss");
   ui->label->setText(timetostring);

}

void timer::thedate()
{
  QDate date=QDate::currentDate();
QString datetostring  = date.toString("dd MMM yyyy");
ui->label_2->setText(datetostring);
}


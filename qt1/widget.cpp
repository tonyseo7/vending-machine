#include "widget.h"
#include "./ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setDefaultItemBtn(false);
    //changeButton();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){

    if(diff == 0)
        ui->lcdNumber->display(0);

    money += diff;
    ui->lcdNumber->display(money);
    changeButton();
}
void Widget::setDefaultItemBtn(bool selmode)
{
    ui->pbCoffee->setEnabled(selmode);
    ui->pbMilk->setEnabled(selmode);
    ui->pbTea->setEnabled(selmode);
}

void Widget::changeButton(){

    if(money > 199)
        ui->pbMilk->setEnabled(true);
    else
        ui->pbMilk->setEnabled(false);

    if(money > 149)
        ui->pbTea->setEnabled(true);
    else
        ui->pbTea->setEnabled(false);

    if(money > 99)
        ui->pbCoffee->setEnabled(true);
    else
        ui->pbCoffee->setEnabled(false);

}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    QString qTextStr;
    unsigned int money500;
    unsigned int money100;
    unsigned int money50;


    money500 = money/500;
    money100 = (money - (500*money500))/100;
    money50 = (money - (500*money500)-(100*money100))/50;

    qTextStr="500:";
    qTextStr.append(QString::number(money500));

    qTextStr.append(", 100:");
    qTextStr.append(QString::number(money100));

    qTextStr.append(", 50:");
    qTextStr.append(QString::number(money50));

    setDefaultItemBtn(false);
    //changeMoney(0);
    ui->lcdNumber->display(0);

    mb.information(nullptr, "Lef Money", qTextStr);

}






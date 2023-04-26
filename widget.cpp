#include "widget.h"
#include "./ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeButton();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    changeButton();
}

void Widget::changeButton(){
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbmilk->setEnabled(money>=150);
    ui->pbJuice->setEnabled(money>=200);


}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}





void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbmilk_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbJuice_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    mb.information(nullptr, "title", "text");
}



void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


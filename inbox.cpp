#include "inbox.h"
#include "ui_inbox.h"

InBox::InBox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InBox)
{
    ui->setupUi(this);
}

InBox::~InBox()
{
    delete ui;
}

//void InBox::on_pushButton_clicked()
//{

//}

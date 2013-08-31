#include "sentbox.h"
#include "ui_sentbox.h"

SentBox::SentBox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SentBox)
{
    ui->setupUi(this);
}

SentBox::~SentBox()
{
    delete ui;
}

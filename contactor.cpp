#include "contactor.h"
#include "ui_contactor.h"

Contactor::Contactor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Contactor)
{
    ui->setupUi(this);
}

Contactor::~Contactor()
{
    delete ui;
}

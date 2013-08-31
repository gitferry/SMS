#include "trsh.h"
#include "ui_trsh.h"

Trsh::Trsh(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Trsh)
{
    ui->setupUi(this);
}

Trsh::~Trsh()
{
    delete ui;
}

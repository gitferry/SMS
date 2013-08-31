#include "drafts.h"
#include "ui_drafts.h"

Drafts::Drafts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Drafts)
{
    ui->setupUi(this);
}

Drafts::~Drafts()
{
    delete ui;
}

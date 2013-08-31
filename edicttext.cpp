#include "edicttext.h"
#include "ui_edicttext.h"

EdictText::EdictText(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EdictText)
{
    ui->setupUi(this);
}

EdictText::~EdictText()
{
    delete ui;
}

#include "mainwindow.h"
#include "edicttext.h"
#include "ui_mainwindow.h"
#include "sentbox.h"
#include "inbox.h"
#include "stdio.h"
#include "drafts.h"
#include "contactor.h"
#include "trsh.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_teBtn_clicked()
{
    EdictText *et = new EdictText(this);
    et->show();
}

void MainWindow::on_ibBtn_clicked()
{
    InBox *ib = new InBox(this);
    ib->show();
}

void MainWindow::on_sbBtn_clicked()
{
    SentBox *sb = new SentBox(this);
    sb->show();
}

void MainWindow::on_drBtn_clicked()
{
    Drafts *dr = new Drafts(this);
    dr->show();
}

void MainWindow::on_ctBtn_clicked()
{
    Contactor *ct = new Contactor(this);
    ct->show();
}

void MainWindow::on_trBtn_clicked()
{
    Trsh *tr = new Trsh(this);
    tr->show();
}

void MainWindow::on_openBtn_clicked()
{

}

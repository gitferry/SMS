#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_teBtn_clicked();

    void on_ibBtn_clicked();

    void on_sbBtn_clicked();


    void on_drBtn_clicked();

    void on_ctBtn_clicked();

    void on_trBtn_clicked();

    void on_openBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

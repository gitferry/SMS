#ifndef CONTACTOR_H
#define CONTACTOR_H

#include <QMainWindow>

namespace Ui {
class Contactor;
}

class Contactor : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Contactor(QWidget *parent = 0);
    ~Contactor();
    
private:
    Ui::Contactor *ui;
};

#endif // CONTACTOR_H

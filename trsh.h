#ifndef TRSH_H
#define TRSH_H

#include <QMainWindow>

namespace Ui {
class Trsh;
}

class Trsh : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Trsh(QWidget *parent = 0);
    ~Trsh();
    
private:
    Ui::Trsh *ui;
};

#endif // TRSH_H

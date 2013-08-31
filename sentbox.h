#ifndef SENTBOX_H
#define SENTBOX_H

#include <QMainWindow>

namespace Ui {
class SentBox;
}

class SentBox : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SentBox(QWidget *parent = 0);
    ~SentBox();
    
private:
    Ui::SentBox *ui;
};

#endif // SENTBOX_H

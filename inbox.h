#ifndef INBOX_H
#define INBOX_H

#include <QMainWindow>

namespace Ui {
class InBox;
}

class InBox : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit InBox(QWidget *parent = 0);
    ~InBox();
    
private:
    Ui::InBox *ui;
};

#endif // INBOX_H

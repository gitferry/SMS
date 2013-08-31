#ifndef DRAFTS_H
#define DRAFTS_H

#include <QMainWindow>

namespace Ui {
class Drafts;
}

class Drafts : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Drafts(QWidget *parent = 0);
    ~Drafts();
    
private:
    Ui::Drafts *ui;
};

#endif // DRAFTS_H

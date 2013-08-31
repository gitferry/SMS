#ifndef EDICTTEXT_H
#define EDICTTEXT_H

#include <QMainWindow>

namespace Ui {
class EdictText;
}

class EdictText : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit EdictText(QWidget *parent = 0);
    ~EdictText();
    
private:
    Ui::EdictText *ui;
};

#endif // EDICTTEXT_H

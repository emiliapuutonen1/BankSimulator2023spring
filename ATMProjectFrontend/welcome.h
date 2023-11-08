#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class welcome;
}

class welcome : public QWidget
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = nullptr);
    ~welcome();
    void openCardReader(QWidget *parent);

private:
    Ui::welcome *ui;
};

#endif // WELCOME_H

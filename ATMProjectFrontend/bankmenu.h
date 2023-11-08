#ifndef BANKMENU_H
#define BANKMENU_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>

namespace Ui {
class BankMenu;
}

class BankMenu : public QDialog
{
    Q_OBJECT

public:
    explicit BankMenu(QWidget *parent = nullptr);
    ~BankMenu();

    QString getUsername() const;
    void setUsername(const QString &newUsername);

private slots:
    void on_btnEvents_clicked();
    void on_btnClient_clicked();
    void on_btnAccount_clicked();

private:
    Ui::BankMenu *ui;
    QString username;
    QPushButton * btnClient;
};

#endif // BANKMENU_H

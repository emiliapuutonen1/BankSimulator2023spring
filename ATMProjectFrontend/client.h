#ifndef CLIENT_H
#define CLIENT_H
#include "qnetworkreply.h"
#include "qpushbutton.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {class Client;}
QT_END_NAMESPACE

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void on_btnBack_clicked();
    void getClientSlot (QNetworkReply *);
    void addClientSlot (QNetworkReply *);
    void UpdateClientSlot(QNetworkReply *);
    void on_btnClientsclicked();




private:
    Ui::Client *ui;
    void ListModel();
    QPushButton *btnClients;
};

#endif // CLIENT_H


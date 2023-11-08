#include "bankmenu.h"
#include "ui_bankmenu.h"
#include "events.h"
#include "client.h"
#include "Account.h"

BankMenu::BankMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankMenu)
{
    ui->setupUi(this);
}

BankMenu::~BankMenu()
{
    delete ui;
}

QString BankMenu::getUsername() const
{
    return username;
}

void BankMenu::setUsername(const QString &newUsername)
{
    username = newUsername;
    ui->labelBankInfo->setText("Welcome " +username);
}

void BankMenu::on_btnEvents_clicked()
{
    Events *ev= new Events();
    ev->show();
    close();

 /*   QString site_url="http://localhost:3000/Events";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT((QNetworkReply*)));
    reply = manager->get(request);*/
}


void BankMenu::on_btnClient_clicked()
{
    Client *cl= new Client();
    cl->show();

 /* QString site_url="http://localhost:3000/client";
  QNetworkRequest request((site_url));
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

  manager = new QNetworkAccessManager(this);
  connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_btnClient_clicked(QNetworkReply*)));
  reply = manager->get(request);*/
}

void BankMenu::on_btnAccount_clicked()
  {
    Account *ac= new Account();
    ac->show();
    close();

}

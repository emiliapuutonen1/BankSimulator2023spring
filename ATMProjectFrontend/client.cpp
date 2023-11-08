#include "client.h"
#include "qnetworkaccessmanager.h"
#include "qnetworkreply.h"
#include "ui_client.h"
#include "bankmenu.h"
#include <QListView>
#include <QStandardItem>
#include <QtDebug>
#include "bankmenu.h"
QNetworkReply *reply;
QNetworkAccessManager *manager;
QNetworkAccessManager *postManager;
QNetworkAccessManager *putManager;
QByteArray response_data;

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    //btnClients = ui->btnClients;


    QString endpoint = "http://localhost:3000/client/1";
    QUrl url(endpoint);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getClientSlot(QNetworkReply*)));
    manager->get(request);
}

void Client::getClientSlot(QNetworkReply* reply)
{

    QString response = reply->readAll();
    reply->deleteLater();


    QJsonDocument jsonResponse = QJsonDocument::fromJson(response.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QString firstName = jsonObject["Client_firstname"].toString();
    QString lastName = jsonObject["Client_lastname"].toString();
    qDebug()<<jsonResponse.array();

    ui->listProfile->addItem("First Name: " + firstName);
    ui->listProfile->addItem("Last Name: " + lastName);
}



void Client::on_btnBack_clicked()
{
    BankMenu *bm= new BankMenu();
    bm->show();
    close();
}
Client::~Client()
{
    delete ui;
}



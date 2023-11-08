#include "account.h"
#include "bankmenu.h"
#include "ui_account.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

Account::Account(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Account)
{
    ui->setupUi(this);

    btnTen = ui->btnTen;
    btnTwenty = ui->btnTwenty;
    btnFifty = ui->btnFifty;
    btnHundred = ui->btnHundred;
    btnOne = ui->btnOne;
    btnTwo = ui->btnTwo;
    btnThree = ui->btnThree;
    btnFour = ui->btnFour;
    btnFive = ui->btnFive;
    btnSix  = ui->btnSix;
    btnSeven = ui->btnSeven;
    btnEight = ui->btnEight;
    btnNine = ui->btnNine;
    btnNoll = ui->btnNoll;
    btnOk = ui->btnOk;

    connect(btnTen, &QPushButton::clicked, this, &Account::tenClicked);
     connect(btnTwenty, &QPushButton::clicked, this, &Account::twentyClicked);
      connect(btnFifty, &QPushButton::clicked, this, &Account::fiftyClicked);
       connect(btnHundred, &QPushButton::clicked, this, &Account::hundredClicked);
    connect(btnOne, &QPushButton::clicked, this, &Account::oneClicked);
     connect(btnTwo, &QPushButton::clicked, this, &Account::twoClicked);
      connect(btnThree, &QPushButton::clicked, this, &Account::threeClicked);
       connect(btnFour, &QPushButton::clicked, this, &Account::fourClicked);
        connect(btnFive, &QPushButton::clicked, this, &Account::fiveClicked);
         connect(btnSix, &QPushButton::clicked, this, &Account::sixClicked);
          connect(btnSeven, &QPushButton::clicked, this, &Account::sevenClicked);
           connect(btnEight, &QPushButton::clicked, this, &Account::eightClicked);
            connect(btnNine, &QPushButton::clicked, this, &Account::nineClicked);
             connect(btnNoll, &QPushButton::clicked, this, &Account::nollClicked);
              connect(btnOk, &QPushButton::clicked, this, &Account::okClicked);

             QString endpoint = "http://localhost:3000/account";
             QUrl url(endpoint);
             QNetworkRequest request(url);
             request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

             QNetworkAccessManager* manager = new QNetworkAccessManager(this);
             connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getAccountSlot(QNetworkReply*)));
             manager->get(request);

}

void Account::getAccountSlot(QNetworkReply* reply)
{
             QString response = reply->readAll();
             reply->deleteLater();

             QJsonDocument jsonResponse = QJsonDocument::fromJson(response.toUtf8());
             QJsonArray jsonArray = jsonResponse.array();
             QJsonObject jsonObject = jsonArray.at(0).toObject();
             float debitBalance = jsonObject["debitBalance"].toDouble();

             ui->labelBalance->setText(QString::number(debitBalance));

}


Account::~Account()
{
    delete ui;
}

 void Account::tenClicked()
{
     totalWithDrawal = 10;
     ui->labelWithDrawal->setText(QString::number(totalWithDrawal));  //totalWithDrawal = Kaikki Withdrawal buttonit yhdessä paketissa


}

void Account::twentyClicked()
{
    totalWithDrawal = 20;
    ui->labelWithDrawal->setText(QString::number(totalWithDrawal));


}

void Account::fiftyClicked()
{
  totalWithDrawal = 50;
  ui->labelWithDrawal->setText(QString::number(totalWithDrawal));

}

void Account::hundredClicked()
{
   totalWithDrawal = 100;
   ui->labelWithDrawal->setText(QString::number(totalWithDrawal));

}

void Account::oneClicked()
{
   // allNumbersPin = 1;
    //ui->labelPin->setText(QString::number(allNumbersPin));  // allNumberPin = Kaikki pinkoodiin tarvittavat numerot yhdessä paketissa
    QString currentText = ui->lineEditPin->text();
    ui->lineEditPin->setText(currentText + "1");
}

void Account::twoClicked()
{
    //allNumbersPin = 2;
   // ui->labelPin->setText(QString::number(allNumbersPin));
    QString currentText = ui->lineEditPin->text();
    ui->lineEditPin->setText(currentText + "2");
}

void Account::threeClicked()
{
   // allNumbersPin = 3;
   // ui->labelPin->setText(QString::number(allNumbersPin));
    QString currentText = ui->lineEditPin->text();
    ui->lineEditPin->setText(currentText + "3");
}

void Account::fourClicked()
{
    //allNumbersPin = 4;
   // ui->labelPin->setText(QString::number(allNumbersPin));
    QString currentText = ui->lineEditPin->text();
    ui->lineEditPin->setText(currentText + "4");
}

void Account::fiveClicked()
{
   // allNumbersPin = 5;
   // ui->labelPin->setText(QString::number(allNumbersPin));
    QString currentText = ui->lineEditPin->text();
    ui->lineEditPin->setText(currentText + "5");
}

void Account::sixClicked()
{
   // allNumbersPin = 6;
   // ui->labelPin->setText(QString::number(allNumbersPin));
    QString currentText = ui->lineEditPin->text();
    ui->lineEditPin->setText(currentText + "6");
}

void Account::sevenClicked()
{
   // allNumbersPin = 7;
   // ui->labelPin->setText(QString::number(allNumbersPin));
    QString currentText = ui->lineEditPin->text();
    ui->lineEditPin->setText(currentText + "7");
}

void Account::eightClicked()
{
   // allNumbersPin = 8;
  //  ui->labelPin->setText(QString::number(allNumbersPin));
    QString currentText = ui->lineEditPin->text();
    ui->lineEditPin->setText(currentText + "8");
}

void Account::nineClicked()
{
   // allNumbersPin = 9;
   // ui->labelPin->setText(QString::number(allNumbersPin));
    QString currentText = ui->lineEditPin->text();
    ui->lineEditPin->setText(currentText + "9");
}

void Account::nollClicked()
{
    //allNumbersPin = 2;
   // ui->labelPin->setText(QString::number(allNumbersPin));
    QString currentText = ui->lineEditPin->text();
    ui->lineEditPin->setText(currentText + "0");
}

void Account::okClicked()
{

    QString pin = ui->lineEditPin->text();
    double balance = ui->labelBalance->text().toDouble();
    double withdrawal = totalWithDrawal;

    if (pin == correctPin && withdrawal <= balance) {
        double newBalance = balance - withdrawal;
        ui->labelBalance->setText(QString::number(newBalance));
        ui->labelWithDrawal->setText("0");

        /*Update the balance on the REST API*/
        QUrl url("http://localhost:3000/account");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QJsonObject json;
        json["idAccount"] = 1;
        json["balance"] = newBalance;
        QJsonDocument body(json);
        QByteArray data = body.toJson();
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QNetworkReply *reply = manager->post(request, data);

        connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                ui->labelBalance->setText(QString::number(newBalance));
            } else {
                // display an error message
            }
            reply->deleteLater();
            manager->deleteLater();
        });
    } else {
        ui->labelPinOk->setText("Pin wrong or no enough money");
    }
}

void Account::on_pushButton_clicked()
{
  BankMenu *bm= new BankMenu();
  bm->show();
  close();
}
/*void get_debitBalance();

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("http://localhost:3000/account");

    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if (reply->error()) {
            qDebug() << "Error fetching account data:" << reply->errorString();
            return;
        }

        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject account = doc.object();
        int debitBalance = account.value("debitBalance").toInt();

        ui->labelBalance->setText(QString::number(debitBalance));
    });

    manager->get(QNetworkRequest(url));

}*/

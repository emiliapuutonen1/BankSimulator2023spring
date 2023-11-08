#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "qpushbutton.h"
#include "qnetworkaccessmanager.h"
#include <QWidget>
#include <QPushButton>
#include "qnetworkreply.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
//#include <bcrypt.h>

namespace Ui {
class Account;
}

class Account : public QWidget
{
    Q_OBJECT

public:
    explicit Account(QWidget *parent = nullptr);
    ~Account();


signals:
 void btn20Signal();


private slots:
   void tenClicked();
   void twentyClicked();
   void fiftyClicked();
   void hundredClicked();
   void btnTwenty_clicked()
      {
          emit btn20Signal();
      }
   void oneClicked();
   void twoClicked();
   void threeClicked();
   void fourClicked();
   void fiveClicked();
   void sixClicked();
   void sevenClicked();
   void eightClicked();
   void nineClicked();
   void okClicked();
   void nollClicked();

   void on_pushButton_clicked();
   void getAccountSlot (QNetworkReply *);

private:
    Ui::Account *ui;
    QPushButton *btnTen;
    QPushButton *btnTwenty;
    QPushButton *btnFifty;
    QPushButton *btnHundred;
    QPushButton *btnOne;
    QPushButton *btnTwo;
    QPushButton *btnThree;
    QPushButton *btnFour;
    QPushButton *btnFive;
    QPushButton *btnSix;
    QPushButton *btnSeven;
    QPushButton *btnEight;
    QPushButton *btnNine;
    QPushButton *btnNoll;
    QPushButton *btnOk;
    int totalWithDrawal = 0;
    int correctPin= 0000;
  //int allNumbersPin = 0;    // Onko tarvetta?


};

#endif // ACCOUNT_H

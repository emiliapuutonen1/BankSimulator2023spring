#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bankmenu.h"
#include "bankenvironment.h"
#include "QDebug"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include "cardreaderdll.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::on_btnLogin_clicked()
{

    QJsonObject jsonObj;
    jsonObj.insert("username",username);
    jsonObj.insert("password",password);



        // Function to authenticate the user
        // Create a QNetworkAccessManager object
        QNetworkAccessManager networkManager;

        // Create a QNetworkRequest object with the appropriate URL
        QNetworkRequest request;
        request.setUrl(QUrl(BankEnvironment::getBaseURL()+"/card"));  // Replace with your API endpoint URL

        // Send the GET request
        QNetworkReply* reply = networkManager.get(request);

        // Create an event loop to wait for the response
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        // Check for errors during the request
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Error: " << reply->errorString();
            // Handle the error appropriately
        } else {
            // Read the response data
            //QByteArray responseData = reply->readAll();

            // Convert the response data to a QString
            //QString jsonResponse = QString::fromUtf8(responseData);

            // Parse the JSON response
            QJsonDocument jsonResponseDoc = QJsonDocument::fromJson(reply->readAll());

            // Check if the JSON document is valid

            if (!jsonResponseDoc.isNull()) {
                qDebug()<<jsonResponseDoc;
                // If the JSON document is an array
                if (jsonResponseDoc.isArray()) {

                    QJsonArray jsonArray = jsonResponseDoc.array();

                    // Iterate through the array (assuming there's only one object in the array)
                    for (const QJsonValue& value : jsonArray) {
                        //if (value.isObject()) {
                            QJsonObject jsonObject = value.toObject();

                            // Extract the idCard and pincode values from the JSON object
                            QString idCard = jsonObject.value("cardNumber").toString();
                            QString pincode = jsonObject.value("pincode").toString();

                            // Retrieve the PIN code entered by the user
                            QString enteredPincode = ui->lineEditPassword->text(); // Assuming lineEditPassword is a QLineEdit
                            qDebug()<<idCard<<"ja"<<pincode;
                            // Perform authentication check
                            if (idCard == "60006209" && pincode == enteredPincode) {
                                // Authentication successful
                                ui->labelInfo->setText("Welcome");
                                BankMenu *objectBankMenu = new BankMenu(this);
                                objectBankMenu->setUsername(username);
                                objectBankMenu->open();

                            } else {
                                ui->labelInfo->setText("Invalid PIN");
                                ui->lineEditPassword->clear();
                            }

                            break; // Assuming there's only one object in the array, exit the loop

                    }
                }
            } else {
                // Handle JSON parsing error
            }
        }

        // Clean up
        reply->deleteLater();
}
*/
void MainWindow::on_btnLogin_clicked()
{
    // Retrieve the PIN code entered by the user
    QString enteredPincode = ui->lineEditPassword->text(); // Assuming lineEditPassword is a QLineEdit

    // Perform authentication check
    if (enteredPincode == "1234") {
        // Authentication successful
        ui->labelInfo->setText("Welcome");
        BankMenu *objectBankMenu = new BankMenu(this);
        objectBankMenu->setUsername(username);
        objectBankMenu->open();
    } else {
        ui->labelInfo->setText("Invalid PIN");
        ui->lineEditPassword->clear();
    }
}


void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
       qDebug()<<response_data;
       reply->deleteLater();
       loginManager->deleteLater();
}

QByteArray MainWindow::getToken() const
{
    return token;
}

void MainWindow::setToken(const QByteArray &newToken)
{
    token = newToken;
}


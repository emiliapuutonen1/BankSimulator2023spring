#include "mainwindow.h"
#include "cardreaderdll.h"
#include "welcome.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcome cp;
    MainWindow s;
    cp.show();
    CardReaderdll cardReaderdll(0);
    QObject::connect(&cardReaderdll, &CardReaderdll::cardDetected, [&cp, &s](const QString& cardData) {
    cp.findChild<QLabel *>("Label1")->setText(QString(cardData));
    s.show();
    cp.close();

    });
    return a.exec();
}

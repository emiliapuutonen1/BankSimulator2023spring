#include "cardreaderdll.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QtUiTools/QtUiTools>


CardReaderdll::CardReaderdll(QObject* parent) :QObject(parent)
{
    m_serial = new QSerialPort("COM3", this); //COM porttia saattaa joutua vaihtamaan
    if (m_serial->open(QIODevice::ReadWrite)) {
        connect( m_serial, &QSerialPort ::readyRead, this, &CardReaderdll::onDataReady);
    } else {
        qDebug() << "Failed to open serial port: " <<m_serial->errorString();
    }
}

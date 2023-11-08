#ifndef CARDREADERDLL_H
#define CARDREADERDLL_H
#include <QObject>
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>



class CardReaderdll :public QObject
{
    Q_OBJECT
public:
    CardReaderdll (QObject * parent = nullptr);
    void openCardReader(QWidget *parent);
signals:
    void cardDetected(const QString& cardData);
public slots:
    void onDataReady() {
        QByteArray data = m_serial->readAll();
        QString cardData = QString (data);
        cardData.remove(0,3);
        cardData.chop(4);
        emit cardDetected(cardData);

    }
private:
    QSerialPort* m_serial;

};
#endif // CARDREADERDLL_H

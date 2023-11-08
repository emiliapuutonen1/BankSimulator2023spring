/*#ifndef EVENTS_H
#define EVENTS_H

#include <QWidget>

namespace Ui {
class Events;
}

class Events : public QWidget
{
    Q_OBJECT

public:
    explicit Events(QWidget *parent = nullptr);
    ~Events();

private:
    Ui::Events *ui;
};

#endif // EVENTS_H
*/
#ifndef EVENTS_H
#define EVENTS_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QDebug>
#include <QtNetwork>
#include <QObject>
#include <QJsonDocument>
#include <QString>
#include <QList>


namespace Ui {
class Events;
}

class Events : public QWidget
{
    Q_OBJECT


public:
    explicit Events(QWidget *parent = nullptr);
    ~Events();
    void getEvents();

signals:
    void eventSignal(QString);

private slots:
    void on_btn_events_clicked();
    void getEventsSlot(QNetworkReply*reply);

    void on_btn_next_clicked();

    void on_btn_prev_clicked();

private:
    Ui::Events *ui;
    QNetworkAccessManager *getEventsManager;

    QNetworkReply *reply;
    QByteArray response_data;
    QString events;
    int index = 5;
    int eventsI = 0;
    int prevIndex = 0;
    int prevEventsI = 0;
    QList<QString> listEvents;
};

#endif // EVENTS_H

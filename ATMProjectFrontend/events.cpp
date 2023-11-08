/*#include "events.h"
#include "ui_events.h"

Events::Events(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Events)
{
    ui->setupUi(this);
}

Events::~Events()
{
    delete ui;
}
*/
#include "events.h"
#include "ui_events.h"

Events::Events(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Events)
{
    ui->setupUi(this);
}

Events::~Events()
{
    delete ui;
}

void Events::getEvents()
{
    QString site_url="http://localhost:3000/events";
    qDebug() << site_url;
    QNetworkRequest request((site_url));
    getEventsManager = new QNetworkAccessManager(this);
    connect(getEventsManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getEventsSlot(QNetworkReply*)));
    reply = getEventsManager->get(request);
    qDebug() << reply;
}

void Events::on_btn_events_clicked()
{
    getEvents();
}

void Events::getEventsSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach(const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        qDebug() << json_obj["Amount"];
        events+=json_obj["Date"].toString()+" "+json_obj["Time"].toString()+" "+json_obj["Transactions"].toString()+" "+QString::number(json_obj["Amount"].toDouble())+"\r";
        listEvents.append(json_obj["Date"].toString()+" "+json_obj["Time"].toString()+" "+json_obj["Transactions"].toString()+" "+QString::number(json_obj["Amount"].toDouble()));
    }
    ui->te_events->setText(events);
    reply->deleteLater();
    getEventsManager->deleteLater();
}


void Events::on_btn_next_clicked()
{
    QList<QString> nextEvents;
    events = "";
    if(listEvents.isEmpty()){
        events = "";
    } else {
        if(index == listEvents.length() && eventsI == index){
            events+="No more events to browse!";
            ui->te_events->setText(events);
            qDebug() << eventsI << index;

        }else if(index == listEvents.length() && eventsI < index){
            for(int i = eventsI; i < index; i++){
                nextEvents.append(listEvents[i]);
                eventsI++;
            }
            for(int i = 0; i < nextEvents.length(); i++){
                events+=nextEvents[i]+"\r";
            }
            qDebug() << eventsI << index;
            ui->te_events->setText(events);
        }else {
            for(int i = eventsI; i < index; i++){
                nextEvents.append(listEvents[i]);
                eventsI++;
            }
            for(int i = 0; i < nextEvents.length(); i++){
                events+=nextEvents[i]+"\r";
            }
            index+=5;
            if(index > listEvents.length()){
                index = listEvents.length();
            }
            qDebug() << eventsI << index;
            ui->te_events->setText(events);
        }
    }
}


void Events::on_btn_prev_clicked()
{
    QList<QString> nextEvents;
    events = "";
    if(listEvents.isEmpty()){
        events = "";
    } else {
        if(index == 0 && eventsI == index){
            events+="No more events to browse!";
            ui->te_events->setText(events);
            qDebug() << eventsI << index;
        } else if(eventsI == 0 && index > events){
            for(int i = index; i > eventsI; i--){
                nextEvents.append(listEvents[i]);
                index--;
            }
            for(int i = 0; i < nextEvents.length(); i++){
                events+=nextEvents[i]+"\r";
            }
            ui->te_events->setText(events);
        }else {
            if(index >= listEvents.length()){
                index = listEvents.length()-1;
            }
            for(int i = index; i > eventsI; i--){
                nextEvents.append(listEvents[i]);
                index--;
            }
            for(int i = 0; i < nextEvents.length(); i++){
                events+=nextEvents[i]+"\r";
            }
            eventsI -= 5;
            if(eventsI < 0){
                eventsI = 0;
            }
            qDebug() << eventsI << index;
            ui->te_events->setText(events);
        }
    }
}

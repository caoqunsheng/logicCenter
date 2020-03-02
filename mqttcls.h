#ifndef MQTTCLS_H
#define MQTTCLS_H

#include <QObject>
#include <QtMqtt/QMqttClient>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
class mqttCls:public QObject
{
    Q_OBJECT
public:
    mqttCls(QJsonObject object);
    QMqttClient * client(){return mqtt_client;}
    QString topicUi(){return rootUI;}
    QString topicLogic(){return rootLogic;}
    QString topicDevice(){return rootDevice;}
    void insertTopic(QString topic){subTopic.append(topic);}
private:
    void subscribe();
public:
    QMqttClient *mqtt_client;
private:
    QList<QString> subTopic;
    int id;
    QString host;
    quint16 port;
    QString username;
    QString password;
    QString rootLogic;
    QString rootUI;
    QString rootDevice;
signals:
    void recivedMsg(const QByteArray &message, const QMqttTopicName &topic);
private slots:
    void updateLogStateChange();
    void msgRecive(const QByteArray &message, const QMqttTopicName &topic);
    void Publish(const QByteArray &message, const QMqttTopicName &topic);
};

#endif // MQTTCLS_H

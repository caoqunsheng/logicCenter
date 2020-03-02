#ifndef COMCLS_H
#define COMCLS_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTimer>
#include "mqttcls.h"
#include <QThread>
class comCls:public QObject
{
    Q_OBJECT
public:
    comCls();
    void SetId(int deviceId){this->id=deviceId;}
    void SetName(QString name){this->name=name;}
    void SetMqtt(mqttCls *mqtt);
    void StartTimer(int interval);
protected:
    int id;
    QString name;
    mqttCls *mqtt;
    QString publishTopic;
    QString subscribeTopic;
    QThread *m_pThread;
    QTimer *m_pTimer;
    virtual void receive(QByteArray message){}//消息接收处理函数，由msgRecive槽调用，传递到不同的类中
    void Connect();
signals:
    void Publish(const QByteArray &message, const QMqttTopicName &topic);
protected slots:
    virtual void timeProcess(){}//虚函数需要完整定义
    void msgRecive(const QByteArray &message, const QMqttTopicName &topic);
};

#endif // COMCLS_H

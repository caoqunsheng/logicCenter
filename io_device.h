#ifndef IO_DEVICE_H
#define IO_DEVICE_H

#include <QObject>
#include <QtMqtt/QMqttClient>
class IO_device:public QObject
{
public:
    IO_device(QMqttClient *m_client,QString ip);
    bool SubscribeFromUi(QString topic);
    bool SubscribeFromDevice(QString topic);
    void PublishToDeviceTopic(QString topic){this->publishToDeviceTopic=topic;}
    void PublishToUiTopic(QString topic){this->publishToUiTopic=topic;}
    bool GetOutput(uint num);
    bool GetInput(uint num);
public slots:
    void Output( uint , bool );
private slots:
    void msgRecive(const QByteArray &message, const QMqttTopicName &topic);  
private:
    QString ip;
    QString publishToUiTopic;
    QString subscribeFromUiTopic;
    QString publishToDeviceTopic;
    QString subscribeFromDeviceTopic;
    char X[16]={'0'};
    char Y[16]={'0'};
    void publishToDevice(QString dat);
    void publishToUI(QString name,QString dat);
    void reciveRromUi(QByteArray message);
    void reciveRromDevice(QByteArray message);
    void reciveRromLogic(QByteArray message);
    void ioDo(QByteArray byteArray);
    QMqttClient *mqtt_client;
};

#endif // IO_DEVICE_H

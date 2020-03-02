#ifndef IOCLS_H
#define IOCLS_H

#include <QObject>
#include <QtDebug>
#include <QtMqtt/QMqttClient>
#include <QJsonObject>
#include <QJsonDocument>
#include "comcls.h"
struct IOcfg    //设备配置信息
{
    int id;
    QString name;
    int port;
    QList<int> openDelay;
    QList<int> closeDelay;
};
struct IoPort   //端口信息结构表
{
    int deviceId;
    int portId;
    bool value;
};
class IOCls:public  comCls
{
    Q_OBJECT
public:
    IOCls(int portNum);
    void setOpenDelay(int index,int t){openDelay[index]=t;}
    void setCloseDelay(int index,int t){closeDelay[index]=t;}
signals:
    void UpdateX(int id,int port,bool val);
    void UpdateY(int id,int port,bool val);
public slots:
    void Output(QJsonObject json);
private slots:
    void timeProcess();
private:
    int portNum;
    QList<bool>Yback;
    QList<bool>Xback;
    QList<int> openDelay;
    QList<int> closeDelay;
    QList<int> countdown;
    QList<int> countdownLast;
    QList<QString>Yout;
private:
    void receive(QByteArray message);
    void publishToDevice(QJsonObject jsOut);
};

#endif // IOCLS_H

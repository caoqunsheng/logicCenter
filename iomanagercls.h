#ifndef IOMANAGERCLS_H
#define IOMANAGERCLS_H
#include "iocls.h"
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
struct IoNode
{
  int deviceId;  //设备编号和IO结点的对应关系表结构
  IOCls *io;
};
struct UnitePort   //端口信息结构表
{
    int portId;
    bool value;
};
class ioManagerCls:public QObject
{
    Q_OBJECT
public:
    ioManagerCls(QJsonObject object,mqttCls *mqtt);
    void setPort(int portId){operatePort(portId,true);}//打开端口
    void restPort(int portId){operatePort(portId,false);}//关闭端口
public slots:
    void UpdateX(int id,int port,bool val);
    void UpdateY(int id,int port,bool val);
signals:
    void portX(int portUniteId,bool value);//端口统一编号信息发布
    void portY(int portUniteId,bool value);//端口统一编号信息发布
private:
    mqttCls *mqtt;
    QString publishTopic;
    QString subscribeTopic;
    QList<IOcfg> ioCfgList;//IO设备配置表
    QList<IOCls *> ioDevList;//IO设备表
    QList<IoNode *> IoPort;//统一IO列表
private:
    QList<IoNode *> IOList(){return  this->IoPort;}
    void SetPublishTopic(QString topic){this->publishTopic=topic;}
    void SetSubscribeTopic(QString topic){this->subscribeTopic=topic;}
    QList<IOcfg> readIoConfig(QJsonArray Array);
    QList<IoNode *> createIoDevice(QList<IOcfg> cfg);
    void operatePort( int portId,bool value);
    IoNode *getIoDevice(int portId);
};

#endif // IOMANAGERCLS_H

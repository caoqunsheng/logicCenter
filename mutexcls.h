#ifndef MUTEXCLS_H
#define MUTEXCLS_H

#include <QObject>
#include "iomanagercls.h"
class mutexCls:public QObject
{
    Q_OBJECT
public:
    mutexCls();
    void SetIoDevice(ioManagerCls *ioDevice);//指定统一的IO控制设备,引用关系
    void SetLogic(QString logic);
private:
    ioManagerCls *ioDevice;
    QList<int> MutexPort;
private:
    void getPortList();
private slots:
    void portY(int portUniteId,bool value);//端口统一编号信息发布
};

#endif // MUTEXCLS_H

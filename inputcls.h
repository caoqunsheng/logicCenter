#ifndef INPUTCLS_H
#define INPUTCLS_H

#include <QObject>
#include "iomanagercls.h"
class inputCls:public QObject
{
    Q_OBJECT
public:
    inputCls();
    void SetIoDevice(ioManagerCls *ioDevice);//指定统一的IO控制设备,引用关系
    void SetLogic(QString logic);
private:
    ioManagerCls *ioDevice;
    QString logic;//原始输入逻辑字符串
    int outPort;//计算结果输出端口
    int inPort;//计算结果输出端口
private slots:
    void portX(int portUniteId,bool value);//端口统一编号信息发布
};
#endif // INPUTCLS_H

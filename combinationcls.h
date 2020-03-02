#ifndef COMBINATIONCLS_H
#define COMBINATIONCLS_H

#include <QObject>
#include <QStack>
#include "iomanagercls.h"
class combinationCls:public QObject
{
    Q_OBJECT
public:
    combinationCls();
    void SetIoDevice(ioManagerCls *ioDevice);//指定统一的IO控制设备,引用关系
    void SetLogic(QString logic);
    bool process();
private:

    QString logic;//原始输入逻辑字符串
    int outPort;//计算结果输出端口
    QString express;//计算表达式
    ioManagerCls *ioDevice;
    QList<UnitePort> portList;//记录端口状态表
    QList<UnitePort> inputX;//记录输入状态
    QStack<char> operatorsStack;//操作符栈
    QStack<bool> operandStack;

private slots:
    void portX(int portUniteId,bool value){;}//端口统一编号信息发布
    void portY(int portUniteId,bool value);//端口统一编号信息发布
private:
    int compare(char ch) ;
    int deal_date();
};

#endif // COMBINATIONCLS_H

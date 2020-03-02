#include "comcls.h"

comCls::comCls()
{

}
/*****************************************
 * 功能：创建定时器
 * 描述：创建定时器并将它放到另一个线程中，保证主线
 * 程在工作过程中不阻塞。
*****************************************/
void comCls::StartTimer(int interval){
    //初始化工作设备
    m_pThread = new QThread(this);
    m_pTimer = new QTimer();
    m_pTimer->moveToThread(m_pThread);
    m_pTimer->setInterval(interval);
    connect(m_pThread, SIGNAL(started()), m_pTimer, SLOT(start()));
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(process()));
    m_pThread->start();
}
/***********************************************
 * 功能:建立通讯
 * 输入：通讯组件
 * 描述:引用通讯组件，获取通讯主题根目录，并建立又向通讯
************************************************/
void comCls::SetMqtt(mqttCls *mqtt){
    this->mqtt=mqtt;
    this->publishTopic=mqtt->topicLogic()+"/"+name;
    this->subscribeTopic=mqtt->topicDevice()+"/"+name;
    Connect();
}
/***********************************************
 * 功能：建立信息关联
 * 描述：向通讯组件插入订阅话题，建立双向通讯
***********************************************/
void comCls::Connect(){
    mqtt->insertTopic(subscribeTopic);
    connect(mqtt,SIGNAL(recivedMsg(const QByteArray, const QMqttTopicName)),this,SLOT(msgRecive(const QByteArray, const QMqttTopicName)));
    connect(this,SIGNAL(Publish(const QByteArray, const QMqttTopicName)),mqtt,SLOT(Publish(const QByteArray, const QMqttTopicName)));
}
/*************************************************
 * 功能：接收信号测试
 * 描述：只在程序开发阶段进行通讯测试
**************************************************/
void comCls::msgRecive(const QByteArray &message, const QMqttTopicName &topic){
    if(topic==subscribeTopic)receive(message);
}

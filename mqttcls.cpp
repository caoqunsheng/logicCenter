#include "mqttcls.h"
#include <QtWidgets/QMessageBox>
mqttCls::mqttCls(QJsonObject object){
    if(object.contains("mqtt")&&object["mqtt"].isObject()){
        //验证配置文件正确
        QJsonObject obj=object["mqtt"].toObject();
        if (obj.contains("host") && obj["host"].isString())
            host=obj.value("host").toString();
        if (obj.contains("port") && obj["port"].isDouble())
            port=obj.value("port").toInt();
        if (obj.contains("username") && obj["username"].isString())
            username=obj.value("username").toString();
        if (obj.contains("password") && obj["password"].isString())
            password=obj.value("password").toString();
        if (obj.contains("rootLogic") && obj["rootLogic"].isString())
            rootLogic=obj.value("rootLogic").toString();
        if (obj.contains("rootUI") && obj["rootUI"].isString())
            rootUI=obj.value("rootUI").toString();
        if (obj.contains("rootDevice") && obj["rootDevice"].isString())
            rootDevice=obj.value("rootDevice").toString();
        //创建通讯客户端
        mqtt_client = new QMqttClient(this);
        mqtt_client->setHostname(host);
        mqtt_client->setPort(port);
        mqtt_client->setUsername(username);
        mqtt_client->setPassword(password);
        if (mqtt_client->state() == QMqttClient::Disconnected)
            mqtt_client->connectToHost();
        //关联客户端信息
        connect(mqtt_client, &QMqttClient::stateChanged, this, &mqttCls::updateLogStateChange);//状态变化
        connect(mqtt_client, &QMqttClient::messageReceived, this, &mqttCls::msgRecive);//收到信息
    }
}
/******************************
功能：把订阅主题列表加入客户端订阅
输入：订阅主题列表
输出：关联到通讯客端
******************************/
void mqttCls::subscribe(){
    if(subTopic.size()>0){
        for(int i=0;i<subTopic.size();i++){
            auto subscription = mqtt_client->subscribe(subTopic[i], 1);
            if (!subscription) {
                qDebug()<<"test Could not subscribe. Is there a valid connection?";
                return;
            }
        }
    }
}
/*
功能：客户端状态检测
作用：检测到客户端连接服务器成功，订阅所有主题
*/
void mqttCls::updateLogStateChange(){
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(mqtt_client->state())
                    + QLatin1Char('\n');//构建测试信息
    if(mqtt_client->state()==2)subscribe();//服务器连接成功，订阅才是有效的。
}
/*
功能：接收客户端信息
作用：转发收到客户端信息，到内部通讯
*/
void mqttCls::msgRecive(const QByteArray &message, const QMqttTopicName &topic)
{
    const QString content = QDateTime::currentDateTime().toString()
                + QLatin1String(" Received Topic: ")
                + topic.name()
                + QLatin1String(" Message: ")
                + message
                + QLatin1Char('\n');
//    qDebug() <<"mqtt msgRecive:" <<content;
    emit recivedMsg(message,topic);//外部通讯转为内部关联通讯
}
/*
功能：向客户端发布信息
作用：转发内部信息到客户端
*/
void mqttCls::Publish(const QByteArray &message, const QMqttTopicName &topic)
{
    if(mqtt_client->state()==2)
        mqtt_client->publish(topic,message,1,false);
}

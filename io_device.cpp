#include "io_device.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QtSql>
#include <QString>
#include <QtWidgets/QMessageBox>
IO_device::IO_device(QMqttClient *m_client,QString ip)
{
    this->ip=ip;
    mqtt_client=m_client; 
    connect(mqtt_client, &QMqttClient::messageReceived, this, &IO_device::msgRecive);//收到信息
}

bool IO_device::SubscribeFromUi(QString topic){
    subscribeFromUiTopic=topic;
    //从操作界面订阅用户操作系统
    auto subscription = mqtt_client->subscribe(subscribeFromUiTopic, 1);
    if (!subscription) {
        qDebug() << this<<QLatin1String("Error")<<QLatin1String("IO Could not subscribe. Is there a valid connection?");
        return false;
    };
   return true;
}
bool IO_device::SubscribeFromDevice(QString topic){
    subscribeFromDeviceTopic=topic;
    //从设备订阅执行信息
    auto subscription = mqtt_client->subscribe(subscribeFromDeviceTopic, 1);
    if (!subscription) {
        qDebug() << this<<QLatin1String("Error")<<QLatin1String("Could not subscribe. Is there a valid connection?");
        return false;
    };
   return true;
}
//接收信号测试
void IO_device::msgRecive(const QByteArray &message, const QMqttTopicName &topic)
{
    const QString content = QDateTime::currentDateTime().toString()
                + QLatin1String(" Received Topic: ")
                + topic.name()
                + QLatin1String(" Message: ")
                + message
                + QLatin1Char('\n');
//    qDebug() <<"IO_device:" <<content;
    if(topic==subscribeFromUiTopic)reciveRromUi(message);//调用业务逻辑处理
    if(topic==subscribeFromDeviceTopic)reciveRromDevice(message);//调用业务逻辑处理
}
//从ui接收数据
void IO_device::reciveRromUi(QByteArray message)
{
    ioDo(message);
}
//向UI发布数据
void IO_device::publishToUI(QString name, QString dat)
{
    QJsonObject json;//创建一个对象，跟数据类型一样的
    QJsonDocument document;
    json.insert(name,dat);
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    mqtt_client->publish(publishToUiTopic,byteArray,1,false);
}
//发布信号到IO设备端
void IO_device::publishToDevice(QString dat)
{
    QJsonObject json;//创建一个对象，跟数据类型一样的
    QJsonDocument document;
    json.insert("Y",dat);
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    mqtt_client->publish(publishToDeviceTopic,byteArray,1,true);
}
//从设备读取数据
void IO_device::reciveRromDevice(QByteArray message)
{
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(message, &jsonError);  // 转化为 JSON 文档
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError))
    {  // 解析未发生错误
        if (doucment.isObject())// JSON 文档为对象
        {
            QJsonObject object = doucment.object();  // 转化为对象
            //解析设和轩输入信息
            QString str="X";
            if (object.contains(str)) // 包含指定的 key
            {
                QJsonValue value = object.value(str);  // 获取指定 key 对应的 value
                if (value.isString())  // 判断 value 是否为字符串
                {
                    QString res=value.toString();//用一个可变量类型
                    for(int i=0;i<16;i++)
                    {
                        X[i]=res.toUtf8()[i];
//                        qDebug() << "X " << i<<"="<<X[i];
                    }
                }
            }
            publishToUI("X", QString::fromLocal8Bit(X,16));//转发设备信息

            str="Y";
            if (object.contains(str)) // 包含指定的 key
            {
                QJsonValue value = object.value(str);  // 获取指定 key 对应的 value
                if (value.isString())  // 判断 value 是否为字符串
                {
                    QString res=value.toString();//用一个可变量类型
                    for(int i=0;i<16;i++)
                    {
                        Y[i]=res.toUtf8()[i];
//                        qDebug() << "Y " << i<<"="<<Y[i];
                    }
                }
            }
            publishToUI("Y", QString::fromLocal8Bit(Y,16));//转发设备信息
        }
    }
}
//执行统一的IO操作
void IO_device::ioDo(QByteArray message)
{
    char output[16]={0};
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(message, &jsonError);  // 转化为 JSON 文档
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError))
    {  // 解析未发生错误
        if (doucment.isObject())// JSON 文档为对象
        {
            QJsonObject object = doucment.object();  // 转化为对象
            for(int i=0;i<16;i++)output[i]=Y[i];//读入当前设备输出状态
            for(int i=0;i<16;i++)
            {
                QString str="Y"+QString::number(i,16);//使用16进制，避开Y10,包含Y1，字符串搜索错误
                if (object.contains(str)) // 包含指定的 key
                {
                    QJsonValue value = object.value(str);  // 获取指定 key 对应的 value
                    if (value.isString())  // 判断 value 是否为字符串
                    {
                        QVariant res=value.toString();//用一个可变量类型
                        output[i]=res.toBool()?'1':'0';
                        qDebug() << "output " << i<<"="<<output[i];

                    }
                }
            }
            publishToDevice(QString::fromLocal8Bit(output,16));//转发到设备
        }
    }
}
void IO_device::Output( uint num, bool value)
{
    char output[16]={0};
    for(int i=0;i<16;i++)output[i]=Y[i];//读入当前设备输出状态
    output[num]=value?'1':'0';
    for(int i=0;i<16;i++)qDebug() << "output " << i<<"="<<output[i];

    publishToDevice(QString::fromLocal8Bit(output,16));//转发到设备
}
bool IO_device::GetOutput(uint num){return Y[num];}
bool IO_device::GetInput(uint num){return X[num];}

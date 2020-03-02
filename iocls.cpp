#include "iocls.h"
/*********************************
 * 功能：初始化
 * 描述：初始化工作参数
*********************************/
IOCls::IOCls(int portNum){
    this->portNum=portNum;
    for(int i=0;i<portNum;i++)
    {
        openDelay<<0;//初始化延时设置
        closeDelay<<0;//初始化关闭延时
        countdown<<0;//初始化倒计时
        countdownLast<<0;
        Yout<<"false";//初始化输出
        Yback<<false;
        Xback<<false;
    }
}
/*********************************
 * 功能：从通讯组件接收外部信息
 * 函数：虚函数
 * 描述：解析控制器输出信息和输入信息。
 *      按内部信息格式转发信号
*********************************/
void IOCls::receive(QByteArray message)
{
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(message, &jsonError);
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)){
        QJsonObject object = doucment.object();
        if (object.contains("X")&& object["X"].isString()){ // 包含指定的 key
            QString res=object.value("X").toString();//用一个可变量类型
            for(int i=0;i<portNum;i++){
                bool temp=res.toUtf8()[i]=='1'?true:false;
                if(Xback[i]!=temp){
                   Xback[i]=temp;
                   emit UpdateX(id,i,temp);
                }
            }
        }
        if (object.contains("Y")&&object["Y"].isString()) // 包含指定的 key
        {
            QString res=object.value("Y").toString();//用一个可变量类型
            for(int i=0;i<portNum;i++)
            {
                bool temp=res.toUtf8()[i]=='1'?true:false;
                if(Yback[i]!=temp){
                    Yback[i]=temp;
                    emit UpdateY(id,i,temp);//变化即传，实时响应。
                }
            }
        }
    }
}
/***********************************
 * 功能：延时执行端口打开和关闭
 * 描述：定时器服务程序，根据延时时间到打开、关闭
 *      相应端口
 * 输入：缓存的内部了操作请求
 * 输出：通过通讯端口发布端口控制请求
************************************/
void IOCls::timeProcess()
{
    QJsonObject jsOut;
    for (int i=0;i<portNum;i++){

        if(countdown[i]>0){
            countdownLast[i]=countdown[i];
            countdown[i]--;
        }
        if(countdownLast[i]==1 && countdown[i]==0)//寻找计时下降沿触发
        {
            countdownLast[i]=countdown[i];//清除执行条件
            QString str="Y"+QString::number(i,16);
            jsOut.insert(str,Yout[i]);
            publishToDevice(jsOut);
        }
    }
}
/*************************************************
 * 功能：接收信号，并转发给IO设备
 * 描述：收到操作信息，如果当前端口没有配置延时则直接打开，
 *      否则，缓存操作信息，由定时器服务程序执行延时打开。
 * 输入：json格式包
 * 输出：通讯端口或延时缓存
**************************************************/
void IOCls::Output(QJsonObject json)
{
   QJsonObject jsOut;
   for (int i=0;i<portNum;i++) {
       QString str="Y"+QString::number(i,16);
       if(json.contains(str))
       {
           QString y=json.value(str).toString();

           if(y=="true"  && openDelay[i]==0)//直接打开
           {
               Yout[i]=y;
               QString str="Y"+QString::number(i,16);
               jsOut.insert(str,Yout[i]);
               publishToDevice(jsOut);
           }else
           if(y=="false"  && closeDelay[i]==0)//直接打开
           {
               Yout[i]=y;
               QString str="Y"+QString::number(i,16);
               jsOut.insert(str,Yout[i]);
               publishToDevice(jsOut);
           }else
           if(y=="true"  && openDelay[i]>0)//延时打开
           {
               Yout[i]=y;
               if(countdown[i]==0)countdown[i]=openDelay[i];//延时过程中，阻止再次延时
           }else
           if(y=="false"  && closeDelay[i]>0)
           {
               Yout[i]=y;
               if(countdown[i]==0)countdown[i]=closeDelay[i];//延时过程中，阻止再次延时
           }
       }
   }
}
/*************************************************
 * 功能：操作设备端口
 * 描述：向通讯组件发送操作信息，操作设备端口
**************************************************/
void IOCls::publishToDevice(QJsonObject jsOut)
{
    if(!jsOut.isEmpty())
    {
        QJsonDocument document;
        document.setObject(jsOut);
        QByteArray byteArray = document.toJson(QJsonDocument::Compact);
        emit Publish(byteArray, publishTopic);
    }
}

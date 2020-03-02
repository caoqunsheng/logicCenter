#include "iomanagercls.h"
/*****************************************************
 * 功能：创建IO设备，并引入通讯端口
 * 描述：读取IO配置信息，创建设备，将通讯端口分发到每一个IO设备
******************************************************/
ioManagerCls::ioManagerCls(QJsonObject object,mqttCls *mqtt)
{
    if (object.contains("IoControl") && object["IoControl"].isArray() && mqtt!=nullptr)
    {
        this->mqtt=mqtt;
        QJsonArray Array=object["IoControl"].toArray();
        ioCfgList=readIoConfig(Array);
        IoPort=createIoDevice(ioCfgList);
    }
}
/****************************************************
 * 功能：从配置文件产生设备配置信息
 * 输入：配置数组
 * 输出：设备配置表
*****************************************************/
QList<IOcfg> ioManagerCls::readIoConfig(QJsonArray Array){
    QList<IOcfg> list;
    for (int Index = 0; Index < Array.size(); Index++){
        IOcfg cfg;
        QJsonObject obj = Array[Index].toObject();
        if (obj.contains("id") && obj["id"].isDouble())
            cfg.id=obj.value("id").toInt();
        if (obj.contains("name") && obj["name"].isString())
            cfg.name=obj.value("name").toString();
        if (obj.contains("portNum") && obj["portNum"].isDouble())
            cfg.port=obj.value("portNum").toInt();
        if (obj.contains("openDelay") && obj["openDelay"].isArray()){
           QJsonArray delayArray=obj["openDelay"].toArray();
           for(int i=0;i<delayArray.size();i++)
                cfg.openDelay<<delayArray[i].toInt();
        }
        if (obj.contains("closeDelay") && obj["closeDelay"].isArray()){
           QJsonArray delayArray=obj["closeDelay"].toArray();
           for(int i=0;i<delayArray.size();i++)
                cfg.closeDelay<<delayArray[i].toInt();
        }

        list<<cfg;//插入设备链表
    }
    return list;
}
/****************************************************
 * 功能：创建设备
 * 输入：设备配置表
 * 输出：设备列表
*****************************************************/
QList<IoNode *> ioManagerCls::createIoDevice(QList<IOcfg> cfg){
    QList<IoNode *> iolist;
    for (int i=0;i<cfg.size();i++) {
        IOCls *oneDevice=new IOCls(cfg[i].port);//创建单一设备
        oneDevice->SetId(cfg[i].id);//单一设备号
        oneDevice->SetName(cfg[i].name);//单一设备名
        oneDevice->SetMqtt(mqtt);//单一设备通讯适配器
        for(int j=0;j<cfg[i].port;j++)//单一设备各个端口打开延时
            oneDevice->setOpenDelay(j,cfg[i].openDelay[j]);
        for(int j=0;j<cfg[i].port;j++)//单一设备各个端口关闭延时
            oneDevice->setOpenDelay(j,cfg[i].closeDelay[j]);

        connect(oneDevice,SIGNAL(UpdateX(int,int,bool)),this,SLOT(UpdateX(int,int,bool)));
        connect(oneDevice,SIGNAL(UpdateY(int,int,bool)),this,SLOT(UpdateY(int,int,bool)));
        IoNode *node=new IoNode();//建立设备管理表结点
        node->deviceId=cfg[i].id;//设备固有编号
        node->io=oneDevice;//设备指针
        iolist<<node;//设表管理节点插入到管理列表中
    }
    return iolist;
}
/*************************************
 * 功能：发布端口统一编号信息
 * 输入：单一设备端口订阅信息
 * 描述：统一编号=设备编号*100+端口号
 * 输出：端口统一编号信息
**************************************/
void ioManagerCls::UpdateX(int id,int port,bool val){
    int portUniteId=id*100+port;
    bool value=val;
    emit portX(portUniteId,value);
}
/*************************************
 * 功能：发布端口统一编号信息
 * 输入：单一设备端口订阅信息
 * 描述：统一编号=设备编号*100+端口号
 * 输出：端口统一编号信息
**************************************/
void ioManagerCls::UpdateY(int id,int port,bool val){
    int portUniteId=id*100+port;
    bool value=val;
    emit portY(portUniteId,value);
}
/**********************************
 * 功能：输出端口
 * 输入：端口统一编号
 * 描述：调用设备节点输出函数，产生端口输出
***********************************/
void ioManagerCls::operatePort( int portId,bool value)
{
    IoNode *node=getIoDevice(portId);
    int port=portId%100;
        QJsonObject Yout;
        QString str="Y"+QString::number(port,16);

        QString val=value?"true":"false";
        Yout.insert(str,val);
        node->io->Output(Yout);

}
/********************************************
 * 功能：从设备表搜索设备节点
 * 输入：端口统一编号
 * 描述：设备编号=端口统一编号/100,
 * 返回：设备结点为指针
********************************************/
IoNode *ioManagerCls::getIoDevice(int portId)
{
    int deviceId=portId/100;
    for(int j=0;j<IoPort.size();j++){//检索IO设备指针
        if(IoPort[j]->deviceId==deviceId){
          return(IoPort[j]);
        }
    }
    return nullptr;
}

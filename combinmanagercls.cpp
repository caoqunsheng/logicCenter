#include "combinmanagercls.h"
/***************************************************
 * 功能：产生逻辑设备，关联IO设备
 * 输入：配置数据json，引用IO设备
 * 输出：组合逻辑设表、互斥逻辑设备表、输入设备表
****************************************************/
combinManagerCls::combinManagerCls(QJsonObject object,ioManagerCls *ioDevice)
{
    this->ioDevice=ioDevice;
    if (object.contains("logic") && object["logic"].isArray()){
        readConfig(object["logic"].toArray());
        creatLogic();
    }
}
/***************************************************
 * 功能：根据输入文件产生内部配置信息
 * 输入：配置数据json
 * 输出：组合逻辑配置表、互斥逻辑配置表、输入配置表
****************************************************/
void combinManagerCls::readConfig(QJsonArray Array)
{
    for (int Index = 0; Index < Array.size(); Index++)
    {
        QJsonObject Obj = Array[Index].toObject();
         if (Obj.contains("combin") && Obj["combin"].isString())
         {
            combCfgList<<Obj.value("combin").toString();
         }else
         if(Obj.contains("mutex") && Obj["mutex"].isString())
         {
            mutexCfgList<<Obj.value("mutex").toString();
         }else
         if(Obj.contains("input") && Obj["input"].isString())
         {
            inputCfgList<<Obj.value("input").toString();
        }
    }
}
/***************************************************
 * 功能：根据内部配置信息，创建工作设备
 * 输入：组合逻辑配置表、互斥逻辑配置表、输入配置表
 * 输出：组合逻辑设表、互斥逻辑设备表、输入设备表
****************************************************/
void combinManagerCls::creatLogic(){
    for(int indexCfg=0;indexCfg<combCfgList.size();indexCfg++)
    {
        combinationCls *oneCombinObj=new combinationCls();
        oneCombinObj->SetLogic(combCfgList[indexCfg]);
        oneCombinObj->SetIoDevice(ioDevice);
        combinList<<oneCombinObj;
    }
    for (int indexCfg=0;indexCfg<mutexCfgList.size();indexCfg++) {
         mutexCls *mutex=new mutexCls();
         mutex->SetIoDevice(ioDevice);
         mutex->SetLogic(mutexCfgList[indexCfg]);
         mutexList<<mutex;
    }
    for (int indexCfg=0;indexCfg<inputCfgList.size();indexCfg++) {
        inputCls *input=new inputCls();
        input->SetIoDevice(ioDevice);
        input->SetLogic(inputCfgList[indexCfg]);
        inputList<<input;
    }
}

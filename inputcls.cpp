#include "inputcls.h"

inputCls::inputCls()
{

}
/************************************
 * 功能：解析逻辑语句
 * 输入：逻辑语句
 * 输出：输入端口号、输出端口号
************************************/
void inputCls::SetLogic(QString logic){
    this->logic=logic;
    if(logic.contains('=')){
        QStringList li=logic.split('=');
        if(li[0].contains('Y'))outPort=li[0].remove('Y').toInt();
        if(li[1].contains('X'))inPort=li[1].remove('X').toInt();
    }
}
/************************************
 * 功能：引用io设备
 * 输入：统一io设备
 * 计算：指向io设备，并建立端口连接
************************************/
void inputCls::SetIoDevice(ioManagerCls *ioDevice)
{
   this->ioDevice=ioDevice;
   connect(ioDevice,SIGNAL(portX(int ,bool )),this,SLOT(portX(int ,bool )));
}
/************************************
 * 功能：关闭互斥端口
 * 输入：当前端口信息
 * 计算：从互斥列表中，搜索并关闭其它
*************************************/
void inputCls::portX(int portUniteId,bool value){
    if(inPort==portUniteId){
        value?ioDevice->setPort(outPort):ioDevice->restPort(outPort);
    }
}

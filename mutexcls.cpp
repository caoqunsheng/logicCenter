#include "mutexcls.h"
#define MAX_SIZE 512
mutexCls::mutexCls()
{

}
/************************************
 * 功能：关闭互斥端口
 * 输入：当前端口信息
 * 计算：从互斥列表中，搜索并关闭其它
*************************************/
void mutexCls::portY(int portUniteId,bool value){
    if(MutexPort.contains(portUniteId) && value==true){
        for(int i=0;i<MutexPort.size();i++){
            if(MutexPort[i]!=portUniteId)ioDevice->restPort(MutexPort[i]);
        }
    }
}
/************************************
 * 功能：引用io设备
 * 输入：统一io设备
 * 计算：指向io设备，并建立端口连接
************************************/
void mutexCls::SetIoDevice(ioManagerCls *ioDevice)
{
   this->ioDevice=ioDevice;
   connect(ioDevice,SIGNAL(portY(int ,bool )),this,SLOT(portY(int ,bool )));
}
/**************************************
 * 功能：分析互斥端口
 * 输入：逻辑表达式
 * 输出：互斥端口数组
*/
void mutexCls::SetLogic(QString logic){
    QStringList li=logic.split('!');
    for(int i=0;i<li.size();i++){
        MutexPort<<li[i].remove('Y').toInt();
    }
}

#include "combinationcls.h"
#include <QDebug>
//#include <string>
#define MAX_SIZE 512
combinationCls::combinationCls()
{
}
/********************************************************
 * 功能：执行组合逻辑
 * 函数：槽函数
 * 描述：收到来自设备的输出响应信息，执行组合逻辑，并
 *      根据计算结果输出操作指令
 * 输出：统一端口操作指令
*********************************************************/
void combinationCls::portY(int portUniteId,bool value){
    for (int index=0;index<portList.size();index++) {
        if(portList[index].portId==portUniteId){
            portList[index].value=value;
            bool state= process();//逻辑计算;
            state?ioDevice->setPort(outPort):ioDevice->restPort(outPort);
        }
    }
}
/*******************************************************
 * 功能：解析组合逻辑
 * 输入：逻辑语句字符串
 * 描述：解析逻辑语句产生输出端口号、运算端口号、逻辑表达式，逻辑
 *      表达式留给计算过程使用。
 * 输出：输出端口、运算端口、逻辑表达式
*******************************************************/
void combinationCls::SetLogic(QString logic){
    this->logic=logic;
    if(logic.contains('=')){
        QStringList li=logic.split('=');
        if(li[0].contains('Y'))outPort=li[0].remove('Y').toInt();
        express=li[1].remove('Y');
        QByteArray bb=express.toLatin1();
        char buff[MAX_SIZE];
        memset(buff,0,MAX_SIZE);
        for(int i=0;i<bb.size();i++)buff[i]=bb[i];
        char *str=buff;
        char* temp;
        char dest[1024];
        memset(dest,0,MAX_SIZE);
        int num = 0;

        while(*str != '\0'){
           temp = dest;//指向辅助内存
           while(*str >= '0' && *str <= '9'){           /*判断是否是数据*/
              *temp = *str;
              str ++;
              temp ++;
           }                               /*遇到符号退出*/
           if(*str != '(' && *(temp - 1) != '\0'){      /*判断符号是否为'('*/
              *temp = '\0';
              num = atoi(dest);               /*将字符串转为数字*/
              UnitePort node;
              node.portId=num;
              node.value=false;
              portList<<node;      /*将数据压入数据栈*/
           }
           str ++;                 /*指向表达式下一个字符*/
        }
    }
}
void combinationCls::SetIoDevice(ioManagerCls *ioDevice){
   this->ioDevice=ioDevice;
   connect(ioDevice,SIGNAL(portY(int ,bool )),this,SLOT(portY(int ,bool )));
}
/**************************************************
 * 功能：运算符优先级判断
 * 输入：当前运行符
 * 描述：当前运算符和栈顶运算符比较，选择执行方向
***************************************************/
int combinationCls::compare( char ch){                   /*比较操作服优先级*/
    if(operatorsStack.isEmpty() || ch == '(')  /*判断操作符栈是否为空；栈顶操作   符是否为'('*/
    {
        return 0;                       /*操作符压入栈*/
    }else
    if((operatorsStack.top() == '(' && ch != ')'))
    {
        return 0;
    }else
    if( operatorsStack.top() == '+' && ch == '*')           /*判断当前优先级是否比栈顶操作符优先级高*/
    {
        return 0;                      /*操作符压入栈*/
    }else
    if (operatorsStack.top() =='(' && ch == ')' )       /*判断括号内的表达式是否计算完毕*/
    {
        operatorsStack.pop();
        return 1;                       /*对（）进行处理*/
    }else
    {
        return -1;                                          /*进行操作符的运算*/
    }
}
/******************************************************
 * 功能：单步逻辑计算
 * 描述：复杂逻辑通过压栈的方法，分解到单步计算，并将计算结果压栈
 * 输入：栈
 * 输出：栈
*******************************************************/
int combinationCls::deal_date(){    /*进行数据运算*/
    bool value = false;
    bool B1=operandStack.pop();
    bool B2=operandStack.pop();
    char opr=operatorsStack.pop();
    switch(opr)
    {
    case '+' :value = B1 || B2;            /*加法操作，改为逻辑或*/
        break;
    case '*' :value = B1 && B2;            /*乘法操作，改为逻辑与*/
        break;
    default:break;
    }
    operandStack.push(value);                          /*将操作符栈顶下移一位*/
    return value;
}
/**********************************************
 * 功能：组合逻辑计算
 * 输入：输入端口当前取值、逻辑表达式
 * 描述：本功能由端口信息槽触发，即当前端口数值变化时，
 *      执行逻辑运算，产生计算结果
 * 输出：计算结果
***********************************************/
bool combinationCls::process(){
    QByteArray bb=express.toLatin1();
    char buff[MAX_SIZE];
    memset(buff,0,MAX_SIZE);
    char dest[MAX_SIZE];
    memset(dest,0,MAX_SIZE);
    for(int i=0;i<bb.size();i++)buff[i]=bb[i];
    char *str=buff;
    char* temp;

    int num = 0;
    int i = 0;
    operatorsStack.clear();//操作符栈
    operandStack.clear();
    while(*str != '\0')
    {
       temp = dest;//指向辅助内存
       while(*str >= '0' && *str <= '9'){           /*判断是否是数据*/
          *temp = *str;
          str ++;
          temp ++;
       }                               /*遇到符号退出*/
       if(*str != '(' && *(temp - 1) != '\0'){      /*判断符号是否为'('*/
          *temp = '\0';
          num = atoi(dest);               /*将字符串转为数字*/
          bool val=false;
          for (int index=0;index<portList.size();index++) {
             if(portList[index].portId==num){
                 val=portList[index].value;
                 break;
             }
          }
          operandStack.push(val);
       }
       while(1){
          i = compare(*str);      /*判断操作符优先级*/
          if(i == 0){
              if(*str!='\0')operatorsStack.push(*str);
              break;
          }
          else if(i == 1){                         /*判断括号内的表达式是否结束*/
               str++;
          }
          else if(i == -1){                        /*进行数据处理*/
               deal_date();
          }
       }
       str ++;                 /*指向表达式下一个字符*/
   }
   bool res=operandStack.top();
   return res;
}


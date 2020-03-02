#ifndef COMBINMANAGERCLS_H
#define COMBINMANAGERCLS_H
#include "combinationcls.h"
#include "mutexcls.h"
#include <QObject>
#include "iocls.h"
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "iomanagercls.h"
#include "inputcls.h"
class combinManagerCls:public QObject
{
    Q_OBJECT
public:
    combinManagerCls(QJsonObject object,ioManagerCls *ioDevice);
private:
    QList<QString> combCfgList;
    QList<QString> mutexCfgList;
    QList<QString> inputCfgList;
    ioManagerCls *ioDevice;
    QList<combinationCls*>combinList;
    QList<mutexCls*>mutexList;
    QList<inputCls*>inputList;

private:
    void readConfig(QJsonArray Array);
    void creatLogic();
};

#endif // COMBINMANAGER_H

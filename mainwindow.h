#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QtMqtt/QMqttClient>
#include "mqttcls.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "iocls.h"
#include "mutexcls.h"
#include <QJsonArray>
#include "combinationcls.h"
#include "iomanagercls.h"
namespace Ui {
    class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonConnect_clicked();
    void brokerDisconnected();
    void updateLogStateChange();
    void msgRecive(const QByteArray &message, const QMqttTopicName &topic);
    void on_buttonPublish_clicked();
    void on_buttonSubscribe_clicked();
    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
    QMqttClient *m_client;
    mqttCls *mqtt;
    QJsonObject objectConfig;
private:
    void uiInit();
    QJsonObject analysisConfig(QString filename);

    void CreateSysCls();
};

#endif // MAINWINDOW_H

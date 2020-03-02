#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QDateTime>
#include <QtWidgets/QMessageBox>
#include "QLabel"
#include <QFileInfo>
#include "combinmanagercls.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectConfig=analysisConfig("config.json");//读取设备配置文件
    mqtt=new mqttCls(objectConfig);//创建通讯设备
    uiInit();//关联测试界面
    ioManagerCls *ioManager=new ioManagerCls(objectConfig,mqtt);//创建全局IO
    combinManagerCls *combinManger=new combinManagerCls(objectConfig,ioManager);//创建组合逻辑
    updateLogStateChange();
}
MainWindow::~MainWindow()
{
    delete ui;
    qApp->quit();
}
void MainWindow::uiInit()
{
    m_client=mqtt->client();
    connect(m_client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);//状态变化
    connect(m_client, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnected);//断开连接
    connect(m_client, &QMqttClient::messageReceived, this, &MainWindow::msgRecive);//收到信息
    connect(m_client, &QMqttClient::pingResponseReceived, this, [this]() {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" PingResponse")
                    + QLatin1Char('\n');
        ui->editLog->insertPlainText(content);
    });
    ui->lineEditHost->setText(m_client->hostname());
    ui->spinBoxPort->setValue(m_client->port());
    ui->lineEditUser->setText(m_client->username());
    ui->lineEditPassword->setText(m_client->password());
    ui->editLog->setMaximumBlockCount(50);
}
void MainWindow::on_buttonConnect_clicked()
{    
    if (m_client->state() == QMqttClient::Disconnected) {
        ui->buttonConnect->setText(tr("Disconnect"));
        m_client->connectToHost();
    } else {
        ui->buttonConnect->setText(tr("Connect"));
        m_client->disconnectFromHost();
    }
}
void MainWindow::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
    ui->editLog->insertPlainText(content);
    if(m_client->state()==2){
        ui->lineEditHost->setEnabled(false);
        ui->spinBoxPort->setEnabled(false);
        ui->lineEditUser->setEnabled(false);
        ui->lineEditPassword->setEnabled(false);
    }else {
        ui->lineEditHost->setEnabled(true);
        ui->spinBoxPort->setEnabled(true);
        ui->lineEditUser->setEnabled(true);
        ui->lineEditPassword->setEnabled(true);
    }
}

void MainWindow::brokerDisconnected()
{
    ui->lineEditHost->setEnabled(true);
    ui->spinBoxPort->setEnabled(true);
    ui->lineEditUser->setEnabled(true);
    ui->lineEditPassword->setEnabled(true);
    ui->buttonConnect->setText(tr("Connect"));
}

void MainWindow::on_buttonPublish_clicked()
{
    if (m_client->publish(ui->lineEditTopic->text(),
                          ui->lineEditMessage->text().toUtf8(),
                          ui->spinQoS_2->text().toUInt(),
                          ui->checkBoxRetain->isChecked()) == -1)
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
}

void MainWindow::msgRecive(const QByteArray &message, const QMqttTopicName &topic)
{

    const QString content = QDateTime::currentDateTime().toString()
                + QLatin1String(" Received Topic: ")
                + topic.name()
                + QLatin1String(" Message: ")
                + message
                + QLatin1Char('\n');
    ui->editLog->insertPlainText(content);

}
void MainWindow::on_buttonSubscribe_clicked()
{
    auto subscription = m_client->subscribe(ui->lineEditTopic->text(), ui->spinQoS->text().toUInt());
    if (!subscription) {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("test Could not subscribe. Is there a valid connection?"));
        return;
    }

}
QJsonObject MainWindow::analysisConfig(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
        qDebug()<<"Couldn't open config file.";
    QByteArray configData = file.readAll();
    file.close();
    QJsonDocument doucment(QJsonDocument::fromJson(configData));
    QJsonObject obj = doucment.object();  // 转化为对象
    return obj;
}
void MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}

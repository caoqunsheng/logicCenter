/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QSpinBox *spinBoxPort;
    QLineEdit *lineEditUser;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditHost;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label;
    QPushButton *buttonConnect;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEditTopic;
    QLabel *label_5;
    QSpinBox *spinQoS;
    QPushButton *buttonSubscribe;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEditMessage;
    QCheckBox *checkBoxRetain;
    QLabel *label_7;
    QSpinBox *spinQoS_2;
    QPushButton *buttonPublish;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *editLog;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(654, 768);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        spinBoxPort = new QSpinBox(groupBox_3);
        spinBoxPort->setObjectName(QString::fromUtf8("spinBoxPort"));
        spinBoxPort->setMaximum(99999);
        spinBoxPort->setValue(61613);

        gridLayout_2->addWidget(spinBoxPort, 1, 1, 1, 1);

        lineEditUser = new QLineEdit(groupBox_3);
        lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));

        gridLayout_2->addWidget(lineEditUser, 2, 1, 1, 1);

        lineEditPassword = new QLineEdit(groupBox_3);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEditPassword, 3, 1, 1, 1);

        lineEditHost = new QLineEdit(groupBox_3);
        lineEditHost->setObjectName(QString::fromUtf8("lineEditHost"));

        gridLayout_2->addWidget(lineEditHost, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 3, 0, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setSizeIncrement(QSize(0, 0));
        label->setBaseSize(QSize(0, 0));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        buttonConnect = new QPushButton(groupBox_3);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));

        gridLayout_2->addWidget(buttonConnect, 3, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout_4->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEditTopic = new QLineEdit(groupBox_2);
        lineEditTopic->setObjectName(QString::fromUtf8("lineEditTopic"));

        gridLayout->addWidget(lineEditTopic, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        spinQoS = new QSpinBox(groupBox_2);
        spinQoS->setObjectName(QString::fromUtf8("spinQoS"));
        spinQoS->setMaximum(2);
        spinQoS->setValue(1);

        gridLayout->addWidget(spinQoS, 1, 1, 1, 1);

        buttonSubscribe = new QPushButton(groupBox_2);
        buttonSubscribe->setObjectName(QString::fromUtf8("buttonSubscribe"));
        buttonSubscribe->setEnabled(true);

        gridLayout->addWidget(buttonSubscribe, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, 0, -1, -1);
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        lineEditMessage = new QLineEdit(groupBox_4);
        lineEditMessage->setObjectName(QString::fromUtf8("lineEditMessage"));

        gridLayout_3->addWidget(lineEditMessage, 0, 2, 1, 1);

        checkBoxRetain = new QCheckBox(groupBox_4);
        checkBoxRetain->setObjectName(QString::fromUtf8("checkBoxRetain"));

        gridLayout_3->addWidget(checkBoxRetain, 2, 2, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 2, 0, 1, 1);

        spinQoS_2 = new QSpinBox(groupBox_4);
        spinQoS_2->setObjectName(QString::fromUtf8("spinQoS_2"));
        spinQoS_2->setMaximum(2);
        spinQoS_2->setValue(1);

        gridLayout_3->addWidget(spinQoS_2, 1, 2, 1, 1);

        buttonPublish = new QPushButton(groupBox_4);
        buttonPublish->setObjectName(QString::fromUtf8("buttonPublish"));
        buttonPublish->setEnabled(true);

        gridLayout_3->addWidget(buttonPublish, 1, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);


        verticalLayout_4->addWidget(groupBox_4);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        editLog = new QPlainTextEdit(groupBox);
        editLog->setObjectName(QString::fromUtf8("editLog"));

        horizontalLayout_2->addWidget(editLog);


        verticalLayout_4->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 654, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "logic center", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        lineEditUser->setText(QCoreApplication::translate("MainWindow", "admin", nullptr));
        lineEditPassword->setText(QCoreApplication::translate("MainWindow", "password", nullptr));
        lineEditHost->setText(QCoreApplication::translate("MainWindow", "192.168.43.101", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Host:", nullptr));
        buttonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Topic", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Topic:", nullptr));
        lineEditTopic->setText(QCoreApplication::translate("MainWindow", "ui/kettle1", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "QoS:", nullptr));
        buttonSubscribe->setText(QCoreApplication::translate("MainWindow", "Subscribe", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Messaeg", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Content:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "QoS:", nullptr));
        lineEditMessage->setText(QCoreApplication::translate("MainWindow", "{\"cmd\":\"keep\",\"upperLimit\":50,\"upperBuff\":2,\"lowerLimit\":30,\"lowerBuff\":2}", nullptr));
        checkBoxRetain->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Retain:", nullptr));
        buttonPublish->setText(QCoreApplication::translate("MainWindow", "Publish", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "information", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "System", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

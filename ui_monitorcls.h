/********************************************************************************
** Form generated from reading UI file 'monitorcls.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORCLS_H
#define UI_MONITORCLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_monitorCls
{
public:
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
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_4;
    QLineEdit *sub_ui;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *pub_ui;
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
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *monitorCls)
    {
        if (monitorCls->objectName().isEmpty())
            monitorCls->setObjectName(QString::fromUtf8("monitorCls"));
        monitorCls->resize(733, 633);
        verticalLayout_4 = new QVBoxLayout(monitorCls);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_3 = new QGroupBox(monitorCls);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
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

        groupBox_5 = new QGroupBox(monitorCls);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(0, 0));
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, 0, -1, -1);
        sub_ui = new QLineEdit(groupBox_5);
        sub_ui->setObjectName(QString::fromUtf8("sub_ui"));

        gridLayout_4->addWidget(sub_ui, 1, 2, 1, 1);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        pub_ui = new QLineEdit(groupBox_5);
        pub_ui->setObjectName(QString::fromUtf8("pub_ui"));

        gridLayout_4->addWidget(pub_ui, 0, 2, 1, 1);


        verticalLayout_5->addLayout(gridLayout_4);


        verticalLayout_4->addWidget(groupBox_5);

        groupBox_2 = new QGroupBox(monitorCls);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
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

        groupBox_4 = new QGroupBox(monitorCls);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_3 = new QGridLayout();
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

        groupBox = new QGroupBox(monitorCls);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        editLog = new QPlainTextEdit(groupBox);
        editLog->setObjectName(QString::fromUtf8("editLog"));

        horizontalLayout_2->addWidget(editLog);


        verticalLayout_4->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(monitorCls);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);


        retranslateUi(monitorCls);
        QObject::connect(buttonBox, SIGNAL(accepted()), monitorCls, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), monitorCls, SLOT(reject()));

        QMetaObject::connectSlotsByName(monitorCls);
    } // setupUi

    void retranslateUi(QDialog *monitorCls)
    {
        monitorCls->setWindowTitle(QCoreApplication::translate("monitorCls", "Dialog", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("monitorCls", "\350\277\236\346\216\245", nullptr));
        label_8->setText(QCoreApplication::translate("monitorCls", "Username:", nullptr));
        lineEditUser->setText(QCoreApplication::translate("monitorCls", "admin", nullptr));
        lineEditPassword->setText(QCoreApplication::translate("monitorCls", "password", nullptr));
        lineEditHost->setText(QCoreApplication::translate("monitorCls", "192.168.43.101", nullptr));
        label_2->setText(QCoreApplication::translate("monitorCls", "Port:", nullptr));
        label_9->setText(QCoreApplication::translate("monitorCls", "Password:", nullptr));
        label->setText(QCoreApplication::translate("monitorCls", "Host:", nullptr));
        buttonConnect->setText(QCoreApplication::translate("monitorCls", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("monitorCls", "\350\257\235\351\242\230\347\233\256\345\275\225", nullptr));
        label_10->setText(QCoreApplication::translate("monitorCls", "\345\217\221\345\270\203\346\240\271\347\233\256\345\275\225", nullptr));
        label_11->setText(QCoreApplication::translate("monitorCls", "\350\256\242\351\230\205\346\240\271\347\233\256\345\275\225", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("monitorCls", "\350\257\235\351\242\230", nullptr));
        label_3->setText(QCoreApplication::translate("monitorCls", "Topic:", nullptr));
        lineEditTopic->setText(QCoreApplication::translate("monitorCls", "UI/tank1", nullptr));
        label_5->setText(QCoreApplication::translate("monitorCls", "QoS:", nullptr));
        buttonSubscribe->setText(QCoreApplication::translate("monitorCls", "\350\256\242\351\230\205\350\257\235\351\242\230\346\265\213\350\257\225", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("monitorCls", "\344\277\241\346\201\257", nullptr));
        label_4->setText(QCoreApplication::translate("monitorCls", "Content:", nullptr));
        label_6->setText(QCoreApplication::translate("monitorCls", "QoS:", nullptr));
        lineEditMessage->setText(QCoreApplication::translate("monitorCls", "{\"cmd\":\"increase\",\"incMass\":500}", nullptr));
        checkBoxRetain->setText(QString());
        label_7->setText(QCoreApplication::translate("monitorCls", "Retain:", nullptr));
        buttonPublish->setText(QCoreApplication::translate("monitorCls", "\345\217\221\345\270\203\350\257\235\351\242\230\346\265\213\350\257\225", nullptr));
        groupBox->setTitle(QCoreApplication::translate("monitorCls", "\346\265\213\350\257\225\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class monitorCls: public Ui_monitorCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORCLS_H

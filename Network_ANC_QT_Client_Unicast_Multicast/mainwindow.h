#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QThread>
#include <QMainWindow>
#include <QApplication>

//#include "myrunnablestartserver.h"
#include "objectstartserver.h"
#include "myobjectupmeverysec.h"
#include "ui_mainwindow.h"

#include "corba_file/MessengerC.h"
#include "corba_file/MessengerS.h"

#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_sys_time.h"
#include <iostream>
#include "ace/Get_Opt.h"
#include <orbsvcs/CosNamingC.h>
#include "tao/Object_T.h"



namespace Ui {
class MainWindow;
}

typedef ::LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeLogic  cmpLogic;
typedef ::CORBA::Long CORBALong;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static QObject *parentLocal;
    static CORBA::ORB_var orb;

    QThread mThreadUPMEverySec;
    MyObjectUPMEverySec cMyObjectUPMEverySec;

    QThread mThreadStartServer;
    ObjectStartServer cMyObjectStartServer;

public slots:
    void send_messageSlot(QString,QString,CORBALong,QString,QString);
    void slotcmdUpdateParametersNewSent();
    void slotMessageUpdateParametersLogicSent(cmpLogic);

    
private slots:

    void on_pushButtonMessageGUI_clicked();

    void on_pushButtonUpdateParam_clicked();

    void on_pushButtonUpdateParamNEW_clicked();

    void on_pushButtonUpdateParamMulticast_clicked();

    void on_pushButtonUnicastMulticastON_clicked();

    void on_pushButtonUpdateParamMulticastLoop_clicked();

    void on_pushButtonStartUpdateParamMulticastEverySecond_clicked();

    void on_pushButtonStopUpdateParamMulticastEverySecond_clicked();

    void on_pushButtonStartCom_clicked();

    void on_pushButtonStopCom_clicked();

    void on_pushButtonUnicastMulticastServerON_clicked();

private:
    Ui::MainWindow *ui;
    void sleepNseconds(int);

    void SendMessageUpdateParametersLogicPrivate(cmpLogic);
    Messenger_var messenger;
    Messenger_var messengerMulti1;
    int CountMessage;
    bool StopVar;

};


#endif // MAINWINDOW_H

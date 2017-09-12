#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "myrunnablestartserver.h"
#include "objectstartserver.h"

#include <QMainWindow>
#include <QThread>
#include <QtCore>

#include "corba_file/MessengerS.h"
#include "corba_file/Messenger2S.h"


#include "ui_mainwindow.h"

#include "Messenger_i.h"


#include <fstream>
#include <iostream>
#include <string>


#include "ace/Get_Opt.h"
#include "ace/OS_NS_stdio.h"
#include <orbsvcs/CosNamingC.h>
#include <orbsvcs/PortableGroup/MIOP.h>
#include <orbsvcs/PortableGroup/GOA.h>
#include <tao/ORB.h>
#include <ace/String_Base.h>


namespace Ui {
class MainWindow;
}

typedef ::LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeNew  cmpNEW;
typedef ::LocalInterface::CompositeTypes::cmdUpdateParametersCompType  cmp;
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

    QThread mThreadStartServer;
    ObjectStartServer cMyObjectStartServer;

public slots:
    void send_messageSlot(QString,QString,CORBALong,QString,QString);
    void cmdUpdateParametersNewSlot(cmpNEW);
    void cmdUpdateParametersSlot(cmp);
    void slotMessageUpdateParametersLogicBackSent(cmpLogic);

private slots:
    void on_pushButtonUnicastMulticastON_clicked();

    void on_pushButton_clicked();

    void on_pushButtonUnicastMulticastServerON_clicked();

private:
    Ui::MainWindow *ui;


    void sleepNseconds(int);
    void SendMessageUpdateParametersLogicPrivate(cmpLogic);

    Messenger2_var messenger2;
    int CountMessage;

};



#endif // MAINWINDOW_H

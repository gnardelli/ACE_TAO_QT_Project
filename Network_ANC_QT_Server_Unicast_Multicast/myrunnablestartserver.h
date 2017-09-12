#ifndef MYRUNNABLESTARTSERVER_H
#define MYRUNNABLESTARTSERVER_H



#include <QObject>
#include <QRunnable>
#include <QtCore>

#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <fstream>
#include <iostream>
#include <string>


#include "ace/Get_Opt.h"
#include "ace/OS_NS_stdio.h"
#include <orbsvcs/CosNamingC.h>
#include <orbsvcs/PortableGroup/MIOP.h>
#include <orbsvcs/PortableGroup/GOA.h>
#include <ace/String_Base.h>
#include <tao/PortableServer/PortableServerC.h>
#include <tao/ORB.h>


class MyRunnableStartServer : public QObject, public QRunnable
{
    Q_OBJECT
public:
    MyRunnableStartServer();



protected:
    void run();

private:
    void sleepNseconds(int);
    void destroyORB();

};


#endif // MYRUNNABLESTARTSERVER_H

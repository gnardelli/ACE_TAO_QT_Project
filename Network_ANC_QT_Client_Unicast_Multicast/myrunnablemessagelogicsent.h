#ifndef MYRUNNABLEMESSAGELOGICSENT_H
#define MYRUNNABLEMESSAGELOGICSENT_H

#include <QObject>
#include <QRunnable>
#include <QtCore>

#include "mainwindow.h"
#include "ui_mainwindow.h"


typedef ::LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeLogic  cmpLogic;


class MyRunnableMessageLogicSent : public QObject, public QRunnable
{
    Q_OBJECT
public:
    MyRunnableMessageLogicSent();

signals:
    void MessageUpdateParametersLogicSent(cmpLogic);

public slots:
    void slotcmdUpdateParametersLogicBackSent(cmpLogic);

protected:
    void run();

private:
    cmpLogic ParamNewLocal;
    void sleepNseconds(int);

};


#endif // MYRUNNABLEMESSAGELOGICSENT_H









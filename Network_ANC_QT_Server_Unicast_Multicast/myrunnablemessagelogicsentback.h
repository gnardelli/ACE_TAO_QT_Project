#ifndef MYRUNNABLEMESSAGELOGICSENTBACK_H
#define MYRUNNABLEMESSAGELOGICSENTBACK_H


#include <QObject>
#include <QRunnable>
#include <QtCore>

#include "mainwindow.h"
#include "ui_mainwindow.h"

typedef ::LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeLogic  cmpLogic;

class MyRunnableMessageLogicSentBack : public QObject, public QRunnable
{
    Q_OBJECT
public:
    MyRunnableMessageLogicSentBack();

signals:
    void MessageUpdateParametersLogicSentBack(cmpLogic);


public slots:
    void slotcmdUpdateParametersLogicSent(cmpLogic);

protected:
    void run();

private:
    cmpLogic ParamNewLocal;
    void sleepNseconds(int);


};

#endif // MYRUNNABLEMESSAGELOGICSENTBACK_H

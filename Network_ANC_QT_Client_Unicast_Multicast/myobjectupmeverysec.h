#ifndef MYOBJECTUPMEVERYSEC_H
#define MYOBJECTUPMEVERYSEC_H

#include <QObject>
#include <QThread>
#include <QtCore>

#include "tao/Object_T.h"

class MyObjectUPMEverySec : public QObject
{
    Q_OBJECT
public:
    explicit MyObjectUPMEverySec(QObject *parent = 0);
    void DoSetup(QThread &cThread);
    bool stop;

signals:
    void cmdUpdateParametersNewSent();


public slots:
    void DoWork();

};

#endif // MYOBJECTUPMEVERYSEC_H

#ifndef OBJECTSTARTSERVER_H
#define OBJECTSTARTSERVER_H

#include <QObject>
#include <QThread>
#include <tao/ORB.h>

class ObjectStartServer : public QObject
{
    Q_OBJECT
public:
    explicit ObjectStartServer(QObject *parent = 0);
    void DoSetup(QThread &cThread);
    bool stop;

signals:
    void cmdUpdateParametersNewSent();

public slots:
    void DoWork();
    void destroyORB();


};

#endif // OBJECTSTARTSERVER_H

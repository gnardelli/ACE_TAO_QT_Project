#include "myobjectupmeverysec.h"





MyObjectUPMEverySec::MyObjectUPMEverySec(QObject *parent) :
    QObject(parent)
{
}

void MyObjectUPMEverySec::DoSetup(QThread &cThread)
{
    connect(&cThread,SIGNAL(started()),this,SLOT(DoWork()));

}

void MyObjectUPMEverySec::DoWork()
{
    const int NUM_SECONDS = 1;

    while (true){


            QMutex mutex;
            mutex.lock();
            if (stop) break;
            mutex.unlock();

            //emit NumberChanged(this->Counter++);

            //this->msleep(100);


           // delay for 10 seconds
           for(int i = 0 ; i < NUM_SECONDS ; i++) { usleep(1000 * 1000); }
           // print

           emit cmdUpdateParametersNewSent();


    }
}

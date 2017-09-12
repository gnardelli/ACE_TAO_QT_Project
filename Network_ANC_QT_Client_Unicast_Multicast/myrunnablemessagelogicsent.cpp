#include "myrunnablemessagelogicsent.h"


MyRunnableMessageLogicSent::MyRunnableMessageLogicSent()
{
}


void MyRunnableMessageLogicSent::run()
{


    sleepNseconds(1);
    emit MessageUpdateParametersLogicSent(ParamNewLocal);



}


void MyRunnableMessageLogicSent::sleepNseconds(int NUM_SECONDS) {
    for(int i = 0 ; i < NUM_SECONDS ; i++) { usleep(1000 * 1000); }
}


void MyRunnableMessageLogicSent::slotcmdUpdateParametersLogicBackSent(cmpLogic ParamNew) {


        ParamNewLocal.Eta=ParamNew.Eta;
        ParamNewLocal.Famigliari=ParamNew.Famigliari;
        ParamNewLocal.Figli=ParamNew.Figli;
        ParamNewLocal.Tel=ParamNew.Tel;


}





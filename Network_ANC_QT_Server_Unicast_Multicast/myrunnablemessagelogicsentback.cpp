#include "myrunnablemessagelogicsentback.h"

MyRunnableMessageLogicSentBack::MyRunnableMessageLogicSentBack()
{
}


void MyRunnableMessageLogicSentBack::run()
{


    sleepNseconds(1);
    emit MessageUpdateParametersLogicSentBack(ParamNewLocal);


}


void MyRunnableMessageLogicSentBack::sleepNseconds(int NUM_SECONDS) {
    for(int i = 0 ; i < NUM_SECONDS ; i++) { usleep(1000 * 1000); }
}


void MyRunnableMessageLogicSentBack::slotcmdUpdateParametersLogicSent(cmpLogic ParamNew) {


        ParamNewLocal.Eta=ParamNew.Eta;
        ParamNewLocal.Famigliari=ParamNew.Famigliari;
        ParamNewLocal.Figli=ParamNew.Figli;
        ParamNewLocal.Tel=ParamNew.Tel;


}

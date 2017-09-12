// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0a
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_codegen.cpp:1551

#include "Messenger2_i.h"





// Implementation skeleton constructor
Messenger2_i::Messenger2_i (void)
{

    qRegisterMetaType<CORBALong>("CORBALong");
    connect(this,SIGNAL(MessSent(QString,QString,CORBALong,QString,QString)),MainWindow::parentLocal,SLOT(send_messageSlot(QString,QString,CORBALong,QString,QString)));




}

// Implementation skeleton destructor
Messenger2_i::~Messenger2_i (void)
{
}




::CORBA::Boolean Messenger2_i::send_message2 (
  const char * Name,
  const char * LastName,
  ::CORBA::Long eta,
  const char * subject,
  const char * message)
{
 

   QString NameEmit(Name);
   QString LastNameEmit(LastName);
   QString subjectEmit(subject);
   QString messageEmit(message);


   emit MessSent(NameEmit,LastNameEmit,eta,subjectEmit,messageEmit);


   return true;

}


void Messenger2_i::cmdUpdateParametersLogicBack (
  const ::LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeLogic & cmdUpdateParametersParamLogic)
{


    MyRunnableMessageLogicSent *task = new MyRunnableMessageLogicSent();

    qRegisterMetaType<cmpLogic>("cmpLogic");
    connect(task,SIGNAL(MessageUpdateParametersLogicSent(cmpLogic)),MainWindow::parentLocal,SLOT(slotMessageUpdateParametersLogicSent(cmpLogic)));
    connect(this,SIGNAL(cmdUpdateParametersLogicBackSent(cmpLogic)),task,SLOT(slotcmdUpdateParametersLogicBackSent(cmpLogic)));

    task->setAutoDelete(true);
    emit cmdUpdateParametersLogicBackSent(cmdUpdateParametersParamLogic);

    QThreadPool::globalInstance()->start(task);

    /*

        delete cMyObjectMessageLogic;
        cMyObjectMessageLogic =0;

        mThreadMessageLogic = new QThread();

        cMyObjectMessageLogic = new MyObjectMessageLogicSent();

        cMyObjectMessageLogic->DoSetup(*mThreadMessageLogic);
        cMyObjectMessageLogic->moveToThread(mThreadMessageLogic);

        connect(cMyObjectMessageLogic, SIGNAL(destroyed()), mThreadMessageLogic, SLOT(quit()));
        connect(mThreadMessageLogic, SIGNAL(finished()), mThreadMessageLogic, SLOT(deleteLater()));


        mThreadMessageLogic->start();

        */






}


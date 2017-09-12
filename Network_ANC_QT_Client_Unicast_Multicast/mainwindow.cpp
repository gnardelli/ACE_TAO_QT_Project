#include "mainwindow.h"





QObject * MainWindow::parentLocal=0;
CORBA::ORB_var MainWindow::orb=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::parentLocal=this;


    int argc;


    argc=2;
    char* argv[2];

    const char *arg0 = "-ORBInitRef NameService=corbaloc:iiop:9.10.10.10:12345/NameService";
    const char *arg1 = "-ORBListenEndpoints iiop://9.10.10.10:54321";
   // const char *arg2 = "-ORBDottedDecimalAddresses 1";


    argv[0] = (char*)arg0;
    argv[1] = (char*)arg1;
  //  argv[2] = (char*)arg2;

    //ACE_TCHAR *argv [];
    // Initialize and error check ORBMulti
    MainWindow::orb  = CORBA::ORB_init (argc, argv);

    if (CORBA::is_nil(MainWindow::orb.in()))
    {
        std::cout << "Could not initialize ORB" << std::endl;
        exit(1);
    }


    CountMessage=0;


}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::send_messageSlot(QString Name,QString LastName,CORBALong eta,QString subject,QString message)
{



    ui->lineEditName_2->setText(Name);
    ui->lineEditLastName_2->setText(LastName);
    ui->lineEditEta_3->setText(QString::number(eta));
    ui->lineEditSubject_2->setText(subject);
    ui->plainTextEditContentMessage_2->setPlainText(message);

            //std::cout << Name.toUtf8() << std::endl;
    //std::cout << LastName.toUtf8() << std::endl;
    //std::cout << eta << std::endl;
    //std::cout << subject.toUtf8() << std::endl;
    //std::cout << message.toUtf8() << std::endl;

}


void MainWindow::slotcmdUpdateParametersNewSent()
{
    try {


        LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeNew cmdUpdateParametersParamMulti;


        cmdUpdateParametersParamMulti.Eta=ui->lineEditEtaMult->text().toInt();
        cmdUpdateParametersParamMulti.Famigliari=ui->lineEditFamigliariMult->text().toInt();
        cmdUpdateParametersParamMulti.Figli=ui->lineEditFigliMult->text().toInt();
        cmdUpdateParametersParamMulti.Tel1=ui->lineEditTel1Mult->text().toInt();
        cmdUpdateParametersParamMulti.Tel2=ui->lineEditTel2Mult->text().toInt();
        cmdUpdateParametersParamMulti.Val1=ui->lineEditVal1Mult->text().toInt();
        cmdUpdateParametersParamMulti.Val2=ui->lineEditVal2Mult->text().toInt();


        messengerMulti1->cmdUpdateParametersNew(cmdUpdateParametersParamMulti);

    }
    catch(const CORBA::Exception& ex) {
        std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;
        //return 1;
    }
}


void MainWindow::on_pushButtonMessageGUI_clicked()
{

    try {


        CORBA::String_var Name = CORBA::string_alloc(81);
        CORBA::String_var LastName = CORBA::string_alloc(81);
        CORBA::Long Eta;
        CORBA::String_var subject = CORBA::string_alloc(81);
        CORBA::String_var message = CORBA::string_alloc(200);


        Name = ui->lineEditName->text().toAscii();
        LastName = ui->lineEditLastName->text().toAscii();
        Eta =  ui->lineEditEta->text().toLong();

        subject = ui->lineEditSubject->text().toAscii();

        message = ui->plainTextEditContentMessage->toPlainText().toAscii();

        messenger->send_message(Name.in(), LastName.in(), Eta, subject.in(), message.in());



    }
    catch(const CORBA::Exception& ex) {
        std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;
        //return 1;
    }


}

void MainWindow::on_pushButtonUpdateParam_clicked()
{


    try {



        LocalInterface::CompositeTypes::cmdUpdateParametersCompType cmdUpdateParametersParam;



        cmdUpdateParametersParam.PrimaryNTP_ServIP_Addr=ui->lineEditPrimaryNTP_ServIP_Addr->text().toInt();
        cmdUpdateParametersParam.SecondaryNTP_ServIP_Addr=ui->lineEditSecondaryNTP_ServIP_Addr->text().toInt();
        cmdUpdateParametersParam.TimeCorrection=ui->lineEditTimeCorrection->text().toInt();
        cmdUpdateParametersParam.NTP_Threshold=ui->lineEditNTP_Threshold->text().toInt();
        cmdUpdateParametersParam.PrivateHostAddr=ui->lineEditPrivateHostAddr->text().toInt();
        cmdUpdateParametersParam.PrivateHostMask=ui->lineEditPrivateHostMask->text().toInt();
        cmdUpdateParametersParam.PrivateHostPort=ui->lineEditPrivateHostPort->text().toInt();
        cmdUpdateParametersParam.PublicVoIP_Addr=ui->lineEditPublicVoIP_Addr->text().toInt();
        cmdUpdateParametersParam.PublicVoIP_Mask=ui->lineEditPublicVoIP_Mask->text().toInt();
        cmdUpdateParametersParam.PublicVoIP_Port=ui->lineEditPublicVoIP_Port->text().toInt();
        cmdUpdateParametersParam.PublicHostAddr=ui->lineEditPublicHostAddr->text().toInt();
        cmdUpdateParametersParam.PublicHostMask=ui->lineEditPublicHostMask->text().toInt();
        cmdUpdateParametersParam.PrivateHostAddr=ui->lineEditPrivateHostAddr->text().toInt();
        cmdUpdateParametersParam.PrivateRR_Mask=ui->lineEditPrivateRR_Mask->text().toInt();
        cmdUpdateParametersParam.PublicRR_Addr=ui->lineEditPublicRR_Addr->text().toInt();
        cmdUpdateParametersParam.PublicRR_Mask=ui->lineEditPublicRR_Mask->text().toInt();
        cmdUpdateParametersParam.PrivateRP_Addr=ui->lineEditPrivateRP_Addr->text().toInt();
        cmdUpdateParametersParam.PrivateRP_Mask=ui->lineEditPrivateRP_Mask->text().toInt();
        cmdUpdateParametersParam.PrivateRP_Port=ui->lineEditPrivateRP_Port->text().toInt();
        cmdUpdateParametersParam.PublicRP_Addr=ui->lineEditPublicRP_Addr->text().toInt();
        cmdUpdateParametersParam.PublicRP_Mask=ui->lineEditPublicRP_Mask->text().toInt();



        messenger->cmdUpdateParameters(cmdUpdateParametersParam);




    }
    catch(const CORBA::Exception& ex) {
        std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;
        //return 1;
    }

}

void MainWindow::on_pushButtonUpdateParamNEW_clicked()
{

    try {


        LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeNew cmdUpdateParametersParamNew;


        cmdUpdateParametersParamNew.Eta=ui->lineEditEta_2->text().toInt();
        cmdUpdateParametersParamNew.Famigliari=ui->lineEditFamigliari->text().toInt();
        cmdUpdateParametersParamNew.Figli=ui->lineEditFigli->text().toInt();
        cmdUpdateParametersParamNew.Tel1=ui->lineEditTel1->text().toInt();
        cmdUpdateParametersParamNew.Tel2=ui->lineEditTel2->text().toInt();
        cmdUpdateParametersParamNew.Val1=ui->lineEditVal1->text().toInt();
        cmdUpdateParametersParamNew.Val2=ui->lineEditVal2->text().toInt();




        messenger->cmdUpdateParametersNew(cmdUpdateParametersParamNew);



    }
    catch(const CORBA::Exception& ex) {
        std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;
        //return 1;
    }

}



void MainWindow::on_pushButtonUpdateParamMulticast_clicked()
{
    try {





        LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeNew cmdUpdateParametersParamMulti;




        cmdUpdateParametersParamMulti.Eta=ui->lineEditEtaMult->text().toInt();
        cmdUpdateParametersParamMulti.Famigliari=ui->lineEditFamigliariMult->text().toInt();
        cmdUpdateParametersParamMulti.Figli=ui->lineEditFigliMult->text().toInt();
        cmdUpdateParametersParamMulti.Tel1=ui->lineEditTel1Mult->text().toInt();
        cmdUpdateParametersParamMulti.Tel2=ui->lineEditTel2Mult->text().toInt();
        cmdUpdateParametersParamMulti.Val1=ui->lineEditVal1Mult->text().toInt();
        cmdUpdateParametersParamMulti.Val2=ui->lineEditVal2Mult->text().toInt();



        messengerMulti1->cmdUpdateParametersNew(cmdUpdateParametersParamMulti);






    }
    catch(const CORBA::Exception& ex) {
        std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;
        //return 1;
    }

}

void MainWindow::on_pushButtonUnicastMulticastON_clicked()
{
    try
    {

        // Initialize and error check Naming Service objects
        CORBA::Object_var NameServiceObjectVar;


        NameServiceObjectVar = MainWindow::orb->resolve_initial_references("NameService");



        if (CORBA::is_nil(NameServiceObjectVar.in()))
        {
            std::cout << "Could not initialize Naming Service" << std::endl;
            exit(1);
        }

        CosNaming::NamingContext_var NamingContextVar =
                CosNaming::NamingContext::_narrow(NameServiceObjectVar.in());
        if (CORBA::is_nil(NamingContextVar.in()))
        {
            std::cout << "Could not initialize Naming Context" << std::endl;
            exit(1);
        }


        // Obtain and error check handle to the distributed Servant
        CosNaming::Name UCastName(1);
        UCastName.length(1);
        UCastName[0].id = CORBA::string_dup("Serv1");
        CORBA::Object_var UCastTemp = NamingContextVar->resolve(UCastName);
        if (CORBA::is_nil(UCastTemp.in()))
        {
            std::cout << "Could not initialize UCastTemp" << std::endl;
            exit(1);
        }



        // Obtain and error check two multicast group handles
        CosNaming::Name MCastName1(1);
        MCastName1.length(1);
        MCastName1[0].id = CORBA::string_dup("MCAST1");
        CORBA::Object_var MCastTemp1 = NamingContextVar->resolve(MCastName1);
        if (CORBA::is_nil(MCastTemp1.in()))
        {
            std::cout << "Could not initialize MCastTemp1" << std::endl;
            exit(1);
        }



        // Narrow
        messenger = Messenger::_narrow(UCastTemp);
        if (CORBA::is_nil(messenger.in())) {
            std::cerr << "Argument is not a Messenger reference" << std::endl;
            //return 1;
        }

        // Get reference to Root POA.
        CORBA::Object_var obj = MainWindow::orb->resolve_initial_references("RootPOA");
        PortableServer::POA_var poa = PortableServer::POA::_narrow(obj.in());

        // Activate POA manager
        PortableServer::POAManager_var mgr = poa->the_POAManager();
        mgr->activate();


        messengerMulti1 = TAO::Narrow_Utils<Messenger>::unchecked_narrow (MCastTemp1.in (), _TAO_Messenger_Proxy_Broker_Factory_function_pointer);

        if (CORBA::is_nil(messengerMulti1.in())) {
              std::cerr << "Argument is not a Messenger reference" << std::endl;
              //return 1;
        }


        ui->tabwidget->setEnabled(true);
        ui->tabWidgetMulti->setEnabled(true);

        ui->lineEditEtaMult->setEnabled(true);
        ui->lineEditFamigliariMult->setEnabled(true);
        ui->lineEditFigliMult->setEnabled(true);
        ui->lineEditTel1Mult->setEnabled(true);
        ui->lineEditTel2Mult->setEnabled(true);
        ui->lineEditVal1Mult->setEnabled(true);
        ui->lineEditVal2Mult->setEnabled(true);


        ui->pushButtonUnicastMulticastON->setEnabled(false);




    }

    catch(const CORBA::Exception& ex)
    {
        std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;
        //return 1;
    }

}

void MainWindow::on_pushButtonUpdateParamMulticastLoop_clicked()
{
    try {





        LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeNew cmdUpdateParametersParamMulti;


        cmdUpdateParametersParamMulti.Eta=ui->lineEditEtaMult->text().toInt();
        cmdUpdateParametersParamMulti.Famigliari=ui->lineEditFamigliariMult->text().toInt();
        cmdUpdateParametersParamMulti.Figli=ui->lineEditFigliMult->text().toInt();
        cmdUpdateParametersParamMulti.Tel1=ui->lineEditTel1Mult->text().toInt();
        cmdUpdateParametersParamMulti.Tel2=ui->lineEditTel2Mult->text().toInt();
        cmdUpdateParametersParamMulti.Val1=ui->lineEditVal1Mult->text().toInt();
        cmdUpdateParametersParamMulti.Val2=ui->lineEditVal2Mult->text().toInt();



        for (int jj=1;jj<100;jj++) {
            messengerMulti1->cmdUpdateParametersNew(cmdUpdateParametersParamMulti);
        }






    }
    catch(const CORBA::Exception& ex) {
        std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;
        //return 1;
    }
}



void MainWindow::on_pushButtonStartUpdateParamMulticastEverySecond_clicked()
{

    cMyObjectUPMEverySec.stop = false;
    cMyObjectUPMEverySec.DoSetup(mThreadUPMEverySec);
    cMyObjectUPMEverySec.moveToThread(&mThreadUPMEverySec);
    connect(&cMyObjectUPMEverySec,SIGNAL(cmdUpdateParametersNewSent()),this,SLOT(slotcmdUpdateParametersNewSent()));
    mThreadUPMEverySec.start();


    // Started
    //mThreadUpdateParamMulticastEverySecond = new MyThreadUpdateParamMulticastEverySecond(this);
    //connect(mThreadUpdateParamMulticastEverySecond,SIGNAL(cmdUpdateParametersNewSent()),this,SLOT(slotcmdUpdateParametersNewSent()));
    //mThreadUpdateParamMulticastEverySecond->stop = false;
    //mThreadUpdateParamMulticastEverySecond->start();


    ui->pushButtonStartUpdateParamMulticastEverySecond->setEnabled(false);
    ui->pushButtonStopUpdateParamMulticastEverySecond->setEnabled(true);

}

void MainWindow::on_pushButtonStopUpdateParamMulticastEverySecond_clicked()
{
    //Stopped
    //mThreadUpdateParamMulticastEverySecond->stop = true;
    cMyObjectUPMEverySec.stop = true;
    ui->pushButtonStartUpdateParamMulticastEverySecond->setEnabled(true);
    ui->pushButtonStopUpdateParamMulticastEverySecond->setEnabled(false);

}




void MainWindow::slotMessageUpdateParametersLogicSent(cmpLogic Params)
{



    QString qStr = QString::number(CountMessage);

    QString SEta = QString::number(Params.Eta);
    QString SFamigliari = QString::number(Params.Famigliari);
    QString SFigli = QString::number(Params.Figli);
    QString STel = QString::number(Params.Tel);


    QString TotStr = "Eta:" + SEta + " Famigliari:" + SFamigliari + " Figli:" + SFigli + " Tel:" + STel;

    cmpLogic Paramsx2;

    Paramsx2.Eta = Params.Eta+2;
    Paramsx2.Famigliari = Params.Famigliari+2;
    Paramsx2.Figli = Params.Figli+2;
    Paramsx2.Tel = Params.Tel+2;

    ui->plainTextEditComunication->appendPlainText("MessageUpdateParametersLogicBack received (" + qStr +") [ " + TotStr + " ]");
    SendMessageUpdateParametersLogicPrivate(Paramsx2);


}



void MainWindow::SendMessageUpdateParametersLogicPrivate(cmpLogic Params)

try {

     if (!StopVar) {

        messenger->cmdUpdateParametersLogic(Params);
        QString qStr = QString::number(++CountMessage);

        QString SEta = QString::number(Params.Eta);
        QString SFamigliari = QString::number(Params.Famigliari);
        QString SFigli = QString::number(Params.Figli);
        QString STel = QString::number(Params.Tel);

        QString TotStr = "Eta:" + SEta + " Famigliari:" + SFamigliari + " Figli:" + SFigli + " Tel:" + STel;

        ui->plainTextEditComunication->appendPlainText("MessageUpdateParametersLogic sent (" + qStr +") [ " + TotStr + " ]");
    }


}
catch(const CORBA::Exception& ex) {
    std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;
    //return 1;
}




void MainWindow::on_pushButtonStartCom_clicked()
{

    ui->pushButtonStopCom->setEnabled(true);
    ui->pushButtonStartCom->setEnabled(false);
    StopVar=false;

    cmpLogic Params;
    Params.Eta=28;
    Params.Famigliari=3;
    Params.Figli=4;
    Params.Tel=4076;

    SendMessageUpdateParametersLogicPrivate(Params);



}

void MainWindow::on_pushButtonStopCom_clicked()
{
    ui->pushButtonStopCom->setEnabled(false);
    ui->pushButtonStartCom->setEnabled(true);

    StopVar=true;

}


void MainWindow::sleepNseconds(int NUM_SECONDS) {
    for(int i = 0 ; i < NUM_SECONDS ; i++) { usleep(1000 * 1000); }
}


void MainWindow::on_pushButtonUnicastMulticastServerON_clicked()
{
    /*
    ui->pushButtonUnicastMulticastServerON->setEnabled(false);
    MyRunnableStartServer *taskServer = new MyRunnableStartServer();
    taskServer->setAutoDelete(true);
    QThreadPool::globalInstance()->start(taskServer);

    */

    cMyObjectStartServer.stop = false;
    cMyObjectStartServer.DoSetup(mThreadStartServer);
    cMyObjectStartServer.moveToThread(&mThreadStartServer);
    //connect(&cMyObjectStartServer,SIGNAL(cmdUpdateParametersNewSent()),this,SLOT(slotcmdUpdateParametersNewSent()));
    mThreadStartServer.start();


    ui->pushButtonUnicastMulticastServerON->setEnabled(false);


}

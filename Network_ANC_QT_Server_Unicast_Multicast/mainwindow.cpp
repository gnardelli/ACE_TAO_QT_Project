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
    const char *arg1 = "-ORBListenEndpoints iiop://9.0.0.11:54321";
  //  const char *arg2 = "-ORBDottedDecimalAddresses 1";


    argv[0] = (char*)arg0;
    argv[1] = (char*)arg1;
   // argv[2] = (char*)arg2;

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
        messenger2 = Messenger2::_narrow(UCastTemp);
        if (CORBA::is_nil(messenger2.in())) {
            std::cerr << "Argument is not a Messenger reference" << std::endl;
            //return 1;
        }

        // Get reference to Root POA.
        CORBA::Object_var obj = MainWindow::orb->resolve_initial_references("RootPOA");
        PortableServer::POA_var poa = PortableServer::POA::_narrow(obj.in());

        // Activate POA manager
        PortableServer::POAManager_var mgr = poa->the_POAManager();
        mgr->activate();



        ui->tabWidgetMessage2->setEnabled(true);
        ui->pushButtonUnicastMulticastON->setEnabled(false);




    }

    catch(const CORBA::Exception& ex)
    {
        std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;
        //return 1;
    }

}




void MainWindow::send_messageSlot(QString Name,QString LastName,CORBALong eta,QString subject,QString message) {


    ui->lineEditName->setText(Name);
    ui->lineEditLastName->setText(LastName);
    ui->lineEditEta_2->setText(QString::number(eta));
    ui->lineEditSubject->setText(subject);
    ui->plainTextEditContentMessage->setPlainText(message);


}

void MainWindow::cmdUpdateParametersNewSlot(cmpNEW ParamNew) {


    ui->lineEditEta->setText(QString::number(ParamNew.Eta));
    ui->lineEditFamigliari->setText(QString::number(ParamNew.Famigliari));
    ui->lineEditFigli->setText(QString::number(ParamNew.Figli));
    ui->lineEditTel->setText(QString::number(ParamNew.Tel1));
    ui->lineEditTel2->setText(QString::number(ParamNew.Tel2));
    ui->lineEditVal1->setText(QString::number(ParamNew.Val1));
    ui->lineEditVal2->setText(QString::number(ParamNew.Val2));

    ui->lineEditEtaMult->setText(QString::number(ParamNew.Eta));
    ui->lineEditFamigliariMult->setText(QString::number(ParamNew.Famigliari));
    ui->lineEditFigliMult->setText(QString::number(ParamNew.Figli));
    ui->lineEditTelMult->setText(QString::number(ParamNew.Tel1));
    ui->lineEditTel2Mult->setText(QString::number(ParamNew.Tel2));
    ui->lineEditVal1Mult->setText(QString::number(ParamNew.Val1));
    ui->lineEditVal2Mult->setText(QString::number(ParamNew.Val2));


}


void MainWindow::cmdUpdateParametersSlot(cmp Param) {


    ui->lineEditPrimaryNTP_ServIP_Addr->setText(QString::number(Param.PrimaryNTP_ServIP_Addr));
    ui->lineEditSecondaryNTP_ServIP_Addr->setText(QString::number(Param.SecondaryNTP_ServIP_Addr));
    ui->lineEditTimeCorrection->setText(QString::number(Param.TimeCorrection));
    ui->lineEditNTP_Threshold->setText(QString::number(Param.NTP_Threshold));

    ui->lineEditPrivateHostAddr->setText(QString::number(Param.PrivateHostAddr));

    ui->lineEditPrivateHostMask->setText(QString::number(Param.PrivateHostMask));
    ui->lineEditPrivateHostPort->setText(QString::number(Param.PrivateHostPort));

    ui->lineEditPublicHostAddr->setText(QString::number(Param.PublicHostAddr));
    ui->lineEditPublicHostMask->setText(QString::number(Param.PublicHostMask));
    ui->lineEditPrivateRP_Addr->setText(QString::number(Param.PrivateRP_Addr));
    ui->lineEditPrivateRP_Port->setText(QString::number(Param.PrivateRP_Port));

    ui->lineEditPrivateRR_Mask->setText(QString::number(Param.PrivateRR_Mask));
    ui->lineEditPublicRR_Addr->setText(QString::number(Param.PublicRR_Addr));
    ui->lineEditPublicRR_Mask->setText(QString::number(Param.PublicRR_Mask));
    ui->lineEditPublicRP_Addr->setText(QString::number(Param.PublicRP_Addr));
    ui->lineEditPublicRP_Mask->setText(QString::number(Param.PublicRP_Mask));
    ui->lineEditPrivateRP_Addr->setText(QString::number(Param.PrivateRP_Addr));
    ui->lineEditPrivateRP_Mask->setText(QString::number(Param.PrivateRP_Mask));

    ui->lineEditPublicVoIP_Addr->setText(QString::number(Param.PublicVoIP_Addr));
    ui->lineEditPublicVoIP_Mask->setText(QString::number(Param.PublicVoIP_Mask));
    ui->lineEditPublicVoIP_Port->setText(QString::number(Param.PublicVoIP_Port));

}





void MainWindow::slotMessageUpdateParametersLogicBackSent(cmpLogic Params)
{



    QString qStr = QString::number(++CountMessage);


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

    ui->plainTextEditComunication->appendPlainText("MessageUpdateParametersLogic received (" + qStr +") [ " + TotStr + " ]");
    SendMessageUpdateParametersLogicPrivate(Paramsx2);

}




void MainWindow::on_pushButton_clicked()
{
    try {


        CORBA::String_var Name = CORBA::string_alloc(81);
        CORBA::String_var LastName = CORBA::string_alloc(81);
        CORBA::Long Eta;
        CORBA::String_var subject = CORBA::string_alloc(81);
        CORBA::String_var message = CORBA::string_alloc(200);


        Name = ui->lineEditName_2->text().toAscii();
        LastName = ui->lineEditLastName_2->text().toAscii();
        Eta =  ui->lineEditEta_3->text().toLong();

        subject = ui->lineEditSubject_2->text().toAscii();

        message = ui->plainTextEditContentMessage_2->toPlainText().toAscii();


        messenger2->send_message2(Name.in(), LastName.in(), Eta, subject.in(), message.in());




    }
    catch(const CORBA::Exception& ex) {
        std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;
        //return 1;
    }

}



void MainWindow::SendMessageUpdateParametersLogicPrivate(cmpLogic Params) {


        try {



            messenger2->cmdUpdateParametersLogicBack(Params);
            QString qStr = QString::number(CountMessage);

            QString SEta = QString::number(Params.Eta);
            QString SFamigliari = QString::number(Params.Famigliari);
            QString SFigli = QString::number(Params.Figli);
            QString STel = QString::number(Params.Tel);

            QString TotStr = "Eta:" + SEta + " Famigliari:" + SFamigliari + " Figli:" + SFigli + " Tel:" + STel;


            ui->plainTextEditComunication->appendPlainText("MessageUpdateParametersLogicBack sent (" + qStr +") [ " + TotStr + " ]");


        }
        catch(const CORBA::Exception& ex) {
            std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;
            //return 1;
        }

}


void MainWindow::sleepNseconds(int NUM_SECONDS) {
    for(int i = 0 ; i < NUM_SECONDS ; i++) { usleep(1000 * 1000); }
}



void MainWindow::on_pushButtonUnicastMulticastServerON_clicked()
{
    ui->pushButtonUnicastMulticastServerON->setEnabled(false);

    /*

    MyRunnableStartServer *taskServer = new MyRunnableStartServer();
    taskServer->setAutoDelete(true);
    QThreadPool::globalInstance()->start(taskServer);

    */



    cMyObjectStartServer.stop = false;
    cMyObjectStartServer.DoSetup(mThreadStartServer);
    cMyObjectStartServer.moveToThread(&mThreadStartServer);
    //connect(&cMyObjectStartServer,SIGNAL(cmdUpdateParametersNewSent()),this,SLOT(slotcmdUpdateParametersNewSent()));
    mThreadStartServer.start();


}

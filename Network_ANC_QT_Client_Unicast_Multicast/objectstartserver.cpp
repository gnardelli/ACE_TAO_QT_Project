#include "objectstartserver.h"
#include <QtCore>


#include "mainwindow.h"
#include "ui_mainwindow.h"


// $Id$

#include "Messenger2_i.h"
#include <fstream>
#include <iostream>
#include <string>


#include "ace/Get_Opt.h"
#include "ace/OS_NS_stdio.h"
#include <orbsvcs/CosNamingC.h>
#include <orbsvcs/PortableGroup/MIOP.h>
#include <orbsvcs/PortableGroup/GOA.h>
#include <tao/ORB.h>
#include <ace/String_Base.h>
#include <tao/PortableServer/PortableServerC.h>



ObjectStartServer::ObjectStartServer(QObject *parent) :
    QObject(parent)
{
}



void ObjectStartServer::DoSetup(QThread &cThread)
{
    connect(&cThread,SIGNAL(started()),this,SLOT(DoWork()));
}

void ObjectStartServer::DoWork()
{


    try {



    // Initialize and error check POA objects (Root POA, POA Manager)
    CORBA::Object_var poa_object = MainWindow::orb->resolve_initial_references("RootPOA");
    if (CORBA::is_nil(poa_object.in()))
    {
        std::cout << "Could not initialize POA Object" << std::endl;
        exit(1);
    }


    /*

    PortableServer::POA_var root_poa = PortableServer::POA::_narrow(poa_object.in());
    if (CORBA::is_nil(root_poa.in()))
    {
        std::cout << "Could not initialize POA" << std::endl;
        exit(1);
    }

    */


    PortableGroup::GOA_var root_poa = PortableGroup::GOA::_narrow(poa_object.in ());
    if (CORBA::is_nil(root_poa.in()))
    {
        std::cout << "Could not initialize Root POA" << std::endl;
        exit(1);
    }




    PortableServer::POAManager_var poa_manager = root_poa->the_POAManager ();
    if (CORBA::is_nil(poa_manager.in()))
    {
        std::cout << "Could not initialize POA Manager" << std::endl;
        exit(1);
    }



    CORBA::Object_var NameServiceObjectVar = MainWindow::orb->resolve_initial_references("NameService");
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



    // Obtain multiple Group corbalocs from file
    //std::ifstream corbaLocFile1("group1.ior");
    //std::string groupCorbaloc1;
    //corbaLocFile1 >> groupCorbaloc1;

    //std::ifstream corbaLocFile2("group2.ior");
    //std::string groupCorbaloc2;
    //corbaLocFile2 >> groupCorbaloc2;

    // Convert Group corbaloc into Object_var, then ObjectId_var


    //CORBA::Object_var McastTemp1 = orb->string_to_object(groupCorbaloc1.c_str());
    //CORBA::Object_var McastTemp2 = orb->string_to_object(groupCorbaloc2.c_str());



    //PortableServer::ObjectId_var id1 =  root_poa->create_id_for_reference (McastTemp1.in ());

    //PortableServer::ObjectId_var id2 = root_poa->create_id_for_reference (McastTemp2.in ());

    // Create and activate an instance of our servant.



    //MainWindow::
/*

    Messenger2_i server_impl (void);

    root_poa->activate_object_with_id (id1.in (), &server_impl);

    //root_poa->activate_object_with_id (id2.in (), &server_impl);


    CosNaming::Name MCastName1(1);
    MCastName1.length(1);
    MCastName1[0].id = CORBA::string_dup("MCAST1");
    NamingContextVar->rebind(MCastName1, McastTemp1.in());



*/

    PortableServer::Servant_var<Messenger2_i> servant = new Messenger2_i();

    // Write its stringified reference to stdout
    PortableServer::ObjectId_var oid =  root_poa->activate_object(servant.in());

    poa_object = root_poa->id_to_reference(oid.in());


    CosNaming::Name UCastName(1);
    UCastName.length(1);
    UCastName[0].id = CORBA::string_dup("Serv1");

    Messenger2_var messenger2 = Messenger2::_narrow(poa_object.in());
    NamingContextVar->rebind(UCastName, messenger2.in());


    // Activate POA, run ORB (Servant now listening for incoming requests)



    //CosNaming::Name MCastName2(1);
    //MCastName2.length(1);
    //MCastName2[0].id = CORBA::string_dup("MCAST2");
    //NamingContextVar->rebind(MCastName2, McastTemp2.in());



    poa_manager->activate ();
    MainWindow::orb->run ();
    root_poa->destroy (1, 1);

    MainWindow::orb->destroy ();



    }
    catch(const CORBA::Exception& ex) {
      std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;

    }


}


void ObjectStartServer::destroyORB(){

    MainWindow::orb->destroy ();

}


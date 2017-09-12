#include "myrunnablestartserver.h"

MyRunnableStartServer::MyRunnableStartServer()
{
}


void MyRunnableStartServer::run()
{


    try {



    // Initialize and error check POA objects (Root POA, POA Manager)
    CORBA::Object_var poa_object;

    poa_object = MainWindow::orb->resolve_initial_references("RootPOA");


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
    std::ifstream corbaLocFile1("group1.ior");
    std::string groupCorbaloc1;
    corbaLocFile1 >> groupCorbaloc1;

    //std::ifstream corbaLocFile2("group2.ior");
    //std::string groupCorbaloc2;
    //corbaLocFile2 >> groupCorbaloc2;

    // Convert Group corbaloc into Object_var, then ObjectId_var







    CORBA::Object_var McastTemp1 = MainWindow::orb->string_to_object(groupCorbaloc1.c_str());
    //CORBA::Object_var McastTemp2 = orb->string_to_object(groupCorbaloc2.c_str());


    PortableServer::ObjectId_var id1 =  root_poa->create_id_for_reference (McastTemp1.in ());

    //PortableServer::ObjectId_var id2 = root_poa->create_id_for_reference (McastTemp2.in ());



    // Create and activate an instance of our servant.
    Messenger_i server_impl (MainWindow::orb.in(),0);


    //MainWindow::

    root_poa->activate_object_with_id (id1.in (), &server_impl);

    //root_poa->activate_object_with_id (id2.in (), &server_impl);


    CosNaming::Name MCastName1(1);
    MCastName1.length(1);
    MCastName1[0].id = CORBA::string_dup("MCAST1");
    NamingContextVar->rebind(MCastName1, McastTemp1.in());




    PortableServer::Servant_var<Messenger_i> servant = new Messenger_i(MainWindow::orb.in(),0);





    // Write its stringified reference to stdout
    PortableServer::ObjectId_var oid =  root_poa->activate_object(servant.in());
    poa_object = root_poa->id_to_reference(oid.in());


    CosNaming::Name UCastName(1);
    UCastName.length(1);
    UCastName[0].id = CORBA::string_dup("Serv1");

    Messenger_var messenger = Messenger::_narrow(poa_object.in());
    NamingContextVar->rebind(UCastName, messenger.in());


    // Activate POA, run ORB (Servant now listening for incoming requests)



    //CosNaming::Name MCastName2(1);
    //MCastName2.length(1);
    //MCastName2[0].id = CORBA::string_dup("MCAST2");
    //NamingContextVar->rebind(MCastName2, McastTemp2.in());



    poa_manager->activate ();
    MainWindow::orb->run ();
    root_poa->destroy (1, 1);


    }
    catch(const CORBA::Exception& ex) {
      std::cerr << "Caught a CORBA::Exception: " << ex << std::endl;

    }

}


void MyRunnableStartServer::sleepNseconds(int NUM_SECONDS) {
    for(int i = 0 ; i < NUM_SECONDS ; i++) { usleep(1000 * 1000); }
}



void MyRunnableStartServer::destroyORB(){

    MainWindow::orb->destroy ();

}

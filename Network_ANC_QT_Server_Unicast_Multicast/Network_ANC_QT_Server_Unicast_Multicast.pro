#-------------------------------------------------
#
# Project created by QtCreator 2012-12-26T17:30:28
#
#-------------------------------------------------

QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Network_ANC_QT_Server_Unicast_Multicast

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += /opt/ACE_wrappers\
               /opt/ACE_wrappers/TAO\
               /opt/ACE_wrappers/TAO/orbsvcs

LIBS += -L/opt/ACE_wrappers/lib\
        -lTAO_CosNaming\
        -lTAO_Messaging\
        -lTAO_PI\
        -lTAO_CodecFactory\
        -lTAO_PortableServer\
        -lTAO_PortableGroup\
        -lTAO_CosEvent\
        -lTAO_CosEvent_Skel\
        -lTAO_Valuetype\
        -lTAO_AnyTypeCode\
        -lTAO\
        -lACE



SOURCES += mainwindow.cpp Messenger_i.cpp\
    MessengerServer.cpp \
    corba_file/MessengerS.cpp \
    corba_file/MessengerC.cpp \
    corba_file/MessengerC.inl \
    corba_file/MessengerS.inl \
    corba_file/Messenger2S.inl \
    corba_file/Messenger2S.cpp \
    corba_file/Messenger2C.inl \
    corba_file/Messenger2C.cpp \
    corba_file/typedefMessageS.inl \
    corba_file/typedefMessageC.inl \
    corba_file/typedefMessageC.cpp \
    corba_file/typedefMessageS.cpp \
    myrunnablemessagelogicsentback.cpp \
    myrunnablestartserver.cpp \
    objectstartserver.cpp


HEADERS  += mainwindow.h Messenger_i.h \
    corba_file/MessengerS.h \
    corba_file/MessengerC.h \
    corba_file/Messenger2S.h \
    corba_file/Messenger2C.h \
    corba_file/typedefMessageC.h \
    corba_file/typedefMessageS.h \
    myrunnablemessagelogicsentback.h \
    myrunnablestartserver.h \
    objectstartserver.h

FORMS    += mainwindow.ui


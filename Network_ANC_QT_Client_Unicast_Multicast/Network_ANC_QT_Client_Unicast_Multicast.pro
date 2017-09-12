#-------------------------------------------------
#
# Project created by QtCreator 2012-12-20T11:59:49
#
#-------------------------------------------------

QT       += core

QT       += gui

TARGET = Network_ANC_QT_Client_Unicast_Multicast
CONFIG   += console
CONFIG   -= app_bundle

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
        -lTAO_Valuetype\
        -lTAO_AnyTypeCode\
        -lTAO\
        -lACE

TEMPLATE = app


# Input
HEADERS += \
    mainwindow.h \
    myobjectupmeverysec.h \
    Messenger2_i.h \
    corba_file/Messenger2C.h \
    corba_file/MessengerC.h \
    corba_file/typedefMessageS.h \
    corba_file/typedefMessageC.h \
    corba_file/Messenger2S.h \
    corba_file/MessengerS.h \
    myrunnablemessagelogicsent.h \
    myrunnablestartserver.h \
    objectstartserver.h

SOURCES += MessengerClient.cpp \
    mainwindow.cpp \
    myobjectupmeverysec.cpp \
    Messenger2_i.cpp \
    corba_file/Messenger2C.cpp \
    corba_file/Messenger2C.inl \
    corba_file/MessengerC.cpp \
    corba_file/typedefMessageS.inl \
    corba_file/typedefMessageC.inl \
    corba_file/typedefMessageC.cpp \
    corba_file/typedefMessageS.cpp \
    corba_file/MessengerC.inl \
    corba_file/Messenger2S.cpp \
    corba_file/Messenger2S.inl \
    corba_file/MessengerS.inl \
    corba_file/MessengerS.cpp \
    myrunnablemessagelogicsent.cpp \
    myrunnablestartserver.cpp \
    objectstartserver.cpp

FORMS += \
    mainwindow.ui

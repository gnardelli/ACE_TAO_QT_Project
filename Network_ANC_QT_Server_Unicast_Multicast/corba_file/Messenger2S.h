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
// be/be_codegen.cpp:460

#ifndef _TAO_IDL_MESSENGER2S_1DE1J0_H_
#define _TAO_IDL_MESSENGER2S_1DE1J0_H_


#include "Messenger2C.h"
#include "typedefMessageS.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/get_arg.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Messaging/MessagingS.h"
#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:68

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:308

#if !defined (_MESSAGING_EXCEPTIONHOLDER__SARG_TRAITS_)
#define _MESSAGING_EXCEPTIONHOLDER__SARG_TRAITS_

  template<>
  class SArg_Traits< ::Messaging::ExceptionHolder>
    : public
        Object_SArg_Traits_T<
            ::Messaging::ExceptionHolder *,
            ::Messaging::ExceptionHolder_var,
            ::Messaging::ExceptionHolder_out,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:147

#if !defined (_MESSENGER2__SARG_TRAITS_)
#define _MESSENGER2__SARG_TRAITS_

  template<>
  class  SArg_Traits< ::Messenger2>
    : public
        Object_SArg_Traits_T<
            ::Messenger2_ptr,
            ::Messenger2_var,
            ::Messenger2_out,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:147

#if !defined (_AMI_MESSENGER2HANDLER__SARG_TRAITS_)
#define _AMI_MESSENGER2HANDLER__SARG_TRAITS_

  template<>
  class  SArg_Traits< ::AMI_Messenger2Handler>
    : public
        Object_SArg_Traits_T<
            ::AMI_Messenger2Handler_ptr,
            ::AMI_Messenger2Handler_var,
            ::AMI_Messenger2Handler_out,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/interface_sh.cpp:78

class POA_Messenger2;
typedef POA_Messenger2 *POA_Messenger2_ptr;

class  POA_Messenger2
  : public virtual PortableServer::ServantBase
{
protected:
  POA_Messenger2 (void);

public:
  /// Useful for template programming.
  typedef ::Messenger2 _stub_type;
  typedef ::Messenger2_ptr _stub_ptr_type;
  typedef ::Messenger2_var _stub_var_type;

  POA_Messenger2 (const POA_Messenger2& rhs);
  virtual ~POA_Messenger2 (void);

  virtual ::CORBA::Boolean _is_a (const char* logical_type_id);

  static void _is_a_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant);
  
  static void _non_existent_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant);
  
  static void _interface_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant);
  
  static void _component_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant);
  
  static void _repository_id_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant);
  
  virtual void _dispatch (
      TAO_ServerRequest & req,
      void * servant_upcall);
  
  ::Messenger2 *_this (void);
  
  virtual const char* _interface_repository_id (void) const;

  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_sh.cpp:41

  virtual ::CORBA::Boolean send_message2 (
    const char * Name,
    const char * LastName,
    ::CORBA::Long eta,
    const char * subject,
    const char * message) = 0;

  static void send_message2_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant);

  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_sh.cpp:41

  virtual void cmdUpdateParametersLogicBack (
    const ::LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeLogic & cmdUpdateParametersParamLogic) = 0;

  static void cmdUpdateParametersLogicBack_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant);
};

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_sh.cpp:78

class POA_AMI_Messenger2Handler;
typedef POA_AMI_Messenger2Handler *POA_AMI_Messenger2Handler_ptr;

class  POA_AMI_Messenger2Handler
  : public virtual POA_Messaging::ReplyHandler
{
protected:
  POA_AMI_Messenger2Handler (void);

public:
  /// Useful for template programming.
  typedef ::AMI_Messenger2Handler _stub_type;
  typedef ::AMI_Messenger2Handler_ptr _stub_ptr_type;
  typedef ::AMI_Messenger2Handler_var _stub_var_type;

  POA_AMI_Messenger2Handler (const POA_AMI_Messenger2Handler& rhs);
  virtual ~POA_AMI_Messenger2Handler (void);

  virtual ::CORBA::Boolean _is_a (const char* logical_type_id);

  static void _is_a_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant);
  
  static void _non_existent_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant);
  
  static void _interface_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant);
  
  static void _component_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant);
  
  static void _repository_id_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant);
  
  virtual void _dispatch (
      TAO_ServerRequest & req,
      void * servant_upcall);
  
  ::AMI_Messenger2Handler *_this (void);
  
  virtual const char* _interface_repository_id (void) const;

  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_sh.cpp:41

  virtual void send_message2 (
    ::CORBA::Boolean ami_return_val) = 0;

  static void send_message2_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant);

  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_sh.cpp:41

  virtual void send_message2_excep (
    ::Messaging::ExceptionHolder * excep_holder) = 0;

  static void send_message2_excep_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant);
};
#if defined (__ACE_INLINE__)
#include "Messenger2S.inl"
#endif /* defined INLINE */

#endif /* ifndef */


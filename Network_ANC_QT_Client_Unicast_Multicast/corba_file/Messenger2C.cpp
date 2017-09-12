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
// be/be_codegen.cpp:375


#include "Messenger2C.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/AnyTypeCode/Value_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Value_Field.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Messaging/Asynch_Invocation_Adapter.h"
#include "tao/Messaging/ExceptionHolder_i.h"
#include "tao/Valuetype/ValueFactory.h"
#include "tao/Object_T.h"
#include "tao/SystemException.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "Messenger2C.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from 
// be/be_visitor_exception/exception_cs.cpp:101

MessengerUnableToSendMessage2::MessengerUnableToSendMessage2 (void)
  : ::CORBA::UserException (
        "IDL:MessengerUnableToSendMessage2:1.0",
        "MessengerUnableToSendMessage2"
      )
{
}

MessengerUnableToSendMessage2::~MessengerUnableToSendMessage2 (void)
{
}

MessengerUnableToSendMessage2::MessengerUnableToSendMessage2 (const ::MessengerUnableToSendMessage2 &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

MessengerUnableToSendMessage2&
MessengerUnableToSendMessage2::operator= (const ::MessengerUnableToSendMessage2 &_tao_excp)
{
  this->::CORBA::UserException::operator= (_tao_excp);
  return *this;
}

void MessengerUnableToSendMessage2::_tao_any_destructor (void *_tao_void_pointer)
{
  MessengerUnableToSendMessage2 *_tao_tmp_pointer =
    static_cast<MessengerUnableToSendMessage2 *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

MessengerUnableToSendMessage2 *
MessengerUnableToSendMessage2::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<MessengerUnableToSendMessage2 *> (_tao_excp);
}

const MessengerUnableToSendMessage2 *
MessengerUnableToSendMessage2::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const MessengerUnableToSendMessage2 *> (_tao_excp);
}

::CORBA::Exception *MessengerUnableToSendMessage2::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::MessengerUnableToSendMessage2, 0);
  return retval;
}

::CORBA::Exception *
MessengerUnableToSendMessage2::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::MessengerUnableToSendMessage2 (*this),
      0
    );
  return result;
}

void MessengerUnableToSendMessage2::_raise (void) const
{
  throw *this;
}

void MessengerUnableToSendMessage2::_tao_encode (TAO_OutputCDR &cdr) const
{
  if (!(cdr << *this))
    {
      throw ::CORBA::MARSHAL ();
    }
}

void MessengerUnableToSendMessage2::_tao_decode (TAO_InputCDR &cdr)
{
  if (!(cdr >> *this))
    {
      throw ::CORBA::MARSHAL ();
    }
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr MessengerUnableToSendMessage2::_tao_type (void) const
{
  return ::_tc_MessengerUnableToSendMessage2;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:86

static TAO::TypeCode::Struct_Field<
  char const *,
  ::CORBA::TypeCode_ptr const *> const * const 
    _tao_fields_MessengerUnableToSendMessage2 = 0;
  
static TAO::TypeCode::Struct<
  char const *,
  ::CORBA::TypeCode_ptr const *,
  TAO::TypeCode::Struct_Field<
    char const *,
    ::CORBA::TypeCode_ptr const *> const *,
  TAO::Null_RefCount_Policy>
_tao_tc_MessengerUnableToSendMessage2 (
  ::CORBA::tk_except,
  "IDL:MessengerUnableToSendMessage2:1.0",
  "MessengerUnableToSendMessage2",
  _tao_fields_MessengerUnableToSendMessage2,
  0);

::CORBA::TypeCode_ptr const _tc_MessengerUnableToSendMessage2 =
  &_tao_tc_MessengerUnableToSendMessage2;

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:53

// Traits specializations for Messenger2.

Messenger2_ptr
TAO::Objref_Traits<Messenger2>::duplicate (
    Messenger2_ptr p)
{
  return Messenger2::_duplicate (p);
}

void
TAO::Objref_Traits<Messenger2>::release (
    Messenger2_ptr p)
{
  ::CORBA::release (p);
}

Messenger2_ptr
TAO::Objref_Traits<Messenger2>::nil (void)
{
  return Messenger2::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messenger2>::marshal (
    const Messenger2_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*_TAO_Messenger2_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj) = 0;

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:80

::CORBA::Boolean
Messenger2::send_message2 (
  const char * Name,
  const char * LastName,
  ::CORBA::Long eta,
  const char * subject,
  const char * message)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Messenger2_Proxy_Broker_ == 0)
    {
      Messenger2_setup_collocation ();
    }
  
  TAO::Arg_Traits< ::ACE_InputCDR::to_boolean>::ret_val _tao_retval;
  TAO::Arg_Traits< char *>::in_arg_val _tao_Name (Name);
  TAO::Arg_Traits< char *>::in_arg_val _tao_LastName (LastName);
  TAO::Arg_Traits< ::CORBA::Long>::in_arg_val _tao_eta (eta);
  TAO::Arg_Traits< char *>::in_arg_val _tao_subject (subject);
  TAO::Arg_Traits< char *>::in_arg_val _tao_message (message);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_Name,
      &_tao_LastName,
      &_tao_eta,
      &_tao_subject,
      &_tao_message
    };

  static TAO::Exception_Data
  _tao_Messenger2_send_message2_exceptiondata [] = 
    {
      {
        "IDL:MessengerUnableToSendMessage2:1.0",
        MessengerUnableToSendMessage2::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , _tc_MessengerUnableToSendMessage2
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      6,
      "send_message2",
      13,
      this->the_TAO_Messenger2_Proxy_Broker_
    );

  _tao_call.invoke (
      _tao_Messenger2_send_message2_exceptiondata,
      1
    );

  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:80

void
Messenger2::cmdUpdateParametersLogicBack (
  const ::LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeLogic & cmdUpdateParametersParamLogic)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Messenger2_Proxy_Broker_ == 0)
    {
      Messenger2_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::LocalInterface::CompositeTypes::cmdUpdateParametersCompTypeLogic>::in_arg_val _tao_cmdUpdateParametersParamLogic (cmdUpdateParametersParamLogic);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_cmdUpdateParametersParamLogic
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "cmdUpdateParametersLogicBack",
      28,
      this->the_TAO_Messenger2_Proxy_Broker_,
      TAO::TAO_ONEWAY_INVOCATION
    );

  _tao_call.invoke (0, 0);
}

// TAO_IDL - Generated from
// be/be_visitor_operation/ami_cs.cpp:61

void
Messenger2::sendc_send_message2 (
  ::AMI_Messenger2Handler_ptr ami_handler,
  const char * Name,
  const char * LastName,
  ::CORBA::Long eta,
  const char * subject,
  const char * message)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Messenger2_Proxy_Broker_ == 0)
    {
      Messenger2_setup_collocation ();
    }
  
  TAO::Arg_Traits<void>::ret_val _tao_retval;
  TAO::Arg_Traits< char *>::in_arg_val _tao_Name (Name);
  TAO::Arg_Traits< char *>::in_arg_val _tao_LastName (LastName);
  TAO::Arg_Traits< ::CORBA::Long>::in_arg_val _tao_eta (eta);
  TAO::Arg_Traits< char *>::in_arg_val _tao_subject (subject);
  TAO::Arg_Traits< char *>::in_arg_val _tao_message (message);

  TAO::Argument *_the_tao_operation_signature[] =
    {
      &_tao_retval,
      &_tao_Name,
      &_tao_LastName,
      &_tao_eta,
      &_tao_subject,
      &_tao_message
    };

  TAO::Asynch_Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      6,
      "send_message2",
      13,
      this->the_TAO_Messenger2_Proxy_Broker_
    );

  _tao_call.invoke (
      ami_handler,
      &AMI_Messenger2Handler::send_message2_reply_stub
    );
}

Messenger2::Messenger2 (void)
 : the_TAO_Messenger2_Proxy_Broker_ (0)
{
  this->Messenger2_setup_collocation ();
}

void
Messenger2::Messenger2_setup_collocation ()
{
  if (::_TAO_Messenger2_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_Messenger2_Proxy_Broker_ =
        ::_TAO_Messenger2_Proxy_Broker_Factory_function_pointer (this);
    }
}

Messenger2::~Messenger2 (void)
{}

void 
Messenger2::_tao_any_destructor (void *_tao_void_pointer)
{
  Messenger2 *_tao_tmp_pointer =
    static_cast<Messenger2 *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

Messenger2_ptr
Messenger2::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<Messenger2>::narrow (
        _tao_objref,
        "IDL:Messenger2:1.0",
        _TAO_Messenger2_Proxy_Broker_Factory_function_pointer
      );
}

Messenger2_ptr
Messenger2::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<Messenger2>::unchecked_narrow (
        _tao_objref,
        "IDL:Messenger2:1.0",
        _TAO_Messenger2_Proxy_Broker_Factory_function_pointer
      );
}

Messenger2_ptr
Messenger2::_nil (void)
{
  return 0;
}

Messenger2_ptr
Messenger2::_duplicate (Messenger2_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messenger2::_tao_release (Messenger2_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
Messenger2::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:Messenger2:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        ) == 0
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->::CORBA::Object::_is_a (value);
    }
}

const char* Messenger2::_interface_repository_id (void) const
{
  return "IDL:Messenger2:1.0";
}

::CORBA::Boolean
Messenger2::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:70

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_Messenger2 (
    ::CORBA::tk_objref,
    "IDL:Messenger2:1.0",
    "Messenger2");
  
::CORBA::TypeCode_ptr const _tc_Messenger2 =
  &_tao_tc_Messenger2;

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:53

// Traits specializations for AMI_Messenger2Handler.

AMI_Messenger2Handler_ptr
TAO::Objref_Traits<AMI_Messenger2Handler>::duplicate (
    AMI_Messenger2Handler_ptr p)
{
  return AMI_Messenger2Handler::_duplicate (p);
}

void
TAO::Objref_Traits<AMI_Messenger2Handler>::release (
    AMI_Messenger2Handler_ptr p)
{
  ::CORBA::release (p);
}

AMI_Messenger2Handler_ptr
TAO::Objref_Traits<AMI_Messenger2Handler>::nil (void)
{
  return AMI_Messenger2Handler::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<AMI_Messenger2Handler>::marshal (
    const AMI_Messenger2Handler_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*_TAO_AMI_Messenger2Handler_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj) = 0;

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:80

void
AMI_Messenger2Handler::send_message2 (
  ::CORBA::Boolean ami_return_val)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_AMI_Messenger2Handler_Proxy_Broker_ == 0)
    {
      AMI_Messenger2Handler_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::ACE_InputCDR::to_boolean>::in_arg_val _tao_ami_return_val (ami_return_val);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_ami_return_val
    };

  static TAO::Exception_Data
  _tao_AMI_Messenger2Handler_send_message2_exceptiondata [] = 
    {
      {
        "IDL:MessengerUnableToSendMessage2:1.0",
        MessengerUnableToSendMessage2::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , _tc_MessengerUnableToSendMessage2
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "send_message2",
      13,
      this->the_TAO_AMI_Messenger2Handler_Proxy_Broker_
    );

  _tao_call.invoke (
      _tao_AMI_Messenger2Handler_send_message2_exceptiondata,
      1
    );
}

void
AMI_Messenger2Handler::send_message2_reply_stub (
  TAO_InputCDR &_tao_in, 
  ::Messaging::ReplyHandler_ptr _tao_reply_handler,
  ::CORBA::ULong reply_status)
{
  // Retrieve Reply Handler object.
  AMI_Messenger2Handler_var _tao_reply_handler_object =
    AMI_Messenger2Handler::_narrow (_tao_reply_handler);

  // Exception handling
  switch (reply_status)
  {
    case TAO_AMI_REPLY_OK:
    {

      ::CORBA::Boolean ami_return_val;      // Demarshall all the arguments.
      if (!(

            (_tao_in >> ::ACE_InputCDR::to_boolean (ami_return_val))
         ))
        throw ::CORBA::MARSHAL ();
      
      // Invoke the call back method.
      _tao_reply_handler_object->send_message2 (
          
          ami_return_val
        );
      break;
    }
    case TAO_AMI_REPLY_USER_EXCEPTION:
    case TAO_AMI_REPLY_SYSTEM_EXCEPTION:
    {
      const ACE_Message_Block* cdr = _tao_in.start ();
      
      static TAO::Exception_Data exceptions_data [] = 
      {
        {
          "IDL:MessengerUnableToSendMessage2:1.0",
          MessengerUnableToSendMessage2::_alloc
#if TAO_HAS_INTERCEPTORS == 1
          , _tc_MessengerUnableToSendMessage2
#endif /* TAO_HAS_INTERCEPTORS */
        }
      };

      ::CORBA::ULong const exceptions_count = 1;

      ::CORBA::OctetSeq _tao_marshaled_exception (
          static_cast <CORBA::ULong> (cdr->length ()),
          static_cast <CORBA::ULong> (cdr->length ()),
          reinterpret_cast <unsigned char*> (cdr->rd_ptr ()),
          0
        );
      ::Messaging::ExceptionHolder* exception_holder_ptr = 0;
      ACE_NEW (
          exception_holder_ptr,
          ::TAO::ExceptionHolder (
            (reply_status == TAO_AMI_REPLY_SYSTEM_EXCEPTION),
            _tao_in.byte_order (),
            _tao_marshaled_exception,
            exceptions_data,
            exceptions_count,
            _tao_in.char_translator (),
            _tao_in.wchar_translator ())
          );
        
      ::Messaging::ExceptionHolder_var exception_holder_var = exception_holder_ptr;
      _tao_reply_handler_object->send_message2_excep (
          exception_holder_var
        );
      break;
    }
    case TAO_AMI_REPLY_NOT_OK:
      // @@ Michael: Not even the spec mentions this case.
      //             We have to think about this case.
      break;
  }
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:80

void
AMI_Messenger2Handler::send_message2_excep (
  ::Messaging::ExceptionHolder * excep_holder)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_AMI_Messenger2Handler_Proxy_Broker_ == 0)
    {
      AMI_Messenger2Handler_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::Messaging::ExceptionHolder>::in_arg_val _tao_excep_holder (excep_holder);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_excep_holder
    };

  static TAO::Exception_Data
  _tao_AMI_Messenger2Handler_send_message2_excep_exceptiondata [] = 
    {
      {
        "IDL:MessengerUnableToSendMessage2:1.0",
        MessengerUnableToSendMessage2::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , _tc_MessengerUnableToSendMessage2
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "send_message2_excep",
      19,
      this->the_TAO_AMI_Messenger2Handler_Proxy_Broker_
    );

  _tao_call.invoke (
      _tao_AMI_Messenger2Handler_send_message2_excep_exceptiondata,
      1
    );
}

AMI_Messenger2Handler::AMI_Messenger2Handler (void)
 : the_TAO_AMI_Messenger2Handler_Proxy_Broker_ (0)
{
  this->AMI_Messenger2Handler_setup_collocation ();
}

void
AMI_Messenger2Handler::AMI_Messenger2Handler_setup_collocation ()
{
  if (::_TAO_AMI_Messenger2Handler_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_AMI_Messenger2Handler_Proxy_Broker_ =
        ::_TAO_AMI_Messenger2Handler_Proxy_Broker_Factory_function_pointer (this);
    }
  
  this->Messaging_ReplyHandler_setup_collocation ();
}

AMI_Messenger2Handler::~AMI_Messenger2Handler (void)
{}

void 
AMI_Messenger2Handler::_tao_any_destructor (void *_tao_void_pointer)
{
  AMI_Messenger2Handler *_tao_tmp_pointer =
    static_cast<AMI_Messenger2Handler *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

AMI_Messenger2Handler_ptr
AMI_Messenger2Handler::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<AMI_Messenger2Handler>::narrow (
        _tao_objref,
        "IDL:AMI_Messenger2Handler:1.0",
        _TAO_AMI_Messenger2Handler_Proxy_Broker_Factory_function_pointer
      );
}

AMI_Messenger2Handler_ptr
AMI_Messenger2Handler::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<AMI_Messenger2Handler>::unchecked_narrow (
        _tao_objref,
        "IDL:AMI_Messenger2Handler:1.0",
        _TAO_AMI_Messenger2Handler_Proxy_Broker_Factory_function_pointer
      );
}

AMI_Messenger2Handler_ptr
AMI_Messenger2Handler::_nil (void)
{
  return 0;
}

AMI_Messenger2Handler_ptr
AMI_Messenger2Handler::_duplicate (AMI_Messenger2Handler_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
AMI_Messenger2Handler::_tao_release (AMI_Messenger2Handler_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
AMI_Messenger2Handler::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/Messaging/ReplyHandler:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:AMI_Messenger2Handler:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        ) == 0
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->::CORBA::Object::_is_a (value);
    }
}

const char* AMI_Messenger2Handler::_interface_repository_id (void) const
{
  return "IDL:AMI_Messenger2Handler:1.0";
}

::CORBA::Boolean
AMI_Messenger2Handler::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:70

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_AMI_Messenger2Handler (
    ::CORBA::tk_objref,
    "IDL:AMI_Messenger2Handler:1.0",
    "AMI_Messenger2Handler");
  
::CORBA::TypeCode_ptr const _tc_AMI_Messenger2Handler =
  &_tao_tc_AMI_Messenger2Handler;

// TAO_IDL - Generated from 
// be/be_visitor_exception/any_op_cs.cpp:45
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Dual_Impl_T<MessengerUnableToSendMessage2>::demarshal_value (
      TAO_InputCDR & cdr
    )
  {
    ::CORBA::String_var id;

    if (!(cdr >> id.out ()))
      {
        return false;
      }
    
    try
      {
        this->value_->_tao_decode (cdr);
      }
    catch (const ::CORBA::Exception &)
      {
        return false;
      }

    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// Copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    const MessengerUnableToSendMessage2 &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<MessengerUnableToSendMessage2>::insert_copy (
      _tao_any,
      MessengerUnableToSendMessage2::_tao_any_destructor,
      _tc_MessengerUnableToSendMessage2,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    MessengerUnableToSendMessage2 *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<MessengerUnableToSendMessage2>::insert (
      _tao_any,
      MessengerUnableToSendMessage2::_tao_any_destructor,
      _tc_MessengerUnableToSendMessage2,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    MessengerUnableToSendMessage2 *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const MessengerUnableToSendMessage2 *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    const MessengerUnableToSendMessage2 *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<MessengerUnableToSendMessage2>::extract (
        _tao_any,
        MessengerUnableToSendMessage2::_tao_any_destructor,
        _tc_MessengerUnableToSendMessage2,
        _tao_elem
      );
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:46
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<Messenger2>::to_object (
      ::CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    Messenger2_ptr _tao_elem)
{
  Messenger2_ptr _tao_objptr =
    Messenger2::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    Messenger2_ptr *_tao_elem)
{
  TAO::Any_Impl_T<Messenger2>::insert (
      _tao_any,
      Messenger2::_tao_any_destructor,
      _tc_Messenger2,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    Messenger2_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<Messenger2>::extract (
        _tao_any,
        Messenger2::_tao_any_destructor,
        _tc_Messenger2,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:46
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<AMI_Messenger2Handler>::to_object (
      ::CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    AMI_Messenger2Handler_ptr _tao_elem)
{
  AMI_Messenger2Handler_ptr _tao_objptr =
    AMI_Messenger2Handler::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    AMI_Messenger2Handler_ptr *_tao_elem)
{
  TAO::Any_Impl_T<AMI_Messenger2Handler>::insert (
      _tao_any,
      AMI_Messenger2Handler::_tao_any_destructor,
      _tc_AMI_Messenger2Handler,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    AMI_Messenger2Handler_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<AMI_Messenger2Handler>::extract (
        _tao_any,
        AMI_Messenger2Handler::_tao_any_destructor,
        _tc_AMI_Messenger2Handler,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_cs.cpp:49
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const MessengerUnableToSendMessage2 &_tao_aggregate
  )
{
  // Marshal the repository ID.
  return (strm << _tao_aggregate._rep_id ());
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &,
    MessengerUnableToSendMessage2&
  )
{
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:53

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messenger2_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Messenger2_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::Messenger2 RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        _TAO_Messenger2_Proxy_Broker_Factory_function_pointer
      );
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:53

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const AMI_Messenger2Handler_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    AMI_Messenger2Handler_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::AMI_Messenger2Handler RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        _TAO_AMI_Messenger2Handler_Proxy_Broker_Factory_function_pointer
      );
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL



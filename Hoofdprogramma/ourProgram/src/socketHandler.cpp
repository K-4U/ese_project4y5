// {{{RME classifier 'Logical View::TCPIP::socketHandler'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "socketHandler.h"
#endif

#include <RTSystem/ourProgram.h>
#include <socketHandler.h>
#include <TCPCONSTANTS.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_socketHandler_init( const RTObject_class * type, socketHandler * target )
{
	(void)new( target ) socketHandler;
}

static void rtg_socketHandler_copy( const RTObject_class * type, socketHandler * target, const socketHandler * source )
{
	(void)new( target ) socketHandler( *source );
}

static void rtg_socketHandler_destroy( const RTObject_class * type, socketHandler * target )
{
	target->~socketHandler();
}

const RTObject_class RTType_socketHandler =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "socketHandler"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( socketHandler )
  , (RTInitFunction)rtg_socketHandler_init
  , (RTCopyFunction)rtg_socketHandler_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_socketHandler_destroy
  , 1
  , socketHandler::rtg_socketHandler_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
socketHandler::socketHandler( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
socketHandler::~socketHandler( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
socketHandler::socketHandler( const socketHandler & rtg_arg )
	: rtg_state_socketHandler( rtg_arg.rtg_state_socketHandler )
	, sockets( rtg_arg.sockets )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
socketHandler & socketHandler::operator=( const socketHandler & rtg_arg )
{
	if( this != &rtg_arg )
		sockets = rtg_arg.sockets;
	return *this;
}
// }}}RME

const RTFieldDescriptor socketHandler::rtg_socketHandler_fields[] =
{
	// {{{RME classAttribute 'sockets'
	{
		"sockets"
	  , RTOffsetOf( socketHandler, sockets )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

#if OBJECT_DECODE
RTTypeInstaller rtg_socketHandler_installer( RTType_socketHandler );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME

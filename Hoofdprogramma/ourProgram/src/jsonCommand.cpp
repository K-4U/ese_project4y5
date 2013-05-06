// {{{RME classifier 'Logical View::TCPIP::jsonCommand'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "jsonCommand.h"
#endif

#include <RTSystem/ourProgram.h>
#include <jsonCommand.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_jsonCommand_init( const RTObject_class * type, jsonCommand * target )
{
	(void)new( target ) jsonCommand;
}

static void rtg_jsonCommand_copy( const RTObject_class * type, jsonCommand * target, const jsonCommand * source )
{
	(void)new( target ) jsonCommand( *source );
}

static void rtg_jsonCommand_destroy( const RTObject_class * type, jsonCommand * target )
{
	target->~jsonCommand();
}

const RTFieldDescriptor rtg_jsonCommand_fields[] =
{
	// {{{RME classAttribute 'command'
	{
		"command"
	  , RTOffsetOf( jsonCommand, command )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'data'
  , {
		"data"
	  , RTOffsetOf( jsonCommand, data )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , (const RTObject_class *)0
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

const RTObject_class RTType_jsonCommand =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "jsonCommand"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( jsonCommand )
  , (RTInitFunction)rtg_jsonCommand_init
  , (RTCopyFunction)rtg_jsonCommand_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_jsonCommand_destroy
  , 2
  , rtg_jsonCommand_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
jsonCommand::jsonCommand( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
jsonCommand::~jsonCommand( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
jsonCommand::jsonCommand( const jsonCommand & rtg_arg )
	: command( rtg_arg.command )
	, data( rtg_arg.data )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
jsonCommand & jsonCommand::operator=( const jsonCommand & rtg_arg )
{
	if( this != &rtg_arg )
	{
		command = rtg_arg.command;
		data = rtg_arg.data;
	}
	return *this;
}
// }}}RME

#if OBJECT_DECODE
RTTypeInstaller rtg_jsonCommand_installer( RTType_jsonCommand );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME

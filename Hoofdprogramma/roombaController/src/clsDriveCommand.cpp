// {{{RME classifier 'Logical View::Roomba::clsDriveCommand'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "clsDriveCommand.h"
#endif

#include <RTSystem/roombaController.h>
#include <clsDriveCommand.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_clsDriveCommand_init( const RTObject_class * type, clsDriveCommand * target )
{
	(void)new( target ) clsDriveCommand;
}

static void rtg_clsDriveCommand_copy( const RTObject_class * type, clsDriveCommand * target, const clsDriveCommand * source )
{
	(void)new( target ) clsDriveCommand( *source );
}

static void rtg_clsDriveCommand_destroy( const RTObject_class * type, clsDriveCommand * target )
{
	target->~clsDriveCommand();
}

const RTFieldDescriptor rtg_clsDriveCommand_fields[] =
{
	// {{{RME classAttribute 'right'
	{
		"right"
	  , RTOffsetOf( clsDriveCommand, right )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'left'
  , {
		"left"
	  , RTOffsetOf( clsDriveCommand, left )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

const RTObject_class RTType_clsDriveCommand =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "clsDriveCommand"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( clsDriveCommand )
  , (RTInitFunction)rtg_clsDriveCommand_init
  , (RTCopyFunction)rtg_clsDriveCommand_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_clsDriveCommand_destroy
  , 2
  , rtg_clsDriveCommand_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
clsDriveCommand::clsDriveCommand( void )
	: right( 0 )
	, left( 0 )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
clsDriveCommand::~clsDriveCommand( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
clsDriveCommand::clsDriveCommand( const clsDriveCommand & rtg_arg )
	: right( rtg_arg.right )
	, left( rtg_arg.left )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
clsDriveCommand & clsDriveCommand::operator=( const clsDriveCommand & rtg_arg )
{
	if( this != &rtg_arg )
	{
		right = rtg_arg.right;
		left = rtg_arg.left;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'clsDriveCommand(int,int)'
clsDriveCommand::clsDriveCommand( int left, int right )
	// {{{RME tool 'OT::Cpp' property 'ConstructorInitializer'
	// {{{USR

	// }}}USR
	// }}}RME
{
	// {{{USR
	//std::cout << dec << "New drive command: L=" << left << " R=" << right << endl;
	this->left = left;
	this->right = right;
	// }}}USR
}
// }}}RME

#if OBJECT_DECODE
RTTypeInstaller rtg_clsDriveCommand_installer( RTType_clsDriveCommand );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME

// {{{RME classifier 'Logical View::Roomba::clsDriveCommand'

#ifndef clsDriveCommand_H
#define clsDriveCommand_H

#ifdef PRAGMA
#pragma interface "clsDriveCommand.h"
#endif

#include <RTSystem/roombaController.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTObject_class RTType_clsDriveCommand;

class clsDriveCommand
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classAttribute 'right'
	int right;
	// }}}RME
	// {{{RME classAttribute 'left'
	int left;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	clsDriveCommand( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~clsDriveCommand( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	clsDriveCommand( const clsDriveCommand & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	clsDriveCommand & operator=( const clsDriveCommand & rtg_arg );
	// }}}RME
	// {{{RME operation 'clsDriveCommand(int,int)'
	explicit clsDriveCommand( int left, int right );
	// }}}RME
};

struct RTTypedValue_clsDriveCommand
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_clsDriveCommand( const clsDriveCommand & rtg_value )
		: data( &rtg_value ), type( &RTType_clsDriveCommand )
	{
	}
	inline RTTypedValue_clsDriveCommand( const clsDriveCommand & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_clsDriveCommand( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* clsDriveCommand_H */

// }}}RME

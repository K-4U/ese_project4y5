// {{{RME classifier 'Logical View::TCPIP::jsonCommand'

#ifndef jsonCommand_H
#define jsonCommand_H

#ifdef PRAGMA
#pragma interface "jsonCommand.h"
#endif

#include <RTSystem/roombaController.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include "../../include/json.h"
#include <stdio.h>

using namespace std;

// }}}USR
// }}}RME

extern const RTObject_class RTType_jsonCommand;

class jsonCommand
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
	// {{{RME classAttribute 'command'
	std::string command;
	// }}}RME
	// {{{RME classAttribute 'data'
	Json::Value data;
	// }}}RME

private:
	// {{{RME classAttribute 'jsonReader'
	Json::Reader jsonReader;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	jsonCommand( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~jsonCommand( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	jsonCommand( const jsonCommand & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	jsonCommand & operator=( const jsonCommand & rtg_arg );
	// }}}RME
	// {{{RME operation 'jsonCommand(std::string)'
	jsonCommand( std::string jsonCommand );
	// }}}RME
	// {{{RME operation 'createJsonString()'
	std::string createJsonString( void );
	// }}}RME
	static const RTFieldDescriptor rtg_jsonCommand_fields[];
};

struct RTTypedValue_jsonCommand
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_jsonCommand( const jsonCommand & rtg_value )
		: data( &rtg_value ), type( &RTType_jsonCommand )
	{
	}
	inline RTTypedValue_jsonCommand( const jsonCommand & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_jsonCommand( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* jsonCommand_H */

// }}}RME

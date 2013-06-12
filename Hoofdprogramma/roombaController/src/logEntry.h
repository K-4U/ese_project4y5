// {{{RME classifier 'Logical View::logEntry'

#ifndef logEntry_H
#define logEntry_H

#ifdef PRAGMA
#pragma interface "logEntry.h"
#endif

#include <RTSystem/roombaController.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <ctime>
#include <string>
#include "../../include/json.h"

using namespace std;

// }}}USR
// }}}RME

extern const RTObject_class RTType_logEntry;

class logEntry
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
	// {{{RME classAttribute 'timeOfEntry'
	time_t timeOfEntry;
	// }}}RME
	// {{{RME classAttribute 'entry'
	std::string entry;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	logEntry( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~logEntry( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	logEntry( const logEntry & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	logEntry & operator=( const logEntry & rtg_arg );
	// }}}RME
	// {{{RME operation 'logEntry(std::string)'
	logEntry( std::string entry );
	// }}}RME
	// {{{RME operation 'generateJson()'
	Json::Value generateJson( void );
	// }}}RME
	static const RTFieldDescriptor rtg_logEntry_fields[];
};

struct RTTypedValue_logEntry
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_logEntry( const logEntry & rtg_value )
		: data( &rtg_value ), type( &RTType_logEntry )
	{
	}
	inline RTTypedValue_logEntry( const logEntry & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_logEntry( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* logEntry_H */

// }}}RME

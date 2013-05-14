// {{{RME classifier 'Logical View::Serial::byteArray'

#ifndef byteArray_H
#define byteArray_H

#ifdef PRAGMA
#pragma interface "byteArray.h"
#endif

#include <RTSystem/ourProgram.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <stdio.h>
#include <vector>

// }}}USR
// }}}RME

extern const RTObject_class RTType_byteArray;

class byteArray
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
	// {{{RME classAttribute 'data'
	vector< char > data;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	byteArray( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	byteArray( const byteArray & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	byteArray & operator=( const byteArray & rtg_arg );
	// }}}RME
	// {{{RME operation 'byteArray(char*)'
	byteArray( char * chars );
	// }}}RME
	// {{{RME operation 'get(int)'
	char get( int index );
	// }}}RME
	// {{{RME operation 'size()'
	int size( void );
	// }}}RME
	// {{{RME operation 'getAll()'
	RTString getAll( void );
	// }}}RME
	static const RTFieldDescriptor rtg_byteArray_fields[];
};

struct RTTypedValue_byteArray
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_byteArray( const byteArray & rtg_value )
		: data( &rtg_value ), type( &RTType_byteArray )
	{
	}
	inline RTTypedValue_byteArray( const byteArray & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_byteArray( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* byteArray_H */

// }}}RME

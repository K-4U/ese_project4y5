// {{{RME classifier 'Logical View::TCPIP::socketHandler'

#ifndef socketHandler_H
#define socketHandler_H

#ifdef PRAGMA
#pragma interface "socketHandler.h"
#endif

#include <RTSystem/ourProgram.h>
class TCPCONSTANTS;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
//zet windowsversie op XP
#define WINVER 0x0501

#include <winsock2.h> 
#include <ws2tcpip.h> 
#include <stdio.h>
#include <TCPCONSTANTS.h>


#include <list>
using namespace std;

// }}}USR
// }}}RME

extern const RTObject_class RTType_socketHandler;

class socketHandler
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
	struct RTState_socketHandler
	{
		inline RTState_socketHandler( void )
			: state( 1U )
		{
		}
		inline ~RTState_socketHandler( void )
		{
		}
		unsigned char state;
	};
	RTState_socketHandler rtg_state_socketHandler;
	// {{{RME classAttribute 'sockets'
	list< SOCKET > sockets;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	socketHandler( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~socketHandler( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	socketHandler( const socketHandler & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	socketHandler & operator=( const socketHandler & rtg_arg );
	// }}}RME
	static const RTFieldDescriptor rtg_socketHandler_fields[];
};

struct RTTypedValue_socketHandler
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_socketHandler( const socketHandler & rtg_value )
		: data( &rtg_value ), type( &RTType_socketHandler )
	{
	}
	inline RTTypedValue_socketHandler( const socketHandler & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_socketHandler( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* socketHandler_H */

// }}}RME
